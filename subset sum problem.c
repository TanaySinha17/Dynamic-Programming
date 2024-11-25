#include <stdio.h>

#define MAX 20

int weights[MAX], solution[MAX], n, target;

void sumOfSubsets(int sum, int index, int remaining) {
    if (sum == target) {
        printf("Solution: ");
        for (int i = 0; i < index; i++) {
            if (solution[i] == 1)
                printf("%d ", weights[i]);
        }
        printf("\n");
        return;
    }

    if (sum > target || index == n)
        return;

    solution[index] = 1; // Include the current element
    sumOfSubsets(sum + weights[index], index + 1, remaining - weights[index]);

    solution[index] = 0; // Exclude the current element
    sumOfSubsets(sum, index + 1, remaining - weights[index]);
}

int main() {
    int totalSum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
        totalSum += weights[i];
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    if (totalSum < target) {
        printf("No solution exists.\n");
    } else {
        sumOfSubsets(0, 0, totalSum);
    }

    return 0;
}
