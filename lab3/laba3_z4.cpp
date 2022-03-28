#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    const int n=7, m=9, x= n+m;
    int arr[n], arr1[m], arr2[x], tmp=0;
    cout << "fill in array #1:" << endl;
    for (int i=0; i<n; i++)
    {
        do
        {
        cout << "input " << i+1 << " element: ";
        cin >> arr[i];
        }
        while (arr[i] < 0);
        arr2[tmp] = arr[i];
        tmp++;
    }
    cout << "fill in array #2:" << endl;
    for (int i=0; i<m; i++)
    {
        do
        {
        cout << "input " << i+1 << " element: ";
        cin >> arr1[i];
        }
        while (arr1[i] < 0);
        arr2[tmp] = arr1[i];
        tmp++;
    }
    cout << "result array:" << endl;
    for (int i=0; i<x; i++)
        cout << arr2[i] << ' ';
    cout << "after sort:" << endl;
    for (int i=0; i<x-1; i++)
    {
        for(int j=0; j<x-1; j++)
        {
            if (arr2[j]>arr2[j+1])
                swap(arr2[j],arr2[j+1]);
        }
    }
    for (int i=0; i<x; i++)
        cout << arr2[i] << ' ';
    cout << endl;
    system("pause");
}