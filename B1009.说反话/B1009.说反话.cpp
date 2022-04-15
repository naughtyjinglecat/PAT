#include<cstdio>
#include<string.h>


int main(void){
    int sign[50];
    char str[90];
    int i = 0, j = 0, m = 0;
    scanf("%[^\n]", str);
    memset(sign, -1, sizeof(sign));
    if(str[0] != '\0'){
        sign[0] = 0;
        j++;
    }
    while (str[i] != '\0')
    {
        if(str[i] == ' '){
            sign[j] = i + 1;
            j++;
        }
        i++;
    }
    for(int k = j - 1; k >= 0; k--){
        m = sign[k];
        while(str[m] != ' ' && str[m] != '\0'){
            printf("%c", str[m]);
            m++;
        }
        if(k != 0){
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
    
    return 0;
}