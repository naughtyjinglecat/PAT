#include<cstdio>
#include<string.h>

/*读一个一位数*/
void r_Odigit(char num[]);
/*读一个两位数*/
void r_Tdigit(char num[]);
/*读一个三位数*/
void r_Thdigit(char num[]);
/*读一个四位数*/
void r_Fdigit(char num[]);
/*读一个5-8位数*/
void r_Wdigit(char num[]);
/*读一个九位数*/
void r_Jdigit(char num[]);
/*读一个不超过九位的数*/
void read(char num[]);


int main(void){
    char num[11];
    scanf("%s", num);
    read(num);
    printf("\n");
    return 0;
}

void r_Odigit(char num[]){
    char digit[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    printf("%s", digit[num[0] - '0']);
}
void r_Tdigit(char num[]){
    char digit[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    printf("%s Shi", digit[num[0] - '0']);
    if(num[1] != '0'){
        printf(" ");
        r_Odigit(num + 1);
    }
}
void r_Thdigit(char num[]){
    char digit[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    printf("%s Bai", digit[num[0] - '0']);
    if(num[1] != '0'){
        printf(" ");
        r_Tdigit(num + 1);
    }
    else if(num[2] != '0'){
        printf(" ling ");
        r_Odigit(num + 2);
    }
}
void r_Fdigit(char num[]){
    char digit[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    printf(" %s Qian", digit[num[0] - '0']);
    if(num[1] != '0'){
        printf(" ");
        r_Thdigit(num + 1);
    }
    else if(num[2] != '0'){
        printf(" ling ");
        r_Tdigit(num + 2);
    }
    else if(num[3] != '0'){
        printf(" ling ");
        r_Odigit(num + 3);
    }
}
void r_Wdigit(char num[]){
    int n = strlen(num);
    int i = n - 4;
    switch(i){
    case 4:
        r_Fdigit(num);
        break;
    case 3:
        r_Thdigit(num);
        break;
    case 2:
        r_Tdigit(num);
        break;
    case 1:
        r_Odigit(num);
        break;
    default:
        break;
    }
    printf(" Wan");
    if(num[n - 4] != '0'){
        r_Fdigit(num + n - 4);
    }
    else if(num[n - 3] != '0'){
        printf(" ling ");
        r_Thdigit(num + n - 3);
    }
    else if(num[n - 2] != '0'){
        printf(" ling ");
        r_Tdigit(num + n - 2);
    }
    else if(num[n - 1] != '0'){
        printf(" ling ");
        r_Odigit(num + n - 1);
    }
}

void r_Jdigit(char num[]){
    int i = 0;
    char digit[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    printf("%s Yi", digit[num[0] - '0']);
    /*剩余数字是一个八位数*/
    if(num[1] != '0'){
        r_Wdigit(num + 1);
    }
    else{

        num += 2;
        for(i = 0; i < 7; i++){
            if(num[0] != '0'){
                break;
            }
            num++;
        }
        if(i != 7){
            printf(" ling ");
        }
        if(i <= 2){
            r_Wdigit(num);
        }
        else if( i == 3){
            r_Fdigit(num);
        }
        else if(i == 4){
            r_Thdigit(num);        
        }
        else if(i == 5){
            r_Tdigit(num);
        }
        else if(i == 6){
            r_Odigit(num);
        }
    }
}





void read(char num[]){
    int n = strlen(num);
    if(num[0] == '-'){
        printf("Fu ");
        n--;
        num++;
    }
    switch(n)
    {
    case 1:
        r_Odigit(num);
        break;
    case 2:
        r_Tdigit(num);
        break;
    case 3:
        r_Thdigit(num);
        break;
    case 4:
        r_Fdigit(num);
        break;
    case 9:
        r_Jdigit(num);
        break;
    default:
    r_Wdigit(num);
        break;
    }
    
}