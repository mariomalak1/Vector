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

// template class to make vector data structure
template <class T>
class MEVector {
private:
    unsigned long long int Size; // member that holds the number of elements in the vector
    unsigned long long int Capacity; // member that holds the number of all places in the vector (in dynamic memory)
    T *arr; // pointer of the same type of the vector
public:
    /// @brief Basic constructor that initialize the obj with size 0 and capacity of 10 and take no parameter
    // No content is added, size = 0
    // Assign a default size value
    MEVector();

    /// @brief a constructor that takes a given capacity value to initialize with and the size will be 0
    /// @param cap initial value to the capacity of the vector
    MEVector (int); // Initialize by specific capacity

    /// @brief a constructor that initialize the vector with n elements from an array and the size will be = n
    /// @param arr array to take the elements from
    /// @param n the number of elements to take from the array
    MEVector (T*, int n ); // Initialize by n items from array


    /// @brief copy constructor the initialize the vector from another vector and copy the data it contains to the vector
    /// @param other the other vector to copy from
    MEVector (const MEVector&); // Initialize with a copy

    /// @brief move constructor that moves data from one vector to this vector
    /// @param other the vector to move from
    MEVector(const MEVector&& other);

    /// @brief destructor to free memory
    ~MEVector(); // Delete allocated memory

    /// @brief overloading copy assignment (=) operator so we can assign an object from another object copy
    /// @param other the other vector to assign from
    /// @return object from the same type (vector)
    MEVector &operator=(const MEVector& other); // Copy assignment


    /// @brief overloading move assignment (=) operator so we can assign an object from another then make it empty
    /// @param other other the other vector to assign from
    /// @return object from the same type (vector)
    MEVector &operator=(const MEVector&& other); // Move assignment

    /// @brief overloading the [] operator so we can access specific element in the vector
    /// @param i the index we want to access
    /// @return the element that refers to that index
    // Access operations
    T& operator[](int i); // Access item by reference
    // Throw an exception if out of range

    /// @brief a function to add element to the vector from the back
    /// @param val the value we want to add
    /// @return size of the vector after add the val
    // Modifying operations
    int push_back(T val); // Add item to end of vec & return # of items, increase capacity if needed


    /// @brief a function to remove element from the back of the vector
    /// @return return the deleted element
    T pop_back(); // Remove and return last element in vec

    /// @brief a function to remove one element by its index
    /// @param itr the index of the element we want to remove
    void erase(T* itr); // Remove item at iterator

    /// @brief a function to remove element from index to other index
    /// @param itr1 the first index
    /// @param itr2 the second index
    // Throw exception if invalid iter
    // iterator 1 <= iterator 2 otherwise do nothing
    // Throw exception if any iterator outside range
    void erase(T *itr1, T *itr2);// Remove items between


    /// @brief a function to clear the vector and make it empty
    void clear(); // Delete all vector content

    /// @brief a function that takes an index and a value to add that value in that index
    /// @param itr the index we want
    /// @param val the value we want to add
    // Throw exception if invalid
    void insert(T *itr, T val); // Insert item at iterator

    // Iterators // Supports *, + and ++ operations at least
    // Can use: typedef T* iterator
    // Or u can use std::iterator, so you can
    // apply STL algorithms on MEVector

    /// @brief a method that return an pointer to the begin of the vector
    /// @return pointer to the first value of the vector
    T* begin(); // Return an iterator (T*)

    /// @brief  a method that return an pointer to the end of the vector
    /// @return pointer to the last value of the vector
    T* end(); // Return an iterator (T*)

    // Comparison operations

    /// @brief overloading == operator to compare two vectors
    /// @param vec the other vector to compare with
    /// @return true or false, if they are equal return true else return false
    // Return true if they are equal
    bool operator==(const MEVector<T>&vec);

    /// @brief overloading < operator to compare two vectors
    /// @param vec the other vector to compare with
    /// @return true or false
    // Return true if first different item in this is < in other
    bool operator< (const MEVector<T>&vec); // Compares item by item

    // Capacity operations

