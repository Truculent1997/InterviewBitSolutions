int Solution::numDecodings(string A) {
    int n=A.length();
    if(n==0){
        return 0;
    }
    if(n==1){
        if(A[0]!='0')return 1;
        else return 0;
    }
    if(A.length()>=2)
    {
        int fib[n+1];
        if(A[0]=='0')return 0;
        fib[0]=1;
        fib[1]=1;
        for(int i=1;i<n;i++){
            if(A[i]=='0'){
                if(A[i-1]=='1'||(A[i-1]=='2'))fib[i+1]=fib[i-1];
                else return 0;
            }
            else{
                if(A[i-1]=='1'||(A[i-1]=='2'&&A[i]<='6'))
                    fib[i+1]=fib[i-1]+fib[i];
                else
                    fib[i+1]=fib[i];
            }
        }
        return fib[n];
    }
    
}
