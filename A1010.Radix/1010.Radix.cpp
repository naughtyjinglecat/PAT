/*需要订正*/

#include<cstdio>

int digit_num(char dig);

int main(void){
    int i = 0;
    char a[12], b[12];
    char *p_a = a, *p_b = b;
    int length_a = 0, length_b = 0;
    int tag = 0;
    int radix = 0;
    int dec_a = 0, dec_b = 0;
    char* temp = NULL;
    int dig_temp = 0;
    int dig_xishu = 1;
    scanf("%s %s %d %d", a, b, &tag, &radix);
    if(tag == 2){
        temp = p_a;
        p_a = p_b;
        p_b = temp;
    }
    while(a[i] != '\0'){
        length_a++;
        i++;
    }
    i = 0;
    while(b[i] != '\0'){
        length_b++;
        i++;
    }
    for(i = length_a - 1; i >= 0; i--){
        dig_temp = digit_num(a[i]);
        dec_a += dig_temp * dig_xishu;
        dig_xishu = dig_xishu * radix;
    }
    dig_xishu = 1;
    radix = 1;
    do{
        dec_b = 0;
        for(i = length_b - 1; i >= 0; i--){
            dig_temp = digit_num(b[i]);
            if(dig_temp > radix){
                break;
            }
            dec_b += dig_temp * dig_xishu;
            dig_xishu = dig_xishu * radix;
        }
        dig_xishu = 1;
        radix++;
    }while(dec_a > dec_b);
    if(dec_a == dec_b){
        printf("%d\n", radix - 1);
    }
    else{
        printf("Impossible\n");
    }
}

int digit_num(char dig){
    int ans = -10000;
    if(dig >= '0' && dig <= '9'){
        ans = dig - '0';
    }else if(dig >= 'a' && dig <= 'z'){
        ans = dig - 'a' + 10;
    }
    return ans;
}