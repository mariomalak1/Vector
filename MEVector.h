///////////////////////////////////////////////////////
// OOP Assignment 3 - Dr.El ramly
// team member 1 : Mario Malak Alabd - ID : 20210313
// team member 2 : Ehab Ashraf Malaka - ID : ....
// version 1
// description of this task:
// this class Mario Ehab Vector ME Vector
// that as STL vector in its creation and functionality
///////////////////////////////////////////////////////

#ifndef MEVECTOR_MEVECTOR_H
#define MEVECTOR_MEVECTOR_H
#include <iostream>
using namespace std;

template <class T>
class MEVector {
private:
    unsigned long long int Size; // member that holds the number of elements in the vector
    unsigned long long int Capacity; // member that holds the number of all places in the vector (in dynamic memory)
    T *arr; // pointer of the same type of the vector
public:
    // Constructors and Big 4
    MEVector (int); // Initialize by specific capacity

    // No content is added, size = 0
    // Assign a default size value

//    MEVector (T*, int n ); // Initialize by n items from array
//    MEVector (const MEVector&); // Initialize with a copy
    ~MEVector(); // Delete allocated memory
    MEVector &operator=(const MEVector&); // Copy assignment
    MEVector &operator=(const MEVector&&); // Move assignment

    // Access operations
    T& operator[](int); // Access item by reference
    // Throw an exception if out of range

    // Modifying operations
    int push_back(T); // Add item to end of vec & return # of items
    // Increase capacity of needed
    T pop_back(); // Remove and return last element in vec
    void erase(T* p); // Remove item at iterator

    // Throw exception if invalid iter
    void erase(T *p1, T *p2);// Remove items between

    // iterator 1 <= iterator 2 otherwise do nothing
    // Throw exception if any iterator outside range
    void clear(); // Delete all vector content
    void insert(T *p, T); // Insert item at iterator
    // Throw exception if invalid

    // Iterators // Supports *, + and ++ operations at least
    // Can use: typedef T* iterator
    // Or u can use std::iterator, so you can
    // apply STL algorithms on MEVector
    T* begin(); // Return an iterator (T*)
    T* end(); // Return an iterator (T*)

    // Comparison operations
    bool operator==(const MEVector<T>&); // Return true if ==
    bool operator< (const MEVector<T>&); // Compares item by item

    // Return true if first different item in this is < in other
    // Capacity operations
    int size() const; // Return current size of vec
    int capacity() const; // Return size of current allocated array
    int resize(); // Relocate to bigger space
    bool empty(); // Return true if size is 0

    // Friends
    friend ostream& operator << (ostream& out, MEVector<T>vec);
};




#endif //MEVECTOR_MEVECTOR_H
