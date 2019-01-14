int Solution::sqrt(int A) {
    if(A==0)return 0;
    long int l=1;
    long int r=A-1;
    long long int a=A;
    long long int ans;
    while(l<=r){
        long long int m=(l+r)/2;
        // cout<<m*m<<"  "<<a<<endl;
        if(m*m==a)return m;
        else if(m*m>a)r=m-1;
        else{
            ans=m;
            l=m+1;
        }
    }
    return ans;
}
