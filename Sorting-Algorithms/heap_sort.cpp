#include <iostream>

#define left(i) ((i)<<1)|1
#define right(i) ((i+1)<<1)
#define parent(i) i>>1

using namespace std;

void printArray(int* arr, int length){
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int* array, int start, int size){
    int largest = start;

    int l = left(start);
    int r = right(start);
    
    if (l < size && array[l] >= array[largest]) largest = l;
    if (r < size && array[r] >= array[largest]) largest = r;

    if (largest != start){
        swap(array[start] , array[largest]);
        heapify(array, largest, size);
    }
    return;
}

void build_heap(int* array, int size){
    for (int i = (size-1)>>2; i >= 0; i--){
        heapify(array, i , size);
    }
}

void heap_sort(int* array, int size){
    build_heap(array, size);

    cout << "Heap = ";
    printArray(array, size);
    cout << endl;

    int heap_size = size;
    int j = 0;
    
    for (int i = size-1; i >= 0; i--){
        swap(array[j] , array[i]);
        heap_size--;
        cout << "Before heapifying = ";
        printArray(array, size);
        heapify(array, j , heap_size);
        cout << "After heapifying  = ";
        printArray(array, size);
        cout << endl;
    }
}

int main(){
    int* arr;
    int size;

    cout << "Please enter the size of the array ";
    cin >> size;
    arr = new int[size];
    cout << "Please enter the elements of the array ";
    for (int i = 0; i < size; i++) cin >> arr[i];

    printArray(arr, size);
    heap_sort(arr, size);
    printArray(arr, size);

    return 0;
}