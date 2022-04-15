#include<cstdio>
#include<string.h>

void output(int hashtable[], char temp){
    if(hashtable[temp] > 0){
        printf("%c", temp);
        hashtable[temp]--;
    }
}

int main(void){
    int hashtable[128];
    char temp = '\0';
    int i = 0;
    memset(hashtable, 0, sizeof(hashtable));
    while(temp != '\n'){
        temp = getchar();
        hashtable[temp]++;
    }
    while(hashtable['P'] + hashtable['A'] + hashtable['T'] + hashtable['e'] + hashtable['s'] + hashtable['t'] > 0){
        output(hashtable, 'P');
        output(hashtable, 'A');
        output(hashtable, 'T');
        output(hashtable, 'e');
        output(hashtable, 's');
        output(hashtable, 't');
    }
    printf("\n");
    return 0;
}