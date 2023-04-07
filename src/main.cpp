#include <iostream>

#include "Object/Array/BaseArray.h"
#include "Object/Initialize/Random/Random.h"

int main() {

    auto array = new BaseArray<int>(getRandomNumberBetweenRange(200, 300));

    for (int i = 0; i < array->size(); ++i) {
        array->setElement((int &&) i, i);
    }

    array->sort();

    array->print(std::cout, *array);


    delete array;

    return 0;
}
