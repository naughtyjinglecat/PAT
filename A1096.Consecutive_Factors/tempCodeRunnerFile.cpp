int maxLength(int n, int start){
    long long temp = start;
    int length = 0;
    for(int i = 1; i <= n; i++){
        if(n % temp == 0){
            length++;
            temp *= start + i;
        }
    }
}