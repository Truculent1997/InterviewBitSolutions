int Solution::braces(string A) {
    stack<char> m;
    for(int i=0;i<A.length();i++){
        if(A[i]==')'){
            if(m.top()=='(')return 1;
            else{
                m.pop();
                if(m.top()=='(')return 1;
                while(m.top()!='('){
                    m.pop();
                }
                m.pop();
            }
        }
        else{
            m.push(A[i]);
        }
    }
    return 0;
}
