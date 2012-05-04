#ifndef PLAYER_H
#define PLAYER_H
#include <utility>
#include <vector>
#include <iostream>
using std::pair;
using std::vector;
using std::istream;

// first == revenue, second == value
typedef pair<double, double> product;

class player {
	public:
		player(istream &in);
		player(const vector<product>& products, double gamma);
		void set_v0(double v0);
        // Get raw v0
        double get_v0();
		// Get V_g(O)^gamma
		double get_value();
		double get_revenue();
		vector<product>& get_products();
		// Solve returns an int, the number of objects in the optimal set
		//    and the value of the optimal
		pair<double, int> solve();
	private:
		double _v0;
		vector<product> _products;
		double _gamma;
		double _value;
		pair<double, int> _optimal;
		// If _dirty == true, then _optimal is invalid
		bool _dirty;
		bool _dirty_value;
};

// Compute the no-purchase option for "current" (0 <= current < players.size())
double compute_v0(vector<player>& players, int current);

#endif
