unsigned int Solution::reverse(unsigned int A) {
    int n=32;
    unsigned int ans=0;
    while(n){
        ans=(ans<<1)|(A&1);
        A=A>>1;
        n--;
    }
    return ans;
}
