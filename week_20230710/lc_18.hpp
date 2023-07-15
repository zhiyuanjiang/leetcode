#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        long long t2 = target;
        for(int i = 0; i < n; ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n; ++j){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int p = j+1, q = n-1;
                long long tmp = t2 - nums[i] - nums[j];
                while(p < q){
                    if(nums[p] + nums[q] == tmp){
                        vector<int> data{nums[i], nums[j], nums[p], nums[q]};
                        ans.push_back(data);
                        while(p+1 < q && nums[p+1] == nums[p]) p++;
                        p++;
                        while(q-1 > p && nums[q-1] == nums[q]) q--;
                        q--;
                    }else if(nums[p] + nums[q] < tmp){
                        p++;
                    }else{
                        q--;
                    }
                }
            }
        }
        return ans;
    }
};