#include<cstdio>
#include<string.h>
/*发生了数组越界，因为访问数组的时候忘记了检查数组边界，提交了两次，25分*/

int main(void){
    /*三标志，-1代表这个数没出现过，0代表这个数出现过是关建数，1代表是非关键数*/
    int hashtable[105];
    int k;
    int temp;
    int sign = 0;
    memset(hashtable, -1, sizeof(hashtable));
    scanf("%d", &k);

    for(int i = 0; i < k; i++){
        scanf("%d", &temp);
        if(hashtable[temp] != 1){
            hashtable[temp] = 0;
            while(temp != 1){
                if(temp % 2 == 1){
                    temp = (3*temp + 1)/2;
                }
                else{
                    temp /= 2;
                }
                if(temp <= 100){
                    hashtable[temp] = 1;
                }
            }
        }
    }
    for(int i = 100; i >= 1;i--){
        if(hashtable[i] == 0){
            if(sign == 0){
                printf("%d", i);
                sign = 1;
            }
            else{
                printf(" %d", i);
            }
        }
    }
    printf("\n");
    return 0;
}