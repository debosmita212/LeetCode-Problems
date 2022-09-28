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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //create a dummy node
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        //Use slow and fast pointer
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        //edge cases
        if(head==NULL || n==0)
            return head;
        //increment fast upto n
        for(int i=1;i<=n;i++)
            fast=fast->next;
        //until fast reaches last node increment slow and fast by one
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        //slow->next is the nth element from last which has to be deleted
        slow->next=slow->next->next;
        //return head of modified linked list
        return dummy->next;
    }
};