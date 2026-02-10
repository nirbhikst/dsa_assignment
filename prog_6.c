// prog_6.c
#include <stdio.h>

void swap(int *a,int *b){ int t=*a; *a=*b; *b=t; }

void heapify_max(int a[], int n, int i){
    int largest=i;
    int l=2*i+1, r=2*i+2;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i){
        swap(&a[i], &a[largest]);
        heapify_max(a,n,largest);
    }
}

void build_max_heap(int a[], int n){
    for(int i=n/2-1; i>=0; i--) heapify_max(a,n,i);
}

void heapify_min(int a[], int n, int i){
    int smallest=i;
    int l=2*i+1, r=2*i+2;
    if(l<n && a[l]<a[smallest]) smallest=l;
    if(r<n && a[r]<a[smallest]) smallest=r;
    if(smallest!=i){
        swap(&a[i], &a[smallest]);
        heapify_min(a,n,smallest);
    }
}

void build_min_heap(int a[], int n){
    for(int i=n/2-1; i>=0; i--) heapify_min(a,n,i);
}

void print_arr(const int a[], int n){
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int a[]={4,10,3,5,1,2,8};
    int n=sizeof(a)/sizeof(a[0]);

    int maxh[100], minh[100];
    for(int i=0;i<n;i++){ maxh[i]=a[i]; minh[i]=a[i]; }

    printf("Original: "); print_arr(a,n);

    build_max_heap(maxh,n);
    printf("Max-Heap: "); print_arr(maxh,n);

    build_min_heap(minh,n);
    printf("Min-Heap: "); print_arr(minh,n);

    return 0;
}
