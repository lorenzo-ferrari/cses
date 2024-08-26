#include <iostream>

void mv(int n, int a, int b) {
	if (!n) return;
	mv(n-1, a, 6-a-b);
	std::cout << a << " " << b << "\n";
	mv(n-1, 6-a-b, b);
}

int32_t main() {
	int n;
	std::cin >> n;

	std::cout << (1 << n) - 1 << "\n";
	mv(n, 1, 3);
}
