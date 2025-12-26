#include "bits/stdc++.h"
using namespace std;
using LL = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	vector<LL> primes;
	static constexpr int N = 2e6;
	{
		array<bool, N> d;
		for (int i = 2; i < N; ++i) {
			if (!d[i]) {
				primes.push_back(i);
				for (int j = 2 * i; j < N; j += i)
					d[j] = 1;
			}
		}
	}

	auto isPrime = [&](LL x) -> bool {
		for (int i = 0; primes[i] * primes[i] <= x; ++i)
			if (x % primes[i] == 0)
				return false;
		return true;
	};

	int t; cin >> t;
	while (t--) {
		LL n; cin >> n;
		while (!isPrime(++n));
		cout << n << "\n";
	}
}
