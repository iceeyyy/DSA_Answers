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
    ListNode* deleteMiddle(ListNode* head) {

        if(!head || !head->next) return NULL;  //edge case

        int len=0;
        ListNode* temp=head;
        ListNode* temp2=head;

        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        temp=head; //reset temp pointer

        int mid = len/2;
        int cnt = mid-1; // must stop behind temp pntr

        while(cnt){
            temp2=temp2->next;
            cnt--;
        }

        while(mid){
            temp=temp->next;
            mid--;
        }

        temp2->next=temp->next;
        temp->next=NULL;

        delete temp;

        return head;

    }
};