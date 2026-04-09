#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void rows_and_columns() {
    int n, m;
    printf("Enter N and M: ");
    if (scanf("%d %d", &n, &m) != 2) return;

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) { 
        matrix[i] = (int *)malloc(m * sizeof(int));
    } 
    printf("Enter elements:\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    bool rows_ok = true;
    bool cols_ok = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (matrix[i][j] >= matrix[i][j + 1]) {
                rows_ok = false;
                break; 
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (matrix[i][j] <= matrix[i + 1][j]) {
                cols_ok = false;
                break; 
            }
        }
    }
    printf("Rows increasing: %s, Columns decreasing: %s\n", 
           rows_ok ? "Yes" : "No", cols_ok ? "Yes" : "No");

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
} 

void max_neighbor_sum() {
    int n, m;
    printf("Enter N and M: ");
    if (scanf("%d %d", &n, &m) != 2) return;

    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) a[i] = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);

    int max_sum = -2121212121;
    int target_val = a[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int current_sum = 0;
            for (int ni = i - 1; ni <= i + 1; ni++) {
                for (int nj = j - 1; nj <= j + 1; nj++) {
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && !(ni == i && nj == j)) {
                        current_sum += a[ni][nj];
                    }
                }
            }
            if (current_sum > max_sum) {
                max_sum = current_sum;
                target_val = a[i][j];
            }
        }
    }
    printf("Number with biggest neighbor sum (%d) is: %d\n", max_sum, target_val);

    for (int i = 0; i < n; i++) free(a[i]);
    free(a);
}

void swap_min_max_rows() {
    int n, m;
    printf("Enter N and M: ");
    if (scanf("%d %d", &n, &m) != 2) return;

    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) mat[i] = (int *)malloc(m * sizeof(int));

    int min_val = 2121212121, max_val = -2121212121;
    int min_row = 0, max_row = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] < min_val) { min_val = mat[i][j]; min_row = i; }
            if (mat[i][j] > max_val) { max_val = mat[i][j]; max_row = i; }
        }
    }

    if (min_row != max_row) {
        int *temp = mat[min_row];
        mat[min_row] = mat[max_row];
        mat[max_row] = temp;
    }
    printf("Result after switching row %d and %d:\n", min_row, max_row);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%d ", mat[i][j]);
        printf("\n");
        free(mat[i]);
    }
    free(mat);
}

void friends() {
    int n, m;
    printf("Enter people count (N) and friends (M): ");
    if (scanf("%d %d", &n, &m) != 2) return;

    int *friend_counts = (int *)calloc(n + 1, sizeof(int));

    printf("Enter %d friendships:\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u <= n && v <= n) {
            friend_counts[u]++;
            friend_counts[v]++;
        }
    }
    int query;
    printf("Enter person number: ");
    scanf("%d", &query);
    if (query <= n) {
        printf("Person %d has %d friends.\n", query, friend_counts[query]); 
    }

    free(friend_counts);
}

void kids_software() {
    int *data = NULL;
    int size = 0;
    int command, x;

    printf("Comands: 1 (Add), 2 (Delete), 3 (Smallest), 0 (Exit)\n");
    while (scanf("%d", &command) && command != 0) {
        if (command == 1) { 
            scanf("%d", &x);
            data = (int *)realloc(data, (size + 1) * sizeof(int));
            data[size++] = x;
        } 
        else if (command == 2) { 
            scanf("%d", &x);
            int new_size = 0;
            for (int i = 0; i < size; i++) {
                if (data[i] != x) data[new_size++] = data[i]; 
            }
            size = new_size;
            data = (int *)realloc(data, size * sizeof(int));
        } 
        else if (command == 3) { 
            scanf("%d", &x);
            if (x > 0 && x <= size) {
                qsort(data, size, sizeof(int), compare);
                printf("%d-th smallest is: %d\n", x, data[x - 1]);
            }
        }
    }
    free(data);
}

void process_primes() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1) return;

    int *arr = (int *)malloc(n * sizeof(int));
    int *primes = (int *)malloc(n * sizeof(int));
    int p_count = 0, remaining_count = 0;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (is_prime(val)) {
            primes[p_count++] = val; 
        } else {
            arr[remaining_count++] = val;
        }
    }
    printf("Original array: ");
    for (int i = 0; i < remaining_count; i++) printf("%d ", arr[i]);
    printf("\nSecond array: ");
    for (int i = 0; i < p_count; i++) printf("%d ", primes[i]); 
    printf("\n");

    free(arr);
    free(primes);
}

void submatrix() {
    int n, m;
    printf("Enter N and M: ");
    scanf("%d %d", &n, &m);

    if (n < 3 || m < 3) {
        printf("The matrix is too small.\n");
        return;
    }

    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) scanf("%d", &mat[i][j]); 
    }
    int max_sum = -2121212121, best_r = 0, best_c = 0;

    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            int current_sum = 0;
            for (int r = i; r < i + 3; r++)
                for (int c = j; c < j + 3; c++) current_sum += mat[r][c];

            if (current_sum > max_sum) {
                max_sum = current_sum;
                best_r = i;
                best_c = j;
            }
        }
    }
    printf("Matrix with max sum:\n");
    for (int i = best_r; i < best_r + 3; i++) {
        for (int j = best_c; j < best_c + 3; j++) printf("%d ", mat[i][j]);
    }
    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
}

void insert() {
    int size = 10;
    int *arr = (int *)malloc(100 * sizeof(int));

    printf("Enter the first 10 numbers: ");
    for (int i = 0; i < 10; i++) scanf("%d", &arr[i]); 

    int value, index;
    printf("Enter number index: ");
    while (scanf("%d", &value) && value != 0) {
        scanf("%d", &index);
        
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }
    printf("Result: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    free(arr);
}

int main(){
    int choice;
    printf("Enter task to run: ");
    scanf("%d", &choice);

    switch(choice){
        case 1: rows_and_columns(); break;
        case 2: max_neighbor_sum(); break;
        case 3: swap_min_max_rows(); break;
        case 4: friends(); break;
        case 5: kids_software(); break;
        case 6: process_primes();
        case 7: submatrix(); break;
        case 8: insert(); break;
        default: printf("Invalid task number!");
    }
    return 0;
}