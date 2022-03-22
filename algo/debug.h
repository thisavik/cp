#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T, class cmp = std::less<T>>
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// print pair
template <typename A, typename B>
ostream &operator<<(ostream &out, const pair<A, B> &a)
{
    out << "(" << a.first << "," << a.second << ")";
    return out;
}

// print array
template <typename T, size_t N>
ostream &operator<<(ostream &out, const array<T, N> &a)
{
    out << "[";
    bool first = true;
    for (auto &v : a)
    {
        out << (first ? "" : ", ");
        out << v;
        first = 0;
    }
    out << "]";
    return out;
}

// print vector
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &a)
{
    out << "[";
    bool first = true;
    for (auto &v : a)
    {
        out << (first ? "" : ", ");
        out << v;
        first = 0;
    }
    out << "]";
    return out;
}

// print set
template <typename T, class Cmp>
ostream &operator<<(ostream &out, const set<T, Cmp> &a)
{
    out << "{";
    bool first = true;
    for (auto &v : a)
    {
        out << (first ? "" : ", ");
        out << v;
        first = 0;
    }
    out << "}";
    return out;
}

// print ordered_set
template <typename T, class Cmp>
ostream &operator<<(ostream &out, const ordered_set<T, Cmp> &a)
{
    out << "{";
    bool first = true;
    for (auto &v : a)
    {
        out << (first ? "" : ", ");
        out << v;
        first = 0;
    }
    out << "}";
    return out;
}

// print unordered_set
template <typename T, class Cmp>
ostream &operator<<(ostream &out, const unordered_set<T, Cmp> &a)
{
    out << "{";
    bool first = true;
    for (auto &v : a)
    {
        out << (first ? "" : ", ");
        out << v;
        first = 0;
    }
    out << "}";
    return out;
}

// print map
template <typename U, typename T, class Cmp>
ostream &operator<<(ostream &out, const map<U, T, Cmp> &a)
{
    out << "{";
    bool first = true;
    for (auto &p : a)
    {
        out << (first ? "" : ", ");
        out << "(" << p.first << ":" << p.second << ")";
        first = 0;
    }
    out << "}";
    return out;
}

// print unordered_map
template <typename U, typename T, class Cmp>
ostream &operator<<(ostream &out, const unordered_map<U, T, Cmp> &a)
{
    out << "{";
    bool first = true;
    for (auto &p : a)
    {
        out << (first ? "" : ", ");
        out << p.first << ":" << p.second;
        first = 0;
    }
    out << "}";
    return out;
}

// print queue
template <typename U>
ostream &operator<<(ostream &out, const queue<U> &q)
{
    out << "[";
    bool first = true;
    queue<U> qq = q;
    while (!qq.empty())
    {
        out << (first ? "" : ", ");
        out << qq.front();
        qq.pop();
        first = 0;
    }
    out << "]";
    return out;
}

// print stack
template <typename U>
ostream &operator<<(ostream &out, const stack<U> &s)
{
    out << "[";
    bool first = true;
    stack<U> ss = s;
    while (!ss.empty())
    {
        out << (first ? "" : ", ");
        out << ss.top();
        ss.pop();
        first = 0;
    }
    out << "]";
    return out;
}

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}
