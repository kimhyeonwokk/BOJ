// 9613
#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		vector<int> temp_vec;
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			temp_vec.push_back(temp);
		}
		long long int result = 0;
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				result += gcd(temp_vec[j], temp_vec[k]);
			}
		}
		cout << result << endl;
	}
}
