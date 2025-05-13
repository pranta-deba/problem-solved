#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to insert an element into the max heap
void insert(vector<int> &heap, int value)
{
    heap.push_back(value);
    int i = heap.size() - 1;

    // Sift up to maintain max heap property
    while (i != 0 && heap[(i - 1) / 2] < heap[i])
    {
        std::swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> heap;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insert(heap, value);
    }

    cout << "Max Heap:\n";
    for (int val : heap)
        cout << val << " ";
    cout << endl;

    return 0;
}
