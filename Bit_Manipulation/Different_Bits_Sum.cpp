long long int smooth(long long int ans){
    return (ans+1000000007)%1000000007;
}
int Solution::cntBits(vector<int> &A) {
    bool f=true;
    int c=0;
    int n=A.size();
    vector<int> cc(32,0);
    int i;
    for(i=0;i<=31&&f;i++){
        f=false;
        c=0;
        for(int j=0;j<A.size();j++){
            if(A[j]>0)f=true;
            c=c+(A[j]&1);
            A[j]=A[j]>>1;
        }
        cc[i]=c;
        //cout<<cc[i]<<"  ";
    }
    //cout<<"\n";
    long long int ans=0;
    for(int j=0;j<=31&&j<i-1;j++){
            long long int x=smooth(smooth(n-cc[j])*cc[j]);
            ans=smooth(ans+smooth(2*x));
    }
    return ans;
}
