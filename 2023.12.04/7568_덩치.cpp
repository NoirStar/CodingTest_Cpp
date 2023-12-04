#include <bits/stdc++.h>

using namespace std;

struct Person {
	int nWeight;
	int nHeight;
	int nRank;
};

int main() {
	int nPerson;
	cin >> nPerson;

	vector<Person> vPerson(nPerson);
	for (int i = 0; i < nPerson; i++) {
		cin >> vPerson[i].nWeight >> vPerson[i].nHeight;
		vPerson[i].nRank = 1;
	}

	for (int i = 0; i < nPerson; i++) {
		for (int j = 0; j < nPerson; j++) {
			if (i == j) continue;
			if (vPerson[i].nHeight < vPerson[j].nHeight &&
				vPerson[i].nWeight < vPerson[j].nWeight) {
				vPerson[i].nRank++;
			}
		}
	}

	for (const auto& p : vPerson) {
		cout << p.nRank << ' ';
	}


	return 0;
}