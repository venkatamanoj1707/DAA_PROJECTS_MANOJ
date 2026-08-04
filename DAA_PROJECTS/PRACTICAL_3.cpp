#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

void maxHeapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void maxHeapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void minHeapify(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void minHeapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }

    reverse(arr.begin(), arr.end());
}

void display(vector<int> arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    vector<int> marks(n);

    cout << "Enter student marks:\n";
    for (int i = 0; i < n; i++)
        cin >> marks[i];

    vector<int> maxHeapArray = marks;
    vector<int> minHeapArray = marks;

    auto startMax = high_resolution_clock::now();
    maxHeapSort(maxHeapArray);
    auto endMax = high_resolution_clock::now();

    auto startMin = high_resolution_clock::now();
    minHeapSort(minHeapArray);
    auto endMin = high_resolution_clock::now();

    cout << "\nOriginal Marks:\n";
    display(marks);

    cout << "\nAfter Max Heap Sort (Ascending):\n";
    display(maxHeapArray);

    cout << "\nAfter Min Heap Sort (Ascending):\n";
    display(minHeapArray);

    auto nanoMax = duration_cast<nanoseconds>(endMax - startMax);
    auto microMax = duration_cast<microseconds>(endMax - startMax);

    auto nanoMin = duration_cast<nanoseconds>(endMin - startMin);
    auto microMin = duration_cast<microseconds>(endMin - startMin);

    cout << "\n========== MAX HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << nanoMax.count() << " ns\n";
    cout << "Microseconds : " << microMax.count() << " us\n";

    cout << "\n========== MIN HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << nanoMin.count() << " ns\n";
    cout << "Microseconds : " << microMin.count() << " us\n";

    return 0;
}


Enter number of students: 6
Enter student marks:
40
50
80
60
10
60

Original Marks:
40 50 80 60 10 60 

After Max Heap Sort (Ascending):
10 40 50 60 60 80 

After Min Heap Sort (Ascending):
10 40 50 60 60 80 

========== MAX HEAP SORT ==========
Nanoseconds  : 1330 ns
Microseconds : 1 us

========== MIN HEAP SORT ==========
Nanoseconds  : 1270 ns
Microseconds : 1 us


=== Code Execution Successful ===