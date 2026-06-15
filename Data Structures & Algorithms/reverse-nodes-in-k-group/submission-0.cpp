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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }

        ListNode* temp = head;

        for(int i = 0; i < k; i++) {
            if(temp == nullptr) {
                return head;
            }
            temp = temp->next;
        }

        int count = 0;

        ListNode* cur = head;
        ListNode* prev = nullptr;

        while(cur && count < k){
            ListNode* nxt = cur->next;

            cur -> next = prev;
            prev = cur;
            cur = nxt;
            count++;
        }

        head->next = reverseKGroup(cur,k);

        return prev;
    }
};
