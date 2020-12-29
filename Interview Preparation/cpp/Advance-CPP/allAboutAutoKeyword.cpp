#include <iostream>
#include <vector>
using namespace std;

// void HelloWorld() {
//   cout << "hello" << "\n";
// }
void HelloWorld(int a) {
  cout << "hello" << a << "\n";
}


int main()
{

  // auto num = 10;
  // cout << num << "\n";

  // num = 5;

  // auto name = "an";
  // cout << name;


  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  for(auto num: v)
    cout << num << " ";
  cout << "\n";
  auto func = HelloWorld;
  func(7);


  // return type of a function pointer void(*function_name_whatever_we_want)()
  // void(*function)() = HelloWorld;
  // function();


  typedef void(*HelloWorldFunction)(int);

  HelloWorldFunction f = HelloWorld;
  f(4);
}