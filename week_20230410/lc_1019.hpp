/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <vector>
#include <stack>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> stk;
        int cnt = 0;
        while(head){
            ans.push_back(head->val);
        
            while(!stk.empty()){
                if(ans[stk.top()] >= head->val){
                    stk.push(cnt);
                    break;
                }else{
                    ans[stk.top()] = head->val;
                    stk.pop();
                }
            }

            if(stk.empty()){
                stk.push(cnt);
            }

            head = head->next;
            cnt++;
        }

        while(!stk.empty()){
            ans[stk.top()] = 0;
            stk.pop();
        }

        return ans;
    }
};