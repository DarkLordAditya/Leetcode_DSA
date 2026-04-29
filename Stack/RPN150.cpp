#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();

                if(token == "+") st.push(num2 + num1);
                else if(token == "-") st.push(num2 - num1);
                else if(token == "*") st.push(num2 * num1);
                else st.push(num2 / num1);
            } 
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};

int main() {
    Solution obj;
    vector<string> tokens = {"2","1","+","3","*"};
    
    int num = obj.evalRPN(tokens);
    cout << num << endl;

    return 0;
}