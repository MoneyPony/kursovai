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
        printf("Введите ваш выбор: ");
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
                printf("Курс успешно добавлен!\n");
            }
            else
            {
                printf("Достигнуто максимальное количество курсов!\n");
            }
            break;
        case 2:
            if (courseCount == 0)
            {
                printf("Нет доступных курсов\n");
            }
            else
            {
                char searchName[50];
                printf("Введите название курса для поиска: ");
                scanf("%49s", searchName);
                int found = 0;
                for (int i = 0; i < courseCount; i++)
                {
                    if (strcmp(courses[i].name, searchName) == 0)
                    {
                        printf("Название: %s\n", courses[i].name);
                        printf("Преподаватель: %s\n", courses[i].instructor);
                        printf("Тема: %s\n", courses[i].tema);
                        printf("Рейтинг: %.2f\n", courses[i].rating);
                        printf("Стоимость: %.2f\n", courses[i].cost);
                        printf("Длительность: %d\n", courses[i].time);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    printf("Курс с указанным названием не найден\n");
                }
            }
            break;
        case 3:
            if (courseCount == 0)
            {
                printf("Нет доступных курсов\n");
            }
            else
            {
                float searchCost;
                printf("Введите стоимость курса для поиска: ");
                scanf("%f", &searchCost);
                int found = 0;
                for (int i = 0; i < courseCount; i++)
                {
                    if (courses[i].cost == searchCost)
                    {
                        printf("Название: %s\n", courses[i].name);
                        printf("Преподаватель: %s\n", courses[i].instructor);
                        printf("Тема: %s\n", courses[i].tema);
                        printf("Рейтинг: %.2f\n", courses[i].rating);
                        printf("Стоимость: %.2f\n", courses[i].cost);
                        printf("Длительность: %d\n", courses[i].time);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    printf("Курсы с указанной стоимостью не найдены\n");
                }
            }
            break;
        case 4:
            if (courseCount == 0)
            {
                printf("Нет доступных курсов для сортировки\n");
            }
            else
            {
                bubbleSort(courses, courseCount);
                printf("Курсы успешно отсортированы по рейтингу!\n");
            }
            break;
        case 5:
            printf("Выход из программы\n");
            break;
        default:
            printf("Некорректный выбор. Пожалуйста, попробуйте снова\n");
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
            printf("Ошибка ввода. Пожалуйста, введите корректное целое число.\n");
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
            printf("Ошибка ввода. Пожалуйста, введите корректное число.\n");
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
    printf("Добро пожаловать в программу управления образовательными курсами!\n");
    printf("_________________________________________________________________\n");
    printf("Меню:\n");
    printf("1. Добавить курс\n");
    printf("2. Поиск курса по названию\n");
    printf("3. Поиск курса по стоимости\n");
    printf("4. Вывести список курсов\n");
    printf("5. Сортировать курсы по рейтингу\n");
    printf("6. Выйти из программы\n");
    printf("-----------------------------------------------------------------\n");
}

void inputCourseInfo(struct Course* course)
{
    printf("Введите название курса: ");
    scanf("%49s", course->name);
    printf("Введите имя преподавателя: ");
    scanf("%49s", course->instructor);
    printf("Введите тему курса: ");
    scanf("%49s", course->tema);
    printf("Введите рейтинг курса: ");
    course->rating = safeInputDouble("");
    printf("Введите стоимость курса: ");
    course->cost = safeInputDouble("");
    printf("Введите длительность курса (в часах): ");
    scanf("%d", &course->time);
}

void printCourse(struct Course* course)
{
    printf("Название: %s\n", course->name);
    printf("Преподаватель: %s\n", course->instructor);
    printf("Тема: %s\n", course->tema);
    printf("Рейтинг: %.2f\n", course->rating);
    printf("Стоимость: %.2f\n", course->cost);
    printf("Длительность: %d\n", course->time);
    printf("------------------------------\n");
}