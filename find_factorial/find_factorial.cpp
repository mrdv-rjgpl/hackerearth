/**
 *
 * \file find_factorial.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/find-factorial/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>

using namespace std;

/**
 *
 * \brief Compute the factorial of the given small number.
 *
 * \param[in] n The input number
 *
 * \return factorial The factorial value of n
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int GetSmallFactorial(int n)
{
	int factorial = 1;
	int i;

	for(i = 2; i <= n; ++i)
	{
		factorial *= i;
	}

	return factorial;
}

int main(int argc, char **argv)
{
	int n;

	cin >> n;
	cout << GetSmallFactorial(n) << endl;

	return 0;
}

