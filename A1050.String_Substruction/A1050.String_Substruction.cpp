/*
用%[^\n]接收字符串的时候要注意，末尾会有一个回车符没有被接受，如果连续使用，这个回车符不会消失会一直在缓冲区，需要用getchar()去接收回车符
*/
#include<cstdio>
#include<string.h>
int main(){
    /*false代表不清理的字符，true代表要清理的字符*/
    bool deletedCharacter[128];
    char strToBeClear[10005], strAimToDelete[10005];
    memset(deletedCharacter, 0, sizeof(deletedCharacter));
    scanf("%[^\n]", strToBeClear);
    getchar();
    scanf("%[^\n]", strAimToDelete);
    for(int i = 0; i < strlen(strAimToDelete); i++){
        deletedCharacter[strAimToDelete[i]] = true;
    }
    for(int i = 0; i < strlen(strToBeClear); i++){
        if(!deletedCharacter[strToBeClear[i]]){
            printf("%c", strToBeClear[i]);
        }
    }
    printf("\n");
    return 0;
}