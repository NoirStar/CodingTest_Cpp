#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	// 짝짓기는 스택이다 기억하기
	// 3 2 1 5 | 3 8    맨처음 아이랑 짝이 되는 아이들은 5 에서 끊긴다. 그 이후는 생각할 필요X
	// 여기서 아이디어를 얻어서 뭔가 큰게 나오면! 어떤 로직
	// 큰 5랑 앞에 작은 3 2 1 이랑 비교하면 됨. 왜냐하면 큰아이 뒤에 나오는수는 비교 필요 X때문
	stack<pair<ll, ll>> s;
	ll nTemp, nRet = 0;
	for (int i = 0; i < n; i++) {
		cin >> nTemp;
		int nCount = 1;

		// 들어오는 수 보다 같거나 작을때 짝짓기가능
		while (s.size() && s.top().first <= nTemp) {
			nRet += s.top().second; // count를 누적(개수세기)
			
			// 같은 경우
			if (s.top().first == nTemp) {
				nCount = s.top().second + 1;
			}
			else {
				nCount = 1;
			}
			s.pop();
		}
		if (s.size()) nRet++;
		s.push({nTemp,nCount});
	}
	cout << nRet;
	
	return 0;
}