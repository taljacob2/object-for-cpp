#include <cstdlib>
#include <ctime>
#include <iostream>

int getRandomNumberBetweenRange(int lowestValuePossible,
                                int highestValuePossible) {
    return lowestValuePossible +
           rand() % (highestValuePossible - lowestValuePossible + 1);
}

int main() {
    srand((unsigned int) time(NULL));

    std::cout << "Hello, World!" << std::endl;

    std::cout << getRandomNumberBetweenRange(200, 300) << std::endl;

    return 0;
}
