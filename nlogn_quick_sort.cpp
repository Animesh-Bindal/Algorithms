#include<iostream>
#include<time.h>
using namespace std;
//QUICK SORT
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
void quicksort(int a[],int beg,int end){
    int i, j, pivot;
    if(beg<end){
        pivot=beg;
        i=beg;
        j=end;
        while(i<j){
            while(a[j]>a[pivot]){j--;}
            while(a[i]<=a[pivot] && i<end){i++;}
            if(i<j){swap(&a[i],&a[j]);}
        }
        swap(&a[pivot],&a[j]);
        quicksort(a,beg,j-1);
        quicksort(a,j+1,end);
    }
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
    quicksort(a,0,n-1);
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<"After sorting array is: ";
    display(n,a);
    cout<<"Time is: "<<elapsed;
    return 0;
}
