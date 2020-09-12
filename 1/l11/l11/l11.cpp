// l1.cpp: определяет точку входа для консольного приложения.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <cstring>




int main(void) {
	setlocale(LC_ALL, "Russian");

	int z = 1;

	while (z > 0)
	{
		printf("\n Выбор задания 1, 2, 3, 4, 5: \n Введите 0, чтобы выйти ");
		scanf("%d", &z);
		system("cls");
		if (z == 1) {

			// Задание 1
			printf("Задание 1\n\nВычисление разницы между максимальным\nи минималоьным значениями массива\n");

			int mas[5] = { 1, 4, 10, -5, 100 };
			int max, min, rez;

			max = mas[0];
			min = mas[0];

			for (int i = 0; i < 5; i++)
			{
				printf("%d ", mas[i]);
			}

			for (int i = 1; i < 5; i++)
			{
				if (max < mas[i])
					max = mas[i];

				if (min > mas[i])
					min = mas[i];
			}

			printf("\n max: %d\n min: %d\n ", max, min);
			printf("Ответ: %d", max - min);
			_getch();
			system("cls");

		}

		// Задание 2
		if (z == 2)
		{
			printf("Задание 2\nИнициализация массива случайными числами\n");

			int mas1[10];

			srand(time(0));

			for (int i = 0; i < 10; i++)
			{
				mas1[i] = rand() % 100 - 10;
			}

			for (int i = 0; i < 10; i++)
			{
				printf("%d |", mas1[i]);
			}

			_getch();
			system("cls");
		}

		// Задание 3
		if (z == 3)
		{
			printf("Задание 3\nСоздание массива произвольного размера, вводимого с клавиатуры.\n");

			int i, n, * mas2;
			srand(time(0));
			printf("Введите размер массива: ");
			scanf("%d", &n);

			mas2 = (int*)malloc(n * sizeof(int));

			for (i = 0; i < n; i++)
			{
				mas2[i] = rand() % 100 - 10;
			}

			for (i = 0; i < n; i++)
			{
				printf("%d |", mas2[i]);
			}
			free(mas2);
			_getch();
			system("cls");
		}

		// Задание 4
		if (z == 4)
		{
			printf("Задание 4\nСумма значений строк и столбцов двумерного массива\n");

			/*int mas3[1][1];*/
			int** mas3;
			int x, y, i, j, strok, stolb;

			srand(time(0));

			printf("Введите кол-во строк: ");
			scanf("%d", &x);
			printf("Введите кол-во столбцов: ");
			scanf("%d", &y);

			mas3 = (int**)malloc(x * sizeof(int*));
			for (int i = 0; i < x; i++) {
				mas3[i] = (int*)malloc(y * sizeof(int));
			}

			for (i = 0; i < x; i++)
			{
				for (j = 0; j < y; j++)
				{
					mas3[i][j] = rand() % 110 - 10;
					printf("%d |", mas3[i][j]);
				}
				printf("\n");
			}

			printf("\n Сумма строк: \n");
			for (i = 0; i < x; i++) {
				strok = 0;
				for (j = 0; j < y; j++) {
					strok += mas3[i][j];
				}
				printf("%d ", strok);
			}
			printf("\n");

			printf("\n Сумма столбцов: \n");
			for (j = 0; j < y; j++) {
				stolb = 0;
				for (i = 0; i < x; i++) {
					stolb += mas3[i][j];
				}
				printf("%d ", stolb);
			}

			for (int i = 0; i < x; i++) {
				free(mas3[i]);
			}
			free(mas3);

			_getch();
			system("cls");
		}

		// Задание 5

		if (z == 5)
		{

			struct student {
				int numzach;
				char familia[20];
				char name[20];
				char facult[20];
			} stud[3], search;
			int i, flag = 0;

			printf("Поиск по структуре.\nИспользовать только латиницу\n\n");

			for (i = 0; i < 3; i++) {
				printf("Введите фамилию студента: ");
				scanf("%20s", &stud[i].familia);
			}
			for (i = 0; i < 3; i++) {
				printf("Введите имя студента: ");
				scanf("%20s", &stud[i].name);
			}
			for (i = 0; i < 3; i++) {
				printf("Введите название факультета %s: ", stud[i].familia);
				scanf("%20s", &stud[i].facult);
			}
			for (i = 0; i < 3; i++) {
				printf("Введите номер зачетной книжки %s: ", stud[i].familia);
				scanf("%d", &stud[i].numzach);
			}
			for (i = 0; i < 3; i++) {
				printf("Студент %s %s обучается на факультете %s, номер зачетной книжки %d\n", stud[i].familia, stud[i].name, stud[i].facult, stud[i].numzach);
			}


			bool ex = false;
			bool poisk = false;
			printf("\nПоиск по фамилии\n");
			while (ex != true)
			{
				printf("Введите фамилию студента: ");
				scanf("%s", &search.familia);
				for (i = 0; i < 3; i++) {
					if (strcmp(stud[i].familia, search.familia) == 0) {
						printf("Студент %s %s обучается на факультете %s, номер зачетной книжки %d\n",

							stud[i].familia, stud[i].name, stud[i].facult, stud[i].numzach);
						flag++;
						poisk = true;
					}
				}
				if (poisk == false)
				{
					printf("\nСтудент не найден\n");
				
				}
			}
			_getch();
			system("cls");
		}
	}
}