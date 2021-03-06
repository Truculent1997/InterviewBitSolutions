bool anagram(string s1,string s2){
    int count[256]={0};
    int count2[256]={0};
    for(int i=0;i<s1.length();i++){
        count[s1[i]]++;
        count2[s2[i]]++;
    }
    for(int i=0;i<255;i++){
        if(count[i]!=count2[i])return false;
    }
    return true;
}
int Solution::isScramble(const string s1, const string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1.size() == 0) return true;
        int n = s1.size();
        bool dp[n][n][n+1];
        for(int l = 1 ; l <= n ; l++)
        {
            for(int i = 0 ; i < n-l+1; i++)
            {
                for(int j = 0 ; j < n-l+1 ; j++)
                {
                    if(l == 1)
                    {
                        if(s1[i] == s2[j]) dp[i][j][l] = true;
                        else dp[i][j][l] = false;
                        continue;
                    }
                    
                    dp[i][j][l] = false;
                    for(int k = 1; k <= l-1; k++)
                    {
                        if( (dp[i][j][k] && dp[i+k][j+k][l-k]) || (dp[i][j+l-k][k] && dp[i+k][j][l-k])  )
                        {
                            dp[i][j][l] = true;
                            break;
                        }
                    }
                }
                
            }
        }
        return dp[0][0][n];
    /*if(A.length()!=B.length())return 0;
    if(A==B)return 1;
    if(!anagram(A,B))return 0;
    int m=A.length();
    bool dp[m][m][m+1];
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            dp[i][j][1]=(A[i]==B[j]);
        }
    }
    return 1;*/
}
