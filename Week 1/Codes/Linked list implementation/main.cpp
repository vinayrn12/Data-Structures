#include <iostream>

using namespace std;

struct list{
    int data;
    struct list* next;
};
list *newnode, *currptr, *prevptr,*start=NULL, *last=NULL;

list *getnode(int value){
    newnode = new list;
    if(newnode == NULL){
        cout<<"\nMemory was not allocated\n";
        return 0;
    }
    else{
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }
}

void insert_begin(){
    int value;
    cout<<"\nEnter node value: ";
    cin>>value;
    newnode = getnode(value);
    currptr = start;
    if(start ==  NULL){
        start = newnode;
        last = newnode;
    }
    else{
        start = newnode;
        start->next = currptr;
    }
    cout<<"\nNode inserted\n";
}

void insert_end(){
    int value;
    cout<<"\nEnter node value: ";
    cin>>value;
    currptr = start;
    newnode = getnode(value);
    if(start == NULL){
        start = newnode;
        last = newnode;
    }
    else{
        last->next = newnode;
        last = newnode;
    }
    cout<<"\nNode inserted\n";
}

void insert_pos(){
    int pos, c=0, value;
    cout<<"\nEnter the position for the element: ";
    cin>>pos;
    currptr = start;
    while(currptr != NULL){
        c++;
        currptr = currptr->next;
    }
    if(pos == 1){
        insert_begin();
    }
    else if(pos <= c){
        currptr = start;
        cout<<"\nEnter node value: ";
        cin>>value;
        newnode = getnode(value);
        for(int i=1; i<pos-1; i++)
            currptr = currptr->next;
        newnode->next = currptr->next;
        currptr->next = newnode;
        cout<<"\nNode inserted\n";
    }
    else if(pos == c+1){
        insert_end();
    }
    else{
        cout<<"\nInvalid position. Try anything between 1 and "<<c+1<<endl;
    }
}

void display(){
    if(start == NULL)
        cout<<"\nList empty\n";
    else{
        cout<<"\nList elements: ";
        for(currptr=start; currptr != last; currptr=currptr->next)
            cout<<currptr->data<<"\t";
        cout<<currptr->data<<endl;
    }
}

void delete_begin(){
    if(start == NULL)
        cout<<"\n List is already empty\n";
    else if(start->next == NULL){
         start = NULL;
         cout<<"\nNode deleted\n";
    }
    else{
        currptr=start;
        start=currptr->next;
        free(currptr);
        cout<<"\nNode deleted\n";
    }
}

void delete_end(){
    if(start == NULL)
        cout<<"\n List is already empty\n";
    else if(start->next == NULL){
         start = NULL;
         cout<<"\nNode deleted\n";
    }
    else{
        for(currptr=start; currptr->next!=last; currptr=currptr->next);
        currptr->next = NULL;
        last=currptr;
        free(currptr);
        cout<<"\nNode deleted\n";
    }
}

void delete_pos(){
    int pos, c=0;
    cout<<"\nEnter the position for the element: ";
    cin>>pos;
    currptr = start;
    while(currptr != NULL){
        c++;
        currptr = currptr->next;
    }
    if(pos == 1){
        delete_begin();
    }
    else if(pos < c){
        prevptr = NULL;
        currptr = start;
        for(int i=1; i<pos; i++){
            prevptr = currptr;
            currptr = currptr->next;
        }
        prevptr->next = currptr->next;
        free(currptr);
        cout<<"\nNode deleted\n";
    }
    else if(pos == c){
        delete_end();
    }
    else{
        cout<<"\nInvalid position. Try anything between 1 and "<<c<<endl;
    }
}

int main()
{
    int n;
    while(true){
        cout<<"\n----\n";
        cin>>n;
        switch(n){
            case 1: insert_begin();
                    break;
            case 2: insert_end();
                    break;
            case 3: insert_pos();
                    break;
            case 4: delete_begin();
                    break;
            case 5: delete_end();
                    break;
            case 6: delete_pos();
                    break;
            case 9: display();
                    break;
            case 8: delete newnode;
                    delete currptr;
                    delete prevptr;
                    delete start;
                    delete last;
                    exit(0);
                    break;
            default: cout<<"\nEnter the correct choice\n";
        }
    }
    return 0;
}
