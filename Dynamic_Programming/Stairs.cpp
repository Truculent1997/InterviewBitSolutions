int Solution::climbStairs(int A) {
    int fib[A+2];
    fib[0]=1;
    for(int i=0;i<A;i++){
        fib[i+1]+=fib[i];
        fib[i+2]+=fib[i];
    }
    return fib[A];
}
