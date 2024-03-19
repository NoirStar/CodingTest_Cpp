#include <bits/stdc++.h>

using namespace std;

int LIS(const vector<int>& seq) {
	vector<int> lis;

	for (int x : seq) {
		// x 이상인 위치를 찾는다. 이분 탐색으로 
		auto it = lower_bound(lis.begin(), lis.end(), x);
		
		// 못찾았다는건 x 가 젤크다는거지 그럼 맨뒤에 넣어준다.
		if (it == lis.end()) {
			lis.push_back(x);
		}
		// 찾았으면 x가 더 작으니까 더 큰 애랑 교환해줌
		else {
			// 예를들어 3 10 20 이고 x 가 15라면  20의위치를 찾고 교환한다.
			*it = x;
		}
	}
	return lis.size(); // 최대 증가 부분 수열의 크기
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	cout << LIS(v);

	return 0;
}