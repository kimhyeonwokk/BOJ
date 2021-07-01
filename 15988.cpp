// 15988 1, 2, 3 더하기
#include <iostream>
#include <vector>
using namespace std;
long long int dp[1000001] = { 0 };
int main() {
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3] )% 1000000009;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		cout << dp[k] << endl;
	}
}
