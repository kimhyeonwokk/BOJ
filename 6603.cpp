// 6603 로또
#include <iostream>
#include <vector>
using namespace std;
vector<int> choosenumber;
void choose(const vector<int>& lotto, int x, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			if (i == 5) {
				cout << choosenumber[i];
				break;
			}
			cout << choosenumber[i] << " ";
		}
		cout << endl;
		return;
	}
	if (lotto.size() <= x) {
		return;
	}
	choosenumber.push_back(lotto[x]);
	choose(lotto, x + 1, cnt + 1);
	choosenumber.pop_back();
	choose(lotto, x + 1, cnt);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (;;) {
		int k;
		int number;
		cin >> k;
		if (k == 0) break;
		vector<int> lotto;
		for (int i = 0; i < k; i++) {
			cin >> number;
			lotto.push_back(number);
		}
		choose(lotto, 0, 0);
		cout << endl;
	}

}
