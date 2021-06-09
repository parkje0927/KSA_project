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

	//재귀함수
	/*
	fruit(1);
	*/

	//<8장>
	//배열
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

	//입력
	getInput(&score[0], 5);

	//계산
	double result = getResult(&score[0], 5);

	//출력
	printArray(&score[0], 5, result);

	char str[80] = "applejam";

	printf("최초 문자열 : %s\n", str);
	printf("문자열 입력 : ");
	scanf_s("%s", str, sizeof(str)); //str은 이미 주소이므로 &를 붙이지 않아도 되는 것이다.
	printf("입력 후 문자열 : %s\n", str);

	//<9장>
	//포인터
	int a = 10, b = 15, total;
	double avg;
	int* pa, * pb;

	int* pt = &total;
	double* pg = &avg;

	pa = &a; //주소 대입
	pb = &b; //주소 대입

	*pt = *pa + *pb; //변수에 값 저장
	*pg = *pt / 2.0; //변수에 값 저장

	printf("두 정수의 값 : %d, %d\n", *pa, *pb);
	printf("두 정수의 합 : %d\n", *pt);
	printf("두 정수의 평균 : %.1lf\n", *pg);

	a = 20;
	printf("*pa = %d", *pa);

	char ch;
	int in;
	double db;

	char* pc = &ch;
	int* pi = &in;
	double* pd = &db;

	printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));
	printf("int형 변수의 주소 크기 : %d\n", sizeof(&in));
	printf("double형 변수의 주소 크기 : %d\n", sizeof(&db));

	printf("char * 포인터의 크기 : %d\n", sizeof(pc));
	printf("int * 포인터의 크기 : %d\n", sizeof(pi));
	printf("double * 포인터의 크기 : %d\n", sizeof(pd));

	printf("char * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pc));
	printf("int * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pi));
	printf("double * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pd));

	//포인터도 형 변환이 가능하다. 

	int a = 10, b = 20;

	printf("swap 전 a : %d, b : %d\n", a, b);
	swap(&a, &b);
	printf("swap 후 a : %d, b : %d\n", a, b);


	//<10장>
	//배열과 포인터
	int ary[5] = { 10, 20, 30, 40, 50 };
	int* pa = ary; //첫 번재 배열 요소 주소
	int* pb = pa + 3; //네 번재 배열 요소 주소 

	printf("pa : %u\n", pa); //10의 주소
	printf("pb : %u\n", pb); //40의 주소 
	pa++;
	printf("pb - pa : %u\n", pb - pa); //40의 주소 - 20의 주소

	printf("앞에 있는 배열 요소의 값 출력 : ");
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
	printf("최댓값 : %lf\n", max);


	//<13장>
	printf("함수 호출 전 a 값 : %d\n", a);
	assign10();
	printf("assign10 호출 후 a 값 : %d\n", a);
	assign20();
	printf("assign20 호출 후 a 값 : %d\n", a);


	int *resp;
	resp = sum(10, 20);
	printf("두 정수의 합 : %d\n", *resp);


	//<14장>
	int* pi;
	double* pd;

	pi = (int*)malloc(sizeof(int));
	if (pi == NULL) {
		printf("메모리가 부족합니다.\n");
		exit(1);
	}

	pd = (double*)malloc(sizeof(double));

	*pi = 10;
	*pd = 3.4;

	printf("정수형으로 사용 : %d\n", *pi);
	printf("실수형으로 사용 : %.1lf\n", *pd);

	free(pi);
	free(pd);


	int* pi;
	int i, sum = 0;

	pi = (int*)malloc(5 * sizeof(int));
	if (pi == NULL) {
		printf("메모리가 부족합니다.\n");
		exit(1);
	}

	printf("다섯 명의 나이를 입력하세요 : ");
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &pi[i]);
		sum += pi[i];
	}

	printf("다섯 명의 평균 나이 : %.1lf\n", (sum / 5.0));
	free(pi); //할당한 메모리 영역 반환 


	int* pi;
	int size = 5;
	int count = 0;
	int num;
	
	pi = (int*)calloc(size, sizeof(int));
	while (1) {
		printf("양수만 입력하세요 => ");
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


	//<17장>
	//구조체
	struct profile yuni;
	strcpy_s(yuni.name, "서하윤");
	yuni.age = 17;
	yuni.height = 164.5;

	yuni.intro = (char*)malloc(80);
	printf("자기소개 : ");
	gets_s(yuni.intro, 100);

	printf("이름 : %s\n", yuni.name);
	printf("나이 : %d\n", yuni.age);
	printf("키 : %.1lf\n", yuni.height);
	printf("자기소개 : %s\n", yuni.intro);
	free(yuni.intro);


	struct student yuni;

	yuni.pf.age = 17;
	yuni.pf.height = 164.5;
	yuni.id = 315;
	yuni.grade = 4.3;

	printf("나이 : %d\n", yuni.pf.age);
	printf("키 : %.1lf\n", yuni.pf.height);
	printf("학번 : %d\n", yuni.id);
	printf("학점 : %.1lf\n", yuni.grade);


	struct student s1 = { 315, "홍길동", 2.4, 17, 180 },
		s2 = { 316, "이순신", 3.7, 29, 170 },
		s3 = { 317, "세종대왕", 4.4, 10, 170 };

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

	printf("학점이 제일 높은 사람\n");
	printf("학번 : %d\n", maxGrade.id);
	printf("이름 : %s\n", maxGrade.name);
	printf("학점 : %.1lf\n", maxGrade.grade);
	printf("나이 : %d\n", maxGrade.age);
	printf("키 : %d\n\n", maxGrade.height);

	printf("나이가 제일 많은 사람\n");
	printf("학번 : %d\n", maxAge.id);
	printf("이름 : %s\n", maxAge.name);
	printf("학점 : %.1lf\n", maxAge.grade);
	printf("나이 : %d\n", maxAge.age);
	printf("키 : %d\n\n", maxAge.height);

	printf("키가 제일 큰 사람\n");
	printf("학번 : %d\n", maxHeight.id);
	printf("이름 : %s\n", maxHeight.name);
	printf("학점 : %.1lf\n", maxHeight.grade);
	printf("나이 : %d\n", maxHeight.age);
	printf("키 : %d\n\n", maxHeight.height);


	struct vision robot;
	printf("시력 입력 : ");
	scanf_s("%lf%lf", &(robot.left), &(robot.right));
	robot = exchange(robot);
	printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);

	struct score yuni = { 90, 80, 70 };
	struct score* ps = &yuni;

	printf("국어 : %d\n", (*ps).kor);
	printf("영어 : %d\n", ps->eng);
	printf("수학 : %d\n", ps->math);


	struct address list[5] = {
		{"홍길동", 23, "111-1111", "울릉도 독도"},
		{"이순신", 35, "222-2222", "서울 건천동"},
		{"장보고", 19, "333-3333", "완도 청해진"},
		{"유관순", 15, "444-4444", "충남 천안"},
		{"안중근", 45, "555-5555", "황해도 해주"}
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

	printf("학번 : %d\n", s1.num);
	s1.grade = 4.4;
	printf("학점 : %.lf\n", s1.grade);
	printf("학번 : %d\n", s1.num);

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
	printf("평균 : %.1lf", result / (double)size);
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
	printf("%d개의 실수 입력 : ", size);
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
	int res; //추후에 주소를 전달해야하므로 값이 날아가면 안 되기 때문에 static 으로 선언한다. 
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
