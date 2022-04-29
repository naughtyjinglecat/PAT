#include<stdio.h>
#include<stdlib.h>
/*明明很简单的题但是只有18分。。。*/


int main(void){
    long long n1, *nums1;
    long long n2, *nums2;
    int sign1 = 0, sign2 = 0;
    long long median;
    scanf("%lld", &n1);
    nums1 = (long long*)malloc(sizeof(long long)*n1);
    for(int i = 0; i < n1; i++){
        scanf("%lld", nums1 + i);
    }
    scanf("%lld", &n2);
    nums2 = (long long*)malloc(sizeof(long long)*n2);
    for(int i = 0; i < n2; i++){
        scanf("%lld", nums2 + i);
    }
    while(sign1 + sign2 <= (n1 + n2)/2){
        if(nums1[sign1] <= nums2[sign2]){
            if(sign1 < n1){
                sign1++;
            }
            else{
                sign2++;
            }
        }
        else{
            if(sign2 < n2){
                sign2++;
            }
            else{
                sign1++;
            }
        }
    }
    median = (nums1[sign1 - 1] >= nums2[sign2 - 1]) ? nums1[sign1 - 1] : nums2[sign2 - 1];
    printf("%lld\n", median);
    return 0;
}