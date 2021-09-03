/**
 *    Author: Nachiket Kanore
 *    Created: Friday 03 September 2021 02:09:28 PM IST
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

	/* http://oeis.org/A172132 */
	/* a(n) = (n - 1)(n + 4)(n^2 - 3n + 4)/2 */
	int N;
	cin >> N;
	FOR (i,1,N) {
		cout << (i - 1) * (i + 4) * (i * i - 3 * i + 4) / 2 << '\n';
	}
}
