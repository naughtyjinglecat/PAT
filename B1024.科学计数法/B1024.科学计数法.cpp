/*百密一疏。。。。*/


#include<cstdio>
#include<string.h>


int main(void){
    char num[10005];
    int xiaoshudian = 2;
    int jiefu;
    int jiema = 0;
    int k;
    memset(num, '\0', sizeof(num));
    scanf("%s", num);
    for(jiefu = xiaoshudian; jiefu < 10005; jiefu++){
        if(num[jiefu] == 'E'){
            jiefu++;
            break;
        }
    }
    for(int i = jiefu + 1; num[i] != '\0'; i++){
        jiema = jiema * 10 + (num[i] - '0');
    }
    if(num[0] == '-'){
        printf("-");
    }
    if(num[jiefu] == '-'){
        printf("0.");
        for(int i = xiaoshudian - jiema; i < 1; i++){
            printf("0");
        }
        for(int i = 1; num[i] != 'E'; i++){
            if(i != xiaoshudian){
                printf("%c", num[i]);
            }
        }
    }
    else{
        printf("%c", num[1]);
        for(int i = 3;i <= xiaoshudian + jiema; i++){
            if(i < jiefu - 1){
                printf("%c", num[i]);
            }
            else{
                printf("0");
            }
            k = i;
        }

        if( xiaoshudian + jiema < jiefu - 2){
            printf(".");
            for(k = k + 1; k < jiefu - 1; k++){
                printf("%c", num[k]);
            }
        }
    }
    printf("\n");
    return 0;
}