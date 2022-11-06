//{ Driver Code Starts
//Initial Template for C++

// C program for implementation of Bubble sort
#include <stdio.h>

// swapping the elements
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>
class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    //T.C=O(N^2) S.C=O(1)
    void bubbleSort(int arr[], int n)
    {
        for(int i=0;i<n;i++){
            bool flag=false;
            //on every iteration maximum element of unsorted array get into their right position
            //so go till n-i-1
            for(int j=0;j<n-i-1;j++){
                if(arr[j+1]<arr[j]){
                    flag=true;
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
            //Already sorted
            if(flag==false) break;
        } 
    }
};


//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
      
    ob.bubbleSort(arr, n);
    printArray(arr, n);
    }
    return 0;;
}
// } Driver Code Ends