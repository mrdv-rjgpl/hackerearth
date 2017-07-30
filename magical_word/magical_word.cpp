/**
 *
 * \file magical_word.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/magical-word/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <cstdlib>
#include <iostream>

#define ASCII_MAX 256u
#define MAX_STRING_LENGTH 500u
#define MAX_PRIME_VALUE 1000u

using namespace std;

/**
 *
 * \brief Check if the given number is prime or not.
 *
 * \details Check all integers until the square root of the input for divisibility. If any of the numbers is a factor
 * of the input, then the input is composite.
 *
 * \param[in] n The number to be checked from primeness
 *
 * \return true if the number is prime
 * \return false if the number is composite
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
bool IsPrime(int n)
{
	bool prime = true;
	int i;

	for(i = 2; (i * i) <= n; ++i)
	{
		if(n % i == 0)
		{
			prime = false;

			break;
		}
	}

	return prime;
}

/**
 *
 * \brief Get the closest letter to the input whose ascii value is a prime number
 *
 * \param[in] c The input character
 *
 * \return d The closest character to c with a prime number for an ascii value
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
char GetMagicLetter(char c)
{
	int i;
	int n = (int)c;
	int lower;
	int upper;
	int magic_letter = MAX_PRIME_VALUE;

	for(i = 'A'; i <= 'z'; ++i)
	{
		if((abs(n - i) < abs(n - magic_letter))
				&& ((i <= 'Z')
					|| (i >= 'a')))
		{
			if(IsPrime(i))
			{
				magic_letter = i;
			}
		}
	}

	return (char)magic_letter;
}

int main(int argc, char **argv)
{
	char s[MAX_STRING_LENGTH];
	int i;
	int n;
	int t;

	cin >> t;

	while(t--)
	{
		cin >> n >> s;

		for(i = 0; i < n; ++i)
		{
			cout << GetMagicLetter(s[i]);
		}

		cout << endl;
	}

	return 0;
}

