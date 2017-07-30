/**
 *
 * \file count_divisors.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/count-divisors/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int k;
	int l;
	int r;

	cin >> l >> r >> k;
	r = r - (r % k);
	l = (l - 1) - ((l - 1) % k);
	cout << ((r - l) / k) << endl;

	return 0;
}

