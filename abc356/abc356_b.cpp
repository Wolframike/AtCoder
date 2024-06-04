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

	vector<int> A(M);

	for (int i = 0; i < M; i++) {
		cin >> A[i];
	}

	int X;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> X;
			A[j] -= X;
		}
	}

	for (int i = 0; i < M; i++) {
		if (A[i] > 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;


	return 0;
}