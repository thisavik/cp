#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int>* seive(int n) {
    bool isprime[n];
    memset(isprime, true, sizeof(isprime));
    for (int i = 2; i*i <= n; i++) {
        for (int j = i*i; j <= n; j += i) {
            if (isprime[j])
                isprime[j]=false;
        }
    }
    vector<int>* primes = new vector<int>();
    for (int i = 2; i <= n; i++) {
        if (isprime[i])
            primes->push_back(i);
    }
    return primes;
}

int main() {
    cout<<"Enter number : ";
    int n;
    cin>>n;
    vector<int>* primes = seive(n);
    for (int i = 0; i < primes->size(); i++) {
        cout << primes->at(i) << " ";
    }
}
