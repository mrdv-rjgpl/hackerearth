/**
 *
 * \file palindrome_check_2.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/palindrome-check-2/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <cstring>
#include <iostream>

#define MAX_STRING_LENGTH 101u

using namespace std;

/**
 *
 * \brief Check if the given string is a palindrome or not.
 *
 * \param[in] s The input string
 *
 * \return true If the string is a palindrome
 * \return false If the string is not a palindrome
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
bool IsPalindrome(char *s)
{
	bool palindrome = true;
	int i;
	int half_string_length;
	int string_length;

	string_length = strlen(s);
	half_string_length = string_length / 2;
	--string_length;

	for(i = 0; i < half_string_length; ++i)
	{
		if(s[i] != s[string_length - i])
		{
			palindrome = false;

			break;
		}
	}

	return palindrome;
}

int main(int argc, char **argv)
{
	char s[MAX_STRING_LENGTH];

	cin >> s;

	if(IsPalindrome(s))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}

