#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "datah.h"

void sub(student_info *test);

int main () {
	student_info test[30];
	sub(test);

	while (1) {

		int num;
		printf("��ȣ�� �Է��ϼ���. (1�� : ��Ī��� / 2�� : �̸� / 3�� : ���� / 4�� : ����ó / 5�� : �̸��� / 6�� : ������� / 7�� : ���� / 8�� : �˻� ����) : ");
		scanf_s("%d", &num);
		
		if (num >= 1 && num <= 8) {

			if (num == 8) {
				printf("�˻��� ����˴ϴ�.\n");
				break;
			}

			char search[50];
			printf("�˻�� �Է��ϼ���.\n");
			scanf("%s", search);

			if (num == 1) { //��Ī���
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].comp) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
			else if (num == 2) { //�̸� 
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].name) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
			else if (num == 3) { //����
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].s) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
			else if (num == 4) { //����ó
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].tel) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
			else if (num == 5) { //�̸���
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].email) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
			else if (num == 6) { //�������
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].birth) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
			else if (num == 7) { // ����
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].major) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
		}
		else {
			printf("�ٽ� �Է����ּ���.");
		}
	}
}


/*
void search(Student* student, int size) {
	printf("�̸� �Է�");
	char find[100];
	scanf("%s", find);
	char* ptr;
	Student* s;
	
	for (s=student; s<student + size; s++) {
		ptr = strstr(s->name, find);
		if (ptr != NULL) {
			printf("%s %s", s->name, s->comp);
		}
	}

}
*/
