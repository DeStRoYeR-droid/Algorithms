#include <iostream>

using namespace std;

void count_sort(int* arr, int length){
    // Array to copy elements of arr
    int* copy_arr = new int[length];

    // Finding maximum and minimum
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < length; i++){
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];

        copy_arr[i] = arr[i];
    }

    // Variables to generate the frequency array
    int range = max - min + 1;
    int* count_array = new int[range];
    
    // Generate frequency array
    for (int i = 0; i < length; i++){
        count_array[arr[i] - min]++;
    }

    // Use frequency array to make a cumulative frequency array
    for (int i = 1; i < range; i++){
        count_array[i] = count_array[i] + count_array[i-1];
    }

    // Sorting the array
    int element;
    for (int i = 0; i < length; i++){
        element = copy_arr[i]; 
        count_array[element - min]--;
        arr[count_array[element - min]] = copy_arr[i];
    }

    delete[] copy_arr;
}

void printArray(int* arr, int length){
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1,2,3,2,3,4,5,7,6,2,3,1,6,2};
    int len = 14;

    cout << "Before sorting ";
    printArray(arr , len);

    count_sort(arr, len);
    
    cout << "After sorting ";
    printArray(arr , len);
       
    return 0;
}