#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<iostream>
using namespace std;
/*debug之下得满分。。。。*/

/*翻转字符串,返回d字符串的长度*/
int reverse(char a[]);

int main(void){
    char* sentence[100];
    int n;
    scanf("%d", &n);
    getchar();
    int i, j = 0;
    /*打断标志*/
    bool inter_Sign = false;
    int min_length = 300,cur_length;
    for(i = 0; i < n; i++){
        sentence[i] = (char*)malloc(sizeof(char)*260);
        memset(sentence[i], 0, sizeof(char)*260);
        // gets(sentence);
        scanf("%[^\n]", sentence[i]);
        getchar();
        // printf("%s\n",sentence[i]);
        cur_length = reverse(sentence[i]);
        min_length = (min_length < cur_length) ? min_length : cur_length;
    }
    while(j < min_length){
        for(i = 0; i < n - 1; i++){
            if(sentence[i][j] == sentence[i+1][j]){
                continue;
            }
            inter_Sign = true;
            break;
        }
        if(inter_Sign == true){
            break;
        }
        j++;
    }

    /*这里想的太多，无论最后一次是循环条件不满足而终止还是break终止，j都会+1，需要把这个1减掉*/
    j--;
    if(j < 0){
        printf("nai\n");
    }
    else{
        for(; j >= 0; j--){
            printf("%c", sentence[0][j]);
        }
        printf("\n");
    }

    return 0;
}

int reverse(char a[]){
    int i = 0, j;
    char temp;
    int length = strlen(a);
    j = length - 1;
    while (i < j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
    return length;
}