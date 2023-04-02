#include<iostream>
#include<time.h>
//CHAINING
#define tsize 10
using namespace std;
typedef struct node node;
struct node{
    int info;
    node *next;
};
node *h[tsize],*temp;
void insert_hashtable(int data){
    int ptr=data % tsize;
    node *head1= (node *)malloc(sizeof(node));
    head1->info=data;
    head1->next=NULL;
    if(h[ptr]==NULL)
        h[ptr]=head1;
    else{
        temp=h[ptr];
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=head1;
    }
}
void direct_search(int data){
    int p=data % tsize;
    if(h[p]==NULL){cout<<"Element not found\n";}
    else{
        int j=0;
        for(temp=h[p];temp!=NULL;temp=temp->next){
            if(temp->info==data){
                cout<<"Element found at position: "<<j<<" of "<<p<<endl;
                break;}
            j++;}
        if(temp==NULL)
            cout<<"Element not found in the table\n";
    }
}
int main()
{
    int data,loc;
    int n,key,pos;
    for(int i=0;i<tsize;i++){
        h[i]=NULL;}
    cout<<"Data items are: ";
    for(int i=0;i<tsize;i++){
        data=rand()%tsize;
        cout<<data<<" ";
        insert_hashtable(data);}
    cout<<endl;
    cout<<"Hash table: \n";
    node *head,*temp;
    for(int i=0;i<11;i++){
        if(h[i]==NULL){
            cout<<i<<"  -1 ";}
        else{
            cout << i <<"  " << h[i]->info;
            temp = h[i];
            while (temp->next != NULL){
                cout << "-> " << temp->next->info << " ";
                temp = temp->next;}}
        cout<<endl;
    }
    cout<<"\nEnter an element to be searched: ";
    cin>>key;
    clock_t start = clock();
    direct_search(key);
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<"Time is: "<<elapsed;
    return 0;
}
