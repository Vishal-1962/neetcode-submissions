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

        ListNode* temp = head;

        // Check if k nodes are available
        int count = 0;
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        // Less than k nodes → don't reverse
        if (count < k)
            return head;

        // Reverse k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // head is now the last node of reversed group
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};