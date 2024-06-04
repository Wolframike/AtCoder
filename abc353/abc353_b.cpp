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
#define debug(x) cerr << #x << ":\n" << x << endl;
#define vin(v) for(auto& x : v) cin >> x;
#define vvin(v) for(auto& x : v) vin(x);
#define sfor(i, n) for(int i = 0; i < n; i++)
#define sforr(i, n) for(int i = n - 1; i >= 0; i--)
#define popcount __builtin_popcount
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

signed main(void) {fast
	int N, K;
	cin >> N >> K;

	vi A(N);
	vin(A);

	int psngr = 0, cart = 0, cap;
	while (psngr != N) {
		cap = K;
		while (psngr != N && cap >= A[psngr])
			cap -= A[psngr++];
		cart++;
	}

	cout << cart << endl;

	return 0;
}
