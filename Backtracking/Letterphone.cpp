vector<string> op{"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> solve(string A,int i){
    if(i==A.length())return {};
    int num=A[i]-'0';
    vector<string> ans;
    for(auto j:op[num]){
        char ch=j;
        if(i==A.length()-1)ans.push_back({ch});
        else{
            vector<string> tmp=solve(A,i+1);
            for(int m=0;m<tmp.size();m++){
                tmp[m].insert(tmp[m].begin(),ch);
                ans.push_back(tmp[m]);
            }
        }
    }
    return ans;
} 
vector<string> Solution::letterCombinations(string A) {
    return solve(A,0);
}
