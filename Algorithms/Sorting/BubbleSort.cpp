#include <iostream>
using namespace std;

void traversal(int arr[], int size){
    if(size == 0){
        cout<<"Array is empty.\n";
    }
    else{
        cout<<"Elements of the array are: \n";
        for(int i=0; i<size; i++){
            cout<<arr[i]<<endl;
        }
    }
}

void BubbleSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j = 1; j<size; j++){
            if(arr[j-1]>arr[j]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

int main() {
    int arr[1000], size = 0;
    cout<<"Enter the size of array (between 1 to 1000): ";
    cin>>size;
    cout<<"Enter the elements of array:\n";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    BubbleSort(arr, size);
    traversal(arr, size);
    return 0;
}