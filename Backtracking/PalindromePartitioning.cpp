bool palind(string A){
    int n=A.length();
    for(int i=0;i<=n/2;i++){
        if(A[i]!=A[n-i-1])return false;
    }
    return true;
}
vector<vector<string>> solve(string A,int i){
    if(A.length()==i)return {};
    else{
        vector<vector<string>> ans;
        for(int j=i;j<A.length();j++){
            string s=A.substr(i,j-i+1);
            if(palind(s)){
                if(j==A.length()-1)return {{s}};
                else{
                    cout<<"1\n";
                    vector<vector<string>> tmp=solve(A,j+1);
                    for(int m=0;m<tmp.size();m++){
                        cout<<"2"<<s<<"  "<<tmp[m][0]<<"\n";
                        tmp[m].insert(tmp[m].begin(),s);
                        cout<<"2"<<s<<"  "<<tmp[m][0]<<"  "<<tmp[m][1]<<"\n";
                        ans.push_back(tmp[m]);
                    }
                }
            }
        }
        return ans;
    }
    
}
vector<vector<string> > Solution::partition(string A) {
    return solve(A,0);
}
