#ifndef MERGESORTER_H
#define MERGESORTER_H

#include "Sorter.h"

template<typename E> class MergeSorter : public Sorter<E> {

  public:
    MergeSorter(E *array, size_t size) : Sorter<E>(array, size) {}

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
                      size_t secondArraySize) {
        E *    resultArray  = new E[firstArraySize + secondArraySize];
        size_t firstReader  = 0;
        size_t secondReader = 0;

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

        delete[] resultArray;
    }

  private:
    static void mergeSort(E *array, size_t size) {
        if (size == 1) { return; }

        if (size == 2) {

            // Sort.
            if (array[0] > array[1]) { swap(array[0], array[1]); }
        }

        E *    firstArray     = array;
        size_t firstArraySize = size / 2;

        E *    secondArray = array + firstArraySize;
        size_t secondSize  = size - firstArraySize;

        mergeSort(firstArray, firstArraySize);
        mergeSort(secondArray, secondSize);

        merge(firstArray, firstArraySize, secondArray, secondSize);
    }

  public:
    void sort() override { mergeSort(this->_array, this->_size); }
};

#endif //MERGESORTER_H
