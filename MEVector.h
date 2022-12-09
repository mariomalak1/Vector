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

    MEVector (T*, int n ); // Initialize by n items from array
    MEVector (const MEVector&); // Initialize with a copy
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

// constructor that takes specific integer, and it's the capacity of this vector
template<class T>
MEVector<T>::MEVector(int size) {
    this->Size = size;
    this->Capacity = size;
    this->arr = new T[size];
}

// constructor that initialized with array and it's size
template<class T>
MEVector<T>::MEVector(T* arrPtr, int n) {
    Capacity = n;
    Size = n;
    arr = new T[Size];

    for (int i = 0; i < Size; ++i) {
        arr[i] = arrPtr[i];
    }
}

// copy constructor
template<class T>
MEVector<T>::MEVector(const MEVector & vec) {
    this->Size = vec.Size;
    this->Capacity = vec.Capacity;
    this->arr = nullptr;

    if (vec.arr != nullptr){
        arr = new T[Size];
        for (int i = 0; i < Size; ++i) {
            arr[i] = vec.arr[i];
        }
    }
}


// assignment operator
template<class T>
MEVector<T> &MEVector<T>::operator=(const MEVector &vec) {
    Size = vec.Size;
    Capacity = vec.Capacity;
    T *newPtr = vec.arr;
    this->arr = newPtr;

    return *this;
}

// move assignment operator that change the ownership of the "rhs" object to lhs object by assignment operator
template<class T>
MEVector<T> &MEVector<T>::operator=(const MEVector<T> && vec) {
    if (this != &vec){
        Capacity = vec.Capacity;
        Size = vec.Size;

        delete arr;
        arr = vec.arr;
        vec.arr = nullptr;
    }
}

// function to make the vector take more capacity that it allocated
template<class T>
int MEVector<T>::resize() {
    T *newArr = new T[Capacity * 2];

    for (int i = 0; i < Size; ++i) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    newArr = nullptr;

    return (Capacity * 2);
}

// destructor that make memory free
template<class T>
MEVector<T>::~MEVector<T>(){
    delete[] arr;
}

// bitwise operator<< to print vector
template<class T>
ostream &operator<<(ostream &out, MEVector<T> vec) {
    cout << "[";
    for (int i = 0; i < vec.Size - 1; ++i) {
        cout << vec[i] << ", ";
    }
    cout << vec[vec.Size - 1] << "]" << endl;
    return out;
}

// function that return vector size
template<class T>
int MEVector<T>::size() const {
    return this->Size;
}

// function to check that the two vectors are equal
template<class T>
bool MEVector<T>::operator==(const MEVector<T> & vec) {
    if (vec.Size == this->Size) {
        for (int i = 0; i < vec.Size; ++i) {
            if (vec[i] != *((this->arr) + i)){
                return false;
            }
        }
        return true;
    }
    return false;
}

template<class T>
bool MEVector<T>::operator< (const MEVector<T>&another){
    for(int i =0; i<Size;i++){
        if(arr[i]>another.arr[i]){
            return false;
        } else{
            continue;
        }
    }
    return true;
}

// function to clear all elements in the vector
template<class T>
void MEVector<T>::clear() {
    this->Capacity = 10;
    this->Size = 0;
    delete[] this->arr;
    arr = nullptr;
}

template<class T>
T* MEVector<T>::begin() {
    return arr;
}

template<class T>
T *MEVector<T>::end() {
    return (arr + Size - 1);
}

// function to put an element in the back of the vector
template<class T>
int MEVector<T>::push_back(T element) {
    Size++;
    if (Size >= Capacity){
        this->resize();
    }
    *((this->arr) + Size -1) = element;
    return Size - 1;
}

template<class T>
T MEVector<T>::pop_back() {
    erase(end());
}

template<class T>
void MEVector<T>::insert(T *p,T element) {
    // to check that the iterator send is in the range of this vector
    if (p >= (arr) and (p < (arr + Size) )){
        // size will increase by one
        Size++;
        // check that capacity is enough
        if(Size >= Capacity){
            Capacity = Size * 2;
        }

        // make new array that holds all old elements in the old array
        T *newArr = new T[Capacity];

        int i = 0;
        // loop in the old array till the location of the iterator, when it reaches to it, it will add its value and break this loop
        for (; i < Size; ++i) {
            if (p == (arr + i)){
                newArr[i] = element;
                break;
            }
            else{
                newArr[i] = arr[i];
            }
        }
        i++;
        // new loop that add the elements in the old array after we insert our value
        for (; i < Size; ++i) {
            newArr[i] = arr[i - 1];
        }

        // to free memory, and avoid memory leaking
        delete[] arr;
        arr = newArr;
        newArr = nullptr;
    }
    else{
        throw invalid_argument("invalid iterator");
    }
}

template<class T>
void MEVector<T>::erase(T *p) {
    if (p > (arr - 1) and p < (arr + Size)){
        for (int i = 0; i < Size; ++i) {
            if (p <= (arr + i) and (i < Size - 1)){
                arr[i] = arr[i+1];
            }
        }
        Size--;
    }else{
        throw invalid_argument("invalid iterator");
    }
}

template<class T>
void MEVector<T>:: erase(T *p1,T *p2) {
    if (p1 > (arr - 1) and p1 < (arr + Size)){
        T *newArr = new T[Capacity-1];
        int count = 0;
        for (int i = 0; i < *p1; ++i) {
            newArr[i] = arr[i];
            count++;
        }
        for (int i = *p2+1; i < Size; ++i) {
            newArr[i-1] = arr[i];
            count++;
        }
        delete[] arr;
        arr = newArr;
        Size=count;
        newArr = nullptr;

    }else{
        throw invalid_argument("invalid iterator");
    }
}

template<class T>
bool MEVector<T>::empty() {
    if (Size==0){
        return true;
    } else{
        return false;
    }
}

template<class T>
T &MEVector<T>::operator[](int index) {
    if (index >= 0 and index < Size){
        return arr[index];
    }else{
        throw invalid_argument("out of range");
    }
}

template<class T>
int MEVector<T>::capacity() const {
    return Capacity;
}



#endif //MEVECTOR_MEVECTOR_H