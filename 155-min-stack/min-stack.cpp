class MinStack {
public:

    stack<int> s,ms;
    int t=INT_MAX;
    MinStack() {
    }
    
    void push(int val) 
    {
        s.push(val);
        if(!ms.empty())
            ms.push(min(val,ms.top()));
        else
            ms.push(val);
    }
    
    void pop(){
        if(!s.empty())
          s.pop();
        if(!ms.empty())
            ms.pop(); 
    }
    int top(){
        return s.top();
    }
    
    int getMin(){
        return ms.top();    
    }
};