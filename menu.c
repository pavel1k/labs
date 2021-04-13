#include "menu.h"
#include "co_num.h"
#include "my_array.h"
#include "tests.h"


void my_sum_int(float* val) {
    int t;
    printf("��  ������� ��������� ������ �������?\n");
    scanf_s("%d", &t);
    *val = *val + t;
}

void my_sum_float(float* val) {
    int t;
    printf("��  ������� ��������� ������ �������?\n");
    scanf_s("%d", &t);
    *val = *val + t;
}

void my_sum_double(double* val) {
    int t;
    printf("��  ������� ��������� ������ �������?\n");
    scanf_s("%d", &t);
    *val = *val + t;
}

void my_mult_int(int* val) {
    int t;
    printf("�� ������� ��������� ������ �������?\n");
    scanf_s("%d", &t);
    *val = *val * t;
}

void my_mult_float(float* val) {
    int t;
    printf("�� ������� ��������� ������ �������?\n");
    scanf_s("%d", &t);
    *val = *val * t;
}
void my_mult_double(double* val) {
    int t;
    printf("�� ������� ��������� ������ �������?\n");
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
            printf("�������! ��������� �������!\n::");
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
            printf("�������! ��������� �������!\n::");
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
            printf("�������! ��������� �������!\n::");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}

complex* get_complex() {
    printf("������� �������������� ����� �����: ");
    float a = get_float(NULL, 0, 0);
    printf("������� ������ ����� �����: ");
    float b = get_float(NULL, 0, 0);
    complex* res = new_complex(a, b);
    return res;
}

Array* fill_array_int() {
    int t;
    Array* array;
    for (array->count = 1; array->count <= array->_allocated; array->count += 1) {
        printf("������� ������� �������\n");
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
        printf("������� ������� �������\n");
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
        printf("������� ������� �������\n");
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
        printf("������� ������� �������\n");
        t = get_complex(NULL, 0, 0);
        if (!array_set(array, array->count - 1, &t))
            return false;

    }
    array->count -= 1;
    return array;
}
void print_menu() {
    printf("�������� ��������:\n"
        "\t1: �������� ������\n"
        "\t2: ������� ������\n"
        "\t3: ��� �������� ������� �� ������\n"
        "\t4: �����������\n"
        "\t5: ��� ������ �� ���������\n"
        "������� �����: ");
}
void print_menu_change() {
    printf("�������� ��������:\n"
        "\t1: ��������� �� \n"
        "\t2: ��������� � \n"
        "\t3: ����������� \n"
        "\t4: �������� ������� � ����� \n"
        "\t5: ������ ��������� ������� \n"
        "������� �����: ");
}

Array* new_array() {
    int n, m, s, l, k, i, t;
    float f;
    double d;
    printf("�������� ��� �������:\n "
        "\t1: ������������� ������\n"
        "\t2: ������ ������������  �����\n"
        "\t3: ������ ������������ ����� ������� ��������\n"
        "\t4: ������ ����������� �����\n:");

    get_int(&n, 1, 4);
    Array* res;

    switch (n) {
    case 1: res = fill_array_int();
            do{
                print_menu();
                scanf_s("%d", &m);
                if (m > 5 || m < 1) {
                    printf("����������� ������� �����, ��������� �������: ");
                    continue;
                }
                if (m == 5) break;
                switch (m) {
                case 1: do {
                            print_menu_change();
                            scanf_s("%d", &s);
                            if (s > 5 || s < 1) {
                                printf("����������� ������� �����, ��������� �������: ");
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
                    printf("����������� ������� �����, ��������� �������: ");
                    continue;
                }
                if (m == 5) break;
                switch (m) {
                case 1: do {
                            print_menu_change();
                            scanf_s("%d", &s);
                            if (s > 5 || s < 1) {
                                printf("����������� ������� �����, ��������� �������: ");
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
                printf("����������� ������� �����, ��������� �������: ");
                continue;
            }
            if (m == 5) break;
            switch (m) {
            case 1: do {
                print_menu_change();
                scanf_s("%d", &s);
                if (s > 5 || s < 1) {
                    printf("����������� ������� �����, ��������� �������: ");
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
        printf("�� ������� ������� ������!\n");
    }
    return res;
}