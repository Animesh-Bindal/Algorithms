#include<iostream>
#include<time.h>
using namespace std;
//COUNT SORT
void display(int n, int a[]){
    for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";}
    cout<<endl;
}
void count_sort(int a[],int n){
    int *b=(int *)malloc(n*sizeof(int));
    int min=a[0],max=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max)
            max=a[i];
        else if(a[i]<min)
            min=a[i];}
    int k=max-min+1;
    int *c=(int *)malloc((k)*sizeof(int));
    for(int i=0;i<k;i++)
        c[i]=0;
    for(int j=0;j<n;j++)
        c[a[j]-min]=c[a[j]-min]+1;
    // display(k,c);
    for(int i=1;i<k;i++)
        c[i]+=c[i-1];
    // display(k,c);
    for(int j=n-1;j>=0;j--){
        b[c[a[j]-min]-1]=a[j]-min;
        c[a[j]-min]--;}
    // display(n,b);
    for(int i=0;i<n;i++)
        a[i]=b[i]+min;
    // display(n,a);
}
int main(){
    int *a; int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        a[i]=rand()%n;
    cout<<"Before sorting array is: ";
    display(n,a);
    clock_t start = clock();
    count_sort(a,n);
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<"After sorting array is: ";
    display(n,a);
    cout<<"Time is: "<<elapsed;
    return 0;
}
