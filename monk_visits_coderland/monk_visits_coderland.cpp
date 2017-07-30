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
unsigned long long int GetMinPetrolCost(vector<int> petrol_costs, vector<int> req_petrol_amounts)
{
	int cheapest_checkpoint;
	int i;
	int num_checkpoints = petrol_costs.size();
	unsigned long long int total_cost = 0;
	vector<unsigned long long int> min_petrol_costs;
	vector<unsigned long long int> min_petrol_amt;

	/* Make the first petrol purchase at the first checkpoint, because there's no other option. */
	cheapest_checkpoint = 0;
	min_petrol_costs.push_back(petrol_costs[0]);
	min_petrol_amt.push_back(req_petrol_amounts[0]);

	/* Iterate from the next checkpoint onwards. */
	for(i = 1; i < num_checkpoints; ++i)
	{
		if(petrol_costs[i] < min_petrol_costs[cheapest_checkpoint])
		{
			/* There's a new cheapest checkpoint on the map, so add it to the list. */
			min_petrol_costs.push_back(petrol_costs[i]);
			min_petrol_amt.push_back(req_petrol_amounts[i]);
			++cheapest_checkpoint;
		}
		else
		{
			/* Buy this petrol at the cheapest checkpoint so far. */
			min_petrol_amt[cheapest_checkpoint] += req_petrol_amounts[i];
		}
	}

	for(i = 0; i <= cheapest_checkpoint; ++i)
	{
		total_cost += (min_petrol_costs[i] * min_petrol_amt[i]);
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
		vector<int> c(n);
		vector<int> l(n);

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

