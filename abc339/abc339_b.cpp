#include <atcoder/dsu>
#include <atcoder/scc>
#include <atcoder/modint>
#include <bits/stdc++.h>

using namespace atcoder;
using namespace std;

#define int long long
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

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
#define iin1(N) int N; std::cin >> N
#define iin2(N1, N2) int N1, N2; std::cin >> N1 >> N2
#define iin3(N1, N2, N3) int N1, N2, N3; std::cin >> N1 >> N2 >> N3
#define iin4(N1, N2, N3, N4) int N1, N2, N3, N4; std::cin >> N1 >> N2 >> N3 >> N4
#define iin(...) iin_GET(__VA_ARGS__, iin4, iin3, iin2, iin1)(__VA_ARGS__)
#define iin_GET(_1, _2, _3, _4, NAME, ...) NAME
#define vin(v) for(auto& x : v) cin >> x
#define vvin(v) for(auto& x : v) vin(x)
#define pin(v) cin >> x.first >> x.second
#define vpin(v) for(auto& x : v) pin(x)

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
	iin(H, W, N);
	vvi A(H, vi(W, 0));
	pair<int, int> pos = {0, 0};
	pair<int, int> dir = {-1, 0};
	sfor(i, N) {
		if (A[pos.first][pos.second] == 0) {
			A[pos.first][pos.second] = 1;
			dir = {dir.second, -dir.first};
			pos = {pos.first + dir.first, pos.second + dir.second};
		} else {
			A[pos.first][pos.second] = 0;
			dir = {-dir.second, dir.first};
			pos = {pos.first + dir.first, pos.second + dir.second};
		}
		if (pos.first == H)
			pos.first = 0;
		if (pos.first == -1)
			pos.first = H - 1;
		if (pos.second == W)
			pos.second = 0;
		if (pos.second == -1)
			pos.second = W - 1;
	}

	sfor(i, H) {
		sfor(j, W)
			cout << (A[i][j] ? '#' : '.');
		cout << endl;
	}

	return 0;
}
