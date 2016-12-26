#include <stdio.h>

int main()

{

    int arr[100], i, num; 

 

    printf("Enter the size of array : ");   

    scanf("%d", &num);   

    printf("Enter the %d elements to be sorted:\n",num); 

    for (i = 0; i < num; i++)

        scanf("%d", &arr[i]); 

    printf("\nThe array of elements before sorting : \n");

    for (i = 0; i < num; i++)

        printf("%d ", arr[i]);  

    printf("\nThe array of elements after sorting : \n"); 

    bucket_Sort(arr, num); 

    for (i=0; i<num; i++){
        printf("%d ",arr[i]);
        }   
    printf("\n");
    return 0;
}


void bucket_Sort(int* arr, int n){
    int i;  
    int count[n]; 
    for (i = 0; i < n; i++){
        count[i] = 0;
    }
    for (i=0;i<n;i++){
        count[arr[i]]++;
    }
    int j=0;
    for (i=0;i<n;i++){  
        for(;count[i]>0;count[i]--){
            arr[j] = i;
            j++;
        }
    }

}   


 



