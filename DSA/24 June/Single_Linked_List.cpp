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
private:
    ListNode* head;
    int length = 0;

public:
    LinkedList() : head(nullptr) {}

    void insert_begin(int n){
        ++length;

        ListNode* temp = new ListNode(n, head);
        head = temp;
    }



    void insert_end(int n){
        ++length;

        if(!head){
            head = new ListNode(n);
            return;
        }

        ListNode* temp = head;
        while(temp->next) temp = temp->next;

        ListNode* temp1 = new ListNode(n);
        temp->next = temp1;
    }



    void insert_index(int index, int n){
        if(!head && index == 0){
            ++length;
            head = new ListNode(n);
            return;
        }

        else if(!head && index > 0) cout << "Invalid Index\n";

        else if(index < 0 || index > length + 1) cout << "Invalid Index\n";

        else if(index == 0){
            insert_begin(n);
            ++length;
            return;
        }

        else if(index == length + 1){
            insert_end(n);
            ++length;
            return;
        }

        ++length;

        ListNode* temp = head;
        int i = 0;

        while(temp->next && i < index - 1){
            ++i;
            temp = temp->next;
        }

        ListNode* temp1 = new ListNode(n, temp->next);
        temp->next = temp1;
    }



    void del_begin(){
        if(!head) return;
        --length;

        ListNode* temp = head;
        head = head->next;

        delete temp;
    }



    void del_end(){
        if(!head) return;
        --length;

        if(!head->next){
            head = nullptr;
            return;
        }

        ListNode* temp = head;
        while(temp->next->next) temp = temp->next;
        
        ListNode* temp1 = temp->next;
        temp->next = nullptr;

        delete temp1;
    }



    void del_index(int index){
        if(!head) return;

        if(index < 0 || index > length){
            cout << "Invalid Index\n";
            return;
        }

        else if(index == 0){
            ListNode* temp = head;
            head = head->next;
            --length;

            delete temp;
            return;
        }
        
        --length;

        ListNode* temp = head;
        int i = 0;

        while(temp->next && i < index - 1){
            temp = temp->next;
            ++i;
        }

        
        ListNode* temp1 = temp->next;
        temp->next = temp->next->next;

        delete temp1;
    }



    void del_val(int n){
        if(!head) return;

        else if(head->val == n){
            ListNode* temp = head;
            head = head->next;
            --length;

            delete temp;
            return;
        }

        else if(!head->next && head->val != n){
            cout << "No maching value found\n";
            return;
        }

        else if(!head->next && head->val == n){
            ListNode* temp = head;
            head = head->next;
            --length;

            delete temp;
            return;
        }

        
        ListNode* temp = head;

        while(temp->next->next && temp->next->val != n) temp = temp->next;

        if(!temp->next->next && temp->next->val != n){
            cout << "No matching value found\n";
            return;
        }

        else if(!temp->next->next && temp->next->val == n) temp->next = temp->next->next;

        else{
            ListNode* temp1 = temp->next;
            temp->next = temp->next->next;

            delete temp1;
        }
        --length;

        return;
    }



    void display(){
        ListNode* temp = head;

        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;

        delete temp;
        // cout << "Size: " << length << endl;
    }
};

int main(){
    LinkedList l;

    l.insert_begin(1);
    l.display();

    l.insert_end(2);
    l.display();

    l.insert_index(2, 3);  // 0-indexed
    l.display();

    l.insert_index(3, 4);  
    l.display();

    l.insert_end(5);  
    l.display();

    l.insert_end(3);  
    l.display();

    l.del_begin();
    l.display();

    l.del_end();
    l.display();

    l.del_index(2);
    l.display();

    l.insert_begin(3);
    l.display();

    l.insert_end(3);
    l.display();

    l.del_val(3);
    l.display();

    l.del_begin();
    l.display();
    
    l.del_end();
    l.display();

    l.del_end();
    l.display();

    l.del_val(1);
    l.display();

    return 0;
}