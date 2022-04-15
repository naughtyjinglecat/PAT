#include<cstdio>
#include<string.h>

/*出错了。。不晓得错哪里了。。。。*/

int main(void){
    /*如果是坏键则记为true，好键记为false*/
    bool brokenButton[128];
    /*记录坏掉的按键字符串*/
    char broken[50];
    char temp = '\0';
    memset(brokenButton, 0, sizeof(brokenButton));
    scanf("%s", broken);
    getchar();
    for(int i = 0; i < strlen(broken); i++){
        if(broken[i] == '+'){
            for(int j = 'A'; j < 'Z'; j++){
                brokenButton[j] = true;
            }
        }
        else if(broken[i] >= 'A' && broken[i] <= 'Z'){
            brokenButton['a' + broken[i] - 'A'] = true;
            brokenButton[broken[i]] = true;
        }
        else{
            brokenButton[broken[i]] = true;
        }
    }
    do{
        temp = getchar();
        if(!brokenButton[temp]){
            printf("%c", temp);
        }
        // else if(temp >= 'A' && temp <= 'Z'&& !brokenButton['a' + temp - 'A']){
        //     printf("%c", 'a' + temp - 'A');
        // }
    }while(temp != '\n');
    return 0;
}