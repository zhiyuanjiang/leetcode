class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        for(i = 1; i < n; ){
            while(i < n && nums[i] == nums[i-1]){
                ++i;
                ans++;
            }
            if(i < n)
                i += 2;
        }
        if(i == n){
            ans++;
        }
        return ans;
    }
};