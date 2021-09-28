/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 29 September 2021 01:09:34 AM IST
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

const int N = 1e6 + 1, mod = 1e9 + 7;
 
int n, x, a[100];
int dp[N];
 
int go(int rem) {
	if (rem <= 0) return rem == 0;
	int &ans = dp[rem];
	if (~ans) return ans;
	ans = 0;
	for (int i = 0; i < n; i++) {
		ans = (ans + go(rem - a[i])) % mod;
	}
	return ans;
}
 
int32_t main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	memset(dp, -1, sizeof(dp));
	int ans = go(x);
	cout << ans;
}
