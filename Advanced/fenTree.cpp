#include <iostream>
#include <vector>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

struct fenwickTree {
	vector<int> BIT;
	// constructor for intialiser
	fenwickTree(vector<int>& v){
		BIT.resize(v.size()+1, 0);
		for(int i=1; i<=v.size(); i++){
			update(v[i-1], i);
		}
	}
	// used when any range query fired
	int getParent(int idx){
		return idx - (idx & (-idx));
	}
	// used while updation of BIT 
	int getNext(int idx){
		return idx + (idx & (-idx));
	}
	// prefix sum range query
	int getSum(int idx){
		int sum = 0;
		idx += 1;
		while(idx > 0){
			sum += BIT[idx];
			idx = getParent(idx);
		}
		return sum;
	}
	// update BIT when original array is updated
	void update(int val, int idx){
		while(idx < BIT.size()){
			BIT[idx] += val;
			idx = getNext(idx);
		}
	}
};

int32_t main() {
	tool();
	vector<int> v {1, 2, 3, 4, 5, 6, 7};
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
	fenwickTree f(v);
	for(int i = 0; i < f.BIT.size(); i++)
		cout << f.BIT[i] << " ";
	cout << "\n";
	cout << f.getSum(5) << "\n";
	cout << f.getSum(4) - f.getSum(1) << endl;
	return 0;
}