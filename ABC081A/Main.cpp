#include <iostream>

using namespace std;

int main() {
	int input;
	cin >> input;

	int count = 0;
	for (int i = 0; i < 3; i++) {
		count += (input >> i) & 1;
	}

	cout << count << endl;
	return 0;
}