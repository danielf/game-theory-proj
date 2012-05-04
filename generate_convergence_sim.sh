#!/bin/bash

rm -f stats_convergence_sim$1
for i in $(seq 2 100); do
# Hard coded number of items, may change later
	echo $i
	printf "%d players: %s\n" "$i" "$(./input_gen $i 1000 100 | ./convergence_sim 2> /dev/null)" >> stats_convergence_sim$1
done
