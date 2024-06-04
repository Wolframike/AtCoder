#include <atcoder/dsu>
#include <atcoder/scc>
#include <bits/stdc++.h>

using namespace atcoder;
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N;
	cin >> N;

	vector<pair<long long, pair<long long, long long>>> cards;

	for (long long i = 1; i <= N; i++) {
		long long a, b;
		cin >> a >> b;
		cards.push_back({i, {a, b}});
	}

	sort(cards.begin(), cards.end(), [](pair<long long, pair<long long, long long>> a, pair<long long, pair<long long, long long>> b) {
		return a.second.first > b.second.first;
	});

	cout << endl;

	vector<long long> garbage;
	long long comparewith = 1;

	for (long long i = 0; i < N - 1; i++) {
		if (i + comparewith >= N)
			break;
		if (cards[i].second.second < cards[i + comparewith].second.second) {
			garbage.push_back(cards[i + comparewith].first);
			i--;
			comparewith++;
		} else {
			i += comparewith - 1;
			comparewith = 1;
		}
	}

	sort(cards.begin(), cards.end(), [](pair<long long, pair<long long, long long>> a, pair<long long, pair<long long, long long>> b) {
		return a.first < b.first;
	});

	sort(garbage.begin(), garbage.end());

	cout << N - garbage.size() << endl;

	long long g = 0;
	for (auto card: cards) {
		if (g < garbage.size() && card.first == garbage[g]) {
			g++;
			continue;
		}
		cout << card.first << " ";
	}

	cout << endl;

	return 0;
}