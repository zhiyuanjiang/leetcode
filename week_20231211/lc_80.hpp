class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.emplace_back(0xffffff);
        int ans = 0;
        int cnt = 1;
        int pre = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == pre){
                cnt++;
                if(cnt > 2){
                    ans++;
                    nums[i] = 0xffffff;
                }
            }else{
                pre = nums[i];
                cnt = 1;
            }
        }
        sort(nums.begin(), nums.end());
        return nums.size() - ans - 1;
    }
};