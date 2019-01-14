int Solution::wordBreak(string A, vector<string> &B) {
    unordered_map<string,bool> my;    
    my.clear();
    bool dp[100001];
    for(int i=0;i<B.size();i++)
        my[B[i]]=1;
    for(int i=0;i<=A.size();i++){
        dp[i]=false;
    }
    dp[0]=true;
    for(int i=1;i<=A.size();i++){
        for(int j=i-1;j>=0;j--){
            if(dp[j]){
                string tmp=A.substr(j,i-j);
                if(my.find(tmp)!=my.end()){
                   dp[i]=true;
                   break;
                }
            }
        }
        if(dp[A.length()])return 1;
    }
    return dp[A.length()];
}
