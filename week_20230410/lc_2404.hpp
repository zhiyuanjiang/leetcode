#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto val : nums){
            if(val & 1) continue;
            mp[val]++;
        }
        int t1,t2;
        t2 = 0;
        t1 = -1;
        for(auto [key, cnt] : mp){
            if(t2 == cnt){
                t1 = min(t1, key);
            }
            if(t2 < cnt){
                t1 = key;
                t2 = cnt;
            }
        }
        return t1;
    }
};