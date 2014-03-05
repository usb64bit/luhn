#ifndef _LUHN_H_
#define _LUHN_H_

#include <string>

using namespace std;

class Luhn
{
public:
	Luhn();
	~Luhn();

	bool check(string);
	int generateCheckDigit(string);
	char randDigit();
	int getCheckDigit();
	void recursiveAppend(string, int);

private:
	string account;
	int checkDigit;
	int lastDigit;
};

#endif