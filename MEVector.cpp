#include "MEVector.h"

/* some instructions:
        any object in function param named vec
        the minimum capacity = 10
*/

// constructor that takes specific integer, and it's the capacity of this vector
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
T &MEVector<T>::operator[](int index) {
    if (index >= 0 and index < Size){
        return (arr + index);
    }else{
        throw invalid_argument("out of range");
    }
}






