#include<cstdio>

int main(void){
    int num = 0;
    char latter = '\0';
    scanf("%d %c", &num, &latter);
    for(int i = 0; i <num; i++){
        printf("%c", latter);
    }
    printf("\n");
    for(int i = 1; i < (num + 1)/2 - 1; i++){
        printf("%c", latter);
        for(int j = 1; j < num - 1; j++){
            printf(" ");
        }
        printf("%c\n", latter);
    }
    for(int i = 0; i <num; i++){
        printf("%c", latter);
    }
    printf("\n");
    return 0;
}