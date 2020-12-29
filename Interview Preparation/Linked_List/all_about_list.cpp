#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(){}
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// function for inserting data in the end of the list
void insert_at_end(Node* head, int data) {
    Node* new_node = new Node(data);
    if(head == NULL)
        head=new_node;
    else {
        Node* temp = head;
        while(temp->next != NULL)
        temp = temp->next;
        temp->next = new_node;
    }
}

// function for insert data in the beginning of the list
void insert_at_beginning(Node* head, int data) {
    Node* new_node = new Node(data);
    Node* temp = head;
    head = new_node;
    head->next = temp;
}


// function for insert data in at the specific position in the list
void insert_at_specific_pos(Node* head, int data,int pos){
    Node* temp1 = head;
    pos=pos-2;
    while(pos--)
        temp1 = temp1->next;
    Node* temp2 = temp1->next;
    Node* new_node = new Node(data);
    temp1->next = new_node;
    temp1->next->next = temp2;
}


// recursive
Node* reverse(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;
    Node* temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

// Iterative
void reverse(Node* head) {
    Node* current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// detect cycle
bool isCycle(Node* head) {
    if(head == NULL) 
        return false;
    Node* slow = head, *fast = head->next;
    while(slow != fast) {
        if(fast == NULL || fast->next == NULL)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

// detect cycle point
void removeLoop(Node* head)
{
    Node* slow = head, *fast = head;
    bool flag = true;
    while(flag || fast != slow) {
        flag = false;
        if(fast == NULL || fast->next == NULL) return;
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    while(fast->next != slow)
        fast = fast->next;
    fast->next = NULL;
}