    /// @brief a function to know the size of the vector
    /// @return the size of the vector
    int size() const; // Return current size of vec

    /// @brief a function to know the capacity of the vector
    /// @return the capacity of the vector
    int capacity() const; // Return size of current allocated array

    /// @brief a function to resize the vector with specific capacity we want
    /// @return capacity of the new vector
    int resize(); // Relocate to bigger space

    /// @brief a boolean function to know if the vector is empty or not
    /// @return true if empty false if not
    bool empty(); // Return true if size is 0

    // Friends
    /// @brief overloading << operator so we can print all  data in the vector
    /// @param out ostream variable to carry the data that will be printed
    /// @param vec the vector we want to print its data
    /// @return ostream object that carry the data
    friend ostream& operator << (ostream &out,  MEVector<T>vec){
        cout << "[";
        for (int i = 0; i < vec.Size - 1; ++i) {
            cout << vec[i] << ", ";
        }
        cout << vec[vec.Size - 1] << "]" << endl;
        return out;
    }
};

//default constructor to assign vector by default values
template<class T>
MEVector<T>::MEVector() {
    Size = 0;
    Capacity = 10;
    arr = new T[Capacity];
}

// constructor that takes specific integer, and it's the capacity of this vector
template<class T>
MEVector<T>::MEVector(int size) {
    this->Size = size;
    this->Capacity = size;
    this->arr = new T[size];

    for(int i = 0; i < Size; i++){
        arr[i] = 0;
    }
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

// move constructor
template<class T>
MEVector<T>::MEVector(const MEVector &&other) {
    if (this != &other){
        Size = other.Size;
        Capacity = other.Capacity;
        delete[] arr;
        arr = new T[Capacity];
        for (int i = 0; i < Size; i++){
            arr[i] = other.arr[i];
        }
    }
    delete[] other.arr;
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
    delete[] arr;

    arr = new T[Capacity];
    for (int i = 0; i < Size; ++i) {
        arr[i] = vec.arr[i];
    }

    return *this;
}

// move assignment operator that change the ownership of the "rhs" object to "lhs" object by assignment operator
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

// destructor that make memory free
template<class T>
MEVector<T>::~MEVector<T>(){
    delete[] arr;
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


// function to check that the first vector are smaller than second vector
template<class T>
bool MEVector<T>::operator< (const MEVector<T> &another){
    for(int i = 0; i < Size; i++){
        if(arr[i] > another.arr[i]){
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


// function to return iterator of beginning of vector
template<class T>
T* MEVector<T>::begin() {
    return arr;
}

// function to return iterator of end of vector
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

// function to delete  element from the end of the vector
template<class T>
T MEVector<T>::pop_back() {
    erase(end());
}
// function to insert element in the specific position of the vector

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
// function to delete element in the specific position of the vector

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

// function to delete elements from the specific position to another specific position in the vector
template<class T>
void MEVector<T>:: erase(T *p1,T *p2) {
    int count = 0;
    if (p1 > (arr - 1) and p1 < (arr + Size)){
        T *newArr = new T[Capacity];

        int j = 0;

        while (&arr[j] != p1){
            count++;
            newArr[j] = arr[j];
            j++;
        }

        while (&arr[++j] != p2);
        ++j;

        for (int i = j; i < Size; ++i) {
            newArr[count] = arr[i];
            count++;
        }
        delete[] arr;

        arr = newArr;

        newArr = nullptr;
        Size = count;
    }else{
        throw invalid_argument("invalid iterator");
    }
}

// function to check that vector is empty or not
template<class T>
bool MEVector<T>::empty() {
    if (Size==0){
        return true;
    } else{
        return false;
    }
}


// operator overloading of "[]" to return index from the vector
template<class T>
T &MEVector<T>::operator[](int index) {
    if (index >= 0 and index < Size){
        return arr[index];
    }else{
        throw invalid_argument("out of range");
    }
}


// function that return capacity(size that vector can store) of the vector
template<class T>
int MEVector<T>::capacity() const {
    return Capacity;
}

#endif //MEVECTOR_MEVECTOR_H