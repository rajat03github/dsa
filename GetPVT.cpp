#include <bits/stdc++.h>
using namespace std;

int getPivot(vector<int> &arr, int n)
{

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] >= arr[0]) // here 0 is index
        {
            start = mid + 1;
        }
        else
        {
            // if we dow mid - 1 then it will go to another line
            end = mid;
        }
        mid = start + (end - start) / 2;
    }

    return start;
}

int binarysearch(vector<int> &arr, int start, int end, int key)
{
    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] == key)
            return mid;
        else if (key > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;

        mid = start + (end - start) / 2;
    }

    return -1;
}

int findPosition(vector<int> &arr, int n, int k)
{
    int pivot = getPivot(arr, n);

    if (k >= arr[pivot] && k <= arr[n - 1])
        return binarysearch(arr, pivot, n - 1, k);
    else
        return binarysearch(arr, 0, pivot - 1, k);
}