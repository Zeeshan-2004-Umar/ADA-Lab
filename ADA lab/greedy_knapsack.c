#include <stdio.h>

int fractional_knapsack(int num_items, int max_weight, int weights[], int values[]) {
    int ratio[num_items];
    for (int i = 0; i < num_items; i++) {
        ratio[i] = (int) values[i] / weights[i];
    }
    int total_value = 0.0;
    int current_weight = 0;
    for (int i = 0; i < num_items; i++) {
        int max_index = -1;
        double max_ratio = -1.0;
        for (int j = 0; j < num_items; j++) {
            if (ratio[j] > max_ratio && weights[j] > 0) {
                max_ratio = ratio[j];
                max_index = j;
            }
        }
        if (max_index == -1) {
            break;
        }
        if (current_weight + weights[max_index] <= max_weight) {
            current_weight += weights[max_index];
            total_value += values[max_index];
            weights[max_index] = 0;
        } else {
            int remaining_weight = max_weight - current_weight;
            total_value += ratio[max_index] * remaining_weight;
            break;
        }
    }

    return total_value;
}

int main() {
    int num_items, max_weight;
    printf("Enter number of items: ");
    scanf("%d", &num_items);

    printf("Enter maximum weight of knapsack: ");
    scanf("%d", &max_weight);

    int weights[num_items], values[num_items];

    printf("Enter weight and value for each item:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &weights[i], &values[i]);
    }

    int max_value = fractional_knapsack(num_items, max_weight, weights, values);
    printf("Maximum value in knapsack = %d\n", max_value);

    return 0;
}

