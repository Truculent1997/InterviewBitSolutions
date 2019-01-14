long long int smooth(long long int ans){
    return (ans+1000000007)%1000000007;
}
int Solution::solve(int A) {
    long long int color2=12;
    long long int color3=24;
    for(int i=2;i<=A;i++){
        long long int temp=smooth(smooth(7*color2)+smooth(5*color3));
        color3=smooth(smooth(10*color2)+smooth(11*color3));
        color2=temp;
    }
    return smooth(color2+color3);
}
