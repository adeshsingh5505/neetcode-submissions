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
private:
    int length(ListNode* head){
        int cnt=0;
        while(head!=NULL){
            head=head->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=length(head);
        if(len<k || head==NULL) return head;
        int cnt=0;
        ListNode* curr=head;
        ListNode* storage=NULL;
        ListNode* prev=NULL;
        while(curr!=NULL && cnt<k){
            storage=curr->next;
            curr->next=prev;
            prev=curr;
            curr=storage;
            cnt++;
        }
        if(storage!=NULL){
            head->next=reverseKGroup(storage,k);
        }
        return prev;
    }
};
