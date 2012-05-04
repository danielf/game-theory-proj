#include "player.h"

#include "math.h"

#include <algorithm>
using std::vector;
using std::sort;
using std::reverse;
using std::pair;
using std::make_pair;

player::player(istream& in) : _dirty(true) {
	int N;
	in >> N >> _gamma;
	_products.resize(N);
	for (int i = 0; i < N; i++)
		in >> _products[i].first >> _products[i].second;
	sort(_products.begin(), _products.end());
	reverse(_products.begin(), _products.end());
	_dirty_value = true;
}

player::player(const vector<product>& products, double gamma) : 
	             _products(products), _gamma(gamma), _dirty(true) {
	sort(_products.begin(), _products.end());
	reverse(_products.begin(), _products.end());
	_dirty_value = true;
}

void player::set_v0(double v0) {
	_v0 = v0;
	_dirty = true;
	_dirty_value = true;
}

double player::get_revenue() {
	int N = _optimal.second;
	double denominator = get_value() + _v0;
	double numerator = 0.;
	for (int n = 0; n < N; n++)
		numerator += _products[n].first*_products[n].second;
	numerator *= pow(get_value(), (_gamma-1)/_gamma);
	return numerator/denominator;
}

double player::get_value() {
	if (!_dirty_value) return _value;
	int N = _optimal.second;
	double ans = 0;
	for (int n = 0; n < N; n++)
		ans += _products[n].second;
	_dirty_value = false;
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
		ans = max(ans, make_pair((pow(denom, _gamma-1)*num)/(_v0 + pow(denom, _gamma)), i+1));
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
