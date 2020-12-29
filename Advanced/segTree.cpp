// segment tree concept used in Range Query Problems
// like min, max, sum, xor
#include <iostream>
#include <cmath>
using namespace std;

struct segTree {
    int *a, n, m;
    segTree(int v[], int n) {
        m = n-1;
        this->n = sizeSeg(n);
        a = new int[this->n];
        build(v, 0, m, 0);
    }
    // building segment tree
    void build(int*, int, int, int);
    // for any query
    int query(int, int, int, int, int);
    int query(int ql, int qh) {
        return query(ql, qh, 0, m, 0);
    }
    // for update at particular index
    void update(int, int, int, int, int);
    void update(int idx, int val) {
        update(idx, val, 0, m, 0);
    }
    // for update in range
    void updateRange(int, int, int, int, int, int);
    void updateRange(int s, int e, int val) {
        updateRange(s, e, val, 0, m, 0);
    }
    int sizeSeg(int n) {
        return (int)pow(2, (int)ceil(log2(n)))*2-1;
    }
    void fill() {
        for(int i = 0; i < n; i++)
            a[i] = 0;
    }
    void print() {
        for(int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
};

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

int32_t main() {
	tool();
    int n, k;
    cin >> n >> k;
    int v[n];
    for(int i = 0; i < n; i++)
        cin >> v[i];
    segTree tree(v, n);
    int s, e, val;
    tree.updateRange(2, 4, 2);
    tree.print();
	return 0;
}

void segTree::build(int* v, int l, int h, int i) {
    if(l == h) {
        a[i] = v[l];
        return;
    }
    int mid = (l+h)/2;
    build(v, l, mid, 2*i+1);
    build(v, mid+1, h, 2*i+2);
    a[i] = max(a[2*i+1], a[2*i+2]);
}

int segTree::query(int ql, int qh, int l, int h, int i) {
    if(ql > h || qh < l)
        return INT32_MIN;
    if(l >= ql && h <= qh)
        return a[i];
    int mid = (l+h)/2;

    return max(query(ql, qh, l, mid, 2*i+1), query(ql, qh, mid+1, h, 2*i+2));
}

void segTree::update(int idx, int val, int l, int h, int i) {
    if(idx > h || idx < l)
        return;
    if(l == h) {
        a[i] += val;
        return;
    }
    int mid = (l+h)/2;
    update(idx, val, l, mid, 2*i+1);
    update(idx, val, mid+1, h, 2*i+2);
    a[i] = max(a[2*i+1], a[2*i+2]);
}

void segTree::updateRange(int s, int e, int val, int l, int h, int i) {
    if(s > h || e < l)
        return;
    if(l == h) {
        a[i] += val;
        return;
    }
    int mid = (l+h)/2;
    updateRange(s, e, val, l, mid, 2*i+1);
    updateRange(s, e, val, mid+1, h, 2*i+2);
    a[i] = max(a[2*i+1], a[2*i+2]);
}