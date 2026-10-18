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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp=head;
        vector<int> values;
        while(temp!=NULL){
            values.push_back(temp->val);
            temp=temp->next;
        }
        reverse(values.begin()+left-1,values.begin()+right);
        for(auto i: values) cout<<i<<" ";
        ListNode* ans=new ListNode(0);
        ListNode* res= ans;
        for(auto i: values){
            ans->next=new ListNode(i);
            ans=ans->next;
        }
        return res->next;
    }
};