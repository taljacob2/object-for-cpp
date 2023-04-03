#include "Random.h"

void initRand() { srand((unsigned int) time(NULL)); }

int getRandomNumberBetweenRange(int lowestValuePossible,
                                int highestValuePossible) {
    return lowestValuePossible +
           rand() % (highestValuePossible - lowestValuePossible + 1);
}

// -----------------------------------------------------------------------------

/*
 * See more here: https://www.geeksforgeeks.org/functions-that-are-executed-before-and-after-main-in-c/
 * See `Initialize.h`.
 */

INITIALIZER(runBeforeMain_Random) {

    /*
     * Apply the constructor attribute to runBeforeMain_Random() so that it is
     * executed before main()
     */
    initRand();
}
