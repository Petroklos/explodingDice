#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold the result of a die roll.
struct results {
    int roll;
    int explosions;
};

// Function to calculate the average value of a die given its size
float calculateAverage(int dieSize) {
    float sum = 0;
    
    for (int i = 1; i <= dieSize; i++) {
        sum += i;
    }
    
    return sum / dieSize;
}

// Function to roll a die and reroll if it explodes (rolls max)
struct results rollDice(int dieSize) {
    int roll = rand() % dieSize + 1;
    int explosions = 0;
    
    if (roll == dieSize) {
        struct results reRoll = rollDice(dieSize);
        roll += reRoll.roll;
        explosions += reRoll.explosions + 1;
    }
    
    struct results result = { .roll = roll, .explosions = explosions };
    
    return result;
}

// Function to roll a die multiple times and calculate statistics
void handleDie(int dieSize) {
    int totalRoll = 0;
    int explosions = 0;
    int loops = 69420;
    
    for (int j = 0; j < loops; j++) {
        struct results result = rollDice(dieSize);
        totalRoll += result.roll;
        explosions += result.explosions;
    }
    
    float averageRoll = (float)totalRoll / loops;
    float dieAverage = calculateAverage(dieSize);
    float numericalIncrease = averageRoll - dieAverage;
    int percentileIncrease = (int)(((averageRoll / dieAverage) - 1) * 100);
    
    printf("Rolling d%ds:\n", dieSize);
    printf("\tTotal Roll = %d\n", totalRoll);
    printf("\tExploded %d times\n", explosions);
    printf("\tRoll Average = %.1f\n", averageRoll);
    printf("\tDie Average = %.1f\n", dieAverage);
    printf("\tAverage Improvement = %.1f (%d%%)\n", numericalIncrease, percentileIncrease);
    printf("\n");
}

int main() {
    srand(time(NULL));
    
    int dicePool[6] = {4, 6, 8, 10, 12, 20};
    int length = sizeof(dicePool) / sizeof(dicePool[0]);
    
    // Loop through and handle each die in the pool
    for (int i = 0; i < length; i++) {
        handleDie(dicePool[i]);
    }
    
    return 0;
}
