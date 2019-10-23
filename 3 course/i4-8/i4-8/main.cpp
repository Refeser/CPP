#include <algorithm>
#include <cstddef>
#include <utility>
#include <array>
#include <string>
#include <iostream>

template<typename T>
void tree_sort(T array[], size_t size) noexcept 
{
	struct tree_t {
		tree_t *left, *right;
		T value;

		tree_t(T &&_value = T()) {
			left = right = nullptr;
			value = forward<T>(_value);
		}

		T* operator()(T array[]) {
			if (this->left)
				array = this->left->operator()(array);
			*array++ = move(this->value);
			if (this->right)
				array = this->right->operator()(array);
			return array;
		}
	} root(move(array[0]));

	for (size_t idx = 1; idx < size; idx++) {
		bool inserted = false;
		tree_t *p_root = &root;
		while (!inserted) {
			if (array[idx] < p_root->value) {
				if (p_root->left) p_root = p_root->left;
				else {
					p_root->left = new tree_t(move(array[idx]));
					inserted = true;
				}
			}
			else {
				if (p_root->right) p_root = p_root->right;
				else {
					p_root->right = new tree_t(move(array[idx]));
					inserted = true;
				}
			}
		}
	}
	root(array);
}

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	cout << "¬ведите числа (10): " << endl;
	array <int, 10> arrInt;
	for (int i = 0; i < 10; i++) {
		cin >> arrInt[i];
	}
	cout << "¬ведите строки (10): " << endl;
	array <string, 10> arrString;
	for (int i = 0; i < 10; i++) {
		cin >> arrString[i];
	}

	for (int i = 0; i < 10; i++) {
		cout << arrInt[i] << ", ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << arrString[i] << ", ";
	}
	cout << endl << endl << endl;

	tree_sort<int>(arrInt.data(), arrString.size());
	tree_sort<string>(arrString.data(), arrString.size());

	for (int i = 0; i < 10; i++) {
		cout << arrInt[i] << ", ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << arrString[i] << ", ";
	}
	cout << endl;

	system("pause");
	return 0;
}