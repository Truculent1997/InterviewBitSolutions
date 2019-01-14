int Solution::longestValidParentheses(string A) {
    int n=A.length();
    stack<pair<char,int>> m;
    int ans=0;
    m.push(make_pair('X',-1));
    for(int i=0;i<n;i++){
        if(m.empty()||m.top().second==-1){
            m.push(make_pair(A[i],i));
        }
        else{
            if(A[i]=='(')m.push(make_pair(A[i],i));
            else{
                char ch=m.top().first;
                int x=m.top().second;
                if(ch=='('){
                    m.pop();
                    ans=max(ans,i-m.top().second);
                }
                else{
                    m.push(make_pair(A[i],i));
                }
                
            }
        }
    }
    return ans;
}
