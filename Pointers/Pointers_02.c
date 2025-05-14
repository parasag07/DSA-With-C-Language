#include <stdio.h>

int main(){
    
    int arr[100];
    int sum, i, size, left=0, right=7;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter array elements: ");
    for(i=0;i<size;i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the target sum- ");
    scanf("%d", &sum);
    while(left<right){
        if((arr[left]+arr[right])==sum) {
            printf("%d and %d are the required indexes\n",left,right);
            printf("Value at index %d is %d\n",left,arr[left]);
            printf("Value at index %d is %d\n",right,arr[right]);
            break;
        }
        else {
            if((arr[left]+arr[right])<sum) {
                left = left+1;
            }
            else {
                right = right - 1 ;
            }
        }
    }
    
    return 0;
}