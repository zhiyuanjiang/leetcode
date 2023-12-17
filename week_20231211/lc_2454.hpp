class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        priority_queue<int> q;
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(!q.empty() && nums[i] > nums[q.top()]){
                ans[q.top()] = nums[i];
                q.pop();
            }
            while(!st.empty() && nums[i] > nums[st.top()]){
                q.push(st.top());
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};