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
ListNode* merge2LL(ListNode* head1, ListNode* head2){
        if(head1==NULL && head2==NULL)return NULL;
        if(head1!=NULL && head2==NULL)return head1;
        if(head1==NULL && head2!=NULL)return head2;
        ListNode* curr1=head1;
        ListNode* curr2=head2;
        ListNode* ans=new ListNode(0);
        ListNode* curr3=ans;
        while(curr1 !=NULL && curr2!=NULL){
                if(curr1->val<=curr2->val){
                    curr3->next=new ListNode(curr1->val);
                    curr1=curr1->next;
                }
                else{
                    curr3->next=new ListNode(curr2->val);
                    curr2=curr2->next;
                }
            curr3=curr3->next;
        }
        if(curr1!=NULL){
            curr3->next=curr1;
        }
        if(curr2!=NULL){
            curr3->next=curr2;
        }
        return ans->next;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge2LL(list1,list2);
    }
};
