#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> ans1(n1), ans2(n2);

    for(int i = 0; i < n1; i++)
    {
        ans1[i] = arr[i + left];
    }

    for(int i = 0; i < n2; i++)
    {
        ans2[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(ans1[i] <= ans2[j])
        {
            arr[k] = ans1[i];
            i++;
        }
        else
        {
            arr[k] = ans2[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = ans1[i];
        k++;
        i++;
    }

    while(j < n2)
    {
        arr[k] = ans2[j];
        k++;
        j++;
    }

}

void MergeSort(vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        MergeSort(arr, mid + 1, right);
        MergeSort(arr, left, mid);

        merge(arr, left, mid, right);
    }
}

int main()
{
    vector<int> arr = {1, 23, 4, 211, 4, 0, 34};

    MergeSort(arr, 0, arr.size() - 1);

    for(int num : arr)
    {
        cout << num << "  ";
    }

    cout << endl;

    return 0;
}