#include <cstdlib>
#include <iostream>
#include <string>
#include "Luhn.h"
using namespace std;

int main(int argc, char** argv) {
	Luhn l;
    string numbers;
    cout << "Enter Account Number or -1 to quit: ";
    cin >> numbers;
    
	while(numbers != "-1")
    {
		if(l.check(numbers))
			cout << "IT WORKS!" << endl;
		else
			cout << "check digit was: " << l.getCheckDigit() << endl;
		cout << endl;
		cout << "Enter Account Number or -1 to quit: ";
		cin >> numbers;
	}

    return 0;
}