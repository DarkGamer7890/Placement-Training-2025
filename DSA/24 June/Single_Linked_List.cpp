#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {} 
    ListNode(int x, ListNode* n) : val(x), next(n) {} 
};

class LinkedList{
public:
    ListNode* insert_begin(ListNode*& head, int n){
        if(!head){
            head = new ListNode(n);
            return head;
        }
        
        ListNode* temp = new ListNode(n, head);
        head = temp;

        return head;
    }



    ListNode* insert_end(ListNode*& head, int n){
        if(!head){
            head = new ListNode(n);
            return head;
        }

        ListNode* temp = head;
        while(temp->next) temp = temp->next;

        ListNode* temp1 = new ListNode(n);
        temp->next = temp1;

        return head;
    }



    ListNode* insert_index(ListNode*& head, int index, int n){
        if(!head){
            head = new ListNode(n);
            return head;
        }

        if(index == 0){
            head = insert_begin(head, n);
            return head;
        }

        ListNode* temp = head;
        int i = 0;

        while(temp->next && i < index - 1){
            ++i;
            temp = temp->next;
        }

        if(!temp->next && i < index - 1) cout << "Invalid Index\n";

        else if(!temp->next && i == index - 1) temp->next = new ListNode(n);

        else{
            ListNode* temp1 = new ListNode(n, temp->next);
            temp->next = temp1;
        }

        return head;
    }



    ListNode* del_begin(ListNode*& head){
        if(!head) return head;

        ListNode* temp = head;
        head = head->next;

        delete temp;
        return head;
    }



    ListNode* del_end(ListNode*& head){
        if(!head) return head;

        if(!head->next) return nullptr;

        ListNode* temp = head;
        while(temp->next->next) temp = temp->next;
        
        ListNode* temp1 = temp->next;
        temp->next = nullptr;

        delete temp1;
        return head;
    }



    ListNode* del_index(ListNode*& head, int index){
        if(!head) return head;

        if(index < 0){
            cout << "Invalid Index\n";
            return head;
        }

        else if(index == 0){
            ListNode* temp = head;
            head = head->next;

            delete temp;
            return head;
        }
        

        ListNode* temp = head;
        int i = 0;

        while(temp->next && i < index - 1){
            temp = temp->next;
            ++i;
        }

        if(!temp->next && i <= index - 1) cout << "Invalid Index\n";

        else{
            ListNode* temp1 = temp->next;
            temp->next = temp->next->next;

            delete temp1;
        }
            
        return head;
    }



    ListNode* del_val(ListNode*& head, int n){
        if(!head) return head;

        else if(!head->next && head->val != n){
            cout << "No maching value found\n";
            return head;
        }

        else if(!head->next && head->val == n){
            ListNode* temp = head;
            head = head->next;

            delete temp;
            return head;
        }

        
        ListNode* temp = head;

        while(temp->next->next && temp->next->val != n) temp = temp->next;

        if(!temp->next->next && temp->next->val != n) cout << "No matching value found\n";
        else if(!temp->next->next && temp->next->val == n) temp->next = temp->next->next;
        else{
            ListNode* temp1 = temp->next;
            temp->next = temp->next->next;

            delete temp1;
        }

        return head;
    }



    void display(ListNode*& head){
        ListNode* temp = head;

        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;

        delete temp;
    }
};

int main(){
    LinkedList l;
    ListNode* head = nullptr;

    head = l.insert_begin(head, 1);
    l.display(head);

    head = l.insert_end(head, 2);
    l.display(head);

    head = l.insert_index(head, 2, 3);  // 0-indexed
    l.display(head);

    head = l.insert_index(head, 3, 4);  
    l.display(head);

    head = l.insert_end(head, 5);  
    l.display(head);

    head = l.insert_end(head, 3);  
    l.display(head);

    head = l.del_begin(head);
    l.display(head);

    head = l.del_end(head);
    l.display(head);

    head = l.del_index(head, 2);
    l.display(head);

    head = l.insert_begin(head, 3);
    l.display(head);

    head = l.insert_end(head, 3);
    l.display(head);

    head = l.del_val(head, 3);
    l.display(head);

    head = l.del_begin(head);
    l.display(head);
    
    head = l.del_end(head);
    l.display(head);

    head = l.del_end(head);
    l.display(head);

    head = l.del_val(head, 1);
    l.display(head);

    return 0;
}