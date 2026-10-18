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
    // ListNode* rev(ListNode* &head){
    //     ListNode* prev=NULL;
    //     ListNode* curr=head;
    //     ListNode* storage=NULL;
    //     while(curr!=NULL){
    //         storage=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=storage;
    //     }
    //     return prev;
    // }
    ListNode* solve(ListNode* l1, ListNode* l2){
        int carry=0;
        ListNode* ans= new ListNode(0);
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        ListNode* curr3=ans;
        while(curr1!=NULL || curr2!=NULL){
            int val1=0,val2=0;
            if(curr1!=NULL)val1=curr1->val;
            if(curr2!=NULL)val2=curr2->val;
            int sum=val1+val2+carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            curr3->next=newnode;
            curr3=curr3->next;
            if(curr2)curr2=curr2->next;
            if(curr1)curr1=curr1->next;
        }
            if(carry!=0){
                ListNode* newnode=new ListNode(carry);
                curr3->next=newnode;
            }
        return ans->next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=solve(l1,l2);
        return ans;
    }
};
