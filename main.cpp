#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> generateData(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000 + 1;
    return arr;
}

// Bubble Sort
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Selection Sort
void selectionSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Function
void merge(vector<int>& arr, int l, int m, int r)
{
    vector<int> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= m)
        temp.push_back(arr[i++]);

    while (j <= r)
        temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[l + k] = temp[k];
}

void mergeSort(vector<int>& arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    srand(time(0));

    int n = 100;
    vector<int> original = generateData(n);
    vector<int> temp;

    clock_t start, end;

    cout << "Sorting Time Comparison\n\n";

    temp = original;
    start = clock();
    bubbleSort(temp);
    end = clock();
    cout << "Bubble Sort    : " << (double)(end - start) << endl;

    temp = original;
    start = clock();
    selectionSort(temp);
    end = clock();
    cout << "Selection Sort : " << (double)(end - start) << endl;

    temp = original;
    start = clock();
    insertionSort(temp);
    end = clock();
    cout << "Insertion Sort : " << (double)(end - start) << endl;

    temp = original;
    start = clock();
    mergeSort(temp, 0, n - 1);
    end = clock();
    cout << "Merge Sort     : " << (double)(end - start) << endl;

    temp = original;
    start = clock();
    quickSort(temp, 0, n - 1);
    end = clock();
    cout << "Quick Sort     : " << (double)(end - start) << endl;

    return 0;
}