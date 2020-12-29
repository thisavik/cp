#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void tool() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
}

struct string_pair
{
    int n,vowel;
    string str;
};

void init();
string_pair aray[101];

int solve(int n, int sum) 
{ 
    int a[n];
    for(int i = 0; i < n; i++)
        a[i] = i+1;
    unordered_set<int> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s.find(sum - a[i]) != s.end() && sum != 2*a[i])
            cnt++;  
        s.insert(a[i]); 
    }
    return cnt;
} 

int32_t main() {
    tool();
    init();
    unordered_map<int, int> mp;
    mp[0] = 0;
    mp[1] = 2;
    mp[2] = 1;
    mp[3] = 2;
    mp[4] = 2;
    mp[5] = 2;
    mp[6] = 1;
    mp[7] = 2;
    mp[8] = 2;
    mp[9] = 2;
    mp[10] = 1;
    mp[11] = 3;
    mp[12] = 2;
    mp[13] = 3;
    mp[14] = 4;
    mp[15] = 3;
    mp[16] = 3;
    mp[17] = 4;
    mp[18] = 3;
    mp[19] = 3;
    mp[20] = 1;
    mp[30] = 1;
    mp[40] = 1;
    mp[50] = 1;
    mp[60] = 1;
    mp[70] = 2;
    mp[80] = 2;
    mp[90] = 2;
    mp[100] = 2;
    int n, k = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x < 20) {
            k += mp[x];
            continue;
        }
        int ones = x % 10; x /= 10;
        int tens = x % 10; x /= 10;
        int hun = x % 10;
        k += (mp[ones] + mp[tens*10] + mp[hun*100]);
    }
    int ans = solve(n, k);
    if(ans > 100)
        cout << "greater 100";
    else
        cout << aray[ans].str;
}


void init()
{
    aray[0].str="zero" ;
    aray[1].str="one" ;
    aray[2].str="two" ;
    aray[3].str="three" ;
    aray[4].str="four" ;
    aray[5].str="five" ;
    aray[6].str="six" ;
    aray[7].str="seven" ;
    aray[8].str="eight" ;
    aray[9].str="nine" ;
    aray[10].str="ten" ;
    aray[11].str="eleven" ;
    aray[12].str="twelve" ;
    aray[13].str="thirteen" ;
    aray[14].str="fourteen" ;
    aray[15].str="fifteen" ;
    aray[16].str="sixteen" ;
    aray[17].str="seventeen" ;
    aray[18].str="eighteen" ;
    aray[19].str="nineteen" ;
    aray[20].str="twenty" ;
    aray[21].str="twenty-one" ;
    aray[22].str="twenty-two" ;
    aray[23].str="twenty-three" ;
    aray[24].str="twenty-four" ;
    aray[25].str="twenty-five" ;
    aray[26].str="twenty-six" ;
    aray[27].str="twenty-seven" ;
    aray[28].str="twenty-eight" ;
    aray[29].str="twenty-nine" ;
    aray[30].str="thirty" ;
    aray[31].str="thirty-one" ;
    aray[32].str="thirty-two" ;
    aray[33].str="thirty-three" ;
    aray[34].str="thirty-four" ;
    aray[35].str="thirty-five" ;
    aray[36].str="thirty-six" ;
    aray[37].str="thirty-seven" ;
    aray[38].str="thirty-eight" ;
    aray[39].str="thirty-nine" ;
    aray[40].str="forty" ;
    aray[41].str="forty-one" ;
    aray[42].str="forty-two" ;
    aray[43].str="forty-three" ;
    aray[44].str="forty-four" ;
    aray[45].str="forty-five" ;
    aray[46].str="forty-six" ;
    aray[47].str="forty-seven" ;
    aray[48].str="forty-eight" ;
    aray[49].str="forty-nine" ;
    aray[50].str="fifty" ;
    aray[51].str="fifty-one" ;
    aray[52].str="fifty-two" ;
    aray[53].str="fifty-three" ;
    aray[54].str="fifty-four" ;
    aray[55].str="fifty-five" ;
    aray[56].str="fifty-six" ;
    aray[57].str="fifty-seven" ;
    aray[58].str="fifty-eight" ;
    aray[59].str="fifty-nine" ;
    aray[60].str="sixty" ;
    aray[61].str="sixty-one" ;
    aray[62].str="sixty-two" ;
    aray[63].str="sixty-three" ;
    aray[64].str="sixty-four" ;
    aray[65].str="sixty-five" ;
    aray[66].str="sixty-six" ;
    aray[67].str="sixty-seven" ;
    aray[68].str="sixty-eight" ;
    aray[69].str="sixty-nine" ;
    aray[70].str="seventy" ;
    aray[71].str="seventy-one" ;
    aray[72].str="seventy-two" ;
    aray[73].str="seventy-three" ;
    aray[74].str="seventy-four" ;
    aray[75].str="seventy-five" ;
    aray[76].str="seventy-six" ;
    aray[77].str="seventy-seven" ;
    aray[78].str="seventy-eight" ;
    aray[79].str="seventy-nine" ;
    aray[80].str="eighty" ;
    aray[81].str="eighty-one" ;
    aray[82].str="eighty-two" ;
    aray[83].str="eighty-three" ;
    aray[84].str="eighty-four" ;
    aray[85].str="eighty-five" ;
    aray[86].str="eighty-six" ;
    aray[87].str="eighty-seven" ;
    aray[88].str="eighty-eight" ;
    aray[89].str="eighty-nine" ;
    aray[90].str="ninety" ;
    aray[91].str="ninety-one" ;
    aray[92].str="ninety-two" ;
    aray[93].str="ninety-three" ;
    aray[94].str="ninety-four" ;
    aray[95].str="ninety-five" ;
    aray[96].str="ninety-six" ;
    aray[97].str="ninety-seven" ;
    aray[98].str="ninety-eight" ;
    aray[99].str="ninety-nine" ;
    aray[100].str="hundred" ;
}
