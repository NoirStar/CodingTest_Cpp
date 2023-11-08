#include <bits/stdc++.h>

using namespace std;

int main() {
	string strInput;
	int nArrayA, nTemp;
	vector<pair<int,int>> vArrayA, vArrayP;

	cin >> nArrayA;

	for (int i = 0; i < nArrayA; i++) {
		cin >> nTemp;
		vArrayA.push_back(make_pair(i, nTemp));
	}

	sort(vArrayA.begin(), vArrayA.end(), 
		[](pair<int, int> p1, pair<int, int> p2) {
		if (p1.second == p2.second) {
			return p1.first < p2.first;
		}
		return p1.second < p2.second;
	});

	for (int i = 0; i < nArrayA; i++) {
		vArrayP.push_back(make_pair(i, vArrayA[i].first));
	}

	sort(vArrayP.begin(), vArrayP.end(),
		[](pair<int, int> p1, pair<int, int> p2) {
		return p1.second < p2.second;
	});


	for (const auto& e : vArrayP) {
		cout << e.first << " ";
	}

	// 1) ArrayA 를 비 내림차순으로 재정렬한다
	// 2) 정렬된 ArrayA의 인덱스 값의 인덱스를 오름차순으로 정렬해서 출력하면


	return 0;
}