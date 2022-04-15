#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

void down(char str[], int length){
    for(int i = 0; i < length; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

int main(){
    char strIn[1005];
    /* 记录每个字符出现的次数 */
    int hashtable[128];
    char mostFrequency = 'a';
    int mostOccurence = 0;
    fill(hashtable, hashtable + 128, 0);
    scanf("%[^\n]", strIn);
    down(strIn, strlen(strIn));
    for(int i = 0; i < strlen(strIn); i++){
        hashtable[strIn[i]]++;
    }
    mostOccurence = hashtable['a'];
    for(char i = 'b'; i <= 'z'; i++){
        if(hashtable[i] > mostOccurence){
            mostOccurence = hashtable[i];
            mostFrequency = i;
        }
    }
    printf("%c %d\n", mostFrequency, mostOccurence);
    return 0;
}