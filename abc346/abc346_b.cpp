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
	int W, B;
	cin >> W >> B;

	int w, b;
	w = W / 7;
	b = B / 5;

	int d = min(w, b);

	W -= d * 7;
	B -= d * 5;

	// cout << W << " " << B << endl;
	if (W + B == 1) {
		cout << "Yes" << endl;
		return 0;
	}
	if (W < B) {
		if (B - W == 1 && B < 4)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		return 0;
	}
	switch (W - B) {
		case 0:
			if (W < 6)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			break;
		case 1:
			cout << "Yes" << endl;
			break;
		case 2:
			cout << "Yes" << endl;
			break;
		case 3:
			if (B == 2) {
				cout << "Yes" << endl;
				return 0;
			}
		case 4:
			if (B == 5)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			break;
		default:
			cout << "No" << endl;
			break;
		
	}


	return 0;
}

/*
wbwbwwbwbwbw | wbwbwwbwbwbw
*/
