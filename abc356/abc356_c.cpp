#include <atcoder/dsu>
#include <atcoder/scc>
#include <bits/stdc++.h>

using namespace atcoder;
using namespace std;
#define int long long

signed main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;

	cin >> N >> M >> K;

	vector<vector<int>> keys(M);
	vector<char> results(M);

	for (int i = 0; i < M; ++i) {
		int C;
		cin >> C;
		keys[i].resize(C);
		for (int j = 0; j < C; ++j) {
			cin >> keys[i][j];
			keys[i][j] -= 1;
		}
		cin >> results[i];
	}

	int comb = 0;

	for (int i = 0; i < (1 << N); ++i) {
		bool valid = true;

		for (int j = 0; j < M; ++j) {
			int usedkeys = 0;

			for (int key : keys[j]) {
				if (i & (1 << key)) {
					usedkeys++;
				}
			}

			if ((results[j] == 'o' && usedkeys < K) || (results[j] == 'x' && usedkeys >= K)) {
				valid = false;
				continue;
			}
		}

		if (valid)
			++comb;
	}

	cout << comb << endl;

	return 0;
}