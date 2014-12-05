#include "BinaryHeap.h"
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
using namespace ods;

template<class T>
void testLinHeap(BinaryHeap<T> *heap) {
	for (int i = 0; i < 1000; i++)
		heap->add(i);

	bool heapCheck = heap->isHeap();

	for(int g = 0; g < 500; g++)
		heap->remove(0);

	bool heapCheck2 = heap->isHeap();

	if (heapCheck && heapCheck2)
		cout << "Addition, removal success!" << endl;
	else
		cout << "Failure to maintain heap property" << endl;
}

template<class T>
void testRndHeap(BinaryHeap<T> *heap) {
	for (int i = 0; i < 1000; i++)
		heap->add(rand() % 2000);

	bool heapCheck = heap->isHeap();

	for(int g = 0; g < 500; g++)
		heap->remove(0);

	bool heapCheck2 = heap->isHeap();

	if (heapCheck && heapCheck2)
		cout << "Addition, removal success!" << endl;
	else
		cout << "Failure to maintain heap property" << endl;
}

int main() {
	
	BinaryHeap<int> b, b2;
	cout << "Test linear adding: " << endl; 
	testLinHeap(&b);
	cout << "Test random adding: " << endl; 
	testRndHeap(&b2);

	return 0;
}
