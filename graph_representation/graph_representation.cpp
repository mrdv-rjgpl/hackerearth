/**
 *
 * \file graph_representation.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/tutorial/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>

using namespace std;

/**
 *
 * \brief Determine if an edge exists in the graph \f$ G \f$ between the nodes \f$ A \f$ and \f$ B \f$.
 *
 * \details Input the graph as an adjacency matrix, without worrying about space constraints. Force a lower triangular
 * matrix, and search for edges only in the lower half of the matrix.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
void EdgeChecks(void)
{
	int a;
	int b;
	int i;
	int m;
	int n;
	int q;

	cin >> n >> m;

	int adjacency_matrix[n][n];

	for(i = 0; i < m; ++i)
	{
		cin >> a >> b;

		adjacency_matrix[a > b? (a - 1): (b - 1)][a > b? (b - 1): (a - 1)] = 1;
	}

	cin >> q;

	for(i = 0; i < q; ++i)
	{
		cin >> a >> b;

		if(adjacency_matrix[a > b? (a - 1): (b - 1)][a > b? (b - 1): (a - 1)] == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}

int main(int argc, char **argv)
{
	EdgeChecks();

	return 0;
}

