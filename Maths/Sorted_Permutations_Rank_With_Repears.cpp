#define p 1000003
int smooth(long long int ans){
    return (ans+p)%p;
}
int factor(vector<int> &fact,int n){
    fact[0]=fact[1]=1;
    for(int i=2;i<=n;i++){
        fact[i]=smooth(fact[i-1]*i);
    }
}
int Solution::findRank(string A) {
    int n=A.length();
    long long int ans=1;
    string use=A;
    int arr[60]={0};
    sort(use.begin(),use.end());
    for(int i=0;i<use.length();i++){
        arr[use[i]-'A']++;
    }
    vector<int> fact(n+1);
    factor(fact,n);
//Converting the number into multiplicative inverse 
    long long int sum=A.length(); 
    vector<long long int> inv(sum+1);
    inv[0]=inv[1]=1;
    for(long i=2;i<=sum;i++){
        inv[i]=inv[p%i]*(p-p/i)%p;
    }
//Calculating inverse factorial here.    
    for(long long int i=2;i<=sum;i++){
        inv[i]=(inv[i]*inv[i-1])%p;
    }    
//Using factoradic system    
    for(int i=0;i<n;i++){
        long long int x=1;
        int temp=0;
        for(int j=0;j<A[i]-'A';j++)temp+=arr[j];
        for(int j=0;j<60;j++)x=smooth(x*inv[arr[j]]);
        ans=smooth(ans+smooth(smooth(temp*fact[n-1-i])*x));
        arr[A[i]-'A']--;
    }
    return ans;
}
