#include <atcoder/dsu>
#include <atcoder/scc>
#include <bits/stdc++.h>

using namespace atcoder;
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long H;
	cin >> H;

	int t = 0;
	int i = 0;
	while (t <= H) {
		t += pow(2, i);
		i++;
	}
	cout << i << endl;

	return 0;
}