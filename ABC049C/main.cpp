#include <iostream>

using namespace std;

enum class State {
	ALL_ACCEPTABLE,
	AFTER_DREAM,
	AFTER_DREAMER,
	AFTER_ERASE,
};

constexpr char DREAM[] = "dream";
constexpr char DREAMER[] = "dreamer";
constexpr char ERASE[] = "erase";
constexpr char ASE[] = "ase";
constexpr char ERASER[] = "eraser";

int main()
{
	string S;
	cin >> S;

	State current_state = State::ALL_ACCEPTABLE;

	size_t i = 0;

	while (i < S.size()) {

		char s = S[i];

		uint64_t left_size = S.size() - i;

		switch (current_state)
		{
		case State::ALL_ACCEPTABLE:
			if (left_size < 5) {
				cout << "NO" << endl;
				return 0;
			}
			else if (s == 'd') {
				for (size_t j = 1; j < 5; j++) {
					if (S[i + j] != DREAM[j]) {
						cout << "NO" << endl;
						return 0;
					}
				}
				i += 5;
				current_state = State::AFTER_DREAM;
			}
			else if (s == 'e') {
				for (size_t j = 1; j < 5; j++) {
					if (S[i + j] != ERASE[j]) {
						cout << "NO" << endl;
						return 0;
					}
				}
				i += 5;
				current_state = State::AFTER_ERASE;
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
			break;
		case State::AFTER_DREAM:
			if (s == 'e' && left_size >= 2) {
				if (S[i + 1] != 'r') {
					cout << "NO" << endl;
					return 0;
				}

				i += 2;
				current_state = State::AFTER_DREAMER;
			}
			else if (s == 'd' && left_size >= 5) {
				for (size_t j = 1; j < 5; j++) {
					if (S[i + j] != DREAM[j]) {
						cout << "NO" << endl;
						return 0;
					}
				}

				i += 5;
				current_state = State::AFTER_DREAM;
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
			break;
		case State::AFTER_DREAMER:
			if (left_size < 3) {
				cout << "NO" << endl;
				return 0;
			}
			else if (s == 'a') {
				for (size_t j = 1; j < 3; j++) {
					if (S[i + j] != ASE[j]) {
						cout << "NO" << endl;
						return 0;
					}
				}

				i += 3;
				current_state = State::AFTER_ERASE;
			}
			else if (left_size < 5) {
				cout << "NO" << endl;
				return 0;
			}
			else if (s == 'd') {
				for (size_t j = 1; j < 5; j++) {
					if (S[i + j] != DREAM[j]) {
						cout << "NO" << endl;
						return 0;
					}
				}

				i += 5;
				current_state = State::AFTER_DREAM;
			}
			else if (s == 'e') {
				for (size_t j = 1; j < 5; j++) {
					if (S[i + j] != ERASE[j]) {
						cout << "NO" << endl;
						return 0;
					}
				}

				i += 5;
				current_state = State::AFTER_ERASE;
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
			break;
		case State::AFTER_ERASE:
			if (s == 'r') {
				i += 1;
				current_state = State::ALL_ACCEPTABLE;
			}
			else if (left_size < 5) {
				cout << "NO" << endl;
				return 0;
			}
			else if (s == 'd') {
				for (size_t j = 1; j < 5; j++) {
					if (S[i + j] != DREAM[j]) {
						cout << "NO" << endl;
						return 0;
					}
				}

				i += 5;
				current_state = State::AFTER_DREAM;
			}
			else if (s == 'e') {
				for (size_t j = 1; j < 5; j++) {
					if (S[i + j] != ERASE[j]) {
						cout << "NO" << endl;
						return 0;
					}
				}

				i += 5;
				current_state = State::AFTER_ERASE;
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
	return 0;
}