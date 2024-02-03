#include<iostream>
using namespace std;

template<class t> void swap(t *a,t *b){
    t temp = *a;
    *a = b;
    *b = temp;
}
template<class t> int partition(t arr[],int p,int r){
    int pivot = arr[p];
    int start = p+1,end = r;
    while(start<end){
        while(pivot >= arr[start])start++;
        while(pivot < arr[end]) end--;
        if(end > start){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[end], arr[p]);
    return end;
}
template<class t> void quick_sort(t arr[],int p ,int r){
    if(p >= r)
    return ;
    int pivot_index = partition(arr,p,r);
    //recursion
    quick_sort(arr,p,pivot_index-1);
    quick_sort(arr,pivot_index + 1,r);  
}

//merge sort:
template<class T> void merge(T arr[],int lb,int mid,int up){
    T temp[up-lb+1];
    int i = lb , j = mid+1,k  = 0;
    while(i <= mid && j <= up){
        if(arr[i]<=arr[j])
        temp[k++]= arr[i++];
        else 
        temp[k++]=arr[j++];  
    }
    while(i<= mid)
    temp[k++]= arr[i++];
    while(j <= up)
    temp[k++]= arr[j++];
    for(int index = 0;index < up-lb+1 ; index++)
    arr[index+lb] = temp[index];
}
template<class T>void  merge_sort(T arr[],int lb,int up){
    if(lb < up)
   {
    int mid;
    mid = (lb+up)/2;
    merge_sort(arr,lb,mid);
    merge_sort(arr,mid+1,up);
    merge(arr,lb,mid,up);
    }
}
int main(){
    int arr1[8]= {200,0,30,1,50,4,3,-1};
    char arr2[10]={'a','m','n','j','e','c'};
    string name = "aman jain is my name.";
    float num[5] = {1.01,2.01,3.01,0.01,3.30};
    merge_sort(arr1,0,7);
    for(int i = 0;i<8;i++)
    cout<<arr1[i]<<" ";

    return 0;

}
