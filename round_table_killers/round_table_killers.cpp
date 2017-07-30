/**
 *
 * \file round_table_killers.cpp
 *
 * \brief Solution to https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/round-table-killers-b7b93156/
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 *
 * \brief Play a single turn of the round table killing game.
 *
 * \details The player with the gun kills x % k people clockwise to him, and hands the gun to the first living person
 * after that. The player states are updated accordingly.
 *
 * \param[in] num_players The number of players who started the game
 * \param[in] player_states The state fo health of each player at the start of the turn
 * \param[in] player_index The index of the player with the gun
 * \param[in] modulo_operand The modulo operand to determine the number of people a player kills.
 *
 * \return The index of the next player to hold the gun
 *
 * \author Mardava Gubbi <mrdv.rjgpl@gmail.com>
 *
 */
int SingleKillingTurn(int num_players, int *player_states, int player_index, int modulo_operand)
{
	int i = (player_index + 1) % num_players;
	int num_kills = 0;

	while(num_kills < (player_index + 1) % modulo_operand)
	{
		if(player_states[i] == 1)
		{
			++num_kills;
			player_states[i] = 0;
		}

		do
		{
			i = (i + 1) % num_players;
		} while(player_states[i] == 0);

	}

	return i;
}

int main(int argc, char **argv)
{
	int i;
	int k;
	int n;
	int x;
	int *player_states;
	int num_players_alive;

	cin >> n >> k >> x;
	num_players_alive = n;
	--x;
	player_states = new int[n];

	for(i = 0; i < n; ++i)
	{
		player_states[i] = 1;
	}

	while(num_players_alive > (x + 1) % k)
	{
		num_players_alive -= (x + 1) % k;
		x = SingleKillingTurn(n, player_states, x, k);
	}

	cout << (x + 1) << endl;

	return 0;
}

