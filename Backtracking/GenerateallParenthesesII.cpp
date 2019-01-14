vector<string> solve(int A,int l,int r){
    if(A==l+r)return {};
    else{
        vector<string> ans;
        if(l<A/2){
            vector<string> tmp=solve(A,l+1,r);
            for(int m=0;m<tmp.size();m++){
                tmp[m].insert(0,1,'(');
                ans.push_back(tmp[m]);
            }
        }
        if(l>r){
            if(l+r+1==A){
                return {")"};
            }
            else{
                vector<string> tmp=solve(A,l,r+1);
                for(int m=0;m<tmp.size();m++){
                    tmp[m].insert(0,1,')');
                    ans.push_back(tmp[m]);
                }                
            }
        }
        return ans;
    }
}    
vector<string> Solution::generateParenthesis(int A) {
    return solve(2*A,0,0);
}
