#include "player.h"
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

const int ROUNDS = 10;

int main() {
	vector<player> players;
	int N;
	double v0;
	cin >> N >> v0;
	players.clear();
	for (int i = 0; i < N; i++) {
		players.push_back(player(cin));
		players.back().set_v0(v0);
	}
	printf("\tPlayer 0: %f using %d/%d\n",  players[0].solve().first, players[0].solve().second, (int)players[0].get_products().size());
	for (int r = 0; r < ROUNDS; r++) {
		printf("Round %d\n", r+1);
		for (int i = 0; i < N; i++) {
			double temp = compute_v0(players, i);
			players[i].set_v0(v0 + temp);
			printf("\tPlayer %d: %f using %d/%d, with external v0 = %f\n", i, players[i].solve().first, players[i].solve().second, (int)players[i].get_products().size(), temp);
			fprintf(stderr, "revenue of first unpicked: %f total revenue: %f\n", players[i].get_products()[players[i].solve().second].first, players[i].solve().first);
		}
	}
	return 0;
}
