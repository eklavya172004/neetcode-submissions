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
    int length(ListNode* head){
        ListNode* l1 = head;
        int count = 0;

        while(l1 != nullptr){
            l1 = l1->next;
            count++;
        }

        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;

        int N = length(head);

        if(N == n) return head->next;

        int move = N - n - 1;

        ListNode* curr = head;

        while(move > 0){
            curr = curr -> next;
            move--;
        }

        curr->next = curr->next->next;
    
        return head;
    }
};
