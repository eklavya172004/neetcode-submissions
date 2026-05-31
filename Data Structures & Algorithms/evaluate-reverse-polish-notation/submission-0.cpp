class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i =  0 ; i < tokens.size() ; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*"  || tokens[i] == "/"){               
                int a = st.top();
                st.pop();
                
                int b = st.top();
                st.pop();
            
                int result = evaluate(tokens[i][0],b,a);

                st.push(result);
            }else{
                int number = stoi(tokens[i]);
                st.push(number);
            }
        }

        return st.top();
    }

    int evaluate(char op,int op1,int op2){
        switch(op){
            case '+' : return op1 + op2;
            case '-' : return op1 - op2;
            case '*':  return  (op1 * op2); 
            case '/': return op1/op2;
        }

        return 0;
    }
};
