/* 完美运行 */
#include<cstdio>
#include<string.h>


/*把十进制的a转化为m进制的数, 用数组b返回结果*/
void transform(int m, int a, char b[]);

int main(void){
    int a, b, c;
    char RGB[6];
    memset(RGB, '0', sizeof(RGB));
    scanf("%d %d %d",&a, &b, &c);
    transform(13, a, RGB);
    transform(13, b, RGB + 2);
    transform(13, c, RGB + 4);
    printf("#");
    for(int i = 0; i < 6; i++){
        printf("%c", RGB[i]);
    }
    printf("\n");
    return 0;
}

void transform(int m, int a, char b[]){
    int yushu;
    char sign[13];
    sign[0] = '0';
    for(int i = 1; i <= 9; i++){
        sign[i] = sign[i-1] + 1;
    }
    sign[10] = 'A';
    for(int i = 11; i < 13; i++){
        sign[i] = sign[i-1] + 1;
    }
    yushu = a % m;
    b[1] = sign[yushu];
    a = a/m;
    yushu = a%m;
    b[0] = sign[yushu];
}