// 15650번  N과 M (2)
#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> original;
vector<int> v1;
void find(int index, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << v1[i] << " ";
		}
		cout << "\n";
		return;
	}
	if (index >= original.size()) return;
	v1.push_back(original[index]);
	find(index + 1, cnt + 1);
	v1.pop_back();
	find(index + 1, cnt);

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		original.push_back(i);
	find(0, 0);
}
