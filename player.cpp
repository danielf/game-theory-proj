#include "player.h"

#include "math.h"

#include <algorithm>
using std::vector;
using std::sort;
using std::reverse;
using std::pair;
using std::make_pair;

player::player(const vector<product>& products, double gamma) : 
	             _products(products), _gamma(gamma), _dirty(true) {
	sort(_products.begin(), _products.end());
	reverse(_products.begin(), _products.end());
}

void player::set_v0(double v0) {
	_v0 = v0;
	_dirty = true;
}

double player::get_value() {
	if (!_dirty) return _value;
	int N = solve().second;
	double ans = 0;
	while (N--)
		ans += _products[N].second;
	return _value = pow(ans, _gamma);
}

vector<product>& player::get_products() {
	return _products;
}

pair<double, int> player::solve() {
	if (!_dirty) return _optimal;
	pair<double, int> ans = make_pair(0.0, 0);
	double num = 0., denom = 0.;
	for (int i = 0; i < (int)_products.size(); ++i) {
		num += _products[i].first*_products[i].second;
		denom += _products[i].second;
		ans = max(ans, make_pair(pow(num, _gamma-1)/(_v0 + pow(denom, _gamma)), i+1));
	}
	_optimal = ans;
	_dirty = false;
	return ans;
}

double compute_v0(vector<player>& players, int current) {
	double ans = 0.;
	for (int i = 0; i < (int)players.size(); ++i) if (i != current)
		ans += players[i].get_value();
	return ans;
}
