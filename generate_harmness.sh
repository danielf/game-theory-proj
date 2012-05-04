#!/bin/bash

rm -f stats_harmness
for i in $(seq 2 100); do
# Hard coded number of items, may change later
	echo $i
	printf "%d players: %s\n" "$i" "$(./input_gen $i 1000 100 | ./harmness)" >> stats_harmness
done
