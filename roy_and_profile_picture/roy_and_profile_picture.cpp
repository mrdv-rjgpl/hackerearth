/**
 *
 * \file roy_and_profile_picture.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/roy-and-profile-picture/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int l;
	int n;
	int w;
	int h;

	cin >> l >> n;

	while(n--)
	{
		cin >> w >> h;

		if((w < l) || (h < l))
		{
			cout << "UPLOAD ANOTHER" << endl;
		}
		else if(w != h)
		{
			cout << "CROP IT" << endl;
		}
		else
		{
			cout << "ACCEPTED" << endl;
		}
	}
	return 0;
}

