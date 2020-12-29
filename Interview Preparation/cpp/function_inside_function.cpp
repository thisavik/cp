#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    auto print_message = [](string message) {
        // printf("%s\n", message.c_str());
        // cout << message << "\n";
        cout << message.c_str() << "\n";
    };
    for(int i = 0; i < 5; i++)
        print_message("Hello!!!");
    return 0;
}