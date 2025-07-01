// Method 1

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
    int length(ListNode* head){
        int n = 0;
        while(head){
            ++n;
            head = head->next;
        }

        return n;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = length(head);
        int i = 1;

        ListNode* n1 = head;
        while(i < k){
            ++i;
            n1 = n1->next;
        }

        ListNode* n2 = head;
        int j = 1;
        while(j < n - k + 1){
            ++j;
            n2 = n2->next;
        } 
        
        swap(n1->val, n2->val);

        return head;
    }
};




// Method 2

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;

        for(int i = 0; i < k; ++i) fast = fast->next;
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        for(int i = 0; i < k-1; ++i) prev = prev->next;
        
        swap(slow->val, prev->val);

        return head;
    }
};