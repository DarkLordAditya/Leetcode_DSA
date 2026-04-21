#include <iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
stack<int> st;
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
int n = temperatures.size();        
vector<int> result (n,0);
for(int i = 0; i<n; i++){
while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
result[st.top()] = i-st.top();
st.pop();
}
st.push(i);
}
return result;
    }
};

int main(){
Solution ot;
vector<int> num = {73,74,75,71,69,72,76,73};
vector<int> result = ot.dailyTemperatures(num);

for(int e: result){
cout<<e<<" "; 
}
 
return 0;
}