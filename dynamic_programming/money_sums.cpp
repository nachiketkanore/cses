/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 30 September 2021 02:34:13 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

int32_t main() {
	int N; cin >> N;
	const int MX = 1e5;
	bool dp[MX+1]; memset(dp, false, sizeof(dp));
	dp[0] = true;
	FOR (i,1,N) {
		int val;
		cin >> val;

		bool ndp[MX+1]; memset(ndp, false, sizeof(ndp));
		ndp[0] = true;

		FOR (j,1,MX) {
			if (j >= val) ndp[j] |= dp[j - val];
			ndp[j] |= dp[j];
		}

		F0R (j,MX+1) dp[j] = ndp[j];
	}
	vector<int> ans;
	FOR (j,1,MX) if (dp[j]) ans.push_back(j);
	cout << sz(ans) << '\n';
	for (int x: ans) {
		cout << x << ' ';
	}
}
