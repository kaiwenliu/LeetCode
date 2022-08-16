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
    struct compareNodes {
        bool operator()(ListNode*& A, ListNode*& B) {
            return A->val > B->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compareNodes> pq;
        for (ListNode*& l: lists) {
            if (l) {
                pq.push(l);
            }
        }
        if (pq.empty()) {
            return NULL;
        }
        ListNode* head = pq.top();
        pq.pop();
        if (head->next) {
            pq.push(head->next);
        }
        ListNode* prev = head;
        ListNode* curr;
        while (!pq.empty()) {
            curr = pq.top();
            pq.pop();
            prev->next = curr;
            if (curr->next) {
                pq.push(curr->next);
            }
            prev = curr;
        }
        return head;
    }
};
