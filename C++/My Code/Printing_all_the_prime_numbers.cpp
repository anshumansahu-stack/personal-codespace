#include<iostream>
using namespace std;

int main() {
    for (int i = 2, n = 1; i < 10000 && n < 10000; i++) {
        if (i % n == 0 && i > n) {
            n++;
        } else {
            cout << i << endl;
        }
    }

    return 0;
}