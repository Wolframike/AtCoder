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
using vs = vector<string>;
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
	return find(container.begin(), container.end(), element) != container.end();
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
ostream& operator<<(ostream& out, xint value) {
	ostream::sentry s(out);
	if (s) {
		xint tmp = value;
		char buffer[40];
		char* d = end(buffer);
		bool is_negative = tmp < 0;
		if(is_negative) tmp = -tmp;
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while (tmp != 0);
		if(is_negative) {
			--d;
			*d = '-';
		}
		out.rdbuf()->sputn(d, end(buffer) - d);
	}
	return out;
}
ostream& operator<<(ostream& out, xuint value) {
	ostream::sentry s(out);
	if (s) {
		xuint tmp = value;
		char buffer[40];
		char* d = end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while (tmp != 0);
		out.rdbuf()->sputn(d, end(buffer) - d);
	}
	return out;
}
istream& operator>>(istream& in, xint& value) {
	string s;
	in >> s;
	value = 0;
	for (char c : s)
		value = value * 10 + (c - '0');
	return in;
}

istream& operator>>(istream& in, xuint& value) {
	string s;
	in >> s;
	value = 0;
	for (char c : s)
		value = value * 10 + (c - '0');
	return in;
}
void yn(bool b) {
	cout << (b ? "Yes" : "No") << endl;
}
#define debug(x) cerr << #x << ":\n" << x << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define iin1(N) int N; cin >> N
#define iin2(N1, N2) int N1, N2; cin >> N1 >> N2
#define iin3(N1, N2, N3) int N1, N2, N3; cin >> N1 >> N2 >> N3
#define iin4(N1, N2, N3, N4) int N1, N2, N3, N4; cin >> N1 >> N2 >> N3 >> N4
#define iin(...) iin_GET(__VA_ARGS__, iin4, iin3, iin2, iin1)(__VA_ARGS__)
#define iin_GET(_1, _2, _3, _4, NAME, ...) NAME
#define sin(S) string S; cin >> S
#define vsin(V, N) vector<string> V(N); for(auto& x : V) cin >> x
#define viin(V, N) vector<int> V(N); for(auto& x : V) cin >> x
#define vviin(V, H, W) vector<vector<int>> V(H, vector<int>(W)); for(auto& x : V) for(auto& y : x) cin >> y
#define pin(P) pair<int, int> P; cin >> P.first >> P.second
#define vpiiin(V, N) vector<pair<int, int>> V(N); for(auto& x : V) cin >> x.first >> x.second

#define sfor(i, n) for(int i = 0; i < n; i++)
#define sforr(i, n) for(int i = n - 1; i >= 0; i--)
#define foreachelem(x, v) for(auto& x : v)
#define foreachpair(x, y, v) for(auto& [x, y] : v)
#define foreach(...) foreach_GET(__VA_ARGS__, foreachpair, foreachelem)(__VA_ARGS__)
#define foreach_GET(_1, _2, _3, NAME, ...) NAME
#define foreachperm(v) for(bool run = true; run; run = next_permutation(v.begin(), v.end()))
#define forallpair(i, j, v) for(int i = 0; i < v.size(); i++) for(int j = i + 1; j < v.size(); j++)
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

vector<string> carpetgen(int K) {
	if (K == 0)
		return {"#"};
	vector<string> carpet(pow(3, K), string(pow(3, K), ' '));
	vector<string> prev = carpetgen(K - 1);
	for(int i = 0; i < pow(3, K); i += pow(3, K - 1))
		for(int j = 0; j < pow(3, K); j += pow(3, K - 1))
			for(int x = 0; x < pow(3, K - 1); x++)
				for(int y = 0; y < pow(3, K - 1); y++)
					carpet[i + x][j + y] = prev[x][y];
	for(int i = pow(3, K - 1); i < 2 * pow(3, K - 1); i++)
		for(int j = pow(3, K - 1); j < 2 * pow(3, K - 1); j++)
			carpet[i][j] = '.';
	return carpet;
} 

signed main(void) {fast
	iin(N);

	vector<string> carpet = carpetgen(N);
	foreach(s, carpet) {
		cout << s << endl;
	}

	return 0;
}
