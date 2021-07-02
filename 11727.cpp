// 11727 2 x n 타일링 2
#include <iostream>
using namespace std;
int dp[1001] = { 0 };
int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for (int i = 4; i <= 1000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]*2) % 10007;
	}
	cout << dp[n] << endl;

}
