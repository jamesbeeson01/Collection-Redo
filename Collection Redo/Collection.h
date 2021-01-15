#ifndef COLLECTION_H
#define COLLECTION_H

#include <ostream>

class Collection {
private:
    double* array_;
    int index_;
    int capacity_;

public:
    Collection() : array_(new double[100]), capacity_(100), index_(0) {}
    Collection(int capacity) : array_(new double[capacity]), capacity_(capacity), index_(0) {}

    // getters
    int getSize() const { return index_; }
    int getCapacity() const { return capacity_; }
    double get(int ndx) const;
    double getFront() const;
    double getEnd() const;

    // setters
    void add(double value);
    void addFront(double value);

    // other functions
    int find(double needle) const;
    friend std::ostream& operator<<(std::ostream& out, const Collection& c);

};

#endif // !COLLECTION_H