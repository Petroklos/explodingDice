// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct results {
    int roll;
    int explosions;
};

float calculateAverage (int dieSize) {
    float sum = 0;
    for (int i = 1; i <= dieSize; i++) {
        sum += i;
    }
    return sum/dieSize;
}

struct results rollDice (int dieSize) {
    int roll = rand() % dieSize + 1;
    int explosions = 0;
    
    if (roll == dieSize) {
        struct results reRoll = rollDice(dieSize);
        roll += reRoll.roll;
        explosions += reRoll.explosions + 1;
    }
    
    struct results result;
    result.roll = roll;
    result.explosions = explosions;
    
    return result;
}

void handleDie (int dieSize) {
    int totalRoll = 0;
    int explosions = 0;
    int loops = 69420;
    
    for (int j = 0; j < loops; j++) {
        struct results result = rollDice(dieSize);
        totalRoll += result.roll;
        explosions += result.explosions;
    }
    
    float averageRoll = (float)totalRoll/loops;
    float dieAverage = calculateAverage(dieSize);
    float numericalIncrease = averageRoll - dieAverage;
    int percentileIncrase = (int) (((averageRoll/dieAverage) -1) * 100);
    
    printf("Total Roll = %d\n", totalRoll);
    printf("Exploded %d times\n", explosions);
    printf("Roll Average = %.1f\n", averageRoll);
    printf("Die Average = %.1f\n", dieAverage);
    printf("Average Improvement = %.1f (%d%%)\n", numericalIncrease, percentileIncrase);
    printf("\n");
}

int main() {
    srand (time(NULL));
    
    int dicePool[6] = {4, 6, 8, 10, 12, 20};
    int length = sizeof(dicePool) / sizeof(dicePool[0]);
    
    for (int i = 0; i < length; i++) {
        handleDie(dicePool[i]);
    }
    
    return 0;
}