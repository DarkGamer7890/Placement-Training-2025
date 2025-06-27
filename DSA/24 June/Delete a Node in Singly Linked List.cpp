/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        // code here
        if(x == 1) return head->next;
        
        Node* temp = head;
        int i = 1;
        
        while(temp->next != nullptr && i != x - 1){
            ++i;
            temp = temp->next;
        }
        
        if(temp->next) temp->next = temp->next->next;
        
        return head;
    }
};