#ifndef MERGESORTER_H
#define MERGESORTER_H

#include "Sorter.h"

template<typename E> class MergeSorter : public Sorter<E> {

  public:
    void sort(E *array) override {}

};

#endif //MERGESORTER_H
