#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
FILE* fp;//������ļ�
int re_ten();//����10���ڵ�����
float fl_ten();//����10���ڸ�����
int re_hundred();//����100��������
float fl_hundred();//����100���ڸ�����
int symbol();//����Ӽ��˳��ĸ�����
//��������Ӧ�û�Ҫ����ú���
void display_single_int(int n, int rang, int add, int sub, int mul, int div, int way);
void display_single_float(int n, int rang, int add, int sub, int mul, int div, int way);
void display_brackte1(int n, int rang, int add, int sub, int mul, int div, int way);
void display_brackte2(int n, int rang, int add, int sub, int mul, int div, int way);
int main()
{
    int n, intger, brackets;//������Ŀ����,������С���ķ�ʽ,����
    int add, sub, mul, div;//����Ӽ��˳��ķ���
    int way;//�Ƿ���Ҫ������ļ���
    int rang;//��ʽ��Χ
    printf("Сѧ��������\n");
    printf("�붨����Ŀ������\n");
    cin >> n;
    printf("�����������(0Ϊ10,1Ϊ100)\n");
    cin >> rang;
    printf("�Ƿ���Ҫ'+'(1Ϊ��Ҫ,0Ϊ����)\n");
    cin >> add;
    printf("�Ƿ���Ҫ'-'(1Ϊ��Ҫ,0Ϊ����)\n");
    cin >> sub;
    printf("�Ƿ���Ҫ'*'(1Ϊ��Ҫ,0Ϊ����)\n");
    cin >> mul;
    printf("�Ƿ���Ҫ'/'(1Ϊ��Ҫ,0Ϊ����)\n");
    cin >> div;
    printf("��������(1Ϊ����,0Ϊ������)\n");
    cin >> intger;
    printf("��ʽ�Ƿ��������(1Ϊ��Ҫ,0Ϊ����)\n");
    cin >> brackets;
    printf("�Ƿ���Ҫ������ļ�(1Ϊ��Ҫ,0Ϊ����)\n");
    cin >> way;
    if (intger == 1)
    {//����
        switch (brackets)//���ų��ֵ����
        {
        case 1:
            display_brackte1(n, rang, add, sub, mul, div, way);
            break;
        case 0:
            display_single_int(n, rang, add, sub, mul, div, way);
            break;
        }

    }
    if (intger == 0)
    {//Ҫ�󸡵�������
        switch (brackets)
        {
        case 1:
            display_brackte2(n, rang, add, sub, mul, div, way);
            break;
        case 0:
            display_single_float(n, rang, add, sub, mul, div, way);
            break;
        }
    }
    return 0;
}

//����0~10�������
int re_ten()
{
    int a;
    // srand((unsigned)time(NULL));
    a = rand() % 11;
    return a;
}
//����0~100�������
int re_hundred()
{
    int a;
    //srand((unsigned)time(NULL));
    a = rand() % 101;
    return a;
}
//����0~10�����������
float fl_ten()
{
    float x, a = 0.5, b = 10.1;
    x = (rand() % 10001) / 10000.0;
    x = x * (b - a) + a;
    return x;
}

float fl_hundred()
{
    float a = 0.5, b = 100.1;
    float x;
    x = (rand() % 101) / 100.0;
    x = x * (b - a) + a;
    return x;

}
//����1��4����Ӽ��˳�
int symbol()
{
    int a, b;
    //srand((unsigned)time(NULL));
    a = rand() % 100;
    b = a / 25;
    b++;
    return b;
}
//����+��һ����
void display_single_int(int n, int rang, int add, int sub, int mul, int div, int way)
{
    int a, b, c, i;
    srand(time(0));//����ϵͳʱ���������������
    fp = fopen("D:\\text.txt", "w");
    for (i = 0; i < n; i++)
    {
        c = symbol();
        if (rang == 0)
        {
            a = re_ten();
            b = re_ten();
        }
        if (rang == 1)
        {//����0-100������
            a = re_hundred();
            b = re_hundred();
        }
        if (add == 1 && c == 1)//����Ӻų���
        {
            cout << a << "+" << b << "=" << endl;
            if (way == 1)
            {
                if ((fp = fopen("D:\\text.txt", "a")) == NULL)
                {//�����ļ�ʧ��
                    printf("error��\n");
                    exit(0);
                }
                else
                {
                    fprintf(fp, "%d+%d=\n", a, b);
                }
            }
        }
        if (sub == 1 && c == 2)
        {
            if (a > b)
            {
                cout << a << "-" << b << "=" << endl;
                if (way == 1)
                {
                    if ((fp = fopen("D:\\text.txt", "a")) == NULL)
                    {
                        printf("error��\n");
                        exit(0);
                    }
                    else
                    {
                        fprintf(fp, "%d-%d=\n", a, b);
                    }
                }
            }
            else
            {
                cout << b << "-" << a << "=" << endl;
                if (way == 1)
                {//�û�Ҫ��������ļ���
                    if ((fp = fopen("D:\\text.txt", "a")) == NULL)
                    {
                        printf("error��\n");
                        exit(0);
                    }
                    else
                    {
                        fprintf(fp, "%d+%d=\n", b, a);
                    }
                }
            }
        }
        if (mul == 1 && c == 3)
        {
            cout << a << "*" << b << "=" << endl;
            if (way == 1)
            {
                if ((fp = fopen("D:\\text.txt", "a")) == NULL)
                {
                    printf("error��\n");
                    exit(0);
                }
                else
                {
                    fprintf(fp, "%d*%d=\n", a, b);
                }
            }
        }
        if (div == 1 && c == 4)
        {
            cout << a << "/" << b << "=" << endl;
            if (way == 1)
            {
                if ((fp = fopen("D:\\text.txt", "a")) == NULL)
                {
                    printf("error��\n");
                    exit(0);
                }
                else
                {
                    fprintf(fp, "%d/%d=\n", a, b);
                }
            }
        }

    }

}

