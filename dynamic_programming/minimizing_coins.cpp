/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 29 September 2021 01:02:31 AM IST
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

const int INF = 1e18;
int N, T, A[102];
int dp[1000005];

int go(int rem) {
	if (rem < 0) return INF;
	if (rem == 0) return 0;
	int &ans = dp[rem];
	if (~ans) return ans;
	ans = INF;
	FOR (i,1,N) cmin(ans, 1 + go(rem - A[i]));
	return ans;
}

int32_t main() {
	cin >> N >> T;
	FOR (i,1,N) cin >> A[i];
	memset(dp, -1, sizeof(dp));
	int ans = go(T);
	if (ans >= INF) ans = -1;
	cout << ans << '\n';
}
