/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 30 September 2021 01:22:29 PM IST
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

string S;
int dp[20][2][11][2];

int go(int id, bool smt, int last, bool st) {
	if (id == sz(S)) return 1;
	int &ans = dp[id][smt][last][st];
	if (~ans) return ans;
	ans = 0;
	int curr = S[id]-'0';
	FOR (dig, 0, smt? 9: curr) {
		if (dig > 0 || st) {
			if (dig ^ last)
				ans += go(id + 1, smt || (dig < curr), dig, st || (dig > 0));
		} else {
			ans += go(id + 1, smt || (dig < curr), last, st || (dig > 0));
		}
	}
	return ans;
}

int solve(int N) {
	if (N < 0) return 0;
	S.clear();
	while (N) {
		S += (char)((N % 10) + '0');
		N /= 10;
	}
	if (S.empty()) S = "0";
	reverse(S.begin(), S.end());
	memset(dp, -1, sizeof(dp));
	return go(0, 0, 10, 0);
}

int32_t main() {
	int A, B;
	cin >> A >> B;
	cout << solve(B) - solve(A - 1) << '\n';
}
