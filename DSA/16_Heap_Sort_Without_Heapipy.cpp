#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Insert into max heap
void insert(vector<int> &heap, int value)
{
    heap.push_back(value);
    int i = heap.size() - 1;

    while (i != 0 && heap[(i - 1) / 2] < heap[i])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to remove and return max element (root) from heap
int extractMax(vector<int> &heap)
{
    int maxVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    int i = 0;
    int n = heap.size();
    while (true)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && heap[left] > heap[largest])
            largest = left;
        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            i = largest;
        }
        else
        {
            break;
        }
    }

    return maxVal;
}

// Heap sort using insert and extract
vector<int> heapSortWithoutHeapify(vector<int> &arr)
{
    vector<int> heap;
    for (int val : arr)
        insert(heap, val);

    vector<int> sorted;
    while (!heap.empty())
        sorted.push_back(extractMax(heap));

    reverse(sorted.begin(), sorted.end()); // For ascending order
    return sorted;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> sortedArr = heapSortWithoutHeapify(arr);

    cout << "Sorted array without using heapify:\n";
    for (int val : sortedArr)
        cout << val << " ";
    cout << endl;

    return 0;
}
