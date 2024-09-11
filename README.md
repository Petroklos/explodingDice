# Exploding Dice

This C program simulates the "Exploding Dice" mechanic from Kids with Bikes, where rolling the highest value on a die allows an additional roll.  
You can run the program by pasting the code from [explodingDice.c](explodingDice.c) into any online compiler.

## How It Works

The program rolls various dice (`d4`, `d6`, `d8`, `d10`, `d12`, `d20`) multiple times, tracking total rolls, explosions (re-rolls), and calculating average improvements over the standard die average.

## Key Concept: Average Improvement

The average improvement from explosions approximates \( \frac{1}{\text{dieSize} - 1} \), since rolling the highest value on a die (an explosion) adds another average roll.

## Results

The following are the results of a single run. There is some variation from run to run, but not much.

```
Rolling d4s:
	Total Roll = 231405
	Exploded 23164 times
	Roll Average = 3.3
	Die Average = 2.5
	Average Improvement = 0.8 (33%)

Rolling d6s:
	Total Roll = 291153
	Exploded 13845 times
	Roll Average = 4.2
	Die Average = 3.5
	Average Improvement = 0.7 (19%)

Rolling d8s:
	Total Roll = 358407
	Exploded 10047 times
	Roll Average = 5.2
	Die Average = 4.5
	Average Improvement = 0.7 (14%)

Rolling d10s:
	Total Roll = 423923
	Exploded 7761 times
	Roll Average = 6.1
	Die Average = 5.5
	Average Improvement = 0.6 (11%)

Rolling d12s:
	Total Roll = 492272
	Exploded 6282 times
	Roll Average = 7.1
	Die Average = 6.5
	Average Improvement = 0.6 (9%)

Rolling d20s:
	Total Roll = 767534
	Exploded 3593 times
	Roll Average = 11.1
	Die Average = 10.5
	Average Improvement = 0.6 (5%)
```
Explosions impact on the average rolls values is roughly equal to $`\frac{1}{dieSize-1}`$
