int smooth(long long int x){
    return (x+10000003)%10000003;
}
int Solution::paint(int B, int C, vector<int> &A) {
    if(B>A.size())return 0;
    long long int sum=0;
    long long int l=A[0];
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        l=max(l,1ll*A[i]);
    }    
    long long int r=sum;
    long long int ans=-1;
    while(l<=r){
        long long int m=(l+r)/2;
        long i=0;
        int c=1;
        long long int cur=0;
        while(i<A.size()){
            // cout<<i<<"  "<<m<<"   "<<cur+A[i]<<"   "<<c<<endl;
            if(cur+A[i]>m){
                c++;
                cur=A[i];
            }
            else{
                cur+=A[i];
            }
            i++;
        }
        // cout<<l<<"   "<<r<<"   "<<c<<endl;
        if(c<=B){
            ans=m;
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return smooth(ans*C);    
}
