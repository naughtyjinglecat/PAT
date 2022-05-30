#include<iostream>
#include<string>
using namespace std;

/*不知道错在哪里，23分*/

/*将数字num转为保留n位有效数字的科学计数法*/
string transform(string num, int n);
int main(){
    int n;
    string num1, num2;
    cin >> n >> num1 >> num2;
    num1 = transform(num1, n);
    num2 = transform(num2, n);
    if(num1 == num2){
        cout << "YES " << num1 << endl;
    }
    else{
        cout << "NO " << num1 + " " << num2 << endl;
    }
    return 0;
}

void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}
/*将数字转化为字符串*/
string intTostr(int num){
    int temp = num;
    string ans;
    while(num != 0){
        temp = num%10;
        ans.push_back('0' + temp);
        num /= 10;
    }
    if(ans.size() == 0){
        ans.push_back('0');
    }
    for(int i = 0; i < ans.size()/2; i++){
        swap(ans[i], ans[ans.size() - 1 - i]);
    }
    return ans;
}

/*将数字num转为保留n位有效数字的科学计数法*/
string transform(string num, int n){
    int temp = 0;
    int i = 0, j =0, k = 0;
    int exponent = 0;//记录指数数值
    string ans = "0.";
    //查找第一个有效位的下标,用i指向他
    for(i = 0; i < num.size(); i++){
        if(num[i] >= '1' && num[i] <= '9'){
            break;
        }
    }
    if(i == num.size()){
        //若是查找不到第一个非零有效数字，则说明这个数字就是0,第一个有效数位记录为-1
        i = -1;
    }
    //查找小数点所在位置的下标，用j指向他
    for(j = 0; j < num.size(); j++){
        if(num[j] == '.'){
            break;
        }
    }
    //确定指数数值
    exponent = j - i;
    if(i == -1){
        exponent = 0;
    }
    if(exponent < 0){
        exponent++;
    }
    //记录存入结果中的有效数字的数量
    int count = 0;
    while(count < n){
        //若是访问num没有越界
        if(i + k < num.size()){
            //这一位是有效数字
            if(num[i + k] >= '0' && num[i + k] <= '9'){
                ans.push_back(num[i + k]);
                count++;
            }
            k++;
        }
        //若是越界了则有效位补0
        else{
            ans.push_back('0');
            count++;
        }
    }
    ans += "*10^";
    ans += intTostr(exponent);
    return ans;
}