#include <iostream>
#include <algorithm> // std::sort
using namespace std;

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() 
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + n); // std::sort kullanımı
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
