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

	vector<vector<char>> A(N, vector<char>(N)), B(N, vector<char>(N));

	sfor(i, N)
		sfor(j, N)
			cin >> A[i][j];

	sfor(i, N)
		sfor(j, N)
			cin >> B[i][j];

	sfor(i, N)
		sfor(j, N)
			if (A[i][j] != B[i][j]) {
				cout << i + 1 << " " << j + 1 << endl;
				return 0;
			}

	return 0;
}
