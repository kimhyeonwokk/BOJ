#include <iostream>
using namespace std;
int main() {
    int T, num;
    cin >> T;

    int* ci = new int[T];
    int max = 0;
    for (int i = 0; i < T; i++) {
        cin >> num;
        ci[i] = num;
        if (num > max)
            max = num;
    }
    int* num1 = new int[max+1];
    int* num2 = new int[max+1];
    for (int i = 0; i <= max; i++) {
        if (i == 0)
            num1[i] = 1, num2[i] = 0;
        else if (i == 1)
            num1[i] = 0, num2[i] = 1;
        else {
            num1[i] = num1[i - 1] + num1[i - 2];
            num2[i] = num2[i - 1] + num2[i - 2];
        }
    }
    for (int i = 0; i < T; i++) {
        cout << num1[ci[i]] << " " << num2[ci[i]] << endl;
    }
    delete[] ci;
    delete[] num1;
    delete[] num2;
}
