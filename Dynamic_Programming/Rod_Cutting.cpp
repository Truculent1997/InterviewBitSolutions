vector<int> ans;
int back[101][101];
void backtrack(int i,int j,vector<int> B){
    if(i+1>=j)return ;
    else{
        ans.push_back(B[back[i][j]]);
        backtrack(i,back[i][j],B);
        backtrack(back[i][j],j,B);
    }
}
vector<int> Solution::rodCut(int A, vector<int> &B) {
    //memset(back,)
    ans.clear();
    B.insert(B.begin(),0);
    B.push_back(A);
    int n=B.size();
    if(n==2)return ans;
    if(n==3){
        ans.push_back(B[1]);
        return ans;
    }
    long int dp[n+1][n+1];
    for(int gap=1;gap<n;gap++){
        for(int i=0;i<n-gap;i++){
            if(gap==1){
                dp[i][i+1]=0;
                back[i][i+1]=-1;
            }    
            else if(gap==2){
                dp[i][i+2]=B[i+2]-B[i];
                back[i][i+2]=i+1;
            }
            else{
                long mini=LONG_MAX;
                int ind;
                for(int k=1;k<gap;k++){
                    if(dp[i][i+k]+dp[i+k][i+gap]<mini){
                        mini=dp[i][i+k]+dp[i+k][i+gap];
                        ind=i+k;
                    }
                }
                dp[i][i+gap]=mini+B[i+gap]-B[i];
                back[i][i+gap]=ind;
            }
            //cout<<dp[i][i+gap]<<"  ("<<back[i][i+gap]<<")";
        }
        //cout<<"\n";
    }
    backtrack(0,n-1,B);
    return ans;
}
