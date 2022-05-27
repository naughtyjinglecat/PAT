#include<iostream>
#include<string>
using namespace std;


/*将数字num转化为n位有效数字的科学计数法的本体部分, 用n1返回其指数数值*/
string transform(string num, int n, int &n1);


int main(void){
    int n;
    string num1, num2;
    /*记录n1， n2点号的位置*/
    int n1 = 0, n2 = 0;
    cin >> n;
    cin >> num1;
    cin >> num2;
    num1 = transform(num1, n, n1);
    num2 = transform(num2, n, n2);
    if(num1 == num2){
        cout << "YES " << num1 << "*" << "10^" << n << endl;
    }
    else{
        cout << "NO " << num1 << "*" << "10^" << n << " " + num2 << "*" << "10^" << n << endl;
    }
}