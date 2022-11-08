//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {   
        int b[1000000];    
        int k=l; //index of b array;
        int i=l; //index of first subarray
        int j=mid+1; //index of second subarray
        while(i<=mid && j<=r){
            if(arr[i]<arr[j]){
                b[k++]=arr[i++];
            }
            else{
                b[k++]=arr[j++];
            }
        }
        if(i>mid){//first subarray finish so copy the second subarray
            while(j<=r){
                b[k++]=arr[j++];
            }
        }
        else{ //second subarray finish
            while(i<=mid){
                b[k++]=arr[i++];
            }
        }
        //copy into original array
        for(int k=l;k<=r;k++){
            arr[k]=b[k];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r){ //atleast two elements should be there to divide
            int mid=(l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends