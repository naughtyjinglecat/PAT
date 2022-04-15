// 1imits.cpp -- some integer 1imits
#include <iostream>
#include <climits>                  // use limits.h for older systems


int main (){
    using namespace std;
    int n_int = INT_MAX;// initialize n int to max int va1ue
    short n_short = SHRT_MAX; // s沪ηb01s defined in c1 i mits fi1e
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    // sizeof operator yields size of type 。古。f variab1e
    cout << "int is " <<sizeof(int) << " bytes."<<endl;
    cout << "short is " <<sizeof n_short << " bytes."<<endl;
    cout << "long is " <<sizeof n_long << " bytes."<<endl;
    cout << "long long is " <<sizeof n_llong << " bytes."<<endl;
    cout << endl;

    cout << "最大值:" << endl;
    cout << "int:" << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl << endl;

    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;

    return 0;

}