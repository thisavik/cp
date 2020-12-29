#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    LinkedList() {
        head = NULL;
    }
    void reverse() {
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
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    // idea to to return head of each k grp of sublist and save it to head next
    Node* reverse_k(Node* head, int k) {
        Node* pre = NULL;
        Node* curr = head;
        Node* next;
        for(int i=0; i<k && curr != NULL; i++) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        if(curr != NULL)
            head-> next = reverse_k(curr, k);
        return pre;
    }

    // reverse m to n node in list 
    Node* reverse_m_n(Node* head, int m, int n) {
        if(head == nullptr || m == n) return head;

        Node *pre = nullptr;
        Node *cur = head;

        while(m > 1) {
            pre = cur;
            cur = cur->next;
            m--; n--;
        }
        Node *conn = pre, *tail = cur;
        while(n > 0) {
            Node *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            n--;
        }
        if(conn != nullptr) 
            conn->next = pre;
        else
            head = pre;

        tail->next = cur;
        return head;
    }
};

void solve() {
    int n;
    cin >> n;

    LinkedList ll;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        ll.push(x);
    }

    ll.reverse();

    cout << "Given linked list\n";
    ll.print();

    ll.head = ll.reverse_m_n(ll.head, 1, 3);

    cout << "Reversed Linked list \n";
    ll.print();
}

int main()
{
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

bool help(Node** left, Node* right) {
    if(right == nullptr)
        return true;
    bool check1 = help(left, right->next);

    if(!check1) 
        return check1;
    
    bool check2 = (*left)->data == right->data;

    *left = (*left)->next;
    return check2;
}

bool checkPalindrome(Node* head) {
    return help(&head, head);
}