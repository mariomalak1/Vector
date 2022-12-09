#include <iostream>
#include "MEVector.h"
#include <vector>
using namespace std;

void ass(MEVector<int>mario){
    MEVector<int>cc;
    cc = mario;
}

void fun(MEVector<int>mario){
    cout << "[";
    for (int i = 0; i < mario.size() - 1; ++i) {
        cout << mario[i] << ", ";
    }
    cout << mario[mario.size() - 1] << "]" << endl;
}

MEVector<int>reFun(){
    MEVector<int>malak(5);
    return malak;
}

MEVector<int>reFun2(){
    return MEVector<int>(11);
}

int main() {
    MEVector<int> mario(20);

    for (int i = 0; i < 20; ++i) {
        mario[i] = i;
    }

    mario[5] = 18;


    mario.insert(mario.begin(), 55);
//    cout << mario << endl;

    mario.insert(mario.begin() + 5, 15);
//    cout << mario << endl;

    mario.insert(mario.begin() + 18, 488);
//    cout << mario << endl;

    mario.insert(mario.begin() + 0, 129);
//    cout << mario << endl;

    cout << mario.size() << endl;
    cout << mario.capacity() << endl;

    mario.erase(mario.begin() + 3);
//    cout << mario << endl;


//    fun(mario);
    ass(mario);
    MEVector<int>llll(181);
    for (int i = 0; i < 181; ++i) {
        llll[i] = i;
    }
    cout << llll.size() << endl;
    fun(llll);
    llll = mario;
    fun(llll);
    fun(mario);
    cout << llll.size() << endl;
    cout << mario.size() << endl;
    MEVector<int>ma = reFun();
    cout << ma.size() << endl;
    fun(ma);

    MEVector<int>kk = reFun2();
    fun(kk);


    return 0;
}
