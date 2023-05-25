#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main(){
// переменная для того чтобы можно было посчитать функцию
int key_stop=0;
//ВЫЧИСЛЕНИЕ ЗНАЧЕНИЙ ФУНКЦИИ синус икс от икс
while (key_stop!=1){ 
    double x;
    cout<<"Напишите значение x, которое вы хотите увидеть для f(x): ";
    cin>>x;
    if (x==0){
        cout<<"Ошибка"<<endl;
        }
    else cout<<"f(x) = "<<sin(x)/x<<endl;
    cout<<"Для того чтобы продолжить необходимо нажать 1 "<<endl;
    cout<<"Для остановки программы нажмите 0"<<endl;
    cin>>key_stop;
}
//Числа фибоначи
int maximum;
cout<<"Напишите максимальное число, для S (Числа Фибоначи):";
cin>>maximum;
int a=0, b=1, s=0,n=1;
//Простой генератор чисел Фибоначчи
while (s+b<=maximum){ 
    s+=b;
    int c=b;
    b=b+a;
    a=c;
    n+=1;
}
s+=b; n+=1;
//n+1 потому-что необходимо сделать само число больше максимального по условию задачи.
cout<<s<<" "<<n;
}
