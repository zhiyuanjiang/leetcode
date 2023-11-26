#include <pair>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PAI; 
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        nums.emplace_back(2e9+2);
        int n = nums.size();
        vector<PAI> data(n);
        for(int i = 0; i < n; ++i){
            data[i] = make_pair(nums[i], i);
        }
        sort(data.begin(), data.end());
        vector<int> ans(n-1);
        int l = 0;
        for(int i = 1; i < n; ++i){
            if(abs(data[i].first - data[i-1].first) > limit){

                vector<int> tmp;
                for(int j = l; j < i; ++j){
                    tmp.emplace_back(data[j].second);
                }
                sort(tmp.begin(), tmp.end());
                for(int j = 0; j < tmp.size(); ++j){
                    ans[tmp[j]] = data[j+l].first;
                }

                l = i;
            }
        }

        return ans;
    }
};