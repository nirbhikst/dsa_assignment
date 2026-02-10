// prog_8.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long long comps;
    long long swaps;
} Stats;

void swap(int *a,int *b){ int t=*a; *a=*b; *b=t; }

void print_arr(int a[], int n){
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
}

void bubble(int a[], int n, Stats *st){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            st->comps++;
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                st->swaps++;
            }
        }
    }
}

void selection(int a[], int n, Stats *st){
    for(int i=0;i<n-1;i++){
        int mn=i;
        for(int j=i+1;j<n;j++){
            st->comps++;
            if(a[j]<a[mn]) mn=j;
        }
        if(mn!=i){
            swap(&a[i],&a[mn]);
            st->swaps++;
        }
    }
}

void insertion(int a[], int n, Stats *st){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0){
            st->comps++;
            if(a[j]>key){
                a[j+1]=a[j];
                st->swaps++; // treating shifts as swaps/moves for “applicable”
                j--;
            } else break;
        }
        a[j+1]=key;
    }
}

void merge(int a[], int l, int m, int r, Stats *st){
    int n1=m-l+1, n2=r-m;
    int *L=(int*)malloc(n1*sizeof(int));
    int *R=(int*)malloc(n2*sizeof(int));
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int j=0;j<n2;j++) R[j]=a[m+1+j];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        st->comps++;
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];

    free(L); free(R);
}

void merge_sort(int a[], int l, int r, Stats *st){
    if(l>=r) return;
    int m=(l+r)/2;
    mergesort(a,l,m,st);
    mergesort(a,m+1,r,st);
    merge(a,l,m,r,st);
}

int main(){
    int N;
    printf("Enter N: ");
    if(scanf("%d",&N)!=1 || N<=0){ printf("Invalid N\n"); return 0; }

    int *a=(int*)malloc(N*sizeof(int));
    int *b=(int*)malloc(N*sizeof(int));
    srand((unsigned)time(NULL));

    for(int i=0;i<N;i++){
        a[i]= (rand()%1000)+1;
        b[i]=a[i];
    }

    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("> ");
    int ch; scanf("%d",&ch);

    Stats st={0,0};

    printf("\nBefore sorting:\n");
    print_arr(b,N);

    switch(ch){
        case 1: bubble(b,N,&st); break;
        case 2: selection(b,N,&st); break;
        case 3: insertion(b,N,&st); break;
        case 4: mergesort(b,0,N-1,&st); break;
        default: printf("Invalid choice\n"); free(a); free(b); return 0;
    }

    printf("\nAfter sorting:\n");
    print_arr(b,N);

    printf("\nComparisons: %lld\n", st.comps);
    printf("Swaps/Moves (if applicable): %lld\n", st.swaps);

    free(a); free(b);
    return 0;
}
