#include<iostream>
#include<vector>
#include <queue>
using namespace std;
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> st;  

        for (int i = 0; i < nums.size(); i++) {
            if (!st.empty() && st.front() <= i - k) {
                st.pop_front();
            }
            while (!st.empty() && nums[st.back()] < nums[i]) {
                st.pop_back();
            }

            st.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[st.front()]);
            }
        }

        return ans;
    }
};#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> st;  

        for (int i = 0; i < nums.size(); i++) {
            if (!st.empty() && st.front() <= i - k) {
                st.pop_front();
            }
            while (!st.empty() && nums[st.back()] < nums[i]) {
                st.pop_back();
            }

            st.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[st.front()]);
            }
        }

        return ans;
    }
};
int main(){
Solution s;
vector<int> nums = {1,3,-1,-3,5,3,6,7};
int k = 3;
vector<int> ans = s.maxSlidingWindow(nums, k);
for(int i:ans){
cout<<i<<" ";
}
return 0;
}

/*Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]*/