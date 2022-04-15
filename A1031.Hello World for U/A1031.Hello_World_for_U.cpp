/*有一些我也说不清楚的小问题， 得分18分，大思路肯定是对的*/
#include<cstdio>
#include<stdlib.h>
#include<string.h>


int main(void){
    int n1 = 0;
    int n2 = 1;
    int N = 0;
    char *p[30];
    char str[81];
    int i = 0, j = 0;
    scanf("%s", str);
    N = strlen(str);
    while(n1*2 + n2 - 2 <= N){
        n1++;
        n2++;
    }
    n1--;
    n2--;
    if(N- (n1*2 + n2 - 2) == 2){
        n2 += 2;
    }
    else if(N- (n1*2 + n2 - 2) == 1){
        n2++;
    }
    for(i = 0; i < n1; i++){
        p[i] = (char*)malloc(sizeof(char)*n2);
        memset(p[i], ' ', sizeof(char)*n2);
    }
    for(i = 0; i < n1; i++){
        p[i][0] = str[j];
        j++;
    }
    i--;
    for(int k = 1; k < n2; k++){
        p[i][k] = str[j];
        j++;
    }
    for(i = i - 1; i >= 0; i--){
        p[i][n2 - 1] = str[j];
        j++;
    }
    for(i = 0; i < n1; i++){
        for(j = 0; j < n2; j++){
            printf("%c", p[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < n1; i++){
        free(p[i]);
    }


    return 0;
}
