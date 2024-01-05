#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	const int n = 4;
	string a[n] = { "사과", "포도", "배", "귤" };

	// n개의 집합을 생성? 이 아니라 개수 0000 부터 1111 까지 돌겠다는 의미.
	for (int i = 0; i < (1 << n); i++) {
		string ret = "";
		for (int j = 0; j < n; j++) {
			// 돌아가는 i와 and 연산을 통해서 경우의 수를 출력한다.
			// 만약 i가 1100 이라면   1 << j 를 통해 한비트 접근해서 켜져있는지 확인한다.
			if (i & (1 << j)) {
				ret += a[j] + " ";
			}
		}
		cout << ret << '\n';
	}

	return 0;
}