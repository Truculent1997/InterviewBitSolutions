int Solution::evalRPN(vector<string> &A) {
    stack<int> s;
    for(int i=0;i<A.size();i++){
        if((A[i]=="+")||(A[i]=="-")||(A[i]=="*")||(A[i]=="/")){
            int x=s.top();
            s.pop();
            int y=s.top();
            s.pop();
            if(A[i]=="+")s.push(x+y);
            else if(A[i]=="-")s.push(y-x);
            else if(A[i]=="*")s.push(y*x);
            else if(A[i]=="/")s.push(y/x);
        }
        else{
            s.push(stoi(A[i]));
        }
    }
    return s.top();
}
