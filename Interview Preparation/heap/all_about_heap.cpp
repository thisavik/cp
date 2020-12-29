#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent(int n) {
    return (n-1)/2;
}

int left_child(int n) {
    return 2*n+1;
}

int right_child(int n) {
    return 2*n+2;
}

void max_heapify(vector<int>& a, int i, int size) {
    if(i >= size)
        return;
    int l = left_child(i);
    int r = right_child(i);
    int largest = i;
    if(l < size && a[i] < a[l])
        largest = l;
    if(r < size && a[largest] < a[r])
        largest = r;
    if(largest != i) {
        swap(a[i], a[largest]);
        max_heapify(a, largest, size);
    }
}

void build_max_heap(vector<int>& a) {
    int n = a.size();
    for(int i = n/2-1; i >= 0; i--)
        max_heapify(a, i, n);
} 

void min_heapify(vector<int>& a, int i, int size) {
    if(i >= size)
        return;
    int l = 2*i+1;
    int r = 2*i+2;
    int smallest = i;
    if(l < size && a[i] > a[l])
        smallest = l;
    if(r < size && a[smallest] > a[r])
        smallest = r;
    if(smallest != i) {
        swap(a[i], a[smallest]);
        min_heapify(a, smallest, size);
    }    
}

void build_min_heap(vector<int>& a) {
    int n = a.size();
    for(int i = n/2-1; i >= 0; i--)
        min_heapify(a, i, n);    
} 

void push_max_heap(vector<int>& a, int val, int size) {
    a.push_back(val);
    int i = size;
    int p = parent(i);
    while(p >= 0) {
        if(a[p] < a[i]) {
            swap(a[p], a[i]);
            i = p;
            p = parent(p);
        } else 
            break;
    }
}

void push_min_heap(vector<int>& a, int val, int size) {
    a.push_back(val);
    int i = size;
    int p = parent(i);
    while(p >= 0) {
        if(a[p] > a[i]) {
            swap(a[p], a[i]);
            i = p;
            p = parent(p);
        } else 
            break;
    }
}

void delete_max_heap(vector<int>& a, int size) {
    swap(a[0], a[size-1]);
    max_heapify(a, 0, size-1);
}

void delete_min_heap(vector<int>& a, int size) {
    swap(a[0], a[size-1]);
    min_heapify(a, 0, size-1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& val: a)
        cin >> val;
    build_max_heap(a);
    
    cout << "************************************\n";
    for(int& val: a)
        cout << val << " ";
    cout << "\n";

    // push_max_heap(a, 6, a.size());
    // cout << "************************************\n";
    // for(int& val: a)
    //     cout << val << " ";
    // cout << "\n";   
    for(int i=0; i< n; i++)
        delete_max_heap(a, n-i);
    cout << "************************************\n";
    for(int& val: a)
        cout << val << " ";
    cout << "\n";     
}

int32_t main() {
    tool();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}