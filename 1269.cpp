#include <iostream>
#include <unordered_map>
#define MAX 100000000
bool A[MAX] = { 0 };
bool B[MAX] = { 0 };
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sizeA, sizeB;
	int number;
	cin >> sizeA >> sizeB;
	for (int i = 0; i < sizeA; i++) {
		cin >> number;
		A[number] = true;
	}
	for (int i = 0; i < sizeB; i++) {
		cin >> number;
		B[number] = true;
	}
	int same_index = 0;
	for (int i = 0; i < MAX; i++) {
		if (A[i] == 1 && B[i] == 1) {
			same_index++;
		}
	}
	cout << sizeA + sizeB - same_index * 2 << endl;
}