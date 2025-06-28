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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        else if(!head->next->next) return (head->val == head->next->val) ? true : false;

        ListNode* hare = head;
        ListNode* tortoise = head;
        ListNode* prev = nullptr;

        while(hare && hare->next){
            prev = tortoise;
            hare = hare->next->next;
            tortoise = tortoise->next;
        }

        if(hare) tortoise = tortoise->next;
        ListNode* first = reverse(tortoise);

        ListNode* second = head;

        while(first && second){
            if(first->val != second->val) return false;

            second = second->next;
            first = first->next;
        }

        return true;
    }
};