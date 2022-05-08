#include<cstdio>
/*总之就是思路要清晰就很好做，分而治之，这样才好完成各部分函数功能，20分满分*/



typedef struct rationalNum{
    bool sign;
    int integer;
    int numerator;
    int denumerator;
    rationalNum(){
        sign = true;
        integer = 0;
        numerator = 0;
        denumerator = 1;
    }
}rationalNum;


/*将有理数化为最简形式,同事使用符号位记录正负*/
void rationalize(rationalNum &num);

/*将两个有理数相加*/
rationalNum rationAdd(rationalNum a, rationalNum b);

/*将分数转化为假分数*/
void transfrom(rationalNum &a);

int main(void){
    int n;
    rationalNum temp;
    rationalNum ans;
    int sign = false;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        /*每次循环刷新temp各项数值*/
        temp.sign = true;
        temp.integer = 0;
        scanf("%d/%d", &temp.numerator, &temp.denumerator);
        rationalize(temp);
        ans = rationAdd(temp, ans);

    }
    if(ans.integer == 0 && ans.numerator == 0){
        printf("0");
    }
    else{
        if(ans.sign == false){
            printf("-");
        }
        if(ans.integer != 0){
            printf("%d", ans.integer);
            sign = true;

        }
        if(ans.numerator != 0){
            if(sign == true){
                printf(" ");
            }
            printf("%d/%d", ans.numerator, ans.denumerator);
        }
    }
    printf("\n");
    return 0;
}



/*将有理数化为最简形式,同事使用符号位记录正负*/
void rationalize(rationalNum &num){
    if(num.numerator < 0){
        num.sign = false;
        num.numerator *= -1;
    }
    for(int i = 2; i <= num.denumerator; i++){
        if(num.numerator%i == 0 && num.denumerator%i == 0){
            num.numerator /= i;
            num.denumerator /= i;
            /*下次继续检测该数字，因为该因数可能不止出现了一次*/
            i--;
        }
    }
    num.integer += num.numerator/num.denumerator;
    num.numerator %= num.denumerator;
}
/*将两个有理数相加*/
rationalNum rationAdd(rationalNum a, rationalNum b){
    rationalNum ans;
    /*先转化为假分数*/
    transfrom(a);
    transfrom(b);
    /*通分*/
    a.numerator *= b.denumerator;
    b.numerator *= a.denumerator;
    ans.denumerator = a.denumerator*b.denumerator;
    /*相加*/
    ans.numerator = a.numerator + b.numerator;
    /*化简*/
    rationalize(ans);
    return ans;
}
/*将分数转化为假分数*/
void transfrom(rationalNum &a){
    a.numerator += a.integer*a.denumerator;
    a.integer = 0;
    if(a.sign == false){
        a.numerator *= -1;
        a.sign = true;
    }
}
