#ifndef MERGESORTER_H
#define MERGESORTER_H

#include "Sorter.h"

template<typename E> class MergeSorter : public Sorter<E> {

  public:
    MergeSorter(E *array, size_t size, const std::function<bool(E, E)> &compare)
        : Sorter<E>(array, size, compare) {}

  public:
    MergeSorter() = delete;

  private:
    static void copyArray(E *destinationArray, size_t destinationArraySize,
                          E *sourceArray, size_t sourceArraySize) {
        for (int i = 0; i < destinationArraySize && i < sourceArraySize; ++i) {
            destinationArray[i] = sourceArray[i];
        }
    }

  private:
    static void swap(E &first, E &second) {
        E temp = first;
        first  = second;
        second = temp;
    }

  private:
    static void merge(E *firstArray, size_t firstArraySize, E *secondArray,
                      size_t                     secondArraySize,
                      std::function<bool(E, E)> &compare) {
        E *    resultArray  = new E[firstArraySize + secondArraySize];
        size_t firstReader  = 0;
        size_t secondReader = 0;

        while (firstReader + secondReader < firstArraySize + secondArraySize) {
            if (compare(firstArray[firstReader], secondArray[secondReader])) {
                resultArray[firstReader + secondReader] =
                        firstArray[firstReader];
                firstReader++;
            } else {
                resultArray[firstReader + secondReader] =
                        secondArray[secondReader];
                secondReader++;
            }
        }
        while (firstReader < firstArraySize) {
            resultArray[firstReader + secondReader] = firstArray[firstReader];
            firstReader++;
        }
        while (secondReader < secondArraySize) {
            resultArray[firstReader + secondReader] = secondArray[secondReader];
            secondReader++;
        }

        //  Copy `resultArray` to `firstArray`.
        copyArray(firstArray, firstArraySize + secondArraySize, resultArray,
                  firstArraySize + secondArraySize);

        delete[] resultArray;
    }

  private:
    static void mergeSort(E *array, size_t size,
                          std::function<bool(E, E)> &compare) {
        if (size == 1) { return; }

        if (size == 2) {

            // Sort.
            if (compare(array[1], array[0])) { swap(array[1], array[0]); }
        }

        E *    firstArray     = array;
        size_t firstArraySize = size / 2;

        E *    secondArray = array + firstArraySize;
        size_t secondSize  = size - firstArraySize;

        mergeSort(firstArray, firstArraySize, compare);
        mergeSort(secondArray, secondSize, compare);

        merge(firstArray, firstArraySize, secondArray, secondSize, compare);
    }

  public:
    void sort() { mergeSort(this->_array, this->_size, this->_compare); }
};

#endif //MERGESORTER_H
