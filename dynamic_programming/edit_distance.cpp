/**
 *    Author: Nachiket Kanore
 *    Created: Friday 03 February 2023 06:15:35 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

string S, T;
int N, M;
int dp[5001][5001];

int go(int i, int j) {
	if (i == N) {
		// T is still not complete
		// option 1: append remaining chars to S
		// option 2: delete remaining chars from T
		// both require same number of operations
		return M - j;
	}
	if (j == M) {
		// same procedure as above
		return N - i;
	}
	int& ans = dp[i][j];
	if (~ans)
		return ans;
	ans = 1e9;

	if (S[i] == T[j]) {
		ans = min(ans, go(i + 1, j + 1));
	}
	{
		// Handling all cases and ignoring repetitive calls
		// replace one of them to same
		ans = min(ans, 1 + go(i + 1, j + 1));
		// insert T[j] at i
		ans = min(ans, 1 + go(i, j + 1));
		// insert S[i] at j
		ans = min(ans, 1 + go(i + 1, j));
		// remove both -- can also be ignore? Yes, great!
		// ans = min(ans, 2 + go(i + 1, j + 1));
		// remove S[i] -- same call as above, hence ignoring
		// ans = min(ans, 1 + go(i + 1, j));
		// remove T[j] -- same call as above, hence ignoring
		// ans = min(ans, 1 + go(i, j + 1));
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> S >> T;
	N = S.size(), M = T.size();

	// writing a top-down solution first
	// -- it works, so not going to write iterative
	// :)
	cout << go(0, 0);

	return 0;
}
