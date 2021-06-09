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
		printf("번호를 입력하세요. (1번 : 매칭기업 / 2번 : 이름 / 3번 : 성별 / 4번 : 연락처 / 5번 : 이메일 / 6번 : 생년월일 / 7번 : 전공 / 8번 : 검색 종료) : ");
		scanf_s("%d", &num);
		
		if (num >= 1 && num <= 8) {

			if (num == 8) {
				printf("검색이 종료됩니다.\n");
				break;
			}

			char search[50];
			printf("검색어를 입력하세요.\n");
			scanf("%s", search);

			if (num == 1) { //매칭기업
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].comp) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
			else if (num == 2) { //이름 
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].name) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
			else if (num == 3) { //성별
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].s) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
			else if (num == 4) { //연락처
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].tel) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
			else if (num == 5) { //이메일
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].email) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
			else if (num == 6) { //생년월일
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].birth) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
			else if (num == 7) { // 전공
				for (int i = 0; i < 25; i++) {
					if (strcmp(search, test[i].major) == 0) {
						printf("%s %s %s %s %s %s %s\n", test[i].name, test[i].comp, test[i].s, test[i].tel, test[i].email, test[i].birth, test[i].major);
					}
				}
			}
		}
		else {
			printf("다시 입력해주세요.");
		}
	}
}


/*
void search(Student* student, int size) {
	printf("이름 입력");
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
