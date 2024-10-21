#include<iostream>
using namespace std;
void mergeSort(int arr[12],int low,int m,int high)
{   int result[high-low+1];
    int i = low;
    int j = m+1;
    int n = high;
    int k = 0;
    while(i<=m && j<=n)
    {
        if(arr[i]>arr[j])
            result[k++]=arr[j++];
        else
            result[k++]=arr[i++];
    }
    while(i<=m)
         result[k++]=arr[i++];
    while(j<=high)
         result[k++]=arr[j++];
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = result[k];

}
int recursiveSort(int arr[12],int low,int high)
{   if(low<high){
        int m = (low+high)/2;
       recursiveSort(arr,low,m);
       recursiveSort(arr,m+1,high);
        mergeSort(arr, low, m, high);
    }
    return low;
}
int main()
{
    int arr[]={10,20,30,40,50,15,18,25,35,60,70,80};
    recursiveSort(arr,0,11);
     int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
