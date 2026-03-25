#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void fillArrayRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 10001) - 5000;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int taskSum(int arr[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) s += arr[i];
    return s;
}

int taskMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

double taskAverage(int arr[], int n) {
    int s = taskSum(arr, n);
    return (double)s / n;
}

void taskClosestToAverage(int arr[], int n) {
    double avg = taskAverage(arr, n);
    double minDiff = fabs(arr[0] - avg);
    int closestNum = arr[0];
    int position = 0;

    for (int i = 1; i < n; i++) {
        double currentDiff = fabs(arr[i] - avg);
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
            closestNum = arr[i];
            position = i;
        }
    }
    printf("\n   - Number: %d\n   - Index: %d\n", closestNum, position);
}

int main() {
    int numbers[7];
    int n = 7;
    srand(time(NULL));
    fillArrayRandom(numbers, n);
    printArray(numbers, n);

    printf("Sum: %d\n", taskSum(numbers, n));
    
    printf("Biggest number: %d\n", taskMax(numbers, n));
    
    double avg = taskAverage(numbers, n);
    printf("Average: %.3f\n", avg);
    
    printf("Closest: ");
    taskClosestToAverage(numbers, n);

    return 0;
}
