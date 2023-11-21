class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0, n = nums.size();
        int i = 0;
        while(i < n){
            int num = 0;
            for(; i < n; ++i){
                if(nums[i] % 2 == 0 && nums[i] <= threshold){
                    num++;
                    ans = max(ans, num);
                    break;
                } 
            }
            for(i++; i < n; ++i){
                if(nums[i] % 2 != nums[i-1] % 2 && nums[i] <= threshold){
                    num++;
                    ans = max(ans, num);
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};