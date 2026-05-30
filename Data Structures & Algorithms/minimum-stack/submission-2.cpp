class MinStack {
        long long minv = INT_MAX;
        stack<long long> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            minv = val;
            st.push(val);
        }else{
            if(val>=minv){
                 st.push(val);
            }else {
                st.push(2LL*val-minv);
                minv = val; 
                }
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long x = st.top();
        st.pop();

        if(x<minv){
            minv = 2*minv - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;

        long long  x = st.top();

        if(x>=minv) return x;
        else return minv;
    }
    
    int getMin() {
        return minv;
        
    }
};
