#include <iostream>
using namespace std;

struct Node {
	int a = 0;
	Node* sec = nullptr;
};

struct Stek {
	Node* now = nullptr;

	void ins(int z) {
		Node* x = new Node();
		x->a = z;
		x->sec = now;
		now = x;
	}

	int pop() {
		Node* x = now;
		int ans = x->a;
		now = x->sec;
		delete x;
		return ans;
	}
};

int main(int argc, char* argv[]) {

	int n = 1, k = 0, c = 0, q = 0;
	bool interface = true;
	Stek s;
	string arg;
	if (argc > 1) { arg = argv[1]; }
	if (arg == "false" || arg == "0") { interface = false; }
	setlocale(LC_ALL, "ru");
	if (interface) { cout << "Для запуска интерфейса без дополнительных пояснений, передать параметром значение \"false\" или \"0\"\nВведите значения:\n"; }
	
	while (n != 0) {
		k++;
		if (interface) { cout << "Число " << k << " = "; }
		cin >> n;
		s.ins(n);
	}

	if (interface) { cout << "\nОтвет:\n"; }
	
	for (int i = 0; i < k; i++) {
		c = s.pop();
		if (c > 0) {
			cout << c << endl;
			q++;
		}
	}
	if (q == 0) { cout << "Положительных чисел в стеке нет!"; }
}