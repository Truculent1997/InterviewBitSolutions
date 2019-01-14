vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
int dp[501][501][8];
int m,n;
int fix(int i,int j,vector<string> &A,int lol){
    if(dp[i][j][lol]!=-1)return dp[i][j][lol];
    int xx=i+dir[lol][0];
    int yy=j+dir[lol][1];
    if(xx>=0&&xx<m&&yy>=0&&yy<n){
        if(A[xx][yy]=='1')return dp[i][j][lol]=1;
        else return dp[i][j][lol]=fix(xx,yy,A,lol);
    }
    else{
        return dp[i][j][lol]=0;
    }
}
vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    m=A.size();
    if(m==0)return vector<vector<int>>();
    n=A[0].length();
    vector< vector<int> > ans(m, vector<int>(n, 0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<8;k++){
                dp[i][j][k]=-1;
            }
        }
    }
    for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
            int lol=0;
            int c=0;
            for(auto d:dir){
                dp[i][j][lol]=fix(i,j,A,lol);
                if(dp[i][j][lol])ans[i][j]++;
                lol++;
            }
       }
    }
    return ans;
}
