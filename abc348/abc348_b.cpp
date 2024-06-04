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
	int N;
	cin >> N;

	vector<pair<int, int>> P(N);

	sfor(i, N)
		cin >> P[i].first >> P[i].second;
	
	int index;
	double d, dmax;
	sfor(i, N) {
		dmax = 0;
		index = 0;
		sfor(j, N) {
			if (i == j)
				continue;
			d = sqrt(pow(P[i].first - P[j].first, 2) + pow(P[i].second - P[j].second, 2));
			if (d > dmax) {
				dmax = d;
				index = j;
			}
		}
		cout << index + 1 << endl;
	}

	return 0;
}
