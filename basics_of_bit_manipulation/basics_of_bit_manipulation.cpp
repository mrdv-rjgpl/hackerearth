/**
 *
 * \file basics_of_bit_manipulation.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int t;
	int n;
	int num_set_bits = 0;

	cin >> t;

	while(t--)
	{
		cin >> n;
		num_set_bits = 0;

		while(n)
		{
			num_set_bits += (n & 0x00000001);
			n >>= 1;
		}

		cout << num_set_bits << endl;
	}
	return 0;
}

