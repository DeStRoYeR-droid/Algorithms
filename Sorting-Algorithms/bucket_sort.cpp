#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(int* arr, int length){
    int no_of_comparisons = 0;
    int temp;
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
}

void bucket_sort(int* arr, int length){
    // Get the maximum and minimum
    int min , max;
    int lower , higher;

    // Using 3n/2 algorithm to find the maximum and minimum
    // If there are odd elements
    if (length % 2){
        min = arr[0];
        max = arr[0];
        for (int i = 1; i < length-1; i += 2){
            if (arr[i] < arr[i+1]){
                lower = arr[i];
                higher = arr[i+1];
            }
            else{
                lower = arr[i+1];
                higher = arr[i];
            }
            if (lower < min){
                min = lower;
            }
            if (higher > max){
                max = higher;
            }
        }   
    }
    else{
        if (arr[0] < arr[1]){
            min = arr[0];
            max = arr[1];
        }
        else{
            min = arr[1];
            max = arr[0];
        }
        for (int i = 2; i < length-1; i += 2){
            if (arr[i] < arr[i+1]){
                lower = arr[i];
                higher = arr[i+1];
            }
            else{
                lower = arr[i+1];
                higher = arr[i];
            }

            if (lower < min){
                min = lower;
            }
            if (higher > max){
                max = higher;
            }
        }
    }

    vector<int> buckets[10]; 

    cout << "Max - min = " << max << " - " << min << " = " << max - min << endl;
    for (int i = 0; i < length; i++){
        cout << arr[i] << " is in bucket "<<((arr[i] - min) * 10) / (max-min) << endl;
    }
}

int main(){
    int arr[] = {16, 19, 20, 30, 30, 39, 34, 42, 80, 13, 76};
    bucket_sort(arr , 11);
    return 0;
}