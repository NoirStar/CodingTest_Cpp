#include <bits/stdc++.h>

using namespace std;

// n 아이들의 수 , m 색상
long long n, m, highJ = 0, lowJ = 1, midJ;
long long minJ = numeric_limits<long long>::max();

long long v[300001];

// 이진 탐색을 이용. 주어진 범위 안에서 조건을 만족하는 최적 해를 구하는 문제니까 
// 이진탐색을 적용할 수 있음

// 학생들에게 어떤 수 만큼(maxPerStudent) 나눠주면 다 나눠줄 수 있는지 검사
bool IsDistribution(long long maxPerStudent) {
	int reqStudent = 0;
	for (long long i = 0; i < m; i++) {
		// 항상 같은 색상만 가져가고 못받는 애들이 있어도된다.
		reqStudent += v[i] / maxPerStudent;

		// 하나의 색상만 가질수있으므로
		if (v[i] % maxPerStudent) reqStudent++;
	}
	return n >= reqStudent;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> n >> m;
	for (long long i = 0; i < m; i++) {
		cin >> v[i];
		// 이진탐색 범위설정을 위해
		highJ = max(highJ, v[i]);
	}

	while (lowJ <= highJ) {
		midJ = (lowJ + highJ) / 2;
		if (IsDistribution(midJ)) {
			// 다 나눠줄 수있을떄 최소값
			minJ = min(minJ, midJ);
			highJ = midJ - 1;
		}
		else {
			lowJ = midJ + 1;
		}
	}
	
	cout << minJ;

	return 0;
}