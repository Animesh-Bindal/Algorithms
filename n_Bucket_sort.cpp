#include<iostream>
#include<time.h>
#include<malloc.h>
using namespace std;
//BUCKET SORT
struct node{
    double data;
    struct node * next;
};
void display(int n, double a[]){
    for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";}
    cout<<endl;
}
void bucketing(struct node arr[],int n,int loc,double k){
    if(arr[loc].data==-1)
        arr[loc].data=k;
    else{
        struct node *ptr=&arr[loc];
        struct node *p=(struct node *)malloc(sizeof(struct node));
        struct node *temp=ptr;
        p->data=-1;
        while(ptr!=NULL){
            if(ptr->data>=k){
                p->data=k;
                break;}
            temp=ptr;
            ptr=ptr->next;}
        if(p->data==-1){
            temp->next=(struct node *)malloc(sizeof(struct node));
            temp=temp->next;
            temp->data=k;
            temp->next=NULL;}
        else if(ptr==(&arr[loc])){
            p->next=ptr->next;
            temp->next=p;
            p->data=temp->data;
            temp->data=k;}
        else{
            p->next=ptr;
            temp->next=p;}
    }
}
void bucket_sort(double arr[],int n,struct node a[]){
    int loc;
    for(int i=0;i<n;i++){
        loc=(int(arr[i]));
        bucketing(a,n,loc,arr[i]);}
    int k=0;
    for(int i=0;i<n;i++){
        if(a[i].data!=-1){
            arr[k]=a[i].data;
            k++;}
        struct node * ptr=&a[i];
        while(ptr->next!=NULL){
            ptr=ptr->next;
            arr[k]=ptr->data;
            k++;}
    }
}
int main()
{
    struct node *a;
    double * arr;
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    a=(struct node *)malloc(n*sizeof(struct node));
    arr=(double *)malloc(n*sizeof(double));
    for(int i=0;i<n;i++){
        a[i].data=-1;
        a[i].next=NULL;}
    srand(time(0));
    for(int i=0;i<n;i++)
        arr[i]=((float) rand()/RAND_MAX)*10;
    cout<<"Before sorting array is: ";
    display(n,arr);
    clock_t start = clock();
    bucket_sort(arr,n,a);
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<"After sorting array is: ";
    display(n,arr);
    cout<<"Time is: "<<elapsed;
    return 0;
}
