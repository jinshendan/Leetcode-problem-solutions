/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    
    vector<int> nextLargerNodes(ListNode* head) {
        int n = 0;
        vector<int> v;
        while (head != NULL){
            v.push_back(head->val);
            n ++;
            head = head->next;
        }
        
        vector<int> ans(n, 0);
        stack<int> s;
        for (int i = 0; i < n; i++){
            while(!s.empty() and v[s.top()] < v[i]){
                ans[s.top()] = v[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};