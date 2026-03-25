#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void pointers_demonstration() {
    int i = 100;
    int *p = &i;

    printf("Address of i: %x\n", &i);
    printf("Address in pointer: %x\n", p);
    printf("Pointer: %d\n", *p);
}

void pointer_operations(int a, int b){
    int *pa = &a;
    int *pb = &b;

    printf("Sum = %d\n", *pa + *pb);
    printf("Difference = %d\n", *pa - *pb);
    printf("Multiplication = %d\n", (*pa) * (*pb));
    if(*pb != 0){
        printf("Division: %d\n", (*pa) / (*pb));
    }
}

void entry(int n, int array[MAX_SIZE][MAX_SIZE]){
    printf("Enter values in the %d * %d matrix: \n", n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Enter number: [%d][%d]", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", array[i][j]); 
        }
        printf("\n");
    }
}

void diagonals(int n, int array[MAX_SIZE][MAX_SIZE]){
    printf("Glaven diagonal: ");
    for (int i = 0; i < n; i++){
        printf("%d\n", array[i][i]);
    }

    printf("Vtorostepenen diagonal: ");
    for (int i = 0; i < n; i++){
        printf("%d\n", array[i][n - 1 - i]);
    }
}

void around_diagonals(int n, int matrix[MAX_SIZE][MAX_SIZE]) {
    printf("Elements above: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i) printf("%d\n", matrix[i][j]);
        }
    }

    printf("Elements below: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) printf("%d\n", matrix[i][j]); 
        }
    }
}

void check_magic(int n, int array[MAX_SIZE][MAX_SIZE]){
    int magic_sum = 0;
    for (int j = 0; j < n; j++) magic_sum += array[0][j]; 
    int magic_check = 1;

    for (int i = 0; i < n; i++) {
        int row_sum = 0, col_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += array[i][j];
            col_sum += array[j][i];
        }
        if (row_sum != magic_sum || col_sum != magic_sum) {
            magic_check = 0;
            break;
        }
    }

    if (magic_check) printf("\nKvadratat E magicheski! Suma: %d\n", magic_sum);
    else printf("\nKvadratat NE E magicheski.\n");
}

int main(){
    //pointers_demonstration();
    //pointer_operations(48, 24);

    int n;
    printf("Enter size of square matrix: ");
    scanf("%d", &n);
    int array[MAX_SIZE][MAX_SIZE];

    entry(n, array);
    diagonals(n, array);
    around_diagonals(n, array);
    check_magic(n, array);

    return 0;
}