#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

void equals(){
    int n, a[MAX_SIZE];
    printf("Enter array length: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter number: ");
        scanf("%d", &a[i]);
    }

    int max_length = 1, current_length = 1, best_start = 0, start_index = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == a[i-1]){
            current_length++;
        }else {
            if (current_length > max_length){
                max_length = current_length;
                best_start = start_index;
            }
            current_length = 1;
            start_index = i;
        }
    }
    if (current_length > max_length){
        max_length = current_length;
        best_start = start_index;
    }
    printf("Start: %d\nLength: %d\n", best_start, max_length);    
}

void relations(){
    int n, a[MAX_SIZE];
    printf("Enter array length: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("Enter number: ");
        scanf("%d", &a[i]);
    }

    bool valid = true;
    for (int i = 0; i < n-1; i++){
        if (i % 2 == 0){
            if(!(a[i] < a[i+1])) valid = false;
        } else {
            if (!(a[i] > a[i+1])) valid = false;
        }
    }
    if (valid) printf("The relations are right!");
    else printf("The relations are wrong!");
}

void reversed_array(){
    int n, a[MAX_SIZE];
    printf("Enter array length: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("Enter number: ");
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n/2; i++){
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
    printf("Reversed array:\n");
    for (int i = 0; i < n; i++) printf("%d", a[i]);
}

void row_move(){
    int n, a[MAX_SIZE], k, result[MAX_SIZE];
    printf("Enter array length: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter number: ");
        scanf("%d", &a[i]);
    }

    printf("Enter position: ");
    scanf("%d", &k);

    k = k % n;
    for (int i = 0; i < n; i++){
        result[(i + k) % n] = a[i];
    }
    for (int i = 0; i < n; i++) printf("%d", result[i]);
}

void chosen_element(){
    int n, a[MAX_SIZE], k;
    printf("Enter array length: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("Enter number: ");
        scanf("%d", &a[i]);
    }

    printf("Enter chosen element: ");
    scanf("%d", &k);

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] < a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    if(k > 0 && k <= n) printf("%d biggest element is: %d", k, a[k-1]);
}

void longest_rising_or_falling() {
    int n, a[MAX_SIZE];
    printf("Enter array length: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter number: ");
        scanf("%d", &a[i]);
    }

    int max_length = 1, current_length = 1, end_index = 0;
//up
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i-1]) {
            current_length++;
        } else {
            if(current_length > max_length) {
                max_length = current_length;
                end_index = i - 1;
            }
            current_length = 1;
        }
    }
    if(current_length > max_length) {
        max_length = current_length;
        end_index = n - 1;
    }
//down
    current_length = 1; 
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1]) {
            current_length++;
        } else {
            if(current_length > max_length) {
                max_length = current_length;
                end_index = i - 1;
            }
            current_length = 1;
        }
    }

    if(current_length > max_length) {
        max_length = current_length;
        end_index = n - 1;
    }

    printf("The longest row: ");
    int startIdx = end_index - (max_length - 1);
    for(int i = startIdx; i <= end_index; i++) {
        printf("%d ", a[i]);
    }
}

void equal_to_sum(){
    int n, a[MAX_SIZE], target;
    printf("Enter array length: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("Enter number: ");
        scanf("%d", &a[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    for (int i = 0 ; i < n; i++){
        int sum = 0;
        for (int j = i; j < n; j++){
            sum += a[j];
            if (sum == target){
                for(int m = i; m <= j; m++) printf("%d", a[m]);
                printf("\n");
                return;
            }
        }
    }
}

void number_and_index() {
    int a[20], n = 0, val, pos;

    printf("Enter initial data (0 for end): ");
    while (n < 20) {
        if (scanf("%d", &val) != 1 || val == 0) break;
        a[n++] = val;
    }

    printf("Enter number and position (0 for number to end):\n");
    while (n < 20) {
        if (scanf("%d", &val) != 1 || val == 0) break;
        if (scanf("%d", &pos) != 1) break;

        if (pos > n) pos = n;
        if (pos < 0) pos = 0;

        for (int i = n; i > pos; i--) {
            a[i] = a[i - 1];
        }

        a[pos] = val;
        n++; 

        printf("Current array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
    }
}

void equal_numbers() {
    int n, a[MAX_SIZE];
    printf("Enter array length: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter number: ");
        scanf("%d", &a[i]);
    }

    int max_length = 0, current_length = 1, best_val = a[0];
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[i+1]) {
            current_length++;
        } else {
            if(current_length > max_length) {
                max_length = current_length;
                best_val = a[i];
            }
            current_length = 1;
        }
    }
    if(current_length > max_length) {
        max_length = current_length;
        best_val = a[n-1];
    }
    for(int i = 0; i < max_length; i++) printf("%d ", best_val);
}

int main(){
    int choice;
    printf("Enter task to run: ");
    scanf("%d", &choice);

    switch(choice){
        case 1: equals(); break;
        case 2: relations(); break;
        case 3: reversed_array(); break;
        case 4: row_move(); break;
        case 5: chosen_element(); break;
        case 6: longest_rising_or_falling(); break;
        case 7: equal_to_sum(); break;
        case 8: number_and_index(); break;
        case 9: equal_numbers(); break;
        default: printf("Invalid task number!");
    }
    return 0;
}