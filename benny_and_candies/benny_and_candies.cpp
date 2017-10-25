/**
 *
 * \file benny_and_candies.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/benny-and-candies/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>

using namespace std;

#define KOROVKA_PRICE_SHIFT 8u

/**
 *
 * \brief Compute the profit from selling Korovkas over 'n' days.
 *
 * \details Be smart about the computations, using the following rules:
 * 1. For a monotonically increasing sequence of prices, Benny's net profit is the price she sold the last korovka at,
 * minus the price she bought the first korovka at.
 * 2. Any sequence of prices can be split into a series of monotonically increasing sub-sequences.
 *
 * \param[in] a A coefficient used to compute the daily korovka price
 * \param[in] b A coefficient used to compute the daily korovka price
 * \param[in] m A coefficient used to compute the daily korovka price
 * \param[in] n The number of days to be considered
 *
 * \return Benny's net profit from selling korovkas for 'n' days.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
unsigned long int ComputeKorovkaProfitWithSubSequences(int a, int b, int m, int n)
{
	int i;
	unsigned int korovka_price = 0;
	unsigned int korovka_price_prev = 0;
	unsigned int korovka_scale = 0;
	unsigned int korovka_scale_prev = 0;
	unsigned long int korovka_profit = 0;

	for(i = 0; i < n; ++i)
	{
		korovka_scale = ((a * (korovka_scale % m)) + b);

		/* Start from day 1, not 0, since day 0 cannot involve a sale. */
		if(i == 0)
		{
			korovka_price_prev = korovka_scale >> KOROVKA_PRICE_SHIFT;
		}
		else if(i == n - 1)
		{
			korovka_price = korovka_scale >> KOROVKA_PRICE_SHIFT;
			korovka_profit += (korovka_price - korovka_price_prev);
		}

		if(korovka_scale < korovka_scale_prev)
		{
			korovka_price = korovka_scale_prev >> KOROVKA_PRICE_SHIFT;
			korovka_profit += (korovka_price - korovka_price_prev);
			korovka_price_prev = korovka_scale >> KOROVKA_PRICE_SHIFT;
		}

		korovka_scale_prev = korovka_scale;
	}

	return korovka_profit;
}

/*
 * \brief Compute the profit from selling Korovkas over 'n' days.
 *
 * \details Use the brute force greedy method to check if the current day's Korovka price exceeds that of the previous
 * day, and then conduct a (buy on previous day, sell on current dat) sequence for those two prices.
 *
 * \param[in] a A coefficient used to compute the daily korovka price
 * \param[in] b A coefficient used to compute the daily korovka price
 * \param[in] m A coefficient used to compute the daily korovka price
 * \param[in] n The number of days to be considered
 *
 * \return Benny's net profit from selling korovkas for 'n' days.
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
unsigned long int ComputeKorovkaProfitBruteForce(int a, int b, int m, int n)
{
	int i;
	unsigned int korovka_price = 0;
	unsigned int korovka_scale = 0;
	unsigned int korovka_price_prev = 0;
	unsigned long int korovka_profit = 0;

	for(i = 0; i < n; ++i)
	{
		korovka_scale = ((a * (korovka_scale % m)) + b);
		korovka_price = korovka_scale >> KOROVKA_PRICE_SHIFT;

		/* Start from day 1, not 0, since day 0 cannot involve a sale. */
		if((korovka_price > korovka_price_prev) && (i > 0))
		{
			korovka_profit += (korovka_price - korovka_price_prev);
		}

		korovka_price_prev = korovka_price;
	}

	return korovka_profit;
}

int main(int argc, char **argv)
{
	int a;
	int b;
	int m;
	int n;

	cin >> n >> m >> a >> b;
	cout << ComputeKorovkaProfitBruteForce(a, b, m, n) << endl;
	cout << ComputeKorovkaProfitWithSubSequences(a, b, m, n) << endl;

	return 0;
}

