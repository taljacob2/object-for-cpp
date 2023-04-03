#ifndef MERGESORTER_H
#define MERGESORTER_H

#include "Sorter.h"

template<typename E> class MergeSorter : public Sorter<E> {

  private:
    void merge(E *array, size_t size) {}

  private:
    void mergeSort(E *array, size_t size) {}

  public:
    void sort(E *array) override { mergeSort(array); }
};

#endif //MERGESORTER_H
