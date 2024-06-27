#include <iostream>
#include <set>

using namespace std;

int main()
{
	uint64_t N;
	cin >> N;

	set<uint64_t> D;

	for (size_t i = 0; i < N; i++) {
		uint64_t d;
		cin >> d;
		D.insert(d);
	}

	cout << D.size() << endl;
	return 0;
}