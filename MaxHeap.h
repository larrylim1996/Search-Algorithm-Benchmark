#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& heap, int rootPosition);
void deletion(vector<int>& heap);
void insertion(vector<int>& heap, int data);
void levelOrderTraversal(vector<int>& heap);

void heapify(vector<int>& heap, int rootPosition) {
	int largest = rootPosition;
	int left = 2 * rootPosition + 1;
	int right = 2 * rootPosition + 2;

	if (left< heap.size() && heap.at(left)>heap.at(largest)) {
		largest = left;
	}

	if (right< heap.size() && heap.at(right)>heap.at(largest)) {
		largest = right;
	}

	if (largest != rootPosition) {
		int temp = heap.at(rootPosition);
		heap.at(rootPosition) = heap.at(largest);
		heap.at(largest) = temp;
		heapify(heap, largest);
	}
}

void deletion(vector<int>& heap) {
	int last = heap.at(heap.size() - 1);
	heap.at(0) = last;
	heap.pop_back();
	heapify(heap, 0);
}

void insertion(vector<int>& heap, int data) {
	heap.push_back(data);
	heapify(heap, heap.size() - 1);
}

void levelOrderTraversal(vector<int>& heap) {
	for (int i = 0; i < heap.size(); i++) {
		cout << heap.at(i) <<" ";
	}
	cout << endl;
}