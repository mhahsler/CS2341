// C++ program for implementation of Bubble sort
#include <algorithm>
#include <iostream>
#include <time.h>

using namespace std;

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
  
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
  
// Function to print an array 
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int* randomArray(int size)
{
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) 
        arr[i] = rand() % 1000;
    
    return arr;
}


// Driver code
int main()
{

    // set the seed for the random number generator
    // srand(time(NULL));

    int N = 10;
    int* arr = randomArray(N);

    bubbleSort(arr, N);
    
    cout << "Sorted array: \n";
    printArray(arr, N);

    delete [] arr;

    return 0;
}