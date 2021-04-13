#include "menu.h"
#include "co_num.h"
#include "my_array.h"
#include "tests.h"


void my_sum_int(float* val) {
    int t;
    printf("на  сколько увеличить данный элемент?\n");
    scanf_s("%d", &t);
    *val = *val + t;
}

void my_sum_float(float* val) {
    int t;
    printf("на  сколько увеличить данный элемент?\n");
    scanf_s("%d", &t);
    *val = *val + t;
}

void my_sum_double(double* val) {
    int t;
    printf("на  сколько увеличить данный элемент?\n");
    scanf_s("%d", &t);
    *val = *val + t;
}

void my_mult_int(int* val) {
    int t;
    printf("во сколько увеличить данный элемент?\n");
    scanf_s("%d", &t);
    *val = *val * t;
}

void my_mult_float(float* val) {
    int t;
    printf("во сколько увеличить данный элемент?\n");
    scanf_s("%d", &t);
    *val = *val * t;
}
void my_mult_double(double* val) {
    int t;
    printf("во сколько увеличить данный элемент?\n");
    scanf_s("%d", &t);
    *val = *val * t;
}
bool less_int(int* a, int* b)
{
    return  *a < *b;
}
bool less_float(float* a, float* b)
{
    return  *a < *b;
}
bool less_double(double* a, double *b)
{
    return  *a < *b;
}
int get_int(int* n, int down, int up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err, num;

    do {
        err = scanf_s("%d", &num);
        if (err < 0) {
            exit(0);
        }
        if ((num < down || num > up) && k) {
            err = 0;
            printf("Неворно! Повторите попытку!\n::");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}

double get_double(double* n, double down, double up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err;
    double num;

    do {
        err = scanf_s("%lf", &num);
        if (err < 0) {
            exit(0);
        }
        if ((num < down || num > up) && k) {
            err = 0;
            printf("Неворно! Повторите попытку!\n::");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}

float get_float(float* n, float down, float up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err;
    float num;

    do {
        err = scanf_s("%f", &num);
        if (err < 0) {
            exit(0);
        }
        if ((num < down || num > up) && k) {
            err = 0;
            printf("Неворно! Повторите попытку!\n::");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}

complex* get_complex() {
    printf("Введите действительную часть числа: ");
    float a = get_float(NULL, 0, 0);
    printf("Введите мнимую часть числа: ");
    float b = get_float(NULL, 0, 0);
    complex* res = new_complex(a, b);
    return res;
}

Array* fill_array_int() {
    int t;
    Array* array;
    for (array->count = 1; array->count <= array->_allocated; array->count += 1) {
        printf("введите элемент массива\n");
        t = get_int(NULL, 0, 0);
        if (!array_set(array, array->count - 1, &t))
            return false;

    }
    array->count -= 1;
    return array;
}


Array* fill_array_float() {
    float t;
    Array* array;
    for (array->count = 1; array->count <= array->_allocated; array->count += 1) {
        printf("введите элемент массива\n");
        t = get_float(NULL, 0, 0);
        if (!array_set(array, array->count - 1, &t))
            return false;

    }
    array->count -= 1;
    return array;
}

Array* fill_array_double() {
    double t;
    Array* array;
    for (array->count = 1; array->count <= array->_allocated; array->count += 1) {
        printf("введите элемент массива\n");
        t = get_double(NULL, 0, 0);
        if (!array_set(array, array->count - 1, &t))
            return false;

    }
    array->count -= 1;
    return array;
}

Array* fill_array_complex() {
    complex *t;
    Array* array;
    for (array->count = 1; array->count <= array->_allocated; array->count += 1) {
        printf("введите элемент массива\n");
        t = get_complex(NULL, 0, 0);
        if (!array_set(array, array->count - 1, &t))
            return false;

    }
    array->count -= 1;
    return array;
}
void print_menu() {
    printf("выберите действие:\n"
        "\t1: изменить массив\n"
        "\t2: вывести массив\n"
        "\t3: Для удаления массива из памяти\n"
        "\t4: тестировать\n"
        "\t5: Для выхода из программы\n"
        "Введите число: ");
}
void print_menu_change() {
    printf("выберите действие:\n"
        "\t1: увеличить на \n"
        "\t2: увеличить в \n"
        "\t3: сортировать \n"
        "\t4: добавить элемент в конец \n"
        "\t5: убрать последний элемент \n"
        "Введите число: ");
}

Array* new_array() {
    int n, m, s, l, k, i, t;
    float f;
    double d;
    printf("Выберете тип массива:\n "
        "\t1: целочисленный массив\n"
        "\t2: массив вещественных  чисел\n"
        "\t3: массив вещественных чисел двойной точности\n"
        "\t4: массив комплексных чисел\n:");

    get_int(&n, 1, 4);
    Array* res;

    switch (n) {
    case 1: res = fill_array_int();
            do{
                print_menu();
                scanf_s("%d", &m);
                if (m > 5 || m < 1) {
                    printf("Неправильно введено число, повторите попытку: ");
                    continue;
                }
                if (m == 5) break;
                switch (m) {
                case 1: do {
                            print_menu_change();
                            scanf_s("%d", &s);
                            if (s > 5 || s < 1) {
                                printf("Неправильно введено число, повторите попытку: ");
                                 continue;
                            }
                            switch (s) {
                            case 1: array_map(res, my_sum_int); break;
                            case 2: array_map(res, my_mult_int); break;
                            case 3: array_qsort(res, 0, res->count - 1, less_int); break;
                            case 4: k = get_int(NULL, 0, 0);
                                array_push_back(res, &k); break;
                            case 5: array_pop_back(res); break;
                            }
                        }while (1);
                break;
                case 2:
                    for (size_t i = 0; i < res->count; ++i) {
                        array_get(res, i, &t);
                        printf("%d\n", t);
                    } break;
                case 3: array_free(res); break;
                case 4: test(); break;
                default: break;
            }while (1);
    break;
    case 2: res = fill_array_float();
            do {
                print_menu();
                scanf_s("%d", &m);
                if (m > 5 || m < 1) {
                    printf("Неправильно введено число, повторите попытку: ");
                    continue;
                }
                if (m == 5) break;
                switch (m) {
                case 1: do {
                            print_menu_change();
                            scanf_s("%d", &s);
                            if (s > 5 || s < 1) {
                                printf("Неправильно введено число, повторите попытку: ");
                                continue;
                            }
                            switch (s) {
                            case 1: array_map(res, my_sum_float); break;
                            case 2: array_map(res, my_mult_float); break;
                            case 3: array_qsort(res, 0, res->count - 1, less_float); break;
                            case 4: k = get_float(NULL, 0, 0);
                                    array_push_back(res, &k); break;
                            case 5: array_pop_back(res); break;
                        }while (1);
                break;
                case 2:
                    for (size_t i = 0; i < res->count; ++i) {
                        array_get(res, i, &f);
                        printf("%f\n", f);
                    } break;
                case 3: array_free(res); break;
                case 4: test(); break;
                default: break;
            } while (1);
            }
            break;
    case 3: res = fill_array_double();
        do {
            print_menu();
            scanf_s("%d", &m);
            if (m > 5 || m < 1) {
                printf("Неправильно введено число, повторите попытку: ");
                continue;
            }
            if (m == 5) break;
            switch (m) {
            case 1: do {
                print_menu_change();
                scanf_s("%d", &s);
                if (s > 5 || s < 1) {
                    printf("Неправильно введено число, повторите попытку: ");
                    continue;
                }
                switch (s) {
                case 1: array_map(res, my_sum_double); break;
                case 2: array_map(res, my_mult_double); break;
                case 3: array_qsort(res, 0, res->count - 1, less_double); break;
                case 4: k = get_double(NULL, 0, 0);
                    array_push_back(res, &k); break;
                case 5: array_pop_back(res); break;
                }while (1);
                break;
            case 2:
                for (size_t i = 0; i < res->count; ++i) {
                    array_get(res, i, &d);
                    printf("%lf\n", d);
                } break;
            case 3: array_free(res); break;
            case 4: test(); break;
            default: break;
            } while (1);
            }break;
    case 4: res = fill_array_complex(); break;
    default: res = NULL; break;
    }
    if (n >= 1 && n <= 4 && res == NULL) {
        printf("Не удалось создать массив!\n");
    }
    return res;
}