#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//void fruit(int count);
//void getInput(int* score, int size);
//double getResult(int* score, int size);
//void printArray(int* score, int size, double result);
//void swap(int* pa, int* pb);
//void print_ary(int* pa);
//void print_ary(int* pa, int size);
//void input_ary(double* pa, int size);
//double find_max(double* pa, int size);
//int a;
//void assign10();
//void assign20();
//int* sum(int a, int b);
/*
struct profile {
	int age;
	double height;
};

struct student {
	struct profile pf;
	int id;
	double grade;
};

struct student {
	int id;
	char name[20];
	double grade;
	int age;
	int height;
};

struct vision {
	double left;
	double right;
};
struct vision exchange(struct vision robot) {
	double temp;

	temp = robot.left;
	robot.left = robot.right;
	robot.right = temp;

	return robot;
};

struct score {
	int kor;
	int eng;
	int math;
};
*/

/*
struct address {
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};
void print_list(struct address* lp);

struct list {
	int num;
	struct list* next;
};

union student {
	int num;
	double grade;
};
*/

/*
enum season {
	SPRING, SUMMER, FALL, WINTER
};
*/

#if 0
int main() {

	//����Լ�
	/*
	fruit(1);
	*/

	//<8��>
	//�迭
	int val1 = 10;
	int val2 = 20;
	int val3 = 30;
	int val4 = 40;
	int val5 = 50;

	int Val[5];
	int* p_Val;
	p_Val = &Val[0]; //p_val = Val;

	for (int i = 0; i < 5; i++) {
		Val[i] = i + 10;
		printf("%d\n", Val[i]);
	}

	int score[5];

	//�Է�
	getInput(&score[0], 5);

	//���
	double result = getResult(&score[0], 5);

	//���
	printArray(&score[0], 5, result);

	char str[80] = "applejam";

	printf("���� ���ڿ� : %s\n", str);
	printf("���ڿ� �Է� : ");
	scanf_s("%s", str, sizeof(str)); //str�� �̹� �ּ��̹Ƿ� &�� ������ �ʾƵ� �Ǵ� ���̴�.
	printf("�Է� �� ���ڿ� : %s\n", str);

	//<9��>
	//������
	int a = 10, b = 15, total;
	double avg;
	int* pa, * pb;

	int* pt = &total;
	double* pg = &avg;

	pa = &a; //�ּ� ����
	pb = &b; //�ּ� ����

	*pt = *pa + *pb; //������ �� ����
	*pg = *pt / 2.0; //������ �� ����

	printf("�� ������ �� : %d, %d\n", *pa, *pb);
	printf("�� ������ �� : %d\n", *pt);
	printf("�� ������ ��� : %.1lf\n", *pg);

	a = 20;
	printf("*pa = %d", *pa);

	char ch;
	int in;
	double db;

	char* pc = &ch;
	int* pi = &in;
	double* pd = &db;

	printf("char�� ������ �ּ� ũ�� : %d\n", sizeof(&ch));
	printf("int�� ������ �ּ� ũ�� : %d\n", sizeof(&in));
	printf("double�� ������ �ּ� ũ�� : %d\n", sizeof(&db));

	printf("char * �������� ũ�� : %d\n", sizeof(pc));
	printf("int * �������� ũ�� : %d\n", sizeof(pi));
	printf("double * �������� ũ�� : %d\n", sizeof(pd));

	printf("char * �����Ͱ� ����Ű�� ������ ũ�� : %d\n", sizeof(*pc));
	printf("int * �����Ͱ� ����Ű�� ������ ũ�� : %d\n", sizeof(*pi));
	printf("double * �����Ͱ� ����Ű�� ������ ũ�� : %d\n", sizeof(*pd));

	//�����͵� �� ��ȯ�� �����ϴ�. 

	int a = 10, b = 20;

	printf("swap �� a : %d, b : %d\n", a, b);
	swap(&a, &b);
	printf("swap �� a : %d, b : %d\n", a, b);


	//<10��>
	//�迭�� ������
	int ary[5] = { 10, 20, 30, 40, 50 };
	int* pa = ary; //ù ���� �迭 ��� �ּ�
	int* pb = pa + 3; //�� ���� �迭 ��� �ּ� 

	printf("pa : %u\n", pa); //10�� �ּ�
	printf("pb : %u\n", pb); //40�� �ּ� 
	pa++;
	printf("pb - pa : %u\n", pb - pa); //40�� �ּ� - 20�� �ּ�

	printf("�տ� �ִ� �迭 ����� �� ��� : ");
	if (pa < pb) printf("%d\n", *pa); //20
	else printf("%d\n", *pb);


	int ary[5] = { 10, 20, 30, 40, 50 };
	print_ary(ary);


	int ary1[5] = { 10, 20, 30, 40, 50 };
	int ary2[7] = { 10, 20, 30, 40, 50, 60, 70};

	print_ary(ary1, 5);
	printf("\n");
	print_ary(ary2, 7);


	double ary[5];
	double max;
	int size = sizeof(ary) / sizeof(ary[0]);

	input_ary(ary, size);
	max = find_max(ary, size);
	printf("�ִ� : %lf\n", max);


	//<13��>
	printf("�Լ� ȣ�� �� a �� : %d\n", a);
	assign10();
	printf("assign10 ȣ�� �� a �� : %d\n", a);
	assign20();
	printf("assign20 ȣ�� �� a �� : %d\n", a);


	int *resp;
	resp = sum(10, 20);
	printf("�� ������ �� : %d\n", *resp);


	//<14��>
	int* pi;
	double* pd;

	pi = (int*)malloc(sizeof(int));
	if (pi == NULL) {
		printf("�޸𸮰� �����մϴ�.\n");
		exit(1);
	}

	pd = (double*)malloc(sizeof(double));

	*pi = 10;
	*pd = 3.4;

	printf("���������� ��� : %d\n", *pi);
	printf("�Ǽ������� ��� : %.1lf\n", *pd);

	free(pi);
	free(pd);


	int* pi;
	int i, sum = 0;

	pi = (int*)malloc(5 * sizeof(int));
	if (pi == NULL) {
		printf("�޸𸮰� �����մϴ�.\n");
		exit(1);
	}

	printf("�ټ� ���� ���̸� �Է��ϼ��� : ");
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &pi[i]);
		sum += pi[i];
	}

	printf("�ټ� ���� ��� ���� : %.1lf\n", (sum / 5.0));
	free(pi); //�Ҵ��� �޸� ���� ��ȯ 


	int* pi;
	int size = 5;
	int count = 0;
	int num;
	
	pi = (int*)calloc(size, sizeof(int));
	while (1) {
		printf("����� �Է��ϼ��� => ");
		scanf_s("%d", &num);
		if (num <= 0) break;

		if (count == size) {
			size += 5;
			pi = (int*)realloc(pi, size * sizeof(int));
		}
		pi[count++] = num;
	}

	for (int i = 0; i < count; i++) {
		printf("%5d", pi[i]);
	}
	free(pi);


	//<17��>
	//����ü
	struct profile yuni;
	strcpy_s(yuni.name, "������");
	yuni.age = 17;
	yuni.height = 164.5;

	yuni.intro = (char*)malloc(80);
	printf("�ڱ�Ұ� : ");
	gets_s(yuni.intro, 100);

	printf("�̸� : %s\n", yuni.name);
	printf("���� : %d\n", yuni.age);
	printf("Ű : %.1lf\n", yuni.height);
	printf("�ڱ�Ұ� : %s\n", yuni.intro);
	free(yuni.intro);


	struct student yuni;

	yuni.pf.age = 17;
	yuni.pf.height = 164.5;
	yuni.id = 315;
	yuni.grade = 4.3;

	printf("���� : %d\n", yuni.pf.age);
	printf("Ű : %.1lf\n", yuni.pf.height);
	printf("�й� : %d\n", yuni.id);
	printf("���� : %.1lf\n", yuni.grade);


	struct student s1 = { 315, "ȫ�浿", 2.4, 17, 180 },
		s2 = { 316, "�̼���", 3.7, 29, 170 },
		s3 = { 317, "�������", 4.4, 10, 170 };

	struct student maxGrade;
	struct student maxAge;
	struct student maxHeight;

	maxGrade = s1;
	if (s2.grade > maxGrade.grade) maxGrade = s2;
	if (s3.grade > maxGrade.grade) maxGrade = s3;

	maxAge = s1;
	if (s2.age > maxAge.age) maxAge = s2;
	if (s3.age > maxAge.age) maxAge = s3;

	maxHeight = s1;
	if (s2.height > maxHeight.height) maxHeight = s2;
	if (s3.height > maxHeight.height) maxHeight = s3;

	printf("������ ���� ���� ���\n");
	printf("�й� : %d\n", maxGrade.id);
	printf("�̸� : %s\n", maxGrade.name);
	printf("���� : %.1lf\n", maxGrade.grade);
	printf("���� : %d\n", maxGrade.age);
	printf("Ű : %d\n\n", maxGrade.height);

	printf("���̰� ���� ���� ���\n");
	printf("�й� : %d\n", maxAge.id);
	printf("�̸� : %s\n", maxAge.name);
	printf("���� : %.1lf\n", maxAge.grade);
	printf("���� : %d\n", maxAge.age);
	printf("Ű : %d\n\n", maxAge.height);

	printf("Ű�� ���� ū ���\n");
	printf("�й� : %d\n", maxHeight.id);
	printf("�̸� : %s\n", maxHeight.name);
	printf("���� : %.1lf\n", maxHeight.grade);
	printf("���� : %d\n", maxHeight.age);
	printf("Ű : %d\n\n", maxHeight.height);


	struct vision robot;
	printf("�÷� �Է� : ");
	scanf_s("%lf%lf", &(robot.left), &(robot.right));
	robot = exchange(robot);
	printf("�ٲ� �÷� : %.1lf %.1lf\n", robot.left, robot.right);

	struct score yuni = { 90, 80, 70 };
	struct score* ps = &yuni;

	printf("���� : %d\n", (*ps).kor);
	printf("���� : %d\n", ps->eng);
	printf("���� : %d\n", ps->math);


	struct address list[5] = {
		{"ȫ�浿", 23, "111-1111", "�︪�� ����"},
		{"�̼���", 35, "222-2222", "���� ��õ��"},
		{"�庸��", 19, "333-3333", "�ϵ� û����"},
		{"������", 15, "444-4444", "�泲 õ��"},
		{"���߱�", 45, "555-5555", "Ȳ�ص� ����"}
	};

	print_list(list);


	struct list a = { 10, 0 }, b = { 20, 0 }, c = { 30, 0 };
	struct list* head = &a, * current;

	a.next = &b;
	b.next = &c;

	printf("head -> num : %d\n", head->num); //10
	printf("head -> next -> num : %d\n", head->next->num); //20

	printf("list all : ");
	current = head;
	while (current != NULL) {
		printf("%d ", current->num); //10 20 30
		current = current->next;
	}
	printf("\n");


	union student s1 = { 315 };

	printf("�й� : %d\n", s1.num);
	s1.grade = 4.4;
	printf("���� : %.lf\n", s1.grade);
	printf("�й� : %d\n", s1.num);

	enum season ss;
	char *pc = NULL;
	ss = SPRING;

	switch (ss) {
	case SPRING:
		pc = "inline";
		break;
	case SUMMER:
		pc = "swimming";
		break;
	case FALL:
		pc = "trip";
		break;
	case WINTER:
		pc = "skiing";
		break;
	}

	return 0;
}
#endif

