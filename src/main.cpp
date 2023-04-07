#include <iostream>

#include "Object/Array/BaseArray.h"
#include "Object/Random/Random.h"

int main() {

    std::cout << "Hello, World!" << std::endl;

    auto array = new BaseArray<int>(4);

    for (int i = 0; i < array->size(); ++i) {
        array->setElement((int &&) rand() % 20, i);
    }

    array->sort();

    array->print(std::cout, *array);


    delete array;

    return 0;
}
