#include <iostream>
#include "MEVector.h"
using namespace std;
int main() {
    MEVector<int> mario(20);
    for (int i = 0; i < 20; ++i) {
        mario[i] = i;
    }
    cout << mario[5] << endl;
    return 0;
}
