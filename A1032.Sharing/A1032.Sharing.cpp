#include<cstdio>
#include<algorithm>
using namespace std;

//出现了一些小问题，矫正之后25分

/*
1.先计算两个单词的长度之差d，假定单词1比较长，如果单词1比单词2短，
则交换单词1和单词2的地址，使得较长单词定义为单词1，较短单词定义
为单词2
2.访问较长的单词第 d+1 个节点，使得较长单词从d+1个节点开始和较
短单词的长度相等，依次对比剩余字母，若当前字母的地址相同，则说明
从这个字母之后两个单词的字符串相同，直接输出该字母的地址即可，若
到最后也没有遇到地址相同的字母，则输出-1*/

typedef struct node{
    char letter;
    int next;
}node;

//计算单词长度
int wordLength(node nodes[], int word_Start);
//计算第单词第n个字母的地址
int wordnthLetter(node nodes[],int word_Start, int n);

int main(void){
    node nodes[100005];
    int temp_Address;
    int word1, word2, n;
    int length1 = 0, length2 = 0;
    int p1, p2;//连个指针分别访问两个单词字母
    int share = -1;
    scanf("%d %d %d", &word1, &word2, &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp_Address);
        scanf(" %c %d", &nodes[temp_Address].letter, &nodes[temp_Address].next);
    }
    length1 = wordLength(nodes, word1);
    length2 = wordLength(nodes, word2);
    if(length1 < length2){
        swap(length1, length2);
        swap(word1, word2);
    }
    p1 = wordnthLetter(nodes, word1, length1 - length2 + 1);
    p2 = word2;
    while(p1 != -1 && p2 != -1){
        if(p1 == p2){
            share = p1;
            break;
        }
        p1 = nodes[p1].next;
        p2 = nodes[p2].next;
    }
    if(share == -1){
        printf("-1\n");
    }
    else{
        printf("%05d\n", share);
    }
    return 0;
}

//计算单词长度
int wordLength(node nodes[], int word_Start){
    int ans = 0;
    int p =word_Start;
    while(p != -1){
        ans++;
        p = nodes[p].next;
    }
    return ans;
}
//计算第单词第n个字母的地址
int wordnthLetter(node nodes[],int word_Start, int n){
    int ans = -1;
    int p  = word_Start;
    int count = 0;
    int pre = -1;
    while(p != -1){
        count++;
        pre = p;
        p = nodes[p].next;
        if(count == n){
            ans = pre;
            break;
        }
    }
    return ans;
}