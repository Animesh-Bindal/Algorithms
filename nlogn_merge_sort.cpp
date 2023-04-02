#include<iostream>
#include<time.h>
using namespace std;
//MERGE SORT
void display(int n, int a[]){
    for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";}
    cout<<endl;
}
void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
void merge(int c[],int mid,int lo,int hi){
    int *b=(int *)malloc((hi+1)*sizeof(int));
    int i,j,m;
    i=lo;
    j=mid+1;
    m=lo;
    while(i<=mid && j<=hi){
        if(c[i]>c[j]){
            b[m]=c[j];
            m++; j++;}
        else{
            b[m]=c[i];
            m++; i++;}
    }
    while(j<=hi){
        b[m]=c[j];
        m++; j++;}
    while(i<=mid){
        b[m]=c[i];
        m++; i++;}
    for(int x=lo; x<=hi; x++){c[x]=b[x];}
}
void merge_sort(int a[],int lo,int hi){
    int mid;
    if(lo<hi){
        mid=(lo+hi)/2;
        merge_sort(a,lo,mid);
        merge_sort(a,mid+1,hi);
        merge(a,mid,lo,hi);}
}
int main(){
    int *a; int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        a[i]=rand()%100 ;
    cout<<"Before sorting array is: ";
    display(n,a);
    clock_t start = clock();
    merge_sort(a,0,n-1);
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<"After sorting array is: ";
    display(n,a);
    cout<<"Time is: "<<elapsed;
    return 0;
}
