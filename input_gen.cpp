#include <iostream>
#include <cmath>

using namespace std;

void print_usage(char* invoke) {
    printf("Usage: %s <num_of_players> <mean_of_items_per_player> <std_of_items_per_player>\n", invoke);
}

// Return a uniform number from 0 - 1 
inline double uniform() {
    return (double)rand() / (double)RAND_MAX;
}

// Get a random integer following normal distribution with mean and std. 
// http://en.wikipedia.org/wiki/Box_Muller_transform
int get_random(double mean, double std) {
    double u1 = uniform();
    double u2 = uniform();
    return max((int)ceil(sqrt(-2*log(u1))*cos(2*M_PI*u2)*std + mean), 1);
}

// Outer v0
inline double sample_v0() {
    return uniform();    
}

// Inner v0
inline double sample_internal_v0() {
    return uniform();
}

inline double sample_gamma() {
	return uniform();
}

// What's the value for an item?
inline double sample_value() {
    return uniform();
}

// Given value v, what's the revenue?
inline double sample_revenue(double value) {
    return uniform();
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return -1;
    }
    
    int players = atoi(argv[1]);
    double mean = atof(argv[2]);
    double std = atof(argv[3]);
    
    // The total number of players and v0
    printf("%d %f\n", players, sample_v0());

    for (int i = 0; i < players; ++i) {
        int count = get_random(mean, std);
        // Total number of items for player i, and the internal v0
        printf("%d %f", count, sample_gamma());

        for (int j = 0; j < count; ++j) {
            double value = sample_value();
            double revenue = sample_revenue(value);
            printf(" %f %f", revenue, value);
        }

        printf("\n");
    }

    return 0;
}

