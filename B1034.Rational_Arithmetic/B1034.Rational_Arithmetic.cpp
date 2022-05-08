#include<stdio.h>

/*有理数的乘法，实现的太过复杂，尤其是化简函数设计的有很多问题，这接近两百行代码需要重写比较好一点，14分*/


typedef struct rationalNum{
    /*分子记为up，分母记为down,正负用sign标记，true为正数，反之为负数*/
    bool sign;
    int up;
    int down;
    rationalNum(){
        sign = true;
        up = 0;
        down = 1;
    }
}rationalNum;
/*输出有理数num，若num是负数，则用括号括起来*/
void output(rationalNum num);
/*打印加减乘除的结果*/
void print(rationalNum num1, rationalNum num2, rationalNum result, char opt);
/*定义加减乘除*/
rationalNum add(rationalNum a, rationalNum b);
rationalNum minus(rationalNum a, rationalNum b);
rationalNum multiple(rationalNum a, rationalNum b);
rationalNum divide(rationalNum a, rationalNum b);

/*化简有理分式num,返回结果用正负号用sign来标记*/
void simplify(rationalNum &num);

int main(void){
    rationalNum num1, num2;
    rationalNum AddResult, minResult, mulResult, divResult;
    scanf("%d/%d %d/%d", &num1.up, &num1.down, &num2.up, &num2.down);
    if(num1.up < 0){
        num1.sign = false;
        num1.up *= -1;
    }
    if(num2.up < 0){
        num2.sign = false;
        num2.up *= -1;
    }
    AddResult = add(num1, num2);
    minResult = minus(num1, num2);
    mulResult = multiple(num1, num2);
    divResult = divide(num1, num2);

    print(num1, num2, AddResult, '+');
    print(num1, num2, minResult, '-');
    print(num1, num2, mulResult, '*');
    print(num1, num2, divResult, '/');

    return 0;
}


/*输出有理数num，若num是负数，则用括号括起来*/
void output(rationalNum num){
    if(num.down == 0){
        printf("Inf");
        return;
    }
    simplify(num);
    if(num.up == 0){
        printf("0");
    }
    else if(num.sign == true){
        if(num.up >= num.down){
            printf("%d", num.up/num.down);
            if(num.up%num.down != 0){
                printf(" %d/%d", (num.up%num.down), num.down);
            }
        }
        else{
                printf("%d/%d", num.up, num.down);
        }
        
    }
    else{
        printf("(-");
        if(num.up >= num.down){
            printf("%d", num.up/num.down);
            if(num.up%num.down != 0){
                printf(" %d/%d", (num.up%num.down), num.down);
            }
        }
        else{
                printf("%d/%d", num.up, num.down);
        }
        printf(")");
    }
}

void print(rationalNum num1, rationalNum num2, rationalNum result, char opt){
    output(num1);
    printf(" %c ", opt);
    output(num2);
    printf(" = ");
    output(result);
    printf("\n");
}

rationalNum add(rationalNum a, rationalNum b){
    rationalNum ans;
    simplify(a);
    simplify(b);
    if(a.sign == false){
        a.up *= -1;
        a.sign = true;
    }
    if(b.sign == false){
        b.up *= -1;
        b.sign = true;
    }
    ans.down = a.down*b.down;
    ans.up = a.up*b.down+b.up*a.down;
    if(ans.up < 0){
        ans.sign = false;
        ans.up *= -1;
    }
    simplify(ans);
    return ans;
}

rationalNum minus(rationalNum a, rationalNum b){
    rationalNum ans;
    simplify(a);
    simplify(b);
    /*把符号还给数字参与运算*/
    if(a.sign == false){
        a.up *= -1;
        a.sign = true;
    }
    if(b.sign == false){
        b.up *= -1;
        b.sign = true;
    }
    ans.down = a.down*b.down;
    ans.up = a.up*b.down-b.up*a.down;
    if(ans.up < 0){
        ans.sign = false;
        ans.up *= -1;
    }
    simplify(ans);
    return ans;
}
rationalNum multiple(rationalNum a, rationalNum b){
    rationalNum ans;
    simplify(a);
    simplify(b);
    if(a.sign == false){
        a.up *= -1;
    }
    if(b.sign == false){
        b.up *= -1;
    }
    ans.up = a.up*b.up;
    ans.down = a.down*b.down;
    simplify(ans);
    return ans;
}

rationalNum divide(rationalNum a, rationalNum b){
    int temp;
    rationalNum ans;
    ans.sign = EOF;
    simplify(a);
    simplify(b);
    temp = b.up;
    b.up = b.down;
    b.down = temp;
    ans = multiple(a, b);
    return ans;
}

void simplify(rationalNum &num){
    int a = num.up, b = num.down, t;
    if(num.down == 0){
        return;
    }
    t  = a%b;
    if(num.up < 0){
        num.sign = !num.sign;
        num.up *= -1;
    }
    if(num.down < 0){
        num.sign = !num.sign;
        num.down *= -1;
    }
    a = num.up, b = num.down;
    do{
        t =  a % b;
        a = b;
        b = t;
    }while(t != 0);
    if(a != 0){
        num.up /= a;
        num.down /= a;
    }
}