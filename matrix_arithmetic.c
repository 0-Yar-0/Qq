#include <stdio.h>
#include <stdlib.h>

void input(int **matrix, int n, int m);
void output(int **matrix, int n, int m);
int sum(int **matrix1, int **matrix2, int n, int m);
int transpose(int ***matrix, int n, int m);
int mul(int ***matrix1, int **matrix2, int n1, int m1, int m2);

int main() {
    int operation;
    int n, m, n2, m2;

    if (scanf("%d", &operation) != 1 || operation < 1 || operation > 3) {
        printf("n/a\n");
        return 1;
    }

    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("n/a\n");
        return 1;
    }

    int **matrix1 = (int **)malloc(n * sizeof(int *));
    if (!matrix1) {
        printf("n/a\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        matrix1[i] = (int *)malloc(m * sizeof(int));
        if (!matrix1[i]) {
            printf("n/a\n");
            return 1;
        }
    }

    input(matrix1, n, m);

    if (operation == 1) {
        if (scanf("%d %d", &n2, &m2) != 2 || n2 != n || m2 != m) {
            printf("n/a\n");
            return 1;
        }

        int **matrix2 = (int **)malloc(n2 * sizeof(int *));
        if (!matrix2) {
            printf("n/a\n");
            return 1;
        }
        for (int i = 0; i < n2; i++) {
            matrix2[i] = (int *)malloc(m2 * sizeof(int));
            if (!matrix2[i]) {
                printf("n/a\n");
                return 1;
            }
        }

        input(matrix2, n2, m2);

        if (!sum(matrix1, matrix2, n, m)) {
            printf("n/a\n");
            return 1;
        }

        output(matrix1, n, m);

        for (int i = 0; i < n2; i++) {
            free(matrix2[i]);
        }
        free(matrix2);
    } else if (operation == 2) {
        if (scanf("%d %d", &n2, &m2) != 2 || m != n2) {
            printf("n/a\n");
            return 1;
        }

        int **matrix2 = (int **)malloc(n2 * sizeof(int *));
        if (!matrix2) {
            printf("n/a\n");
            return 1;
        }
        for (int i = 0; i < n2; i++) {
            matrix2[i] = (int *)malloc(m2 * sizeof(int));
            if (!matrix2[i]) {
                printf("n/a\n");
                return 1;
            }
        }

        input(matrix2, n2, m2);

        if (!mul(&matrix1, matrix2, n, m, m2)) {
            printf("n/a\n");
            return 1;
        }

        output(matrix1, n, m2);

        for (int i = 0; i < n2; i++) {
            free(matrix2[i]);
        }
        free(matrix2);
    } else if (operation == 3) {
        if (!transpose(&matrix1, n, m)) {
            printf("n/a\n");
            return 1;
        }

        output(matrix1, m, n);
    }

    for (int i = 0; i < n; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    return 0;
}

void input(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("n/a\n");
                exit(1);
            }
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int sum(int **matrix1, int **matrix2, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix1[i][j] += matrix2[i][j];
        }
    }
    return 1;
}

int transpose(int ***matrix, int n, int m) {
    int **temp = (int **)malloc(m * sizeof(int *));
    if (!temp) {
        return 0;
    }
    for (int i = 0; i < m; i++) {
        temp[i] = (int *)malloc(n * sizeof(int));
        if (!temp[i]) {
            for (int k = 0; k < i; k++) {
                free(temp[k]);
            }
            free(temp);
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[j][i] = (*matrix)[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        free((*matrix)[i]);
    }
    free(*matrix);

    *matrix = temp;

    return 1;
}

int mul(int ***matrix1, int **matrix2, int n1, int m1, int m2) {
    int **result = (int **)malloc(n1 * sizeof(int *));
    if (!result) {
        return 0;
    }
    for (int i = 0; i < n1; i++) {
        result[i] = (int *)malloc(m2 * sizeof(int));
        if (!result[i]) {
            for (int k = 0; k < i; k++) {
                free(result[k]);
            }
            free(result);
            return 0;
        }
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m1; k++) {
                result[i][j] += (*matrix1)[i][k] * matrix2[k][j];
            }
        }
    }

    for (int i = 0; i < n1; i++) {
        free((*matrix1)[i]);
    }
    free(*matrix1);

    *matrix1 = result;

    return 1;
}
