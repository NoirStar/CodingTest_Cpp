#include <bits/stdc++.h>

using namespace std;

//string StringPrintf(const char* format, ...) {
//	va_list ap;
//	va_start(ap, format);
//	string result;
//}

void print() {
	cout << "no argument" << endl;
}

template<typename T, typename... Args>
void print(const T& firstArg, const Args&... args) {
	cout << firstArg << endl;
	print(args...);
}

// dp  기저사례, 메모이제이션, 로직, 초기화

int dp[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t,n;
	cin >> t;

	dp[0] = 1;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 10000; j++) {
			// dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
			if (j - i >= 0) dp[j] += dp[j - i];
		}
	}

	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}