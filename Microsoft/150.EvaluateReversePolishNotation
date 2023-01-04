Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    // here we need to evaluate postfix operation
    int evalRPN(vector<string>& tokens) {
        stack<int> st; // for evaluating postfix expression

        for (auto& a : tokens) {
            
            // if the element is an operator then pop 2 operands, perform operation and push the result
            if (a == "+" || a == "-" || a == "*" || a == "/") {
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                string lol = a;

                if (lol == "+") { st.push(val1 + val2); }
                else if (lol == "-") { st.push(val2 - val1); }
                else if (lol == "*") { st.push(val1 * val2); }
                else if (lol == "/") { st.push(val2 / val1); }
            }
            // if the element is an operand then push in stack
            else {
                st.push(stoi(a));
            }
        }

        return st.top();
    }
};
