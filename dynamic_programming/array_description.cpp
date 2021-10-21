/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 21 October 2021 12:31:38 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <cstring>
#include <functional>

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
int dp[100000][105];

int32_t main() {
	int N, M; cin >> N >> M;
	vector<int> A(N); F0R (i,N) cin >> A[i];
	memset(dp, -1, sizeof(dp));
	function<int(int,int)> go = [&](int id, int last) {
		assert(1 <= last && last <= M);
		if (id == N) return int(1);
		int &ans = dp[id][last];
		if (~ans) return ans;
		ans = 0;
		if (A[id] == 0) {
			FOR (val, last - 1, last + 1) {
				if (1 <= val && val <= M) {
					ans += go(id + 1, val);
					ans %= MOD;
				}
			}
		} else {
			if (abs(last - A[id]) <= 1) {
				ans += go(id + 1, A[id]);
				ans %= MOD;
			}
		}
		ans %= MOD;
		return ans;
	};
	int ans = 0;
	if (A[0] == 0) {
		FOR (last,1,M) { ans += go(1, last); ans %= MOD; }
	} else {
		ans = go(1, A[0]);
	}
	cout << ans << '\n';
}
