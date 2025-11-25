#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>

// Рекуррентное суммирование
double sum_recurrent(double x, int N) {
    if (N < 1) return 0;

    double sum = 0;
    double a_n; // текущий член ряда

    // Первый член (n=1)
    a_n = ((3 * pow(x,2)) / 4); // (3!! * x^2) / (2!! * 2) = 3*x^2/4
    sum = a_n;

    // Последующие члены (n=2..N)
    for (int n = 2; n <= N; n++) {
        double ratio = (2.0 * n + 1.0) * (n - 1.0) * pow(x,2) / (2.0 * pow(n,2) * (2.0 * n - 1.0));
        a_n *= ratio; //((2 * n + 1) * (n - 1) / pow(2 * n, 2)) * pow(x, 2);
        sum += a_n;
    }

    return sum;
}

// Прямое суммирование (для проверки)
double sum_direct(double x, int N) {
    double sum = 0;

    for (int n = 1; n <= N; n++) {
        // Вычисляем (2n+1)!!
        double double_fact_odd = 1;
        for (int k = 1; k <= 2 * n + 1; k += 2) {
            double_fact_odd *= k;
        }

        // Вычисляем (2n)!!
        double double_fact_even = 1;
        for (int k = 2; k <= 2 * n; k += 2) {
            double_fact_even *= k;
        }

        double term = (double_fact_odd * pow(x, 2 * n)) / (double_fact_even * (2 * n));
        sum += term;
    }

    return sum;
}
int main() {
   
    double x;
    int N;
    setlocale(LC_ALL,"RU-ru");
    /*
    printf("Введите x: ");
    scanf("%lf", &x);
    printf("Введите N: ");
    scanf("%d", &N);

    if (N < 1) {
        printf("N должно быть >= 1\n");
        return 1;
    }

    double result_recurrent = sum_recurrent(x, N);
    double result_direct = sum_direct(x, N);

    printf("\nРезультаты:\n");
    printf("Рекуррентное суммирование: %.10f\n", result_recurrent);
    printf("Прямое суммирование:       %.10f\n", result_direct);
    printf("Разница:                   %.2e\n", fabs(result_recurrent - result_direct));

    // Дополнительная проверка для нескольких значений
    printf("\nПроверка для различных N:\n");
    printf("N\tРекуррентно\tПрямо\t\tРазница\n");
    for (int test_N = 1; test_N <= 10 && test_N <= N; test_N++) {
        double rec = sum_recurrent(x, test_N);
        double dir = sum_direct(x, test_N);
        printf("%d\t%.6f\t%.6f\t%.2e\n", test_N, rec, dir, fabs(rec - dir));
    }

    return 0;
    */
    double test_values[] = { 0.1, 0.5, 1.0, 1.5, 2.0 };
    int N_values[] = { 1, 3, 5, 8, 10 };

    printf("Сравнение методов суммирования:\n");
    printf("x\tN\tРекуррентно\tПрямо\t\tРазница\t\tОтн.ошибка\n");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            double x = test_values[i];
            int N = N_values[j];

            double rec = sum_recurrent(x, N);
            double dir = sum_direct(x, N);
            double diff = fabs(rec - dir);
            double rel_error = diff / fmax(fabs(rec), fabs(dir));

            printf("%.1f\t%d\t%.8f\t%.8f\t%.2e\t%.2e\n",
                x, N, rec, dir, diff, rel_error);
        }
    }

}