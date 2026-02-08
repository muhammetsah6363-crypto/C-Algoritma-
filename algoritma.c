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

void yazdir(int dizi[] , int n){
    for(int i=0;i<n;i++){
        printf("%d " , dizi[i]);
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

int main(){
    questackTers("merhaba dunya");
    return 0;
}