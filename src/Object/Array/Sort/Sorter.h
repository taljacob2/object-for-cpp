#ifndef SORTER_H
#define SORTER_H

template<typename E> class Sorter {

  private:
    E *_array;

  private:
    size_t _size;

  public:
    Sorter(E *array, size_t size) {
        _array = array;
        _size  = size;
    };

  public:
    virtual ~Sorter() = default;

  public:
    /**
     * Sorts an array.
     */
    virtual void sort() = 0;
};

#endif //SORTER_H
