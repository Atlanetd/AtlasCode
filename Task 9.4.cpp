#include <bits/stdc++.h>
using namespace std;
int main(){
string word[20];
int n;
cin>>n;
//Ввод слов данных.
for(int i=0;i<n;i++){
    cin>>word[i];
}
//Вывод слов с четными номерами.
for (int i=0;i<n;i+=2)
    cout<<word[i]<<" ";
}