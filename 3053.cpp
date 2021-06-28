#include <iostream>
using namespace std;
#define pi 3.14159265359
int main(void)
{
	double R;
	cin >> R;

	cout << fixed;
	cout.precision(6);
	cout << R * R * pi << endl;


	printf("%.6f", R * R * 2);
}
