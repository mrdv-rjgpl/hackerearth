/**
 *
 * \file prime_number_8.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/prime-number-8/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>

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

int main(int argc, char **argv)
{
	int i;
	int n;

	cin >> n;

	for(i = 2; i <= n; ++i)
	{
		if(IsPrime(i))
		{
			cout << i << " ";
		}
	}

	cout << endl;

	return 0;
}

