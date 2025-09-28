#include <iostream>
using namespace std;

int BinarySearch(int arr[], int size, int element){
    int left = 0, right = size-1, mid = (left + right)/2;
    while(left != right){
        if(arr[mid] == element){
            return mid;
        }
        else if (element > arr[mid])
        {
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
        mid = (left + right)/2;
    }
    return -1;
}

int main() {
    int arr[100], size, element;
    cout<<"Enter the size of array(subject to the max size of 100): ";
    cin>>size;
    cout<<"Enter the elements in the array(in ascending order): \n";
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched: ";
    cin>>element;
    int res=BinarySearch(arr, size, element);
    if(res == -1){
        cout<<"Element not found.\n";
    }
    else{
        cout<<"Element found at index "<<res<<endl;
    }
    return 0;
}