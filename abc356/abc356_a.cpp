#include <atcoder/dsu>
#include <atcoder/scc>
#include <bits/stdc++.h>

using namespace atcoder;
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L, R;

	cin >> N >> L >> R;

	vector<int> vec(N);

	iota(vec.begin(), vec.end(), 1);

	reverse(vec.begin() + L - 1, vec.begin() + R);

	for (int i = 0; i < N; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;

	return 0;
}