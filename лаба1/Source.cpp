#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include < string.h >

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	struct student {
		char famil[20];
		char name[20], facult[20];
		int Nomzach;
	} stud[3],search;

	int min, max, n, mm[5][5];
	int* m;
	printf("������� ������ �������:  ");
	scanf("%d", &n);
	m = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		m[i] = rand() % 100;
		printf("%d\n", m[i]);
	}
	min = m[0];
	max = m[0];
	for (int i = 0; i < n; i++) {
		if (m[i] < min)
			min = m[i];
		if (m[i] > max)
			max = m[i];
	}
	printf("min: %d \nmax: %d", min, max);
	free(m);
	printf("\n_________________________\n\n");

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			mm[i][j] = rand() % 100;
			printf("%5d", mm[i][j]);
		}
		printf("\n");
	}
	printf("   ||   ||   ||   ||   ||\n");
	for (int i = 0; i < 5; i++) {
		int u = 0;
		for (int j = 0; j < 5; j++) {
			u += mm[j][i];
		}
		printf("%5d", u);
	}
	printf("\n_________________________\n");

	for (int i = 0; i < 3; i++)
	{
		printf("������� ������� �������� �%d\n", i + 1);
		scanf("%20s", &stud[i].famil);
		printf("������� ��� �������� �%d\n", i + 1);
		scanf("%20s", &stud[i].name);
		printf("������� �������� ���������� �������� �%d\n", i + 1);
		scanf("%20s", &stud[i].facult);
		printf("������� ����� �������� ������ �������� �%d\n", i + 1);
		scanf("%d", &stud[i].Nomzach);
	}
	for (int i = 0; i < 3; i++) {
		printf(" C������ %s %s ��������� �� ���������� %s, ������������� ������ %d\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);

	}
	printf("�����:\n");
	printf("������� - ");
	scanf("%20s", &search.famil);
	printf("��� - ");
	scanf("%20s", &search.name);
	printf("������� - ");
	scanf("%20s", &search.facult);
	printf("����� ������ - ");
	scanf("%d", &search.Nomzach);
	int t = 0;
	for (int i = 0; i < 3; i++) {
		if (strcmp(search.famil, stud[i].famil) == 0 || (strcmp(search.name, stud[i].name) == 0) || strcmp(search.facult, stud[i].facult) == 0 || search.Nomzach == stud[i].Nomzach) {
			printf("���������� ��� ������� %d", i + 1);
			printf(" C������ %s %s ��������� �� ���������� %s, ������������� ������ %d\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
			t = 1;
		}
	}
	if (t == 0) 
		printf("���������� �� �������");
	getchar();
}
