#include<cstdio>
#include<string.h>


int main(){
    int digit[40];
    unsigned int he, d;
    int yushu = 0, shang = 0;
    int i = 0, j = 0, k;
    bool is_Palindromic = true;
    memset(digit, -1, sizeof(digit));
    scanf("%d %d", &he, &d);
    do{
        shang = he/d;
        yushu = he%d;
        digit[i] = yushu;
        i++;
        he = shang;
    }while(he != 0);
    i--;
    /*注意不要越界*/
    if(digit[i] == 0 && i > 0){
        i--;
    }
    k = i;
    while(j <= i){
        if(digit[i] != digit[j]){
            is_Palindromic = false;
            break;
        }
        i--;
        j++;
    }
    if(is_Palindromic == true){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    for(i = k; i > 0; i--){
        printf("%d ", digit[i]);
    }
    printf("%d\n", digit[i]);
    return 0;
}