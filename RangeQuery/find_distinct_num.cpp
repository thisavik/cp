#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e8+1;
const int BLK = 555;
int n;
int input[maxN];
int fre[maxN] = {0};
struct query
{
	int x, y, i;
};

query Qry[maxN];
int cnt = 0;

void addIdx(int i)
{
    fre[input[i]]++;
    if(fre[input[i]] == 1)
        cnt++;
}

void removeIdx(int i)
{
    fre[input[i]]--;
    if(fre[input[i]] == 0)
        cnt--;
}

int32_t main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> input[i];
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
		cin >> Qry[i].x >> Qry[i].y, Qry[i].i = i;
	sort(Qry, Qry+q, [](query q1, query q2) {
		if(q1.x/BLK != q2.x/BLK)
			return q1.x/BLK < q2.x/BLK;
		return q1.y < q2.y;
	});
	int ans[q];
	int ML = 0, MR = -1;
	for(int i = 0; i < q; i++)
	{
	    int l = --Qry[i].x;
	    int r = --Qry[i].y;
	    int idx = Qry[i].i;
	    
	    // extending range
	    while(MR < r) MR++, addIdx(MR);
	    while(ML > l) ML--, addIdx(ML);
	    
	    // reducing range
	    while(MR > r) removeIdx(MR), MR--;
	    while(ML < l) removeIdx(ML), ML++;
	    
	    ans[idx] = cnt;
	}
	for(int i = 0; i < q; i++)
	    cout << ans[i] << "\n";
}
