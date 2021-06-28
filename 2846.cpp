// 2846
#include <iostream>
#define max 1000
using namespace std;
int n[max] = { 0 };
int main() {
	int Number;
	cin >> Number;
	for (int i = 0; i < Number; i++)
		cin >> n[i];
	int result = 0;
	int result_final = 0;
	for (int i = 0; i < Number - 1; i++) {
		if (n[i + 1] > n[i]) {
			result += n[i + 1] - n[i];
			if (result_final < result) {
				result_final = result;
			}
		}
		else 
			result = 0;
	}
	cout << result_final << endl;
}
