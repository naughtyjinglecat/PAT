#include<cstdio>
/*思路没有问题，但是算法效率不高，有优化空间，每次查找不必都从起点开始查找，可以从当前位置开始查找*/

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
/*返回第一个未被放下的数字的下标*/
int findFirstUnfinal(int num[], int n, int &k){
    int ans = -1;
    for(int i = k; i < n; i++){
        if(num[i] != i){
            ans = i;
            k = i;
            break;
        }
    }
    return ans;
}
/*在数组中查找某个元素的下标*/
int findNum(int num[], int n, int find){
    /*该算法中使用了查找来查询某数字编号，事实上更快的方式是使用一个hashtable记录每个数字当前的编号使得每个数字当前位置的编号查询时间复杂度为o(1)量级*/
    int ans;
    for(int i = 0; i < n; i++){
        if(num[i] == find){
            ans = i;
        }
    }
    return ans;
}

int main(void){
    int n;
    /*暂存待交换数字的标号*/
    int temp;
    /*统计有多少数字被放下了*/
    int putdown = 0;
    /*统计一共交换了几次*/
    int count = 0;
    /*标记0的位置*/
    int indexOfZero = -1;
    int* num = NULL;
    int k = 1;
    scanf("%d", &n);
    num = new int[n];
    for(int i = 0; i < n; i++){
        scanf("%d", num + i);
        if(num[i] == i){
            putdown++;
        }
        if(num[i] == 0){
            indexOfZero = i;
        }
    }
    while(putdown < n){
        if(indexOfZero != 0){
            temp = findNum(num, n, indexOfZero);
            swap(num[indexOfZero], num[temp]);
            count++;
            putdown++;
            indexOfZero = temp;
        }
        else{
            temp = findFirstUnfinal(num, n, k);
            /*交换之前需要检查访问范围是否越界, 若temp等于-1，则代表全部数字已经安放妥当，无需继续循环*/
            if(temp == -1){
                break;
            }
            swap(num[indexOfZero], num[temp]);
            count++;
            indexOfZero = temp;
        }
    }
    printf("%d\n", count);
    return 0;
}