#include <cstdlib>
#include <ctime>
#include <iostream>


int main() {
    srand((unsigned int) time(NULL));

    std::cout << "Hello, World!" << std::endl;

    std::cout << rand() << std::endl;

    return 0;
}
