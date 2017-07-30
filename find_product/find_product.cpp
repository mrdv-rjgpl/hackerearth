/**
 *
 * \file find_product.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/find-product/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>

#define MODULO_OPERAND 1000000007u

using namespace std;

int main(int argc, char **argv)
{
	unsigned long long int a;
	int n;
	unsigned long long int product = 1;

	cin >> n;

	while(n--)
	{
		cin >> a;
		product = (product * a) % MODULO_OPERAND;
	}

	cout << product << endl;

	return 0;
}

