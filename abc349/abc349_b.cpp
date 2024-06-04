#include <atcoder/dsu>
#include <atcoder/scc>
#include <atcoder/modint>
#include <bits/stdc++.h>

using namespace atcoder;
using namespace std;

#define int long long
using vi = vector<int>;
using vvi = vector<vector<int>>;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
	for (const auto& v : vec) {
		os << v << (v == vec.back() ? "" : " ");
	}
	return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& vec) {
	for (const auto& v : vec) {
		os << v << (v == vec.back() ? "" : "\n");
	}
	return os;
}
#define debug(x) cerr << #x << ":\n" << x << endl
#define vin(v) for(auto& x : v) cin >> x
#define vvin(v) for(auto& x : v) vin(x)
#define sfor(i, n) for(int i = 0; i < n; i++)
#define sforr(i, n) for(int i = n - 1; i >= 0; i--)
#define ssort(v) sort(v.begin(), v.end())
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define popcount __builtin_popcount
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

signed main(void) {fast
	string S;
	cin >> S;

	vi c(26, 0);

	for (char s: S)
		c[s - 'a']++;

	vi n(101, 0);
	for (int i: c)
		n[i]++;
	
	sfor(i, 100) {
		if (n[i + 1] == 2 || n[i + 1] == 0)
			continue;
		else {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	return 0;
}
