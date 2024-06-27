#include <iostream>

using namespace std;

int main()
{
	uint64_t N;
	cin >> N;

	uint64_t prev_t = 0, prev_x = 0, prev_y = 0;

	for (size_t i = 0; i < N; i++) {
		uint64_t t, x, y;
		cin >> t >> x >> y;
		if ((t % 2) != ((x + y) % 2)) {
			cout << "No" << endl;
			return 0;
		}

		uint64_t def = 0;
		if (prev_x < x)
			def += x - prev_x;
		else
			def += prev_x - x;

		if (prev_y < y)
			def += y - prev_y;
		else
			def += prev_y - y;

		if (def > (t - prev_t)) {
			cout << "No" << endl;
			return 0;
		}

		prev_t = t;
		prev_x = x;
		prev_y = y;
	}

	cout << "Yes" << endl;
	return 0;
}