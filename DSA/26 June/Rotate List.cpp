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
        int n = 0;
        while(head){
            ++n;
            head = head->next;
        }

        return n;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int n = length(head);

        k %= n;

        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0; i < k; ++i) fast = fast->next;

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = nullptr;

        return head;
    }
};