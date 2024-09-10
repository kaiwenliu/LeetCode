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
        if (!head) {
            return NULL;
        }
        stack<ListNode*> nodes;
        ListNode* curr;
        ListNode* next;
        ListNode* restOfList;
        
        int i = 0;
        next = head;
        while (i < k && next) {
            nodes.push(next);
            next = next->next;
            i++;
        }
        if (i < k) {
            return head;
        }
        restOfList = nodes.top()->next;
        head = nodes.top();
        nodes.pop();
        curr = head;
        while (!nodes.empty()) {
            curr->next = nodes.top();
            nodes.pop();
            curr = curr->next;
        }
        curr->next = restOfList;
        
        while (curr) {
            int i = 0;
            next = curr->next;
            while (i < k && next) {
                nodes.push(next);
                next = next->next;
                i++;
            }
            if (i < k) {
                return head;
            }
            restOfList = nodes.top()->next;
            while (!nodes.empty()) {
                curr->next = nodes.top();
                nodes.pop();
                curr = curr->next;
            }
            curr->next = restOfList;
        }
        return head;
    }
};
