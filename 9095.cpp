// 9095 1, 2, 3 더하기
#include <iostream>
#include <vector>
using namespace std;
int dp[12] = { 0 };
int main() {
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		cout << dp[k] << endl;
	}
}
