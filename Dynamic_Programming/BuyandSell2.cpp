int Solution::maxProfit(const vector<int> &A) {
    int n=A.size();
    if(n==0)return 0;
    long long int ans=0;
    int i=0;
    while(i<n-1){
        while((i<n-1)&&A[i]>=A[i+1])i++;
        if(i==n-1)break;
        long long int buy=A[i];
        i++;
        while((i<n)&&A[i]>=A[i-1])i++;
        ans+=(A[i-1]-buy);
    }
    return ans;
}
