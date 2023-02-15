// C++ program for implementation of Bubble sort
#include <algorithm>
#include <iostream>
#include <time.h>

using namespace std;

// A function to implement bubble sort
// Note on passing C arrays: The options are
// * void bubbleSort(int array[], int n) { ... }
// * void bubbleSort(int* array, int n) { ... }
// they do the same.
void bubbleSort(int array[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
  
        for (j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}
  
// Function to print an array 
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// Warning: This function allocates memory and we need to delete
//          it somewhere! 
int* randomArray(int size)
{
    int* array = new int[size];
    for (int i = 0; i < size; ++i) 
        array[i] = rand() % 1000;
    
    return array;
}


// Driver code you probably should have unit tests!
int main()
{

    // set the seed for the random number generator
    srand(time(NULL));

    int N = 10;
    int* array = randomArray(N);

    bubbleSort(array, N);
    
    cout << "Sorted array: \n";
    printArray(array, N);

    // we need this since random array has a new!!!
    delete [] array;

    return 0;
}