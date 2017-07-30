/**
 *
 * \file toggle_string.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/modify-the-string/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <cstring>
#include <iostream>

#define MAX_STRING_LENGTH 101u

using namespace std;

int main(int argc, char **argv)
{
	char s[MAX_STRING_LENGTH];
	int i;

	cin >> s;

	for(i = 0; (i < MAX_STRING_LENGTH) && (s[i] != 0); ++i)
	{
		if((s[i] >= 'A') && (s[i] <= 'Z'))
		{
			s[i] += 'a' - 'A';
		}
		else if((s[i] >= 'a') && (s[i] <= 'z'))
		{
			s[i] -= 'a' - 'A';
		}
	}

	cout << s << endl;

	return 0;
}

