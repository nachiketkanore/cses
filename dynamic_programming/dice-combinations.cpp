/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 29 September 2021 12:59:19 AM IST
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

const int MOD = 1e9 + 7;
int dp[1000005];

int go(int N) {
	if (N <= 0) return N == 0;
	int &ans = dp[N];
	if (~ans) return ans;
	ans = 0;
	FOR (take,1,6) {
		ans += go(N - take);
		if (ans >= MOD)
			ans -= MOD;
	}
	return ans;
}

int32_t main() {
	memset(dp, -1, sizeof(dp));
	int N;
	cin >> N;
	cout << go(N) << '\n';
}
