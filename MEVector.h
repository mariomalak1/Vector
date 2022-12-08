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
    void insert(T *p,T); // Insert item at iterator
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
template<class T>
MEVector<T>::MEVector(int cap) {
    this->Size = 0;
    this->Capacity = cap;
    this->arr = new T[cap];
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
void MEVector<T>::clear() {
    this->Capacity = 10;
    this->Size = 0;
    delete[] this->arr;
}

template<class T>
T *MEVector<T>::begin() {
    return arr;
}
template<class T>
T *MEVector<T>::end() {
    return (arr+Size-1);
}

// function to put an element in the back of the vector
template<class T>
int MEVector<T>::push_back(T element) {
    Size++;
    if (Size >= Capacity){
        cout << this->resize() << endl;
    }
    *((this->arr) + Size -1) = element;
    return Size - 1;
}

template<class T>
T MEVector<T>::pop_back() {
    Size--;
    return Size - 1;

}
template<class T>
void MEVector<T>::insert(T *p,T element) {
    Size++;
    for(int i = Size-1;i>*p;--i){
            arr[i]=arr[i-1];
        }
    arr[*p]=element;
    }

template<class T>
void MEVector<T>::erase(T *p) {
    if (p > (arr - 1) and p < (arr + Size)){
        T *newArr = new T[Capacity];
        for (int i = 0; i < Size; ++i) {
            if (p != (arr + i)){
                newArr[i] = arr[i];
            }
        }
        delete[] arr;
        arr = newArr;
        newArr = nullptr;

    }else{
        throw invalid_argument("invalid iterator");
    }
}

template<class T>
void MEVector<T>:: erase(T *p1,T *p2){
//    if (p1<&Size and p2<&Size ) {
//        throw invalid_argument("invalid iterator");
//    }
     if(p1<p2){
            T *newArr = new T[Capacity];

            for (int i = 0; i < Size; ++i) {
                if (p1 != (arr + i)){
                    newArr[i] = arr[i];
                }
                p1++;
            }
            delete[] arr;
            arr = newArr;
            newArr = nullptr;

        }
    }

template<class T>
T &MEVector<T>::operator[](int index) {
    if (index >= 0 and index < size()){
        return arr[index];
    }else{
        throw invalid_argument("out of range");
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
int MEVector<T>::capacity() const {
    return Capacity;
}











#endif //MEVECTOR_MEVECTOR_H
