int n;

bool isSafe(vector<string> str,int i,int j){
    //Column check
    for(int m=0;m<i;m++){
        if(str[m][j]=='Q')return false;
    }
    //Left upper
    for(int m1=i,n1=j;m1>=0&&n1>=0;m1--,n1--){
        if(str[m1][n1]=='Q')return false;
    }
    //Right upper
    for(int m1=i,n1=j;m1>=0&&n1<n;m1--,n1++){
        if(str[m1][n1]=='Q')return false;
    }
    return true;
}
void solve(vector<vector<string>> &ans,int row,vector<string> &board){
    if(row==n){
        ans.push_back(board);
        return ;
    }
    for(int i=0;i<n;i++){
        if(isSafe(board,row,i)){
            board[row][i]='Q';
            solve(ans,row+1,board);
            board[row][i]='.';
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int A) {
    n=A;
    vector<vector<string>> ans;
    if(A>1&&A<4)return {};
    vector<string> tmp;
    string str="";
    for(int i=0;i<A;i++){
        str+=".";
    }
    for(int i=0;i<A;i++){
        tmp.push_back(str);
    }    
    solve(ans,0,tmp);
    return ans;
}
