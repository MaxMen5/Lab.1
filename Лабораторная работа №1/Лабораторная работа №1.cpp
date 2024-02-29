#include <iostream>
using namespace std;

struct Node {
	int param = 0;
	Node* second = nullptr;
};

struct Stack {
	Node* now = nullptr;
	int count = 0;
	int counting() { return count; }

	void insert(int inputValue) {
		Node* node = new Node();
		node->param = inputValue;
		node->second = now;
		now = node;
		count++;
	}

	int pop() {
		Node* node = now;
		int answer = node->param;
		now = node->second;
		delete node;
		count--;
		return answer;
	}
};

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	int value = 1, kol = 0, output = 0;
	bool interface = true, isPositive = false;
	Stack stack;
	string argument;

	if (argc > 1) { argument = argv[1]; }
	if (argument == "false" || argument == "0") { interface = false; }
	if (interface) { cout << "Для запуска интерфейса без дополнительных пояснений, передать параметром значение \"false\" или \"0\"\nВведите значения:\n"; }

	while (true) {
		if (interface) { cout << "Число " << ++kol << " = "; }
		cin >> value;
		if (value == 0) { break; }
		stack.insert(value);
	}

	if (interface) { cout << "\nОтвет:\n"; }

	for (int i = 0; i < kol; i++) {
		output = stack.pop();
		if (output > 0) {
			cout << output << endl;
			isPositive = true;
		}
	}
	if (!isPositive) { cout << "Положительных чисел в стеке нет!\n"; }
}
