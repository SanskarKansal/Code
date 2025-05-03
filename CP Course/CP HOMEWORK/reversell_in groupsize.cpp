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
            if (head == nullptr || k == 1) {
                return head;
            }
            ListNode* node = head;
            int count = 0;
            while (node != nullptr && count < k) {
                node = node->next;
                count++;
            }
            if (count == k) {
                ListNode* prev = nullptr;
                ListNode* curr = head;
                ListNode* next;
                int i = 0;
                while (i < k && curr != nullptr) {
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                    i++;
                }
                if (next != nullptr) {
                    head->next = reverseKGroup(next, k);
                }
                return prev;
            }
            else {
                return head;
            }
        }
    };
    