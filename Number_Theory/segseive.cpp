// used to find primes in range of long long integer

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

#define int long long 

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("C://git//cp//input.txt", "r", stdin);
        freopen("C://git//cp//output.txt", "w", stdout);
    #endif
}

vector<int>* seive(int n) {

    bool isprime[n+1];
    memset(isprime, true, sizeof(isprime));

    for (int i = 2; i*i <= n; i++) {
        for (int j = i*i; j <= n; j += i) {
            if (isprime[j])
                isprime[j]=false;
        }
    }

    vector<int>* primes = new vector<int>();
    for (int i=2; i<=n; i++) {
        if (isprime[i])
            primes->push_back(i);
    }

    return primes;
}

vector<int>* prime_in_range(int l, int r) {

    vector<int>* primes = seive(2*(floor(sqrt(r)+1)));
    // l -> 0, l+1 -> 1, ...., r-1 -> r-l-1, r -> r-l, r+1 -> r-l+1
    bool isprime[r-l+1];
    memset(isprime, true, sizeof(isprime));

    for (int i=0; primes->at(i)*primes->at(i) < r; i++) {
        int cur = primes->at(i);
        int base = (l/cur)*cur;
        if (base < l) {
            base += cur;
        }
        for (int j = base; j <= r; j += cur) {
            isprime[j-l]=false;
        }
        if (base == cur) {
            isprime[base-l] = true;
        }
    }

    vector<int>* result = new vector<int>();
    for (int i = 0; i < r-l+1; i++) {
        if (isprime[i])
            result->push_back(l+i);
    }

    return result;
}

int32_t main() {
    tool();
    cout<<"Enter lower and upper bound : ";
    int l, r;
    cin >> l >> r;
    vector<int>* primes = prime_in_range(l, r);
    for (int i = 0; i < primes->size(); i++) {
        cout << primes->at(i)<< " ";
    }
}
