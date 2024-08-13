#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result);
void sub(int *buff1, int len1, int *buff2, int len2, int *result);
void printResult(int *result, int len);

int main() {
    int num1[LEN] = {0}; // первое большое число
    int num2[LEN] = {0}; // второе большое число
    int sumResult[LEN + 1] = {0}; // результат сложения
    int subResult[LEN] = {0}; // результат вычитания
    int len1, len2;

    // Считывание первого числа
    printf("Введите длину первого числа: ");
    scanf("%d", &len1);
    printf("Введите первое число: ");
    for (int i = 0; i < len1; i++) {
        scanf("%d", &num1[i]);
    }

    // Считывание второго числа
    printf("Введите длину второго числа: ");
    scanf("%d", &len2);
    printf("Введите второе число: ");
    for (int i = 0; i < len2; i++) {
        scanf("%d", &num2[i]);
    }

    // Сложение
    sum(num1, len1, num2, len2, sumResult);
    printf("Сумма: ");
    printResult(sumResult, LEN + 1);

    // Вычитание
    printf("Разность: ");
    sub(num1, len1, num2, len2, subResult);

    return 0;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result) {
    int carry = 0, i = 0;
    
    while (i < len1 || i < len2 || carry) {
        int value1 = (i < len1) ? buff1[i] : 0;
        int value2 = (i < len2) ? buff2[i] : 0;

        int sum = value1 + value2 + carry;
        result[i] = sum % 10; // берем последнюю цифру
        carry = sum / 10; // перенос
        i++;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result) {
    // Проверка на случай если buff1 < buff2
    if (len1 < len2 || (len1 == len2 && buff1[len1 - 1] < buff2[len2 - 1])) {
        printf("n/a\n");
        return;
    }

    int borrow = 0, i = 0;

    while (i < len1) {
        int value1 = buff1[i];
        int value2 = (i < len2) ? buff2[i] : 0;

        if (value1 < value2 + borrow) {
            value1 += 10;
            result[i] = value1 - value2 - borrow;
            borrow = 1;
        } else {
            result[i] = value1 - value2 - borrow;
            borrow = 0;
        }
        i++;
    }

    // Удаляем ведущие нули из результата
    int start = len1 - 1;
    while(start > 0 && result[start] == 0) {
        start--;
    }

    // Если результат пустой, выводим 0
    if (start == 0 && result[0] == 0) {
        printf("0\n");
    } else {
        for (int j = start; j >= 0; j--) {
            printf("%d", result[j]);
        }
        printf("\n");
    }
}

void printResult(int *result, int len) {
    int start = len - 1;
    while(start > 0 && result[start] == 0) {
        start--;
    }

    if (start == 0 && result[0] == 0) {
        printf("0\n");
    } else {
        for (int j = start; j >= 0; j--) {
            printf("%d", result[j]);
        }
        printf("\n");
    }
}
