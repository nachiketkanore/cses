/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 21 October 2021 12:51:27 PM IST
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

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, T b) { return a < b ? a = b, 1 : 0; } 

const int INF = 1e9;

/* int dp[501][501]; */

/* int go(int A, int B) { */
/* 	if (A == B) return 0; */
/* 	int &ans = dp[A][B]; */
/* 	if (~ans) return ans; */
/* 	ans = INF; */
/* 	FOR (a, 1, A-1) { ans = min(ans, 1 + go(a, B) + go(A - a, B)); if (ans == 1) break; } */
/* 	FOR (b, 1, B-1) { ans = min(ans, 1 + go(A, b) + go(A, B - b)); if (ans == 1) break; } */
/* 	return ans; */
/* } */

int32_t main() {
	int A, B;
	cin >> A >> B;
	int dp[A+1][B+1];
	FOR (i,1,A) {
		FOR (j,1,B) {
			if (i == j) dp[i][j] = 0;
			else {
				dp[i][j] = INF;
				FOR (k, 1, i-1) cmin(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
				FOR (k, 1, j-1) cmin(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
			}
		}
	}
	cout << dp[A][B];
}
