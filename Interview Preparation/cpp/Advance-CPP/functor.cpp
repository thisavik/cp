#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// functor
struct isOdd{
  bool operator()(int x) {
    return x&1;
  }
};

// normal function
bool isEven(int x) {
  return !(x&1);
}
bool isEqual(int a, int b) {
  return a==b;
}

int main() {
  // isOdd isOdd;
  // cout << boolalpha;
  // cout << isOdd(3) << "\n";
  // cout << isOdd(4) << "\n";
  // cout << isEqual(4, 6) << "\n";
  // cout << isEqual(3, 3) << "\n";

  vector<int> v {1,2,3,4,5,6,7,8,9};

  // way how functor get invoked  
  cout << "Odd value count using function : " << count_if(v.begin(), v.end(), isOdd()) << "\n";

  // way how function passed as parameter
  cout << "Even value count using functor : " << count_if(v.begin(), v.end(), isEven) << "\n";

  // Lambda is shorthand syntax of functor
  cout << "Odd value count using lambda : " << count_if(v.begin(), v.end(), [](int a) {
    return a&1;
  });
}