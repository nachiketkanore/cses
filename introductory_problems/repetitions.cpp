/**
 *    Author: Nachiket Kanore
 *    Created: Friday 03 September 2021 01:44:19 PM IST
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

int32_t main() {
	string S;
	cin >> S;
	const int N = S.size();
	int ans = 0;
	for (int i = 0; i < N; ) {
		int j = i, len = 0;
		while (j < N && S[j] == S[i]) ++j, ++len;
		cmax(ans, len);
		i = j;
	}
	cout << ans << '\n';
}
