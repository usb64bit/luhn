#include "Luhn.h"
#include <iostream>
#include <string>


using namespace std;
Luhn::Luhn()
{
	account = "";
	lastDigit = 0;
	checkDigit = 0;
}

Luhn::~Luhn()
{}

bool Luhn::check(string numbers)
{
	//initalize varibles
	string tmp, lDigit;
	int num;

	tmp = numbers;
	lDigit = numbers.at(numbers.length()-1);
	lastDigit = atoi(lDigit.c_str());
	cout << "ldigit:"<< lDigit << endl;
	tmp.erase(numbers.length()-1, numbers.length());
	cout << "tmp :" << tmp << endl;
	num = generateCheckDigit(tmp);
	cout << "num " << num << "checkdigit " <<checkDigit << endl;
	return (num == lastDigit);
}
void Luhn::recursiveAppend(string numbers, int size)
{
	if(numbers.length() == size)
		return;
	


}
int Luhn::getCheckDigit()
{
	return checkDigit;
}

int Luhn::generateCheckDigit(string numbers)
{
	//initalize varibles
	string tmp;
	int num, total = 0;

	//reverse the numbers
	reverse(numbers.begin(), numbers.end());

	//iterate through and calculate
	for(int i=0; i<numbers.length(); i++)
	{
		//convert string to int
		tmp = numbers[i];
		num = atoi(tmp.c_str());
		
		//logic
		if(i%2 == 0)
		{
			if(num > 4) {
                num = (num - 5) * 2 + 1;
            } else {
                num *= 2;
            }
		}

		//keep running total
		total += num;
	}

	checkDigit = (total*9)%10;

	return checkDigit;
}

char randDigit()
{
	return rand()%10+48;
}