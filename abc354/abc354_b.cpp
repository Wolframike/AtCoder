#include <atcoder/dsu>
#include <atcoder/scc>
#include <bits/stdc++.h>

using namespace atcoder;
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<string> S(N);
	vector<int> C(N);

	for (int i = 0; i < N; i++) {
		cin >> S[i] >> C[i];
	}

	sort(S.begin(), S.end());

	int T = 0;
	for (int i = 0; i < N; i++) {
		T += C[i];
	}

	T %= N;

	cout << S[T] << endl;

	return 0;
}