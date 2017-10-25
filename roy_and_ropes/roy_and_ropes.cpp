/**
 *
 * \file roy_and_ropes.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-ropes
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>

using namespace std;

/**
 *
 * \brief Compute the time taken to burn the rope, in minutes.
 *
 * \details The first guess for the burn time is the length of the rope, as one minute is required for each unit length
 * of rope to burn. However, this is not always the final answer, as longer rope segments may be attached to the upper
 * or lower sides of the central rope.
 *
 * Consider the rope segments of lengths \f$ u_k \f$ and \f$ l_k \f$ attached to the upper and lower sides of the
 * central rope at a distance of \f$ k \f$ units from the left end of the rope. Now, the time \f$ t1_k \f$ to burn the
 * upper segment of the rope is given by:
 * \f[
 * t1_k = k + u_k
 * \f]
 *
 * The rope takes \f$ k \f$ minutes to burn from the left end to the node containing the upper segment in question, and
 * then \f$ u_k \f$ minutes to burn the upper segment itself. Similarly, for the lower segment, we have the burn time
 * \f$ t2_k \f$ given by the equation:
 * \f[
 * t2_k = k + l_k
 * \f]
 *
 * We observe that if we count the burn time for each segment from the left end of the rope, then all segments begin
 * burning simultaneously, once the left end is lit. Hence, the total time for the rope to burn is simply the maximum
 * of \f$ t1_k \f$ and \f$ t2_k \f$ as \f$ k \f$ goes from \f$ 1 \f$ to \f$ L - 1 \f$. A running computation of the
 * maximum burn time gives us the final result.
 *
 * \return max_burn_time The total time required for the rope to burn
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int ComputeRopeBurnTime()
{
	int i;
	int l;
	int max_burn_time;

	cin >> l;

	int upper;
	int lower;

	max_burn_time = l;

	/* Input the length of the current upper segment, and compute the total burn time for said segment. */
	for(i = 1; i < l; ++i)
	{
		cin >> upper;

		if(max_burn_time < upper + i)
		{
			max_burn_time = upper + i;
		}
		else
		{
			/* No operation */
		}
	}

	/* Input the length of the current lower segment, and compute the total burn time for said segment. */
	for(i = 1; i < l; ++i)
	{
		cin >> lower;

		if(max_burn_time < lower + i)
		{
			max_burn_time = lower + i;
		}
		else
		{
			/* No operation */
		}
	}

	return max_burn_time;
}

int main(int argc, char **argv)
{
	int i;
	int t;

	cin >> t;

	for(i = 0; i < t; ++i)
	{
		cout << ComputeRopeBurnTime() << endl;
	}

	return 0;
}

