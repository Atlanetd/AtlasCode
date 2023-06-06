#include <iostream>
using namespace std;

int P[3] = { 1,2,3 };
int R[3];

void per(int);

int main() {
    for (int i = 0;i < 3;i++) {
        R[i] = 0;
    }
    per(0);
    return(0);
}

void per(int k) {
    for (int i = 1;i <= 3;i++) {
        if (R[i - 1] == 0) {
            P[k] = i;
            R[i - 1] = 1;
            if (k == 2) {
                for (int j = 0;j < 3;j++) {
                    cout << P[j];
                }
                cout << " ";
            }
            else per(k + 1);
            R[i - 1] = 0;
        }
    }
}
