#include <iostream>
using namespace std;
//Задача о ферзях
int S[21], Q[21], R[41], L[41];
int n, ch;
void Queen(int j) {
    for (int i = 1; i <= n; i++) {
        if (S[i] == 0 && R[(j + 19) - i] == 0 && L[j + i] == 0)
        {
            S[i] = 1; R[(j + 19) - i] = 1; L[j + i] = 1; Q[j] = i;
            if (j == n) {
                ch++;
                for (int k = 1; k <= n; k++) { cout << Q[k] << " "; }
                cout << endl;
            }
            else Queen(j + 1);
            S[i] = 0;
            R[(j + 19) - i] = 0;
            L[j + i] = 0;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    cout << " Введите количество ферзей, от 1 до 20\n";
    cin >> n;
    while (n > 20 || n < 1) { cout << " Введите количество ферзей, от 1 до 20\n"; cin >> n; }
    for (int i = 1; i <= n; i++) { S[i] = 0; }
    for (int i = (1 - n) + 19; i <= (n - 1) + 19; i++) { R[i] = 0; }
    for (int i = 2; i <= 2 * n; i++) { L[i] = 0; }
    ch = 0;
    Queen(1);
    cout << " Найдено " << ch << " возможных вариантов растановки ферзей" << endl;
    return 0;
}