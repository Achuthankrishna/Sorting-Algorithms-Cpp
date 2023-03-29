#include<iostream>
using namespace std;

void merge(int *a,int l,int m,int r)
{
    int nleft=m-l+1;
    int nright=r-m;
    int larr[nleft];
    int rarr[nright];
    for( int i=0;i<nleft;i++)
    {
        larr[i]=a[l+i];
    }
    for( int j=0;j<nright;j++)
    {
        rarr[j]=a[m+1+j];
    }
    
    int i=0,j=0,k=l;
    while (i<nleft && j<nright){
        if(larr[i]<=rarr[j]){
            a[k]=larr[i];
            i++;
        }
        else{
            a[k]=rarr[j];
            j++;
        }
        k++;

    }
    while (i<nleft){
        a[k]=larr[i];
        i+=1;
        k++;
    }
    while (j<nright){
        a[k]=rarr[j];
        j+=1;
        k++;
    }

}
void msort(int *a,int l,int r)
{
    int mid;
    if(l<r)
    {
        mid=(l+r)/2;
        msort(a,l,mid);
        msort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n]; //create an array with given number of elements
   cout << "Enter elements:" << endl;

   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }

   cout << "Array before Sorting: ";
   display(arr, n);
   msort(arr, 0, n-1); //(n-1) for last index
   cout << "Array after Sorting: ";
   display(arr, n);
}