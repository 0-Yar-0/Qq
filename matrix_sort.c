#include <stdio.h>
#include <stdlib.h>

void sort_matrix(int **matrix, int N, int M);
int compare(const void *a, const void *b);
int compare_desc(const void *a, const void *b);

int main() {
    int N, M;

    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("n/a\n");
        return 1;
    }

    if (scanf("%d %d", &M, &N) != 2 || M <= 0 ||N<=0) {
        printf("n/a\n");
        return 1;
    }

    int **matrix = (int **)malloc(N * sizeof(int *));
    if (!matrix) {
        printf("n/a\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        matrix[i] = (int *)malloc(M * sizeof(int));
        if (!matrix[i]) {
            printf("n/a\n");
            return 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("n/a\n");
                return 1;
            }
        }
    }

    sort_matrix(matrix, N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

int compare(const void *a, const void *b) {
    int sum_a = *((int*)a + 1);
    int sum_b = *((int*)b + 1);
    return sum_a - sum_b;
}

int compare_desc(const void *a, const void *b) {
    int sum_a = *((int*)a + 1);
    int sum_b = *((int*)b + 1);
    return sum_b - sum_a;
}

void sort_matrix(int **matrix, int N, int M) {
    int *sums = malloc(N * sizeof(int));
    if (!sums) {
        printf("n/a\n");
        return;
    }
    
    for (int i = 0; i < N; i++) {
        sums[i] = 0;
        for (int j = 0; j < M; j++) {
            sums[i] += matrix[i][j];
        }
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (sums[i] > sums[j]) {
                int *temp = matrix[i];
                matrix[i] = matrix[j];
                matrix[j] = temp;
                int temp_sum = sums[i];
                sums[i] = sums[j];
                sums[j] = temp_sum;
            }
        }
    }

    free(sums);
}
