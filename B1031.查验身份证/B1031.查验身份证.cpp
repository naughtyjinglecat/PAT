#include<cstdio>

int main(void){
    char ID_num[19];
    int sign = 0;//是否有输出
    bool tag = true;//假定身份证无误
    int n;
    int sum = 0;
    int quanzhong[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char z[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", ID_num);
        for(int i = 0; i < 17; i++){
            if(ID_num[i] <= '9' || ID_num[i] >= '0'){
                sum += (ID_num[i] - '0') * quanzhong[i];
            }
            else{
                tag = false;
                break;
            }
        }
        if(z[sum % 11]!= ID_num[17]){
            tag = false;
        }
        if(tag == false){
            printf("%s", ID_num);
            sign = 1;
            if(i != n - 1){
                printf("\n");
            }
        }
        tag = true;
        sum = 0;
    }
    if(sign == 0){
        printf("All passed\n");
    }


    return 0;
}