#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Array/BaseArray.h"

int getRandomNumberBetweenRange(int lowestValuePossible,
                                int highestValuePossible) {
    return lowestValuePossible +
           rand() % (highestValuePossible - lowestValuePossible + 1);
}

int main() {
    srand((unsigned int) time(NULL));

    std::cout << "Hello, World!" << std::endl;

    auto array = new BaseArray<int>(getRandomNumberBetweenRange(200, 300));

    for (int i = 0; i < array->size(); ++i) {
        array->setElement((int &&) i, i);
    }

    array->print(std::cout, *array);

    return 0;
}
