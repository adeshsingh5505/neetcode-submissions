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
void reverse(ListNode* &head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;  
        curr->next = prev;                
        prev = curr;                      
        curr = nextNode;                 
    }
    head = prev;  
    }
public:
    void reorderList(ListNode* &head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newLL=slow->next;
        slow->next=NULL;
        reverse(newLL);
        ListNode* curr=head;
        while(newLL){
            ListNode* storage=NULL;
            ListNode* s2=curr->next;
            curr->next=newLL;
            storage=newLL->next;
            newLL->next=s2;
            newLL=storage;
            curr=curr->next->next;
        }

    }
};