/*
void fruit(int count) {
	printf("apple\n");
	if (count == 3) return;
	fruit(count + 1);
	printf("jam\n");

	//apple
	//apple
	//apple
	//jam
	//jam
}
*/

/*
void getInput(int* score, int size) {
	for (int i = 0; i < size; i++) {
		scanf_s("%d\n", &score[i]);
	}
}

double getResult(int* score, int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += score[i];
	}
	return total;
}

void printArray(int* score, int size, double result) {
	for (int i = 0; i < size; i++) {
		printf("%5d", score[i]);
	}
	printf("��� : %.1lf", result / (double)size);
}
*/

/*
void swap(int* pa, int* pb) {
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}
*/

/*
void print_ary(int* pa) {
	for (int i = 0; i < 5; i++) {
		printf("%d\n", *pa);
		pa++;
	}
}
*/

/*
void print_ary(int* pa, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", pa[i]);
		//10 20 30 40 50
		//10 20 30 40 50 60 70
	}
}
*/

/*
void input_ary(double* pa, int size) {
	printf("%d���� �Ǽ� �Է� : ", size);
	for (int i = 0; i < size; i++) {
		scanf_s("%lf", pa + i);
	}
}

double find_max(double* pa, int size) {
	double max = pa[0];
	for (int i = 1; i < size; i++) {
		if (pa[i] > max) max = pa[i];
	}

	return max;
}
*/

/*
void assign10(void) {
	a = 10;
}

void assign20(void) {
	int a;
	a = 20;
}
*/

/*
int* sum(int a, int b) {
	int res; //���Ŀ� �ּҸ� �����ؾ��ϹǷ� ���� ���ư��� �� �Ǳ� ������ static ���� �����Ѵ�. 
	res = a + b;
	return &res;
}
*/

/*
void print_list(struct address* lp) {
	for (int i = 0; i < 5; i++) {
		//printf("%10s%5d%15s%20s\n", (lp+i) -> name, (lp+i) -> age, (lp+i) -> tel, (lp+i) -> addr);
		printf("%10s%5d%15s%20s\n", lp[i].name, lp[i].age, lp[i].tel, lp[i].addr);
	}
}
*/
