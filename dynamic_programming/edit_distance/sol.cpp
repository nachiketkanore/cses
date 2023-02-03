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

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

string S, T;
int N, M;

int go(int i, int j, string s, string t, int cost) {
	if (i == N) {
		// TODO
		// T is still not complete
		// option 1: append remaining chars to S
		// option 2: delete remaining chars from T
		// both require same number of operations
		cost += M - j;
		if (cost == 1) {
			see(s);
			see(t);
		}
		return M - j;
	}
	if (j == M) {
		// TODO
		// same procedure as above
		cost += N - i;
		if (cost == 1) {
			see(s);
			see(t);
		}
		return N - i;
	}
	int ans = 1e9;

	if (S[i] == T[j]) {
		ans = min(ans, go(i + 1, j + 1, s + S[i], t + T[j], cost));
	}
	{
		// replace one of them to same
		ans = min(ans, 1 + go(i + 1, j + 1, s + T[j], t + T[j], cost + 1));
		// insert T[j] at i
		ans = min(ans, 1 + go(i, j + 1, s + T[j], t + T[j], cost + 1));
		// insert S[i] at j
		ans = min(ans, 1 + go(i + 1, j, s + S[i], t + S[i], cost + 1));
		// remove both
		ans = min(ans, 2 + go(i + 1, j + 1, s, t, cost + 2));
		// remove S[i]
		ans = min(ans, 1 + go(i + 1, j, s, t, cost + 1));
		// remove T[j]
		ans = min(ans, 1 + go(i, j + 1, s, t, cost + 1));
	}
	// see(i, j, ans);
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> S >> T;
	N = S.size(), M = T.size();

	// writing a top-down solution first
	cout << go(0, 0, "", "", 0) << '\n';

	return 0;
}
