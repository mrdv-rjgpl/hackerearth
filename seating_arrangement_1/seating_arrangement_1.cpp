/**
 *
 * \file seating_arrangement_1.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/seating-arrangement-1/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>

#define NUM_UNIQUE_SEATS 12
#define NUM_SINGLE_ROW_SEATS 6
#define NUM_SINGLE_SEAT_SEATS 3

using namespace std;

/**
 *
 * \brief Get the seat number of the seat facing the given seat.
 *
 * \param[in] seat_number The input seat number
 *
 * \return facing_seat_number The facing seat's number
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int GetFacingSeatNumber(int seat_number)
{
	int base_number = ((seat_number - 1) % NUM_UNIQUE_SEATS) + 1;
	int facing_seat_number = seat_number + NUM_UNIQUE_SEATS + 1 - (2 * base_number);

	return facing_seat_number;
}

/**
 *
 * \brief Get the type of the given seat.
 *
 * \param[in] seat_number The input seat number
 *
 * \return 0 If the seat is a window seat
 * \return 1 If the seat is a middle seat
 * \return 2 If the seat is an aisle seat
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int GetSeatType(int seat_number)
{
	int base_number = ((seat_number - 1) % NUM_SINGLE_ROW_SEATS);

	if(base_number >= NUM_SINGLE_SEAT_SEATS)
	{
		base_number = NUM_SINGLE_ROW_SEATS - 1 - base_number;
	}

	return base_number;
}

int main(int argc, char **argv)
{
	int n;
	int fs;
	int s;
	int type;

	cin >> n;

	while(n--)
	{
		cin >> s;
		fs = GetFacingSeatNumber(s);
		type = GetSeatType(fs);
		cout << fs << " ";

		if(type == 0)
		{
			cout << "WS" << endl;
		}
		else if(type == 1)
		{
			cout << "MS" << endl;
		}
		else
		{
			cout << "AS" << endl;
		}
	}

	return 0;
}

