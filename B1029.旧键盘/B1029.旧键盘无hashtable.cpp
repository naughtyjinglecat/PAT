#include<cstdio>
#include<string.h>
/*直接一把过掉了*/
/*将字符串中的小写字母全部转化为大写字母*/
void upper(char str[]){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 'a' + 'A';
        }
    }
}
/*若是在str字符串中包含字符a，则返回true，否则返回false*/
bool find(char str[], char a){
    bool ans = false;
    for(int i = 0; i < strlen(str); i++){
        if(a == str[i]){
            ans = true;
            break;
        }
    }
    return ans;
}

int main(){
    char totalstr[81], partialstr[81];
    /*未输出的字符全部置为false，已经输出的字符全部置位true*/
    bool hashtable[256];
    memset(hashtable, 0, sizeof(hashtable));
    scanf("%s", totalstr);
    scanf("%s", partialstr);
    upper(totalstr);
    upper(partialstr);
    for(int i = 0; i < strlen(totalstr); i++){
        /*如果他不在输入的部分串里*/
        if(!find(partialstr, totalstr[i])){
            /*并且他从未被输出，则将他打印出来*/
            if(hashtable[totalstr[i]] == false){
                printf("%c", totalstr[i]);
                hashtable[totalstr[i]] = true;
            }
        }
    }
    printf("\n");
    return 0;
}