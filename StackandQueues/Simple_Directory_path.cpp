string Solution::simplifyPath(string A) {
    stringstream line(A);
    stack<string> c;
    string mid;
    while(getline(line,mid,'/')){
        if(mid=="."||mid==""){}
        else if(mid==".."){
            if(c.empty()){}
            else c.pop();
        }
        else c.push(mid);
    }
    string ans="";
    if(c.empty())return "/";
    while(!c.empty()){
        if(c.top()!="")
        ans="/"+c.top()+ans;
        c.pop();
    }
    return ans;
}
