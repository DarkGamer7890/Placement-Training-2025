// Method 1 (Recommended if n (size of LinkedList) is unknown)

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
    ListNode* curr_head = nullptr;
public:
    Solution(ListNode* head) : curr_head(head) {}
    
    int getRandom() {
        int nodesSeenTillNow = 0;
        ListNode* head = curr_head;

        ListNode* randomNode = nullptr;

        while(head){
            ++nodesSeenTillNow;

            int randomIndex = rand() % nodesSeenTillNow;
            if(randomIndex == nodesSeenTillNow - 1) randomNode = head;
            head = head->next;
        }

        return randomNode->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */








// Method 2 (takes less time but is not recommended as n should be known for this)

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
    vector<int> v;
    int n{};

    void move(ListNode* head){
        while(head){
            v.push_back(head->val);
            head = head->next;
        }

        n = v.size();
    }
public:
    Solution(ListNode* head){
        move(head);
    }
    
    int getRandom() {
        int randomIndex = rand() % n;
        return v[randomIndex];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */