#include<cstdio>
#include<string.h>

typedef struct card{
    char shape;
    int num;
}card;

void initialize(card cards[]);
void shuff(int start[], int end[], int order[]);

int main(void){
    card cards[54];
    card cards_end[54];//用于记录直接把牌插入所在位置
    int count;
    int order[54];
    int start[54], end[54];//start 数组用于记录当前扑克牌在牌堆里的位置编号，end数组用于记录洗了一次牌之后，理应获取的牌的顺序
    int sign;
    initialize(cards);
    scanf("%d", &count);
    for(int i = 0; i < 54; i++){
        scanf("%d", order + i);
        order[i] = order[i] - 1;
        start[i] = i;
    }
    for(int i = 0; i < count; i++){
        shuff(start, end, order);
    }
    /*洗好牌之后直接把牌插入他的最终位置即可*/
    for(int i = 0; i < 54; i++){
        sign = start[i];
        cards_end[i].shape = cards[sign].shape;
        cards_end[i].num = cards[sign].num;
    }
    for(int i = 0; i < 53; i++){
        printf("%c%d ", cards_end[i].shape, cards_end[i].num);
    }
    printf("%c%d\n", cards_end[53].shape, cards_end[53].num);
    return 0;
}

void initialize(card cards[]){
    for(int i = 0; i < 54; i++){
        if(i/13 == 0){
            cards[i].num = i%13 + 1;
            cards[i].shape = 'S';
        }else if(i/13 == 1){
            cards[i].num = i%13 + 1;
            cards[i].shape = 'H';
        }else if(i/13 == 2){
            cards[i].num = i%13 + 1;
            cards[i].shape = 'C';
        }else if(i/13 == 3){
            cards[i].num = i%13 + 1;
            cards[i].shape = 'D';
        }
        else{
            cards[i].num = i%13 + 1;
            cards[i].shape = 'J';
        }
    }
}

void shuff(int start[], int end[], int order[]){
    for(int i = 0; i < 54; i++){
        end[order[i]] = start[i];
    }
    for(int i = 0; i < 54; i++){
        start[i] = end[i];
    }//把end数组复制给start数组
}