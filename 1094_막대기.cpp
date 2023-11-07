#include <bits/stdc++.h>

using namespace std;
/*

지민이는 길이가 64cm인 막대를 가지고 있다. 어느 날, 그는 길이가 Xcm인 막대가 가지고 싶어졌다. 지민이는 원래 가지고 있던 막대를 더 작은 막대로 자른다음에, 풀로 붙여서 길이가 Xcm인 막대를 만들려고 한다.

막대를 자르는 가장 쉬운 방법은 절반으로 자르는 것이다. 지민이는 아래와 같은 과정을 거쳐서 막대를 자르려고 한다.

지민이가 가지고 있는 막대의 길이를 모두 더한다. 처음에는 64cm 막대 하나만 가지고 있다. 이때, 합이 X보다 크다면, 아래와 같은 과정을 반복한다.
가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 자른다.
만약, 위에서 자른 막대의 절반 중 하나를 버리고 남아있는 막대의 길이의 합이 X보다 크거나 같다면, 위에서 자른 막대의 절반 중 하나를 버린다.
이제, 남아있는 모든 막대를 풀로 붙여서 Xcm를 만든다.
X가 주어졌을 때, 위의 과정을 거친다면, 몇 개의 막대를 풀로 붙여서 Xcm를 만들 수 있는지 구하는 프로그램을 작성하시오.

*/


// 처음에는 64cm  모든 막대의 합이 x 보다 클때
// 제일 짧은 걸 절반으로 자르고
// 남아있는 막대의 길이의 합이 x보다 크거나 같다면 위에서 자른걸 버린다
// x를 만들었을때 몇개의 막대로 만들었는가
int main() {
	int nStickX;
	int nCount = 0;
	vector<int> vSticks(1, 64); 

	cin >> nStickX;

	while (true) {
		int nStick = 0;
		for (int stick : vSticks) {
			nStick += stick;
		}
		
		if (nStick > nStickX) {
			int nShortestStick = vSticks.back() / 2;
			vSticks.pop_back();
			nStick -= nShortestStick;

			if (nStick >= nStickX) {
				vSticks.push_back(nShortestStick);
			}
			else {
				vSticks.push_back(nShortestStick);
				vSticks.push_back(nShortestStick);
			}
		}
		else {
			break;
		}
	}

	cout << vSticks.size();

	return 0;
}