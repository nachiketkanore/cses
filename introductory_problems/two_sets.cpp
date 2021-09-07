/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 07 September 2021 12:57:29 PM IST
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
	int sum = N * (N + 1) / 2;
	if (sum % 2 == 1) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	sum >>= 1;
	vector<int> one, two;
	for (int val = N; val >= 1; --val) {
		if (sum - val >= 0) {
			sum -= val;
			one.push_back(val);
		} else {
			two.push_back(val);
		}
	}
	cout << sz(one) << '\n';
	for (int x : one) cout << x << ' '; cout << '\n';
	cout << sz(two) << '\n';
	for (int x : two) cout << x << ' '; cout << '\n';
}
