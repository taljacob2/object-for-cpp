#ifndef MERGESORTER_H
#define MERGESORTER_H

#include "Sorter.h"

template<typename E> class MergeSorter : public Sorter<E> {

  private:
    void copyArray(E *destinationArray, size_t destinationArraySize,
                   E *sourceArray, size_t sourceArraySize) {
        for (int i = 0; i < destinationArraySize && i < sourceArraySize; ++i) {
            destinationArray[i] = sourceArray[i];
        }
    }

  private:
    void merge(E *firstArray, size_t firstArraySize, E *secondArray,
               size_t secondArraySize) {
        E *           resultArray  = new E[firstArraySize + secondArraySize];
        unsigned long firstReader  = 0;
        unsigned long secondReader = 0;

        while (firstReader + secondReader < firstArraySize + secondArraySize) {
            if (firstArray[firstReader] < secondArray[secondReader]) {
                resultArray[firstReader + secondReader] =
                        firstArray[firstReader];
                firstReader++;
            } else if (firstArray[firstReader] > secondArray[secondReader]) {
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
    }

  private:
    // TODO: check odd size and even size.
    void mergeSort(E *array, size_t size) {
        E *           firstArray     = array;
        unsigned long firstArraySize = size / 2;

        E *           secondArray = array + size / 2;
        unsigned long secondSize  = size / 2;

        merge()
    }

  public:
    void sort(E *array) override { mergeSort(array); }
};

#endif //MERGESORTER_H
