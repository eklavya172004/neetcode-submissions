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
    ListNode* findmiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow ->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr; 

        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while (curr != nullptr)
        {
            ListNode* nxt = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        if(prev != nullptr){
            head = prev;
        }

        return head;
    }

    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        return;

        ListNode* middle = findmiddle(head);
        ListNode* second = reverseList(middle->next);

        middle -> next = nullptr;

        ListNode* l1 = head;
        ListNode* l2 = second;

        while(l1 && l2){
            ListNode* next1 = l1 -> next;
            ListNode* next2 = l2 -> next;

            l1 -> next = l2;
            l2 -> next = next1;

            l1 = next1;
            l2 = next2;
        }
    }
};
