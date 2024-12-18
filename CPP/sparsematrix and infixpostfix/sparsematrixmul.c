#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Sparse {
    int row;
    int col;
    int value;
};

void transpose();
void readMatrix();
void Multiplication();

int main() {
    struct Sparse *S, *L, *b;
    S = (struct Sparse *)malloc(10 * sizeof(struct Sparse));
    L = (struct Sparse *)malloc(10 * sizeof(struct Sparse));
    readMatrix(&S);
    readMatrix(&L);
    b = (struct Sparse *)malloc(10 * sizeof(struct Sparse));
    transpose(&L, &b);
    Multiplication(S, b);
    free(S);
    free(L);
    free(b);
    return 0;
}

void readMatrix(struct Sparse **k) {
    int i;
    *k = (struct Sparse *)malloc(10 * sizeof(struct Sparse));
    printf("Enter the Dimensions:");
    scanf("%d %d", &(*k)[0].row, &(*k)[0].col);
    printf("Enter the number of Non-zero values:");
    scanf("%d", &(*k)[0].value);
    printf("Enter the triples");
    for (i = 1; i <= (*k)[0].value; i++) {
        scanf("%d %d %d", &(*k)[i].row, &(*k)[i].col, &(*k)[i].value);
    }
}

void Multiplication(struct Sparse *S, struct Sparse *b) {
    int i, j, k = 1;
    struct Sparse *A = (struct Sparse *)calloc(20, sizeof(struct Sparse));
    A[0].row = S[0].row;
    A[0].col = b[0].row;
    for (i = 1; i <= S[0].value; i++) {
        for (j = 1; j <= b[0].value; j++) {
            if (S[i].col == b[j].col) {
                A[k].row = S[i].row;
                A[k].col = b[j].row;
                A[k].value = (S[i].value * b[j].value);
                k++;
            }
        }
    }
    int z=0;
    for (i = 1; i <= S[0].value; i++) {
        for (j = i+1; j <= b[0].value; j++) {
            if(A[i].row==A[j].row && A[i].col==A[j].col){
                  A[i].value=A[i].value+A[j].value;
                   for(z=j;z<k;z++){
                      A[z].row=A[z+1].row;
                      A[z].col=A[z+1].col;
                      A[z].value=A[z+1].value;
                   }
                   k--;
                   j--;
               }
            
        }
     }
    A[0].value =--k;
    printf("Multiplication of transpose matrix is:\n");
    for (i = 0; i <=k; i++) {
        printf("%d   %d   %d\n", A[i].row, A[i].col, A[i].value);
    }
    free(A);
}

void transpose(struct Sparse **L, struct Sparse **b) {
    *b = (struct Sparse *)malloc(10 * sizeof(struct Sparse));
    int c = (*b)[0].row = (*L)[0].col;
    int r = (*b)[0].col = (*L)[0].row;
    int n = (*b)[0].value = (*L)[0].value;
    int i, j, curB;
    if (n > 0) {
        curB = 1;
        for (i = 0; i < c; i++) {
            for (j = 1; j < n + 1; j++) {
                if (i == (*L)[j].col) {
                    (*b)[curB].row = (*L)[j].col;
                    (*b)[curB].col = (*L)[j].row;
                    (*b)[curB].value =(*L)[j].value;
                    curB++;
                }
            }
        }
    }
}