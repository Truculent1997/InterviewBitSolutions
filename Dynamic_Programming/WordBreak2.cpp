unordered_map<string,bool> my;
unordered_map<string,vector<string>> dp;
vector<string> combine(string tmp,vector<string> res){
    vector<string> here;
    for(int i=0;i<res.size();i++){
        here.push_back(tmp+" "+res[i]);
    }
    return here;
}
vector<string> solve(string A){
     if(dp.find(A)!=dp.end())return dp[A];
     vector<string> res;
     int size=A.length();
     for(int i=1;i<=size;i++){
         string tmp=A.substr(0,i);
         if(my.find(tmp)!=my.end()){
             vector<string> just=combine(tmp,solve(A.substr(i,size-i)));
             for(int j=0;j<just.size();j++){
                res.push_back(just[j]);
              }
         }

     }
     if(my.find(A)!=my.end()){
         res.push_back(A);
     }
     return dp[A]=res;
 }
vector<string> Solution::wordBreak(string A, vector<string> &B) {
    my.clear();
    dp.clear();
    for(int i=0;i<B.size();i++){
        my[B[i]]=1;
    }
    return solve(A);
}
