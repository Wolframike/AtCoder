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
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
	for (const auto& v : vec)
		os << v << " ";
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& vec) {
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		os << *it;
		if (it + 1 != vec.end())
			os << "\n";
	}
	return os;
}
#define debug(x) cerr << #x << ":\n" << x << endl
#define vin(v) for(auto& x : v) cin >> x
#define vvin(v) for(auto& x : v) vin(x)
#define sfor(i, n) for(int i = 0; i < n; i++)
#define sforr(i, n) for(int i = n - 1; i >= 0; i--)
#define foreach(x, v) for(auto& x : v)
#define foreachperm(v) for(bool run = true; run; run = std::next_permutation(v.begin(), v.end()))
#define ssort(v) sort(v.begin(), v.end())
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define getindex(v, x) (find(v.begin(), v.end(), x) - v.begin())
#define popcount __builtin_popcount
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

signed main(void) {fast
	int N;
	cin >> N;

	N *= 2;
	N++;

	sfor(i, N)
		cout << ((i % 2) == 0 ? 1 : 0);
	cout << endl;

	return 0;
}
