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
class Comparator{
public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);

        ListNode* curr = dummy;

        priority_queue<ListNode*,
                       vector<ListNode*>,
                       Comparator
            > pq;

        for(ListNode* head : lists){
            if(head){
                pq.push(head);
            }
        }

        

        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            dummy->next = node;
            dummy = dummy -> next;

            if(node->next){
                pq.push(node->next);
            }
        }

        return curr -> next;
    }
};
