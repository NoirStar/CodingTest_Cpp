#include <bits/stdc++.h>

using namespace std;

int main() {
	int nCard;
	cin >> nCard;

	deque<int> dqCard(nCard);
	for (int i = 0; i < nCard; i++) {
		dqCard[i] = i + 1;
	}
	
	while (dqCard.size() > 1) {
		dqCard.pop_front();
		dqCard.push_back(dqCard.front());
		dqCard.pop_front();
	}
	cout << *dqCard.begin();

	return 0;
}