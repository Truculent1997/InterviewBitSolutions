#define mod 1000003
int smooth(long long int ans){
    return (ans+mod)%mod;
}
int factor(vector<int> &fact,int n){
    fact[0]=fact[1]=1;
    for(int i=2;i<=n;i++){
        fact[i]=smooth(fact[i-1]*i);
    }
}
int Solution::findRank(string A) {
    int n=A.length();
    string use=A;
    sort(use.begin(),use.end());
    vector<int> fact(n+1);
    factor(fact,n);
//Using factoradic system    
    long long int ans=0;
    for(int i=0;i<n;i++){
        size_t found=use.find(A[i]);
        if(found!=string::npos){
            if(found!=0){
                ans=smooth(ans+smooth(found*fact[n-1-i]));
            }
            use.erase(use.begin()+found);
        }
    }
    return ans+1;
}
