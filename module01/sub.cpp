#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include "datah.h"

void sub(student_info *test) {

	test[30];				// data.h �ش����� �ҷ����

	FILE* fp;
	fopen_s(&fp, "D:\\data.txt", "r");	//�б� ���

	char buffer[1001], * token;

	int i = 0;
	int idx = 0;
	while (!feof(fp)) {
		i = 0;//i�ʱ�ȭ
		fgets(buffer, 1001, fp);
		token = strtok(buffer, ","); // 
		while (token != NULL) {

			if (i == 0) {			//�̸�
				strcpy(test[idx].name, token);
			}
			else if (i == 1) {		//���
				/*test[idx].name = atoi(token);*/
				strcpy(test[idx].comp, token);
			}

			else if (i == 2) {		//����
				strcpy(test[idx].s, token);
			}

			else if (i == 3) {		//����ó
				strcpy(test[idx].tel, token);
			}

			else if (i == 4) {		//�̸���
				strcpy(test[idx].email, token);
			}

			else if (i == 5) {		//�������
				strcpy(test[idx].birth, token);
			}

			else if (i == 6) {		//����
				strcpy(test[idx].major, token);
			}

			i++;
			token = strtok(NULL, ",");
		}
		idx++;
	}

	int cnt = 1;
	//����ü �����Ͱ� ����Ǿ��ִ��� Ȯ��
	/*
	for (i = 0; i < idx; i++)
	{
		//printf("%s , %s , %s , %s , %s , %s, %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
		printf("%s\n", test[i].major);
	}
	*/

	fclose(fp);	// ���� �ݱ�
}