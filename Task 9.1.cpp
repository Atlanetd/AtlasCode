#include <bits/stdc++.h>
using namespace std;

int main(){
// 1
char test[] = "Тест";
// 2
char more_text[] = "Успешно выполнено!";
// 3
char bad_test[] = "Ошибка!"; 
char good_test[] = "Успешно!";
char short_test[] = "Строка слишком короткая!";

// Первая функция
cout<<"Длина строки: "<<strlen(test)<<endl<<endl; 
// Вторая функция
strcat(test, more_text); 
cout<<test<<endl<<endl;
//Третья функция
cout<<"Если первая и вторая строки не совпадают:"<<strcmp(test,bad_test)<<endl;
cout<<"Если первая и вторая строки совпадают:"<<strcmp(test,good_test)<<endl;
cout<<"Если первая если короче второй строки:"<<strcmp(test,short_test)<<endl<<endl;

return 0;
}