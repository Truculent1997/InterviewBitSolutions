bool r[9][10],c[9][10],b[9][10];
bool f=false;
void solve(vector<vector<char>> &A,int i,int j,vector<vector<char>> &ans){
    if(f)return ;
    if(i==9){f=true;ans=A;return ;}
    if(A[i][j]!='.'){
        if(j==8){i=i+1;j=-1;}
        solve(A,i,j+1,ans);
    }
    else{
        for(int m=1;m<=9;m++){
            int box=3*(i/3)+j/3;
            if(!r[i][m]&&!c[j][m]&&!b[box][m]){
                r[i][m]=true;
                c[j][m]=true;
                b[box][m]=true;
                A[i][j]=(char)(m+'0');
                if(j==8){solve(A,i+1,0,ans);}
                else solve(A,i,j+1,ans);
                r[i][m]=false;
                c[j][m]=false;
                b[box][m]=false;
                A[i][j]='.';
                
            }
        }
    }
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    int n=A.size();
    f=false;
    memset(r,false,sizeof(r));
    memset(c,false,sizeof(c));
    memset(b,false,sizeof(b));
    vector<vector<char>> ans;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(A[i][j]!='.')
            {
                int box=3*(i/3)+j/3;
                r[i][A[i][j]-'0']=true;
                c[j][A[i][j]-'0']=true;
                b[box][A[i][j]-'0']=true;
            }
        }
    }
    solve(A,0,0,ans);
    A=ans;
}
