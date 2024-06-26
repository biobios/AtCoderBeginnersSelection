#include <iostream>

using namespace std;

int main() {

	int a, b;

	cin >> a >> b;

	int c = (a & 1) + (b & 1);

	if (c == 2) {
		cout << "Odd" << endl;
	}
	else {
		cout << "Even" << endl;
	}

	return 0;

}