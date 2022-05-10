#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

/*12分，应该是没有考虑到一些特殊情况*/


/*大整数的存储可以考虑把低位放在数组之前，高位放在数组之后
可以用这样子的方式定义
typedef struct bigNum{
    //这里各个数位是逆向存储
    int num[1000];
    int length;
    bigNum(){
        memset(num, 0, sizeof(num));
        length = 0;
    }
}
*/


/*检测数字字符串是否是Palindromic数字*/
bool isPalindromic(char num[]);
/*数字num1+num2，并且用num1返回计算结果*/
void add(char num1[], char num2[]);
int main(void){
    char num[50], revNum[50];
    int k;
    int step = 0;
    scanf("%s %d", num, &k);
    /*如果不是Palindromic数字，则反转数字，并做加法*/
    while(!isPalindromic(num) && step < k){
        /*先把当前数字拷贝一份*/
        strcpy(revNum, num);
        /*反转该数字*/
        reverse(revNum, revNum + strlen(revNum));
        add(num, revNum);
        step++;
    }
    printf("%s\n%d\n", num, step);
    return 0;
}

/*检测数字字符串是否是Palindromic数字*/
bool isPalindromic(char num[]){
    int i = 0, j = strlen(num) - 1;
    while(i <= j){
        if(num[i] != num[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

/*数字num1+num2，并且用num1返回计算结果*/
void add(char num1[], char num2[]){
    char result[50];
    /**/
    int temp = 0;
    int i = strlen(num1) - 1, j = strlen(num2) - 1, k = 0;
    while(i >= 0 && j >= 0){
        result[k] = ((num1[i]-'0') + (num2[j] - '0') + temp)%10 + '0';
        temp = ((num1[i]-'0') + (num2[j] - '0'))/10;
        i--;
        j--;
        k++;
    }
    if(temp != 0){
        result[k] = temp + '0';
        k++;
    }
    result[k] = '\0';
    strcpy(num1, result);
}