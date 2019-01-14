int n;
int sum=0;
unordered_map<int,bool> ans;
int dp[51][51][501];
bool ispossible(int i,vector<int> A,int ele,int cursum,int ind){
    int totaasp=(sum*i)/n;
    if(dp[ind][i-ele][totaasp-cursum]!=-1){
        return dp[ind][i-ele][totaasp-cursum];
    }
    if(i*sum==n*cursum){
        return dp[ind][i-ele][totaasp-cursum]=true;
    }
    if(ind==n||ele==i){
        return dp[ind][i-ele][totaasp-cursum]=false;
    }
    for(int j=ind;j<A.size();j++){
        if(ispossible(i,A,ele+1,cursum+A[j],j+1)){
            ans[j]=true;
            return dp[ind][i-ele][totaasp-cursum]=true;
        }
    }
    return dp[ind][i-ele][totaasp-cursum]=false;
}
vector<vector<int>> Solution::avgset(vector<int> &A) {
     n=A.size();
     sum=0;
     ans.clear();
     vector<vector<int>> ans2;
     for(int i=0;i<51;i++){
         for(int j=0;j<51;j++){
             for(int k=0;k<501;k++){
                 dp[i][j][k]=-1;
             }
         }
     }
     for(int i=0;i<A.size();i++)sum+=A[i];
     sort(A.begin(),A.end());
     for(int i=1;i<=n/2;i++){
        if((sum*i)%n!=0)continue;
        if(ispossible(i,A,0,0,0)){
            vector<int> c1,c2;
            for(int i=0;i<A.size();i++){
                if(ans[i])c1.push_back(A[i]);
                else c2.push_back(A[i]);
            }
            sort(c1.begin(),c1.end());
            sort(c2.begin(),c2.end());
            ans2.push_back(c1);
            ans2.push_back(c2);
            break;           
        }           
     }       
     return ans2;
}
