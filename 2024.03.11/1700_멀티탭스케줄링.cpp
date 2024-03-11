#include <bits/stdc++.h>

using namespace std;

// 메모리 페이징 최적 알고리즘
// Optimal Page Replacement Algorithm
// 실제 시스템에서는 어렵다. 미래를 예측하는거니까 근데 이문제는 미래가 다 주어져있음.
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n, k, nCount=0;

	cin >> k >> n;

	vector<int> v;
	vector<int> vArr(101,0);
	vector<int> vVisited(101, 0);
	for (int i = 0; i < n; i++) {
		cin >> vArr[i];
	}

	// 1. 만약 2 3 이 들어가있고, 1 2 가 들어온다면 1 2 에 없는걸 뽑는다
	// 꽉찬순간에 옵티멀 알고리즘. 가장먼 미래에 참조되는 페이지를 스왑한다.
	// 핵심이 스왑이 가장 적어야함. 그럼 꽂혀있는것중 가장 먼 미래에 나오는걸 스왑하면됨

	for (int i = 0; i < n; i++) {
		// 들어가지 않았던 값이면, 
		if (!vVisited[vArr[i]]) {
			// 콘센트가 꽉 찼을때 빼는걸 시작함
			if (v.size() == k) {
				int lastIdx = 0, pos = 0;

				// 콘센트에 꽂혀있는걸 순회
				for (int a : v) {
					// 가장 먼 미래에 참조되는걸 찾는다.
					int pick = 987654321;
					for (int j = i + 1; j < n; j++) {
						// 꽂혀있는 가전제품 중 가장 먼 미래에 나오는것을 찾는다.
						if (a == vArr[j]) {
							pick = j;
							break;
						}
					}
					if (lastIdx < pick) {
						lastIdx = pick;
						// 꽂혀있는걸 교체하기위한 좌표
						pos = a;
					}
				}
				vVisited[pos] = 0;
				nCount++;
				v.erase(find(v.begin(), v.end(), pos));
			}
			v.push_back(vArr[i]);
			vVisited[vArr[i]] = 1;
		}
	}

	cout << nCount;

	return 0;
}

