#include <iostream>
using namespace std;

int SearchElement(int arr[], int size, int element){
    for(int i = 0; i < size; i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[100], size, element;
    cout<<"Enter the size of array(subject to the max size of 100): ";
    cin>>size;
    cout<<"Enter the elements in the array: ";
    for(int i; i < size; i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched: ";
    cin>>element;
    int res = SearchElement(arr, size, element);
    if(res == -1){
        cout<<"Element not found.";
    }
    else{
        cout<<"Element found at index "<<res<<endl;
    }
    return 0;
}