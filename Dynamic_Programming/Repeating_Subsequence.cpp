int Solution::anytwo(string A) {
    int n=A.length();
    if(n<=2)return 0;
    string res="";
    int count[256]={0};
    for(int i=0;i<n;i++){
        count[A[i]]++;
    }
    for(int i=0;i<n;i++){
        if(count[A[i]]>2)return 1;
        if(count[A[i]]>1){
            res=res+A[i];
        }
    }
    int n1=res.length();
    for(int i=0;i<res.length()/2;i++){
        if(res[i]!=res[n1-i-1])return 1;
    }
    return 0;
}
