/*思路应该没什么大问题，但是不知道哪里错了总之就是非常离谱，21分*/


#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

/*查找当前字符串*/
bool compare(char *a, char *b){
    bool ans = false;
    int lengthA = strlen(a), lengthB = strlen(b);
    char *num1 = new char[lengthA + 1], *num2 = new char[lengthB + 1];
    for(int i = 0; i <= lengthA; i++){
        num1[i] = a[i];
    }
    for(int i = 0; i <= lengthB; i++){
        num2[i] = b[i];
    }
    num1 = strcat(num1, b);
    num2 = strcat(num2, a);
    if(strcmp(num1, num2) < 0){
        ans = true;
    }

    return ans;
}

int main(void){
    int i, j;
    int n;
    /*输出标志，若没有输出，则要输出0*/
    bool sign = false;
    char** num = NULL;
    /*记录第一个被打印的数字节*/
    int firstNum = -1;
    scanf("%d", &n);
    num = new char*[n];
    for(i = 0; i < n; i++){
        num[i] = new char[6];
        scanf("%s", num[i]);
    }
    sort(num, num + n, compare);
    for(i = 0; i < n; i++){
        for(j = 0; j < strlen(num[i]); j++){
            if(num[i][j] != '0'){
                printf("%s", num[i] + j);
                sign = true;
                break;
            }
        }
    }
    for(i += 1; i < n; i++){
        printf("%s", num[i]);
    }
    if(sign == false){
        printf("0");
    }
    printf("\n");
    return 0;
}