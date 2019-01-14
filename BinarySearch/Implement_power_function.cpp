int smooth(long long int ans,int d){
    return (ans+d)%d;
}
int Solution::pow(int x, int n, int d) {
    if(x==0)return 0;
    long long int res=1;
    long long int num=x;
    num=num%d;
    while(n>0){
        if(n&1){
            res=(num*res)%d;
        }
        n=n>>1;
        num=(num*num)%d;
    }
    return (res+d)%d;
}
