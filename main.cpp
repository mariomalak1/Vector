#include "MEVector.h"
#include <iostream>
using namespace std;


// function to show the effect of the assignment operator
void vec(MEVector<int>vector1){
    MEVector<int>cc;
    cc = vector1;
}

// function to return vector to see copy constructor work well
MEVector<int>reFun(){
    MEVector<int>vect1(5);
    return vect1;
}

MEVector<int>reFun2(){
    return MEVector<int>(11);
}

int main() {
    MEVector<int> vector1(20);

    for (int i = 0; i < 20; ++i) {
        vector1[i] = i;
    }

    vector1[5] = 18;
    cout << vector1 << endl;

    vector1.insert(vector1.begin(), 55);
    cout << vector1 << endl;

    vector1.insert(vector1.begin() + 5, 15);
    cout << vector1 << endl;

    vector1.insert(vector1.begin() + 18, 488);
    cout << vector1 << endl;

    vector1.insert(vector1.begin() + 0, 129);
    cout << vector1 << endl;

    cout << vector1.size() << endl;
    cout << vector1.capacity() << endl;

    vector1.erase(vector1.begin() + 3);
    cout << vector1 << endl;

    vector1.erase(vector1.begin() + 1, vector1.begin() + 5);
    cout << vector1 << endl;



    vec(vector1);
    MEVector<int>vector2(181);

    for (int i = 0; i < 181; ++i) {
        vector2[i] = i;
    }

    cout << vector2.size() << endl;
    cout << vector2 << endl;
    vector2 = vector1;
    cout << vector2 << endl;
    cout << vector1 << endl;
    cout << vector2.size() << endl;
    cout << vector1.size() << endl;
    MEVector<int>vect = reFun();
    cout << vect.size() << endl;
    cout << vect << endl;

    MEVector<int>kk = reFun2();
    cout << kk << endl;


    return 0;
}
