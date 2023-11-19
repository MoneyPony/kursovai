#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
struct Course
{
    char name[50];
    char instructor[50];
    char tema[50];
    double rating;
    double cost;
    int time;
};
int safeInputInt(const char prompt[]);
double safeInputDouble(const char prompt[]);
void bubbleSort(struct Course arr[], int n);
void displayWelcomeScreen();
void inputCourseInfo(struct Course* course);
void printCourse(struct Course* course);

int main()
{
    setlocale(LC_ALL, "RUS");
    struct Course courses[100];
    int courseCount = 0;
    int choice;

    system("chcp 1251");
    do
    {
        displayWelcomeScreen();
        printf("������� ��� �����: ");
        choice = safeInputInt("");
        switch (choice)
        {
        case 1:
            if (courseCount < 100)
            {
                struct Course newCourse;
                inputCourseInfo(&newCourse);
                courses[courseCount] = newCourse;
                courseCount++;
                printf("���� ������� ��������!\n");
            }
            else
            {
                printf("���������� ������������ ���������� ������!\n");
            }
            break;
        case 2:
            if (courseCount == 0)
            {
                printf("��� ��������� ������\n");
            }
            else
            {
                char searchName[50];
                printf("������� �������� ����� ��� ������: ");
                scanf("%49s", searchName);
                int found = 0;
                for (int i = 0; i < courseCount; i++)
                {
                    if (strcmp(courses[i].name, searchName) == 0)
                    {
                        printf("��������: %s\n", courses[i].name);
                        printf("�������������: %s\n", courses[i].instructor);
                        printf("����: %s\n", courses[i].tema);
                        printf("�������: %.2f\n", courses[i].rating);
                        printf("���������: %.2f\n", courses[i].cost);
                        printf("������������: %d\n", courses[i].time);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    printf("���� � ��������� ��������� �� ������\n");
                }
            }
            break;
        case 3:
            if (courseCount == 0)
            {
                printf("��� ��������� ������\n");
            }
            else
            {
                float searchCost;
                printf("������� ��������� ����� ��� ������: ");
                scanf("%f", &searchCost);
                int found = 0;
                for (int i = 0; i < courseCount; i++)
                {
                    if (courses[i].cost == searchCost)
                    {
                        printf("��������: %s\n", courses[i].name);
                        printf("�������������: %s\n", courses[i].instructor);
                        printf("����: %s\n", courses[i].tema);
                        printf("�������: %.2f\n", courses[i].rating);
                        printf("���������: %.2f\n", courses[i].cost);
                        printf("������������: %d\n", courses[i].time);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    printf("����� � ��������� ���������� �� �������\n");
                }
            }
            break;
        case 4:
            if (courseCount == 0)
            {
                printf("��� ��������� ������ ��� ����������\n");
            }
            else
            {
                bubbleSort(courses, courseCount);
                printf("����� ������� ������������� �� ��������!\n");
            }
            break;
        case 5:
            printf("����� �� ���������\n");
            break;
        default:
            printf("������������ �����. ����������, ���������� �����\n");
            break;
        }
    } while (choice != 5);
}

int safeInputInt(const char prompt[])
{
    int value;
    char input[50];
    while (1)
    {
        printf("%s", prompt);
        scanf(" %[^\n]s", input);
        char* endptr;
        value = strtol(input, &endptr, 10);
        if (*endptr == '\0')
        {
            break;
        }
        else
        {
            printf("������ �����. ����������, ������� ���������� ����� �����.\n");
            while (getchar() != '\n');
        }
    }
    return value;
}

double safeInputDouble(const char prompt[])
{
    double value;
    char input[50];

    while (1)
    {
        printf("%s", prompt);
        scanf(" %[^\n]s", input);
        char* dotPosition = strchr(input, '.');
        if (dotPosition != NULL)
        {
            *dotPosition = ',';
        }
        char* endptr;
        value = strtod(input, &endptr);
        if (*endptr == '\0')
        {
            break;
        }
        else
        {
            printf("������ �����. ����������, ������� ���������� �����.\n");
            while (getchar() != '\n');
        }
    }
    return value;
}

void bubbleSort(struct Course arr[], int n)
{
    int i, j;
    struct Course temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].rating > arr[j + 1].rating)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayWelcomeScreen()
{
    printf("����� ���������� � ��������� ���������� ���������������� �������!\n");
    printf("_________________________________________________________________\n");
    printf("����:\n");
    printf("1. �������� ����\n");
    printf("2. ����� ����� �� ��������\n");
    printf("3. ����� ����� �� ���������\n");
    printf("4. ������� ������ ������\n");
    printf("5. ����������� ����� �� ��������\n");
    printf("6. ����� �� ���������\n");
    printf("-----------------------------------------------------------------\n");
}

void inputCourseInfo(struct Course* course)
{
    printf("������� �������� �����: ");
    scanf("%49s", course->name);
    printf("������� ��� �������������: ");
    scanf("%49s", course->instructor);
    printf("������� ���� �����: ");
    scanf("%49s", course->tema);
    printf("������� ������� �����: ");
    course->rating = safeInputDouble("");
    printf("������� ��������� �����: ");
    course->cost = safeInputDouble("");
    printf("������� ������������ ����� (� �����): ");
    scanf("%d", &course->time);
}

void printCourse(struct Course* course)
{
    printf("��������: %s\n", course->name);
    printf("�������������: %s\n", course->instructor);
    printf("����: %s\n", course->tema);
    printf("�������: %.2f\n", course->rating);
    printf("���������: %.2f\n", course->cost);
    printf("������������: %d\n", course->time);
    printf("------------------------------\n");
}