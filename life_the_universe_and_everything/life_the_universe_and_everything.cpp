/**
 *
 * \file life_the_universe_and_everything.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/life-the-universe-and-everything/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int n;

	while(1)
	{
		cin >> n;

		if(n == 42)
		{
			break;
		}
		else
		{
			cout << n << endl;
		}
	}

	return 0;
}

