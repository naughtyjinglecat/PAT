#include <iostream>
#include <vector>
#include <string>




using namespace std;

bool checkPerfectNumber(int num);
int main()
{
    
    int a;
    a = checkPerfectNumber(28);
    cout <<a << "木大木大木大木大" <<endl;
    return 0;
}

bool checkPerfectNumber(int num){
    int i = 0;
    int sum=0;//因数求和
    for(i=1;i<num;i++){
        if(num%i==0){
            sum=sum+i;
        }
        
    }
    return sum;
}