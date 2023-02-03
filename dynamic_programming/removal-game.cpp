/**
 *    Author: Nachiket Kanore
 *    Created: Friday 03 February 2023 11:35:04 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int _ = 5000, INF = 1e18;
int N, A[_], dp[_][_];
bool vis[_][_];

int go(int L, int R) {
	if (L > R)
		return 0;
	if (vis[L][R])
		return dp[L][R];
	vis[L][R] = true;
	int ans = -INF;

	int his1 = go(L + 2, R), his2 = go(L + 1, R - 1);
	int c1 = A[L] + min(his1, his2);
	ans = max(ans, c1);

	his1 = go(L + 1, R - 1), his2 = go(L, R - 2);
	int c2 = A[R] + min(his1, his2);
	ans = max(ans, c2);

	dp[L][R] = ans;

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	F0R(i, N) cin >> A[i];
	cout << go(0, N - 1);

	return 0;
}
