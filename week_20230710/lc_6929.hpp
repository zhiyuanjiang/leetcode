#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        std::vector<pair<int, int>> data;
        for(auto val : nums){
            data.emplace_back(val-k, 0);
            data.emplace_back(val+k, 1);
        }
        sort(data.begin(), data.end(), 
                [](pair<int, int>& a, pair<int, int>& b){
            if(a.first == b.first){
                return a.second < b. second;
            }
            return a.first < b.first;
        });
        int cnt = 0, ans = 0;
        for(auto& [_, val] : data){
            if(val == 0) cnt++;
            else cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};