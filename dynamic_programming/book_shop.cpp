/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 30 September 2021 01:11:14 PM IST
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

int32_t main() {
	int N, T;
	cin >> N >> T;
	int cost[N], weight[N];
	F0R (i,N) cin >> cost[i];
	F0R (i,N) cin >> weight[i];
	int dp[T+1];
	memset(dp, 0, sizeof(dp));
	F0R (i,N) {
		int ndp[T+1];
		memset(ndp, 0, sizeof(ndp));
		F0R (j,T+1) {
			if (j >= cost[i]) cmax(ndp[j], dp[j - cost[i]] + weight[i]);
			cmax(ndp[j], dp[j]);
		}
		F0R (j,T+1) dp[j] = ndp[j];
	}
	cout << *max_element(dp, dp + T + 1) << '\n';
}
