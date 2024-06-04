#include <atcoder/dsu>
#include <atcoder/scc>
#include <bits/stdc++.h>

using namespace atcoder;
using namespace std;
#define int long long

signed main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	int l = 0, r = N;

	while (r - l > 1) {
		int mid = (l + r) / 2;
		cout << "? " << mid << endl;
		cout << flush;
		char s;
		cin >> s;
		if (s == '1') {
			r = mid;
		} else {
			l = mid;
		}
	}

	cout << "! " << r - 1 << endl;

	return 0;
}
