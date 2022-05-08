#include<cstdio>
#include<algorithm>
using namespace std;
/*要关注进入循环的条件，关注离开循环的条件，查看了答案的注意点才拿到25分*/

/*将数字字符串转化为纯数字，返回该数字字符数组代表的纯数字*/
int transformToInt(char digit[]){
    return (digit[0]-'0')*1000 + (digit[1]-'0')*100 + (digit[2]-'0')*10 + (digit[3]-'0');
}
/*将纯数字转化为字符串数组*/
void tranformToStr(char digit[], int num){
    digit[4] = '\0';
    digit[3] = '0' + num%10;
    num /= 10;
    digit[2] = '0' + num%10;
    num /= 10;
    digit[1] = '0' + num%10;
    num /= 10;
    digit[0] = '0' + num%10;
}

bool compare(char a, char b){
    return a > b;
}

int main(void){
    int temp = 0;
    char digit[5];
    /*记录该数字位排序之后对应的数字*/
    int num1, num2;
    scanf("%d", &temp);
    tranformToStr(digit, temp);
    if(digit[0] == digit[1] && digit[1] == digit[2] && digit[2] == digit[3]){
        printf("%s - %s = 0000\n", digit, digit);
    }
    else{
        do{
            sort(digit, digit + 4);
            num2 = transformToInt(digit);
            sort(digit, digit + 4, compare);
            num1 = transformToInt(digit);
            temp = num1 - num2;
            tranformToStr(digit, temp);
            printf("%04d - %04d = %04d\n", num1, num2, temp);
        }while(temp != 6174);
    }
    return 0;
}