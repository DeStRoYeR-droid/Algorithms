#include <iostream>

using namespace std;

template <typename T>
void print_array(T* arr, int length){
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition_pivot(int* arr, int start, int end, int length){
    int pivot = arr[end];
    int i = start - 1;

    cout << "Pivot = " << pivot << "\t";

    for (int j = start; j < end; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[j] , arr[i]);
        }
    }
    swap(arr[i+1] , arr[end]);
    print_array(arr, length);
    return i+1;
}

void quick_sort(int* arr, int start, int end, int length){
    if (start >= end) return;

    int position = partition_pivot(arr, start, end, length);
    quick_sort(arr, start, position-1, length);
    quick_sort(arr, position + 1, end, length);
}



int main(){
    int length;
    int* arr;

    cout << "Please enter the size of the array ";
    cin >> length;

    arr = new int(length);

    for (int i = 0; i < length; i++){
        cout << "Please enter element at index " << i << " ";
        cin >> arr[i];
    }

    cout << endl;

    cout << "Unsorted array = ";
    print_array(arr, length);

    quick_sort(arr, 0, length-1, length);

    cout << "Sorted array = ";
    print_array(arr, length);
    cout << endl;

    return 0;
}