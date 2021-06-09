#include <stdio.h>
#include <string.h>

#if 0
int main() {

	FILE* fp;
	int ch;

	fopen_s(&fp, "D:\\test1.txt", "r");
	if (fp == NULL) {
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}

	while (1) {
		ch = fgetc(fp);
		if (ch == EOF) {
			break;
		}
		putchar(ch);
	}
	fclose(fp);

	FILE* fp;
	char str[] = "banana";
	int i = 0;

	fopen_s(&fp, "D:\\test1.txt", "w");
	if (fp == NULL) {
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	while (str[i] != '\0') {
		fputc(str[i], fp);
		i++;
	}
	fputc('\n', fp);
	fclose(fp);

	int ch;
	while (1) {
		ch = getchar();
		if (ch == EOF) {
			break;
		}
		putchar(ch);
	}

	int ch;
	while (1) {
		ch = fgetc(stdin);
		if (ch == EOF) {
			break;
		}
		fputc(ch, stdout);
	}

	FILE* fp;
	fopen_s(&fp, "D:\\test1.txt", "w");

	if (fp == NULL) {
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	int ch;
	while (1) {
		ch = getchar();
		if (ch == EOF) {
			break;
		}
		fputc(ch, fp);
	}
	fputc('\n', fp);
	fclose(fp);

	FILE* fp;
	int ary[10] = { 13, 10, 13, 13, 10, 26, 13, 10, 13, 10 };
	int res;

	fopen_s(&fp, "D:\\test1.txt", "wb");
	for (int i = 0; i < 10; i++) {
		fputc(ary[i], fp);
	}
	fclose(fp);
	fopen_s(&fp, "D:\\test1.txt", "rt");
	while (1) {
		res = fgetc(fp);
		if (res == EOF) break;
		printf("%4d", res);
	}
	fclose(fp);

	FILE* fp;
	char str[20];

	fopen_s(&fp, "D:\\test1.txt", "a+");
	if (fp == NULL) {
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}
	while (1) {
		printf("과일 이름 : ");
		scanf_s("%s", str, sizeof(str));
		if (strcmp(str, "end") == 0) {
			break;
		}
		else if (strcmp(str, "list") == 0) {
			fseek(fp, 0, SEEK_SET);
			while (1) {
				fgets(str, sizeof(str), fp);
				if (feof(fp)) {
					break;
				}
				printf("%s", str);
			}
		}
		else {
			fprintf(fp, "%s\n", str);
		}
	}
	fclose(fp);

	return 0;
}
#endif