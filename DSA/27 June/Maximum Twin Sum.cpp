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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(curr){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next) next = next->next;
        }

        return prev;
    }
public:
    int pairSum(ListNode* head) {
        int sum = INT_MIN;

        ListNode* hare = head;
        ListNode* tortoise = head;

        while(hare && hare->next){
            tortoise = tortoise->next;
            hare = hare->next->next;
        }

        ListNode* first = head;
        ListNode* second = reverse(tortoise);

        while(first && second){
            sum = max(sum, first->val + second->val);

            first = first->next;
            second = second->next;
        }

        return sum;
    }
};