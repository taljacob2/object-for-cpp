#ifndef MERGESORTER_H
#define MERGESORTER_H

#include "Sorter.h"

template<typename E> class MergeSorter : public Sorter<E> {

  private:
    void swap(E &first, E &second) {
        E temp = first;
        first  = second;
        second = temp;
    }

  private:
    void merge(E *firstArray, size_t firstArraySize, E *secondArray,
               size_t secondArraySize) {

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
