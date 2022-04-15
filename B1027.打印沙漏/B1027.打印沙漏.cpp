#include<cstdio>
#include<math.h>

int main(void){
    int num_input;
    int n = 1;
    int sn = 1;
    char syn;
    int sign = 1;
    int shengyu;
    scanf("%d %c", &num_input, &syn);
    while(sn <= num_input){
        shengyu = num_input - sn;
        n = n + 2;
        sn += 2*n ;
    }
    n = n - 2;
    for(int i = 0; i < n; i++){
        if(i < n/2){
            for(int j = 0; j < i; j++){
                printf(" ");
            }
            for(int j = 0; j < n - 2*i; j++){
                printf("%c", syn);
            }
            printf("\n");
        }
        else{
            for(int j = 0; j < (n - sign)/2; j++){
                printf(" ");
            }
            for(int j = 0; j < sign; j++){
                printf("%c", syn);
            }
            printf("\n");
            sign += 2;
        }
    }
    printf("%d\n", shengyu);
    return 0;
}