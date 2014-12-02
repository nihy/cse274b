#include "BinaryHeap.h"
#include <iostream>

using namespace std;
using namespace ods;

int main() {
	
	BinaryHeap<int> b;

	for (int i = 0; i < 40; i++)
		b.add(i);

	// prints array
	for (int g = 0; g < b.size(); g++)
		cout << b.get(g) << ", ";

	cout << endl;
	while (b.size() > 0)
		b.remove(0);

	for (int g = 0; g < b.size(); g++)
		cout << b.get(g) << ", ";


	return 0;
}
