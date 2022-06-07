#include<cstdio>
#include<vector>
using namespace std;

//注意再提前输出结果，要处理剩下的垃圾数据

int main(void){
    int m, n, k;
    int tmp;
    //记录当前即将入栈的元素
    int cur;
    //定义一个标记，若是输出了NO，则修改标记为true，并且则不用再输出YES
    bool sign = false;
    vector<int> st;
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; i++){
        cur = 2;
        st.clear();
        st.push_back(1);
        sign = false;
        for(int j = 0; j < n; j++){
            scanf("%d", &tmp);
            if(sign == true){
                continue;
            }
            if(tmp == st[st.size()-1]){
                st.pop_back();
            }
            else if(tmp > st[st.size()-1]){
                for(; cur <= tmp; cur++){
                    st.push_back(cur);
                }
                if(st.size() > m){
                    sign = true;
                    printf("NO\n");
                }
                st.pop_back();
            }
            else{
                sign = true;
                printf("NO\n");
            }
        }
        if(sign == false){
            printf("YES\n");
        }
    }
    return 0;
}