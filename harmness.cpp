#include "player.h"
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	vector<player> players;
	vector<int> sol[2];
	int N;
	double v0;
	cin >> N >> v0;
	for (int i = 0; i < N-1; i++) {
		players.push_back(player(cin));
		players.back().set_v0(v0);
	}
	player last(cin);
	last.set_v0(v0);
	sol[0].resize(N-1);
	sol[1].resize(N-1);
	sol[1][0] = -1;
	double total_rev_before;
	while (sol[0] != sol[1]) {
		total_rev_before = 0.;
		for (int i = 0; i < N-1; i++) {
			double temp = compute_v0(players, i);
			players[i].set_v0(v0 + temp);
			sol[0][i] = players[i].solve().second;
			total_rev_before += players[i].solve().first;
		}
		swap(sol[0], sol[1]);
	}
	// N-1 players in Nash, last players enters
	last.set_v0(v0 + compute_v0(players, -1));
	last.solve();
	// Get the total revenue of the other players
	double total_rev_after = 0.;
	players.push_back(last);
	for (int i = 0; i < N-1; i++) {
		players[i].set_v0(v0 + compute_v0(players, i));
		total_rev_after += players[i].get_revenue();
	}
	printf("After/Before: %f/%f = %f\n", total_rev_after, total_rev_before, total_rev_after/total_rev_before);
	return 0;
}
