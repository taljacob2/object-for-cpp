#ifndef SORTER_H
#define SORTER_H

#include <functional>

template<typename E> class Sorter {

  protected:
    E *_array;

  protected:
    size_t _size;

  protected:
    std::function<bool(E, E)> _compare;

  public:
    Sorter(E *array, size_t size, const std::function<bool(E, E)> &compare) {
        _array    = array;
        _size     = size;
        _compare = compare;
    };

  public:
    Sorter() = delete;

  public:
    virtual ~Sorter() = default;

  public:
    /**
     * Sorts an array.
     */
    virtual void sort() = 0;
};

#endif //SORTER_H
