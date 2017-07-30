/**
 *
 * \file monk_visits_coderland.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/monk-visits-coderland-4/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>
#include <vector>

#define MAX_PETROL_COST 100000

using namespace std;

/**
 *
 * \brief Get the minimum cost of petrol to get from checkpoint 0 to checkpoint 'N'.
 *
 * \details At each checkpoint 'i', the function computes the lowest cost of petrol 'r_i' up until that checkpoint 'i'.
 * The petrol required to get from checkpoint 'i' to checkpoint 'i + 1' is bought at the rate 'r_i'.
 * The net cost is computed by multiplying the individual costs with the corresponding amounts of petrol.
 *
 * \param[in] petrol_costs The cost of petrol at each checkpoint.
 * \param[in] req_petrol_amounts The required amount of petrol to get from the current checkpoint to the next.
 *
 * \return total_cost The total cost of petrol required to get from checkpoint 0 to checkpoint 'N'.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
unsigned long long int GetMinPetrolCost(
		vector<unsigned long long int> petrol_costs,
		vector<unsigned long long int> req_petrol_amounts)
{
	int i;
	int num_checkpoints = petrol_costs.size();
	unsigned long long int total_cost = 0;
	unsigned long long int min_petrol_cost;

	min_petrol_cost = MAX_PETROL_COST;

	for(i = 0; i < num_checkpoints; ++i)
	{
		if(petrol_costs[i] < min_petrol_cost)
		{
			/* There's a new cheap checkpoint on the map, so drop the cost of petrol from this checkpoint onwards. */
			min_petrol_cost = petrol_costs[i];
		}

		total_cost += (min_petrol_cost * req_petrol_amounts[i]);
	}

	return total_cost;
}

int main(int argc, char **argv)
{
	int i;
	int j;
	int n;
	int t;

	cin >> t;

	for(i = 0; i < t; ++i)
	{
		cin >> n;
		vector<unsigned long long int> c(n);
		vector<unsigned long long int> l(n);

		for(j = 0; j < n; ++j)
		{
			cin >> c[j];
		}

		for(j = 0; j < n; ++j)
		{
			cin >> l[j];
		}

		cout << GetMinPetrolCost(c, l) << endl;
	}

	return 0;
}

