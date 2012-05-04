#include "player.h"
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	vector<player> players;
    vector<double> status;
	int N;
	double v0;
	cin >> N >> v0;
	players.clear();
    status.clear();
	for (int i = 0; i < N; i++) {
		players.push_back(player(cin));
		players.back().set_v0(v0);
        status.push_back(-1.);
	}

    int r = 0;
    while(true) {
		fprintf(stderr, "Round %d\n", ++r);
        bool changed = false;
		for (int i = 0; i < N; i++) {
			double temp = compute_v0(players, i);
			players[i].set_v0(v0 + temp);
            if (status[i] != temp) {
                status[i] = temp;
                changed = true;
            }
			fprintf(stderr, "\tPlayer %d: %f using %d/%d, with external v0 = %f\n", i, players[i].solve().first, players[i].solve().second, (int)players[i].get_products().size(), temp);
			fprintf(stderr, "revenue of first unpicked: %f total revenue: %f\n", players[i].get_products()[players[i].solve().second].first, players[i].solve().first);
		}

        if (!changed) {
            printf("%d\n", r);
            break;
        }
	}

	return 0;
}
