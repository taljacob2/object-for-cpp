#ifndef SORTER_H
#define SORTER_H

template<typename E> class Sorter {

  public:
    Sorter() = default;

  public:
    virtual ~Sorter() = default;

  public:
    /**
     * Sorts an array.
     */
    virtual void sort(E *array) = 0;
};

#endif //SORTER_H
