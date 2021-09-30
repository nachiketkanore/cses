/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 30 September 2021 03:11:07 PM IST
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

struct seg {
	int L, R, cost;
	bool operator < (const seg other) const {
		return R < other.R;
	}
};

int32_t main() {
	int N, ans(0); cin >> N;
	int dp[N]; F0R (i,N) dp[i] = 0;
	vector<seg> A(N);
	F0R (i,N) { cin >> A[i].L >> A[i].R >> A[i].cost; }
	sort(ALL(A));
	F0R (i,N) {
		if (i) cmax(dp[i], dp[i-1]);
		cmax(dp[i], A[i].cost);
		int j = -1;
		int lo = 0, hi = i-1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (A[mid].R < A[i].L) {
				j = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (~j) cmax(dp[i], dp[j] + A[i].cost);
		cmax(ans, dp[i]);
	}
	cout << ans << '\n';
}
