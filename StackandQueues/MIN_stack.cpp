stack<int> mini,val;
MinStack::MinStack() {
    while(!mini.empty()){
        mini.pop();
    }
    while(!val.empty()){
        val.pop();
    }
}

void MinStack::push(int x) {
    val.push(x);
    if(mini.empty())mini.push(x);
    else if(mini.top()>=x){
        mini.push(x);
    }
}

void MinStack::pop() {
    if(val.empty())return ;
    else{
        if(mini.top()==val.top()){
            mini.pop();
        }
        val.pop();
    }
}

int MinStack::top() {
    if(val.empty())return -1;
    else return val.top();
}

int MinStack::getMin() {
    if(mini.empty())return -1;
    else return mini.top();
}

