#include <atcoder/dsu>
#include <atcoder/scc>
#include <atcoder/modint>
#include <bits/stdc++.h>

using namespace atcoder;
using namespace std;

#define int long long
#define inf 1e18
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
class dp_maximize: public vector<int> {
	public:
		explicit dp_maximize(size_t n) : vector<int>(n, -inf) {
			if (n > 0)
				at(0) = 0;
		}
};
class dp_minimize: public vector<int> {
	public:
		explicit dp_minimize(size_t n) : vector<int>(n, inf) {
			if (n > 0)
				at(0) = 0;
		}
};

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
	for (const auto& v : vec)
		os << v << " ";
	return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& vec) {
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		os << *it;
		if (it + 1 != vec.end())
			os << "\n";
	}
	return os;
}
#define debug(x) cerr << #x << ":\n" << x << endl
#define iin1(N) int N; cin >> N
#define iin2(N1, N2) int N1, N2; cin >> N1 >> N2
#define iin3(N1, N2, N3) int N1, N2, N3; cin >> N1 >> N2 >> N3
#define iin4(N1, N2, N3, N4) int N1, N2, N3, N4; cin >> N1 >> N2 >> N3 >> N4
#define iin(...) iin_GET(__VA_ARGS__, iin4, iin3, iin2, iin1)(__VA_ARGS__)
#define iin_GET(_1, _2, _3, _4, NAME, ...) NAME
#define sin(S) string S; cin >> S
#define vin(V, N) vector<int> V(N); for(auto& x : V) cin >> x
#define vvin(V, H, W) vector<vector<int>> V(H, vector<int>(W)); for(auto& x : V) for(auto& y : x) cin >> y
#define pin(P) pair<int, int> P; cin >> P.first >> P.second
#define vpin(V, N) vector<pair<int, int>> V(N); for(auto& x : V) cin >> x.first >> x.second

#define sfor(i, n) for(int i = 0; i < n; i++)
#define sforr(i, n) for(int i = n - 1; i >= 0; i--)
#define foreach(x, v) for(auto& x : v)
#define foreachperm(v) for(bool run = true; run; run = next_permutation(v.begin(), v.end()))
#define ssort(v) sort(v.begin(), v.end())
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define getindex(v, x) (find(v.begin(), v.end(), x) - v.begin())
#define maxof(v) (*max_element(v.begin(), v.end()))
#define minof(v) (*min_element(v.begin(), v.end()))
#define maxon(v) (max_element(v.begin(), v.end()) - v.begin())
#define minon(v) (min_element(v.begin(), v.end()) - v.begin())
#define popcount __builtin_popcount
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

signed main(void) {fast
	iin(N, X);
	vin(S, N);
	int p = 0;
	foreach(s, S)
		if (s <= X)
			p += s;
	cout << p << endl;

	return 0;
}
