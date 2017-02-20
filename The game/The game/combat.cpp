#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
	int pLevel = 10;
	int eLevel = 5;

	if (pLevel > eLevel) {
		cout << "You win.\n";
	}
	else {
		cout << "You lose.\n";
	}

	return 0;
	
}