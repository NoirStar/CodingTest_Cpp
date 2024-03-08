#include <bits/stdc++.h>

using namespace std;


long long s, e, cnt[100001], arr[100001], ret;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	while (e < n) {
		// cnt 중복체크를 하는 배열이 0일때 즉 중복이 아닐때
		if (!cnt[arr[e]]) {
			// 체크
			cnt[arr[e]]++;
			// 다음 인덱스
			e++;
		}
		else {
			// 체크를 했는데, 다음것이 중복이다 이러면 e-s 한게 결국 경우의수
			ret += (e - s);
			// 1 2 3 1 이면 s 를 어차피 증가시켜서 1에대한 중복을 없앨것이기 때문에
			cnt[arr[s]]--;
			s++;
		}
	}
	// e가 끝가지 갔을때
	// 1 2 3 1 2 인데, s가 3이고 e가 2 니까 3 1 2 
	// 3 1 2의 경우의 수는 등차수열   3 1 2  31 12 312   3*4/2
	ret += (long long)(e - s) * (e - s + 1) / 2; // 등차수열의 합

	cout << ret;


	return 0;
}