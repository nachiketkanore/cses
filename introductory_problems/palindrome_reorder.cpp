/**
 *    Author: Nachiket Kanore
 *    Created: Friday 03 September 2021 02:39:23 PM IST
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
	vector<int> f(26);
	int mask = 0;
	for (char ch : S) {
		f[ch-'A']++;
		mask ^= 1 << (ch-'A');
	}
	if (__builtin_popcount(mask) <= 1) {
		string mid;
		F0R (ch,26) if (f[ch]&1) {
			mid = string(f[ch], (char)('A' + ch));
			f[ch] = 0;
		}
		string left, right;
		F0R (ch,26) {
			assert(f[ch] % 2 == 0);
			FOR (i,1,f[ch]) {
				if (i & 1) left += (char)('A' + ch);
				else right += (char)('A' + ch);
			}
		}
		reverse(ALL(left));
		cout << (left + mid + right) << '\n';
	} else {
		cout << "NO SOLUTION\n";
	}
}
