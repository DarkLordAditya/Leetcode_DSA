#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop(); 
                k--;
            }
            st.push(digit); 
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string result = "";
        while (!st.empty()) {
            result += st.top(); 
            st.pop();
        }
        reverse(result.begin(), result.end());

        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }
        result = result.substr(i);

        return result.empty() ? "0" : result; 
    }
};

int main() {
    Solution s;

    string num = "123456";
    int k = 3; 

    string a = s.removeKdigits(num, k); 

    cout << a << endl;

    return 0;
}