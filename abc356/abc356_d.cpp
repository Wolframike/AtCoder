#include <atcoder/dsu>
#include <atcoder/scc>
#include <bits/stdc++.h>

using namespace atcoder;
using namespace std;
#define int long long

signed main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;
	
	int ans = 0;

	for (int i = 0; i < 60; i++) {
		if ((M & (1LL << i)) == 0)
			continue;

		int total = 0;
		int bitunit = 1LL << i;
		int quot = N / (2 * bitunit);
		int rem = N % (2 * bitunit);
		total = quot * bitunit;
		if (rem >= bitunit)
			total += min(rem - bitunit + 1, bitunit);

		ans += total % 998244353;
	}

	cout << ans % 998244353 << endl;

	return 0;
}