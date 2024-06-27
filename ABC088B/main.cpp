#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	uint64_t N;

	cin >> N;

	vector<uint64_t> a(N);

	for (size_t i = 0; i < N; i++) {
		cin >> a[i];
	}

	sort(a.rbegin(), a.rend());

	uint64_t alice_point = 0;

	for (size_t i = 0; i < N; i += 2) {
		alice_point += a[i];
	}

	uint64_t bob_point = 0;

	for (size_t i = 1; i < N; i += 2) {
		bob_point += a[i];
	}

	cout << alice_point - bob_point << endl;

	return 0;
}