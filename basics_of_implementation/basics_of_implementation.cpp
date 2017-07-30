/**
 *
 * \file basics_of_implementation.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/tutorial/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>
#include <cstring>

#define MAX_STRING_LENGTH 100
#define NUM_DIGITS 10

using namespace std;

int main(int argc, char **argv)
{
	char s[MAX_STRING_LENGTH];
	int i;
	int digit_hist[NUM_DIGITS] = {0};

	cin >> s;

	for(i = 0; i < strlen(s); ++i)
	{
		++digit_hist[s[i] - '0'];
	}

	for(i = 0; i < NUM_DIGITS; ++i)
	{
		cout << i << " " << digit_hist[i] << endl;
	}

	return 0;
}

