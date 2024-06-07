#include <atcoder/dsu>
#include <atcoder/scc>
#include <atcoder/modint>
#include <bits/stdc++.h>

using namespace atcoder;
using namespace std;

#define int long long
#define uint unsigned long long
#define double long double
constexpr int inf = 1e18;
constexpr double zero = 1e-9;
using modint1_7 = modint1000000007;
using modint9_3 = modint998244353;
using xint = __int128_t;
using xuint = __uint128_t;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
class dp_template : public vector<int> {
	protected:
		vector<pair<int, int>> weight_cost;
		int threshold;
		explicit dp_template(int N) : vector<int>(), threshold(N) {}
	public:
		void additem(int weight, int cost) {
			weight_cost.push_back({weight, cost});
		}
};

class dp_maximize : public dp_template {
	public:
		explicit dp_maximize(int N) : dp_template(N) {}
		int solve() {
			const int maxweight = max_element(weight_cost.begin(), weight_cost.end())->first;
			resize(threshold + maxweight + 1, -inf);
			at(0) = 0;
			for (int i = 0; i <= threshold; i++) {
				if (at(i) == -inf)
					continue;
				for (auto [w, v] : weight_cost) {
					if (i + w <= threshold + maxweight) {
						at(i + w) = max(at(i + w), at(i) + v);
					}
				}
			}
			return *max_element(begin() + threshold, end());
		}
};

class dp_minimize : public dp_template { 
	public:
		explicit dp_minimize(int N) : dp_template(N) {}
		int solve() {
			const int maxweight = max_element(weight_cost.begin(), weight_cost.end())->first;
			resize(threshold + maxweight + 1, inf);
			at(0) = 0;

			for (int i = 0; i <= threshold; i++) {
				if (at(i) == inf)
					continue;
				for (auto [w, v] : weight_cost) {
					if (i + w <= threshold + maxweight) {
						at(i + w) = min(at(i + w), at(i) + v);
					}
				}
			}
			return *min_element(begin() + threshold, end());
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
#define forall(v) (v).begin(), (v).end()
#define maxof(v) (*max_element(v.begin(), v.end()))
#define minof(v) (*min_element(v.begin(), v.end()))
#define maxon(v) (max_element(v.begin(), v.end()) - v.begin())
#define minon(v) (min_element(v.begin(), v.end()) - v.begin())
#define popcount __builtin_popcount
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

signed main(void) {fast
	iin(N, M);
	sin(S);
	sin(T);

	bool pref, suf;

	pref = T.substr(0, N) == S;
	suf = T.substr(M - N, N) == S;

	if (pref && suf) cout << 0 << endl;
	if (pref && !suf) cout << 1 << endl;
	if (!pref && suf) cout << 2 << endl;
	if (!pref && !suf) cout << 3 << endl;

	return 0;
}
