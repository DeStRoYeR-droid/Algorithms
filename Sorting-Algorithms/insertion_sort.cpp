#include <iostream>
 
using namespace std;

template<typename T> 
int insertion_sort(T* arr, int length){
    int no_of_comparisons = 0;
    T temp;
    int j;
    for (int i = 1; i < length; i++){
        temp = arr[i];
        j = i-1;
        while (j >= 0 && temp < arr[j]){
            arr[j+1] = arr[j];
            j = j - 1;
            no_of_comparisons++;
        }
        no_of_comparisons++;
        arr[j+1] = temp;
    }

    return no_of_comparisons;
}

template <typename T>
void print_array(T* arr, int length){
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
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

    int no_of_comparisons = insertion_sort(arr, length);

    cout << "Sorted array = ";
    print_array(arr, length);
    cout << endl;

    cout << "Number of comparisons by insertion sort = " << no_of_comparisons << endl;

    return 0;
}