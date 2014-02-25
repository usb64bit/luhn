#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void luhn(string numbers)
{
	//initalize varibles
    int len = numbers.length();
	int total = 0;
    int num, checkDigit;
	string tmp;

	//loop through each value
    for(int i=0; i<len-1; i++)
    {
		//get a single letter
        tmp = numbers.at(i);
        
		//convert to int
		num = atoi(tmp.c_str());

		//logic checks
        if((i+1)%2 == 0) {
            if(num > 4) {
                num = (num - 5) * 2 + 1;
            } else {
                num *= 2;
            }
        }

		//keep a running total
		total += num;
    }

	//calculate the check digit
	checkDigit = (10-total%10);

	//get last digit and convert to int
	tmp = numbers.at(len-1);
	num = atoi(tmp.c_str());

	//check if last digit is same as the check digit
	if(num == checkDigit)
		cout << "CORRECT" << endl;

}

int main(int argc, char** argv) {
    string numbers;
    cout << "Enter Account Number or -1 to quit: ";
    cin >> numbers;
    
	while(numbers != "-1")
    {
		luhn(numbers);
		cout << endl;
		cout << "Enter Account Number or -1 to quit: ";
		cin >> numbers;
	}

    return 0;
}