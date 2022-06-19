#include<cstdio>
#include<queue>
#include<malloc.h>
using namespace std;

//思路出现大问题了，这题求解的是体积，但是我求的是切片的面积。。。。。全错

//为当前图分配空间
void allocation(char** &image, int m, int n){
    image = (char**)malloc(sizeof(char*)*m);
    for(int i = 0; i < m; i++){
        image[i] = (char*)malloc(sizeof(char)*n);
    }
}
//为当前图释放空间
void release(char** &image, int m){
    for(int i = 0; i < m; i++){
        free(image[i]);
    }
    free(image);
}

//读入当前图片
void readimage(char** image, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            getchar();
            scanf("%c", &image[i][j]);
        }
    }
}
//计算并返回stroke大小，同时修改当前相连的stroke点值为0
int volume(char** image, int m, int n, int i, int j){
    int count = 0;
    typedef struct address{
        int i;
        int j;
    }address;
    address p, temp;
    queue<address> stroke;
    p.i = i;
    p.j = j;
    stroke.push(p);
    image[p.i][p.j] = '0';
    while(!stroke.empty()){
        p = stroke.front();
        if(p.i-1 >= 0 && image[p.i-1][p.j] == '1'){
            temp.i = p.i-1;
            temp.j = p.j;
            stroke.push(temp);
            image[temp.i][temp.j] = '0';
        }
        if(p.i+1 < m && image[p.i+1][p.j] == '1'){
            temp.i = p.i+1;
            temp.j = p.j;
            stroke.push(temp);
            image[temp.i][temp.j] = '0';
        }
        if(p.j - 1 >= 0 && image[p.i][p.j-1] == '1'){
            temp.i = p.i;
            temp.j = p.j-1;
            stroke.push(temp);
            image[temp.i][temp.j] = '0';
        }
        if(p.j + 1 < n && image[p.i][p.j+1] == '1'){
            temp.i = p.i;
            temp.j = p.j+1;
            stroke.push(temp);
            image[temp.i][temp.j] = '0';
        }
        count++;
        stroke.pop();
    }
    return count;
}

int main(void){
    int m, n, L, t;
    char** image;
    int total_volume = 0;
    int cur_volume;
    int count = 0;
    scanf("%d %d %d %d", &m, &n, &L, &t);
    for(int i = 0; i < L; i++){
        allocation(image, m, n);
        readimage(image, m, n);
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                //如果检测到了stroke且volume大于等于阈值，则计数加1
                if(image[j][k] == '1'){
                    cur_volume = volume(image, m, n, j, k);
                    if(cur_volume >= t){
                        total_volume += cur_volume;
                    }
                }
            }
        }
        release(image, m);
    }
    printf("%d\n", total_volume);
    return 0;
}