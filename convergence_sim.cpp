#include "player.h"
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	vector<player> players;
    vector<double> status;
    vector<double> values;
	int N;
	double v0;
	cin >> N >> v0;
	players.clear();
    status.clear();
    values.clear();
	for (int i = 0; i < N; i++) {
		players.push_back(player(cin));
		players.back().set_v0(v0);
        status.push_back(-1.);
        values.push_back(-1.);
	}

    int r = 0;
    while(true) {
		fprintf(stderr, "Round %d\n", ++r);
        bool changed = false;
		for (int i = 0; i < N; i++) {
			values[i] = compute_v0(players, i);
            double curr_v0 = players[i].get_v0();
			players[i].set_v0(v0 + values[i]);

            if (status[i] != values[i]) {
                status[i] = values[i];
                changed = true;
            }
			fprintf(stderr, "\tPlayer %d: %f using %d/%d, with external v0 = %f\n", i, players[i].solve().first, players[i].solve().second, (int)players[i].get_products().size(), values[i]);
			fprintf(stderr, "revenue of first unpicked: %f total revenue: %f\n", players[i].get_products()[players[i].solve().second].first, players[i].solve().first);

            players[i].set_v0(curr_v0);
		}

        for (int i = 0; i < N; i++) 
            players[i].set_v0(v0+values[i]);

        if (!changed) {
            printf("%d\n", r);
            break;
        }
	}

	return 0;
}
