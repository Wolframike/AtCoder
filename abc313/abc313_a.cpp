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
class dp_minimize : public vector<int> {
	protected:
		vector<pair<int, int>> weight_cost;
		int threshold;
	public:
		explicit dp_minimize(int N) : vector<int>(), threshold(N) {}

		void additem(int weight, int cost) {
			weight_cost.push_back({weight, cost});
		}

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

vector<string> getallsubstrings(string S) {
	vector<string> substrings;
	for (int i = 0; i < S.size(); i++) {
		for (int j = i; j < S.size(); j++) {
			substrings.push_back(S.substr(i, j - i + 1));
		}
	}
	return substrings;
}
template <typename C, typename E>
bool contains(const C& container, const E& element) {
	return std::find(container.begin(), container.end(), element) != container.end();
}

#define acout cout << fixed << setprecision(0)
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
#define indexof(v, x) (find(v.begin(), v.end(), x) - v.begin())
#define freqof(v, x) (count(v.begin(), v.end(), x))
#define forall(v) (v).begin(), (v).end()
#define maxof(v) (*max_element(v.begin(), v.end()))
#define minof(v) (*min_element(v.begin(), v.end()))
#define maxon(v) (max_element(v.begin(), v.end()) - v.begin())
#define minon(v) (min_element(v.begin(), v.end()) - v.begin())
#define deletepos(v, x) (v).erase((v).begin() + x)
#define deleteval(v, x) (v).erase(find(forall(v), x))
#define popcount __builtin_popcount
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

signed main(void) {fast
	iin(N);
	vin(P, N);
	int n = 0;
	while(!(maxon(P) == 0 && freqof(P, maxof(P)) == 1)) {
		P[0]++;
		n++;
	}
	cout << n << endl;

	return 0;
}
