#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1 ; 
int queue[MAX];
int front = -1;
int rear = -1;

void swap(int *a ,int *b){
    int gecici = *a;
    *a=*b;
    *b=gecici;
}

void bubbleSort(int dizi[] , int n){
    int i , j , gecici ;
    for (int i = 0 ; i < n-1 ; i++){
        for (j=0 ; j<n-i-1 ; j++)
            if (dizi[j]>dizi[j+1]){
                swap(&dizi[j],&dizi[j+1]);
                }
        }
    }

void selectionSort(int dizi[] , int n){
    int i , j , en_kucuk , gecici;
    for (i=0 ; i<n-1 ; i++){
        en_kucuk = i;
        for (j=i+1; j < n ; j++){
            if (dizi[j]<dizi[en_kucuk]){
                en_kucuk = j;
            }
        }
        swap(&dizi[en_kucuk],&dizi[i]);
    }

}

void insertionSort(int dizi[] , int n){
    int i , j , key ;
    for( i = 1; i < n; i++ ){
        key = dizi[i];
        j = i-1;
        while( j >= 0 && dizi[j] > key){
            dizi[j+1] = dizi[j];
            j--;
        }
        dizi[j+1] = key;
    }
}

int binarySearch(int dizi[], int boyut , int aranan){
    int bas = 0 ;
    int son = boyut - 1 ;
    
    while(bas<=son){
        int orta = (bas + son)/2;

        if (dizi[orta]==aranan){
            return orta;
        }
        if (aranan < dizi[orta]){
            son = orta - 1;
        }
        
        else{
            bas = orta + 1;
        }
    }
    return -1;
   } 

int linearSearch(int dizi[] , int n , int aranan){
    for (int i = 0 ; i < n ; i++){
        if (dizi[i]==aranan){
            return i;
        }
    }
    return -1;
}

void push(int veri){
    if (top==MAX-1){
        printf("STACK OVERFLOW ! ");
    }
    else {
        top++;
        stack[top]=veri;
    }
}

int pop() {
    if (top == -1) {
        return -1; 
    } else {
        int cikan = stack[top];
        top--;
        return cikan;
    }
}

void tersestack(char cumle[]){
    int i = 0;

    while(cumle[i]!='\0'){
        push(cumle[i]);
        i++;
    }
    while (top!=-1){
        printf("%c " , pop());
    }
}

void decimaltobinary(int sayi){

    while(sayi>0){
        int kalan = sayi%2;
        push(kalan);
        sayi=sayi/2;

    }
    while(top!=-1){
        printf("%d " , pop());
    }

}

int isPalindromeC(char cumle []){
    int i = 0 ;

    while(cumle[i] != '\0'){
        push(cumle[i]);
        i++;
    }

    while(cumle[i] != '\0'){
        if(cumle[i]!=pop()){
            return -1 ; 
        }
        i++;
    }
    return 1 ; 
}

int isPalindromeS(int sayi){
    int yedek = sayi;
    int orijinal = sayi; 

    while(yedek>0){
        push(yedek%10);
        yedek/=10;
    }

    while(orijinal>0){
        if( (orijinal%10) != pop()){
            return 0;
        }
        orijinal/=10;
    }
    return 1;
}

void enqueue(int veri){
    if (rear == MAX-1){
        printf("kuyruk dolu ! ");
        return ;
    }   
    if(front==-1){
        front = 0 ;
    }
    queue[++rear] = veri ; 
}

int dequeue(){
    if (front == -1 || front>rear){
        printf("kuyruk bos");
    }
    
    int cikan = queue[front];
    front++;
    
    if  (front > rear){
        front = -1 , rear = -1 ; 
    }
    return cikan ; 
}

void questackTers(char cumle []){
    int i=0;
    while (cumle[i] != '\0'){
        push(cumle[i]);
        i++;
    }
    while(top!=-1){
        enqueue(pop());
    }
    while (front != -1 && front<=rear){
        printf("%c",dequeue());
    }
}



typedef struct node{
    int data;
    struct node* next;
    struct node* prev;

}node;

