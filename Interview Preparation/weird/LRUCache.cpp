#include <iostream
#include <unordered_map>

using namespace std;
/*
class LRUCache
{
    struct Node
    {
        int k, v;
        Node *l, *r;
        Node(int key, int value) : k(key), v(value), l(NULL), r(NULL) {}
    };
    int cap;
    Node *h, *t;
    unordered_map<int, Node *> mp;

public:
    LRUCache(int capacity) : cap(capacity), h(new Node(-1, -1)), t(new Node(-1, -1)) {}
    void set(int key, int value)
    {
        if(mp.find(key) != mp.end())
        {
            Node *n = mp[key];
            n->v = value;
            deleteNode(n);
            addNode(n);
        }
        else
        {
            if(mp.size() == cap)
            {
                Node *n = t->l;
                mp.erase(n->k);
                deleteNode(n);
                delete(n);
            }
            mp[key] = new Node(key, value);
            addNode(mp[key]);
        }
        
    }
    int get(int key)
    {
        int res = -1;
        if (mp.find(key) != mp.end())
        {
            Node *n = mp[key];
            res = n->v;
            deleteNode(n);
            addNode(n);
        }
        return res;
    }
    void addNode(Node *n)
    {
        n->r = h->r;
        n->r->l = n;
        h->r = n;
        n->l = h;
    }
    void deleteNode(Node *n)
    {
        n->l->r = n->r;
        n->r->l = n->l;
    }
};
*/

int32_t main()
{
}


class LRUCache
{
    struct Node
    {
        int key, value;
        Node *l, *r;
        Node(int k, int v) : key(k), value(v), l(NULL), r(NULL) {}
    };
    int cap;
    Node *h, *t;
    unordered_map<int, Node *> mp;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        h = new Node(-1, -1), t = new Node(-1, -1);
        h->r = t, t->l = h;
    }
    void deleteNode(Node *node)
    {
        node->l->r = node->r;
        node->r->l = node->l;
    }
    void addNode(Node *node)
    {
        node->r = h->r;
        node->r->l = node;
        node->l = h;
        h->r = node;
    }
    int get(int key)
    {
        int res = -1;
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            res = node->value;
            deleteNode(node);
            addNode(node);
        }
        return res;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            node->value = value;
            deleteNode(node);
            addNode(node);
        }
        else
        {
            if (mp.size() == cap)
            {
                Node *node = t->l;
                mp.erase(node->key);
                deleteNode(node);
                delete (node);
            }
            mp[key] = new Node(key, value);
            addNode(mp[key]);
        }
    }
};