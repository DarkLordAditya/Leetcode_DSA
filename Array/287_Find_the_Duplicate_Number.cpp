// Mine code
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int num;
     unordered_map<int, int> freq;
      for (int x : nums) {
        freq[x]++;  
    }
     for (const auto& p : freq) {
        if(p.second>1){
            num = p.first;
            break;
        }
    }
    return num;
    }
};
//  Most Optimize
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};