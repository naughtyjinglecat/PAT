#include<cstdio>
/* 也不知道哪里出错了，得分 16，感觉思路应该是没问题，可能是几个and or 判断把自己绕进去了*/
int main(void){
    int i =0, j = 0;
    char week[7][4] = {"MUN", "TES", "WED", "THU", "FRI", "SAT","SUN"};
    int week_out, hour_out, min_out;
    char code[4][65];
    for(i = 0; i < 4; i++){
    scanf("%s", code[i]);
    }
    i = 0;
    while(code[0][i] != code[1][j] || !(code[0][i] >= 'A' && code[0][i] <= 'G')){
        i++;
        j++;
    }
    week_out = code[0][i] - 'A';
    i += 1;
    j += 1;
    while(code[0][i] != code[1][j] || !(code[0][i] >= 'A' && code[0][i] <= 'N' || code[0][i] >= '0' && code[0][i] <= '9')){
        i++;
        j++;
    }
    if(code[0][i] >= '0' && code[0][i] <= '9'){
        hour_out = code[0][i] - '0';
    }
    else{
        hour_out = code[0][i] - 'A' + 10;
    }
    for(i = 0; i < 65; i++){
        if(code[2][i] == code[3][i] && ((code[2][i] >= 'a' && code[2][i] <= 'z') ||(code[2][i] >= 'A' && code[2][i] <= 'Z'))){
            break;
        }
    }
    min_out = i;
    printf("%s %02d:%02d\n", week[week_out], hour_out, min_out);
    return 0;
}