//������+��һ����ʱ
void display_single_float(int n, int rang, int add, int sub, int mul, int div, int way)
{
    int c, i;
    float a, b;
    srand(time(0));//����ϵͳʱ���������������
    fp = fopen("D:\\text.txt", "w");
    for (i = 0; i < n; i++)
    {
        c = symbol();
        if (rang == 0)
        {
            a = fl_ten();
            b = fl_ten();
        }
        if (rang == 1)
        {
            a = re_hundred();
            b = re_hundred();
        }
        if (add == 1 && c == 1)
        {
            printf("%.2f+%.2f=\n", a, b);
            if (way == 1)
            {
                if ((fp = fopen("D:\\text.txt", "a")) == NULL)
                {
                    printf("error��\n");
                    exit(0);
                }
                else
                {
                    fprintf(fp, "%.2f+%.2f=\n", a, b);
                }
            }
        }
        if (sub == 1 && c == 2)
        {
            if (a > b)
            {
                printf("%.2f-%.2f=\n", a, b);
                if (way == 1)
                {
                    if ((fp = fopen("D:\\text.txt", "a")) == NULL)
                    {
                        printf("error��\n");
                        exit(0);
                    }
                    else
                    {
                        fprintf(fp, "%.2f-%.2f=\n", a, b);
                    }
                }
            }
            else
            {
                printf("%.2f-%.2f=\n", b, a);
                if (way == 1)
                {
                    if ((fp = fopen("D:\\text.txt", "a")) == NULL)
                    {
                        printf("error��\n");
                        exit(0);
                    }
                    else
                    {
                        fprintf(fp, "%.1f-%.1f=\n", b, a);
                    }
                }
            }
        }
        if (mul == 1 && c == 3)
        {
            printf("%.2f*%.2f=\n", a, b);
            if (way == 1)
            {
                if ((fp = fopen("D:\\text.txt", "a")) == NULL)
                {
                    printf("error��\n");
                    exit(0);
                }
                else
                {
                    fprintf(fp, "%.2f*%.2f=\n", a, b);
                }
            }
        }
        if (div == 1 && c == 4)
        {
            printf("%.2f/%.2f=\n", a, b);
            if (way == 1)
            {
                if ((fp = fopen("D:\\text.txt", "a")) == NULL)
                {
                    printf("error��\n");
                    exit(0);
                }
                else
                {
                    fprintf(fp, "%.2f/%.2f=\n", a, b);
                }
            }
        }

    }

}
//����+��������ʽ��
void display_brackte1(int n, int rang, int add, int sub, int mul, int div, int way)
{
    srand(time(0));//����ϵͳʱ���������������
    fp = fopen("D:\\text.txt", "w");
    int a, b, c, d, c1;
    for (int i = 0; i < n; i++)
    {
        c = symbol();//1��4�������
        if (rang == 0)
        {
            a = re_ten();
            b = re_ten();
            d = re_ten();
        }
        if (rang == 1)
        {
            a = re_hundred();
            b = re_hundred();
            d = re_hundred();
        }
        if (add == 1 && c == 1)
        {
            c1 = symbol();
            if (sub == 1 && c1 == 2)
            {
                printf("%d-(%d+%d)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%d-(%d+%d)\n", d, a, b);
                }

            }
            if (mul == 1 && c1 == 3)
            {
                printf("%d*(%d+%d)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%d*(%d+%d)\n", d, a, b);
                }

            }
            if (div == 1 && c1 == 4)
            {
                printf("(%d+%d)/%d\n", a, b, d);
                if (way == 1)
                {
                    fprintf(fp, "%d+%d)/%d\n", a, b, d);
                }

            }
        }
        if (sub == 1 && c == 2)
        {
            c1 = symbol();
            if (add == 1 && c1 == 1)
            {
                printf("%d-(%d+%d)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%d-(%d+%d)\n", d, a, b);
                }
            }
            if (mul == 1 && c1 == 3)
            {
                printf("%d*(%d-%d)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%d*(%d-%d)\n", d, a, b);
                }
            }
            if (div == 1 && c1 == 4)
            {
                printf("(%d-%d)/%d\n", a, b, d);
                if (way == 1)
                {
                    fprintf(fp, "(%d-%d)/%d\n", a, b, d);
                }
            }
        }
        if (mul == 1 && c == 3)
        {
            c1 = symbol();
            if (add == 1 && c1 == 1)
            {
                printf("(%d+%d)/%d\n", a, b, d);
                if (way == 1)
                {
                    fprintf(fp, "(%d+%d)/%d\n", a, b, d);
                }
            }
            if (sub == 1 && c1 == 2)
            {
                printf("%d/(%d-%d)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%d/(%d-%d)\n", d, a, b);
                }
            }
            if (div == 1 && c1 == 4)
            {
                printf("%d*(%d/%d)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%d*(%d/%d)\n", d, a, b);
                }

            }

        }
        if (div == 1 && c == 4)
        {
            c1 = symbol();
            if (add == 1 && c1 == 1)
            {
                printf("(%d+%d)/%d\n", a, b, d);
                if (way == 1)
                {
                    fprintf(fp, "(%d+%d)/%d\n", a, b, d);
                }
            }
            if (sub == 1 && c1 == 2)
            {
                printf("%d/(%d-%d)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%d/(%d-%d)\n", d, a, b);
                }
            }
            if (mul == 1 && c1 == 3)
            {
                printf("(%d*%d)/%d\n", a, b, d);
                if (way == 1)
                {
                    fprintf(fp, "(%d*%d)/%d\n", a, b, d);
                }
            }
        }
    }
}
//������+����
void display_brackte2(int n, int rang, int add, int sub, int mul, int div, int way)
{
    srand(time(0));//����ϵͳʱ���������������
    fp = fopen("D:\\text.txt", "w");
    int c, c1, i;
    float a, b, d;
    for (i = 0; i < n; i++)
    {
        c = symbol();//1��4�������
        if (rang == 0)
        {
            a = fl_ten();
            b = fl_ten();
            d = fl_ten();
        }
        if (rang == 1)
        {
            a = fl_hundred();
            b = fl_hundred();
            d = fl_hundred();
        }
        if (add == 1 && c == 1)
        {
            c1 = symbol();
            if (sub == 1 && c1 == 2)
            {
                printf("%.2f-(%.2f+%.2f)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%.2f-(%.2f+%.2f)\n", d, a, b);
                }

            }
            if (mul == 1 && c1 == 3)
            {
                printf("%.2f*(%.2f+%.2f)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%.2f*(%.2f+%.2f)\n", d, a, b);
                }

            }
            if (div == 1 && c1 == 4)
            {
                printf("(%.2f+%.2f)/%.2f\n", a, b, d);
                if (way == 1)
                {
                    fprintf(fp, "%.2f+%.2f)/%.2f\n", a, b, d);
                }

            }
        }
        if (sub == 1 && c == 2)
        {
            c1 = symbol();
            if (add == 1 && c1 == 1)
            {
                printf("%.2f-(%.2f+%.2f)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%.2f-(%.2f+%.2f)\n", d, a, b);
                }
            }
            if (mul == 1 && c1 == 3)
            {
                printf("%.2f*(%.2f-%.2f)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%.2f*(%.2f-%.2f)\n", d, a, b);
                }
            }
            if (div == 1 && c1 == 4)
            {
                printf("(%.2f-%.2f)/%.2f\n", a, b, d);
                if (way == 1)
                {
                    fprintf(fp, "(%.2f-%.2f)/%.2f\n", a, b, d);
                }
            }
        }
        if (mul == 1 && c == 3)
        {
            c1 = symbol();
            if (add == 1 && c1 == 1)
            {
                printf("(%.2f+%.2f)/%.2f\n", a, b, d);
                if (way == 1)
                {
                    fprintf(fp, "(%.2f+%.2f)/%.2f\n", a, b, d);
                }
            }
            if (sub == 1 && c1 == 2)
            {
                printf("%.2f/(%.2f-%.2f)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%.2f/(%.2f-%.2f)\n", d, a, b);
                }
            }
            if (div == 1 && c1 == 4)
            {
                printf("%.2f*(%.2f/%.2f)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%.2f*(%.2f/%.2f)\n", d, a, b);
                }

            }

        }
        if (div == 1 && c == 4)
        {
            c1 = symbol();
            if (add == 1 && c1 == 1)
            {
                printf("(%.2f+%.2f)/%.2f\n", a, b, d);
                if (way == 1)
                {
                    fprintf(fp, "(%.2f+%.2f)/%.2f\n", a, b, d);
                }
            }
            if (sub == 1 && c1 == 2)
            {
                printf("%.2f/(%.2f-%.2f)\n", d, a, b);
                if (way == 1)
                {
                    fprintf(fp, "%.2f/(%.2f-%.2f)\n", d, a, b);
                }
            }
            if (mul == 1 && c1 == 3)
            {
                printf("(%.2f*%.2f)/%.2f\n", a, b, d);
                if (way == 1)
                {
                    fprintf(fp, "(%.2f*%.2f)/%.2f\n", a, b, d);
                }
            }
        }
    }
}