node* ekle_tekyonlu(node* head , int veri , int index){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode==NULL) return head;
    newnode->data=veri;
    newnode->prev=NULL;
    if(index == 0 || head==NULL){
        newnode->next=head;
        return newnode;
    }
    node* temp = head;
    int i=0;
    
    while(i < index-1 && temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

node* sil_tekyonlu(node* head , int index){
    if(head==NULL) return NULL;

    node* temp = head;

    if(index==0){
        head=head->next;
        free(temp);
        return head;
    }
    int i=0;
    while(i < index-1 && temp->next!=NULL){
        temp=temp->next;
        i++;
    }

    if(temp->next==NULL){
        return head;
    }

    node* silinecek = temp->next;
    temp->next = silinecek->next;
    free(silinecek);
    return head;
}

node* ekle_ciftyonlu(node* head , int veri , int index){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode==NULL) return head;
    newnode->data=veri;

    if (head==NULL || index == 0){
        newnode->next = head;
        newnode->prev = NULL;
        if(head != NULL){
            head->prev=newnode;
        }return newnode; 
        }
    node*temp=head;
    int i = 0;

    while(temp->next!=NULL && i < index-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    newnode->prev=temp;

    if(temp->next!=NULL){
        temp->next->prev=newnode;
    }
    temp->next=newnode;

    return head;
}

node* sil_ciftyonlu(node*head , int index){
    if (head == NULL) return NULL;
    node* temp = head;
    
    if (index==0){
        head=head->next;
        if (head!=NULL){
            head->prev=NULL;
        }
        free(temp);
        return head;
    }

    int i=0;
    while(i<index && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp==NULL) {
        return head;
    }

    if (temp->prev !=NULL){
        temp->prev->next=temp->next;
    }

    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

node* ekle_tekyonludairesel(node* head , int veri , int index){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL) return head;
    newnode -> data = veri; 
    newnode -> prev = NULL;
    if (head == NULL){
        newnode->next=newnode;
        return newnode;
    }
    if (index == 0){
        node* son = head;
        while(son->next != head){
            son=son->next;
        }
        newnode->next=head;
        son->next=newnode;
        return newnode;
    }

    node* temp = head;
    int i=0;

    while(i<index-1 && temp->next != head){
        temp=temp->next;
        i++;
    }

    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

node* sil_tekyonludairesel(node* head , int index){
    if (head==NULL) return NULL;
    if(head->next == head){
        free(head);
        return NULL;
        }
    if (index==0){
        node* son = head;
        while(son->next!=head){
            son=son->next;
        }
        node* silinecek = head;
        head=head->next;
        son->next = head;
        free(silinecek);
        return head;
        }
    node* temp = head;
    int i=0;
    while(i<index-1 && temp->next!=head){
        temp=temp->next;
        i++;
        }
    if(temp->next==head){
        return head;
    } 
    node* silinecek = temp->next;
    temp->next = silinecek->next;
    free(silinecek);
    return head;
}

node* ekle_ciftyonludairesel(node* head , int veri , int index){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL) return head;
    newnode->data=veri;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(head==NULL){
        newnode->next=newnode;
        newnode->prev=newnode;
        return newnode;
        }

        node* son = head->prev;

        if (index==0){
            newnode->prev=son;
            newnode->next=head;
            head->prev=newnode;
            son->next=newnode;

            return newnode;
        }

        node*temp=head;
        int i=0;

        while(i<index-1 && temp->next!=head){
            temp=temp->next;
            i++;
        }

       newnode->next=temp->next;
       newnode->prev=temp;
       temp->next->prev=newnode;
       temp->next=newnode;
       
       return head;
}

node* sil_ciftyonludairesel(node*head , int index){
    if (head==NULL) return NULL;

    node* temp = head;

    if(head->next==head){
        free(head);
        return NULL;
    }
    
    int i=0;
    while(i<index && temp->next!=head){
        temp=temp->next;
        i++;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    if(i<index) return head;
    if(temp==head){
        head=temp->next;
    }
    free(temp);
    return head;
}
 
