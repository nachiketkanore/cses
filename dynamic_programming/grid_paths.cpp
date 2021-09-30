/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 30 September 2021 01:04:14 PM IST
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

int32_t main() {
	int N;
	cin >> N;
	int dp[N+1][N+1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = dp[0][1] = 1;
	FOR (i,1,N) {
		FOR (j,1,N) {
			char ch;
			cin >> ch;
			if (ch == '.')
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			else 
				dp[i][j] = 0;
			if (dp[i][j] >= MOD)
				dp[i][j] -= MOD;
		}
	}
	cout << dp[N][N];
}
