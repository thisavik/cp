#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

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

class LRUCache
{
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int capacity;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    int get(int key)
    {
        int res = -1;
        if(mp.find(key) != mp.end())
        {
            auto node = mp[key];
            l.erase(mp[key]);
            l.push_front({node->first, node->second});
            res = node->second;
        }
        return res;
    }
    int put(int key, int value)
    {
        bool flag = false;
        if(mp.find(key) != mp.end())
        {
            l.erase(mp[key]);
            flag = true;
        }
        else if(mp.size() == capacity)
        {
            mp.erase(l.back().first);
            l.pop_back();
        }
        l.push_front({key, value});
        mp[key] = l.begin();
        return flag;
    }
};