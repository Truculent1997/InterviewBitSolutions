long long int p=1000000007;
long long int smooth(long long int ans){
    return (ans+p)%p;
}
long long int power(long long int x,long long int y) 
{ 
    long long int res = 1;
    x = x % p;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
}
int Solution::solve(int A, vector<int> &B) {
    if(A==B.size())return 0;
    sort(B.begin(),B.end());
    int c=0;
    int j=0;
    int i=1;
    vector<long long int> ans;
    while(i<=A){
        if(i==B[j]){
            if(c!=0)ans.push_back(c);
            j++;
            c=0;
        }
        else{
            c++;
        }
        i++;
    }
    if(c>0)ans.push_back(c);
    long long int ways=1;
    long long int sum=0,x=0;
    for(int i=0;i<ans.size();i++){
        sum=smooth(sum+ans[i]);
        if(B[0]!=1&&i==0){}
        else if(B[B.size()-1]!=A&&i==ans.size()-1){}
        else {
            
            x+=(ans[i]-1);
        }
    }
    ways=smooth(power(2,x));
//Converting the number into multiplicative inverse     
    vector<long long int> inv(sum+1);
    inv[0]=inv[1]=1;
    for(long i=2;i<=sum;i++){
        inv[i]=inv[p%i]*(p-p/i)%p;
    }
//Calculating inverse factorial here.    
    for(long long int i=2;i<=sum;i++){
        inv[i]=(inv[i]*inv[i-1])%p;
    }
//Calculating factorial of total missing places.    
    long long int fact=1;
    for(long long int i=2;i<=sum;i++){
        fact=((fact*i)+p)%p;
    }
    long long int ans1=1;
    ans1=smooth(ways*fact);
    for(int i=0;i<ans.size();i++){
    
        ans1=smooth(ans1*inv[ans[i]]);
    }
    return smooth(ans1);
}
