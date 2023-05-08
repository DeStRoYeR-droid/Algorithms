#include <iostream>

using namespace std;

void printArray(int* arr, int length){
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int* arr, int left, int mid, int right, int length){
    cout << "Before merging \t";
    printArray(arr, length);

    // Copying value from the array
    int i , j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftSubarray[n1] , rightSubarray[n2];

    for (int i = 0; i < n1; i++) leftSubarray[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightSubarray[j] = arr[mid + j + 1];
    cout << "Left sub array = ";
    for (int i = 0; i < n1; i++) cout << leftSubarray[i] << " ";
    cout << endl;
    cout << "Right sub array = ";
    for (int j = 0; j < n2; j++) cout << rightSubarray[j] << " ";
    cout << endl;
    i = 0;      // Index of left sub array
    j = 0;      // Index of right subarray
    k = left;   // Index of pseudo-sorted array

    while (i < n1 && j < n2){
        if (leftSubarray[i] <= rightSubarray[j]){
            arr[k] = leftSubarray[i];
            i++;
        }
        else{
            arr[k] = rightSubarray[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = leftSubarray[i];
        i++; k++;
    }

    while (j < n2){
        arr[k] = rightSubarray[j];
        j++; k++;
    }

    cout << "After merging \t";
    printArray(arr, length);
    cout << endl;
}

void mergeSort(int* arr, int left, int right, int length){
    if (left < right){
        int mid = (left + right) / 2;
        mergeSort(arr, left ,mid, length);
        mergeSort(arr, mid+1, right, length);
        merge(arr, left, mid, right, length);
    }
}


int main(){
    int length;
    int* array;

    cout << "Please enter the length of the array ";
    cin >> length;
    array = new int[length];
    for (int i = 0; i < length; i++){
        cout << "Please enter item of the array ";
        cin >> array[i];
    }

    mergeSort(array , 0 , length-1, length);

    printArray(array, length);
    return 0;
}