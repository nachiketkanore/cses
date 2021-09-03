/**
 *    Author: Nachiket Kanore
 *    Created: Friday 03 September 2021 01:47:09 PM IST
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
	int N;
	cin >> N;
	int prev, ans = 0;
	cin >> prev;
	FOR (i,2,N) {
		int now;
		cin >> now;
		if (now >= prev) {
			prev = now;
			continue;
		} else {
			ans += prev - now;
		}
	}
	cout << ans << '\n';
}
