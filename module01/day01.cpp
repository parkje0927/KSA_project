#include <stdio.h>
#include <string.h>

//int sum(int a, int b);
//int sub(int a, int b);
//int mul(int a, int b);
//double div(int a, int b);

//void print_line(void);


//int main() {

#if 0	
	int val = 10;
	printf("%d\n", val);

	char ch = 65;
	char ch2 = 'A';

	printf("%d %c\n", ch, ch);
	printf("%d %c\n", ch2, ch2);

	//74 117 110 103 104 121 117 110 32 80 97 114 107
	char c1 = 'J'; //74
	char c2 = 'u'; //117
	char c3 = 'n'; //110
	char c4 = 'g'; //103
	char c5 = 'h'; //104
	char c6 = 'y'; //121
	char c7 = 'u'; //117
	char c8 = 'n'; //110
	char c9 = ' '; //32
	char c10 = 'P'; //80
	char c11 = 'a'; //97
	char c12 = 'r'; //114
	char c13 = 'k'; //107

	printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13);
	printf("%c %c %c %c %c %c %c %c %c %c %c %c %c\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13);
#endif

#if 0
	char ch3 = 15;
	char ch4 = -15;
	char result = ch3 + ch4;
#endif

#if 0
	int num = 3;
	float num2 = 3;
	float num3 = 3.5;
	float num4 = 3.14;
#endif

	//unsigned int a;

	//a = 4294967295;
	//printf("%d\n", a); //-1
	//a = -1;
	//printf("%u\n", a); //4294967295

	/*
	unsigned int 라고 선언 했으므로 최상위 부호 비트를 값으로 쓰겠다는 의미
	-> 4294967295 라고 선언을 했으므로 다 11111111로 채워진다. 그래서 -1이라고 출력이 되고,
	-> 부호를 무시하는 %u 를 실행하자, 4294967295 가 출력된다.

	즉, 값이 출력되는 max 값은 알고 있어야 한다.
	*/

	/*
	변수A를 선언해서 값을 복사해놓고 복사한 값을 변경해도
	변수A는 값이 변하지 않는다.
	*/

	
	/*
	int value = 10;

	char fruit[20] = "strawberry";

	printf("딸기 : %s\n", fruit);
	printf("딸기쨈 : %s %s\n", fruit, "jam");

	strcpy_s(fruit, "banana");
	printf("%s\n", fruit);
	*/


	//4장
	//논리연산자는 2개, 비트연산자는 1개를 사용한다. 

	/*
	int a, b;
	int sum, sub, mul, inv;

	a = 10;
	b = 20;
	sum = a + b;
	sub = a - b;
	mul = a * b;
	inv = -a;

	printf("%d %d %d %d", sum, sub, mul, inv);
	*/


	/*int a = 5, b = 5;
	int pre, post;

	pre = (++a) * 3;
	post = (b++) * 3;

	printf("초깃값 a = %d, b = %d\n", a, b);
	printf("전위형 : (++a) * 3 = %d, 후위형 : (b++) * 3 = %d\n", pre, post);*/

	//논리연산자
	/*
	int a = 30;
	int res;

	res = (a > 10) && (a < 20); //false : 0
	printf("res = %d", res);
	res = (a < 10) || (a > 20); // true : 1
	printf("res = %d", res);
	res = !(a >= 30);
	printf("! (a >= 30) : %d\n", res);
	*/


	//형 변환 연산자
	/*
	int a = 20, b = 3;
	double res;

	res = ((double)a) / ((double)b); //실수로 변환
	printf("a = %d, b = %d\n", a, b);
	printf("a / b의 결과 : %.1lf\n", res);

	a = (int)res; //정수로 변환
	printf("(int) %.1lf의 결과 : %d\n", res, a);
	*/


	//sizeof 연산자
	/*
	int a = 10;
	double b = 3.4;

	printf("int형 변수의 크기 : %d\n", sizeof(a)); //4
	printf("double형 변수의 크기 : %d\n", sizeof(b)); //8
	printf("정수형 상수의 크기 : %d\n", sizeof(10)); //4
	printf("수식의 결괏값의 크기 : %d\n", sizeof(1.5 + 3.4)); //8 -> 실수형 상수는 기본이 double 이기 때문이다. 
	printf("char 자료형의 크기 : %d\n", sizeof(char));
	*/


	//복합대입 연산자
	/*
	int a = 10, b = 20;
	int res = 2;

	a += 20;
	res *= b + 10;

	printf("a = %d, b = %d\n", a, b);
	printf("res = %d\n", res);
	*/

	
	//콤마 연산자
	/*
	int a = 10, b = 20;
	int res;

	res = (++a, ++b); //= 와 , 의 우선순위를 비교하여 =가 높으므로 res 에 ++a 값을 저장

	printf("a : %d, b : %d\n", a, b); //11, 21
	printf("res : %d\n", res); //21
	*/


	//조건 연산자
	/*
	int a = 10, b = 20, res;
	res = (a > b) ? a : b;
	printf("큰 값 : %d\n", res);
	*/

	//비트 연산자
	/*
	int a = 10;
	int b = 12;

	printf("a & b : %d\n", a & b); //8  둘 다 1 일때만 1
	printf("a ^ b : %d\n", a ^ b); //6  서로 같은 값이면 0, 다른 값이면 1
	printf("a | b : %d\n", a | b); //14 둘 중에 하나라도 1이면1
	printf("~a : %d\n", ~a); //-11		부정 연산자 
	printf("a << 1 : %d\n", a << 1); //20	왼쪽 이동 연산자, 뒤에는 0으로 채움
	printf("a >> 2 : %d\n", a >> 2); //2	오른쪽 이동 연산자, 앞에는 0으로 채움 
	*/


	//연산자 우선순위와 연산 방향
	/*
	int a = 10, b = 5;
	int res;

	res = a / b * 2;
	printf("res = %d\n", res); //4

	res = ++a * 3; //33
	printf("res = %d\n", res);

	res = a > b && a != 5; //1(true)
	printf("res = %d\n", res);

	res = a % 3 == 0; //0(false)
	printf("res = %d\n", res);

	//단항 연산자(++)가 이항 연산자(*)보다 우선순위가 높다. 
	//산술 > 관계(>, !=) > 논리(&&) 연산자 순서로 우선순위가 높다. 
	*/


	//<5장>
	//if 문의 기본 형식
	/*
	int a = 20;
	int b = 0;

	if (a > 10) {
		b = a;
	}

	printf("a : %d, b : %d\n", a, b);
	*/

	
	//if ~ else
	/*
	int a = 10;

	if (a >= 0) {
		a = 1;
	}
	else {
		a = -1;
	}

	printf("a : %d\n", a);
	*/

	
	//if문 중첩
	/*
	int a = 20, b = 10;
	if (a > 10) {
		if (b >= 0) {
			b = 1;
		}
		else {
			b = -1;
		}
	}
	
	printf("a : %d, b : %d\n", a, b);
	*/


	//switch ~ case문
	/*
	int rank = 2, m = 0;

	switch (rank) {
	case 1:
		m = 300;
		break;
	case 2:
		m = 200;
		break;
	case 3:
		m = 100;
		break;
	default: 
		m = 10;
		break;
	}

	printf("m : %d\n", m);
	//break 가 없는 경우 m = 200을 넣고 100을 넣고 계속 진행하게 된다. 즉, break를 생략하면 모든 문장을 실행한다. 
	*/

	
	//<6장>
	//do ~ while문
	/*
	int a = 1;
	do {
		a = a * 2;
	} while (a < 10);
	printf("a : %d\n", a); //16

	//중첩 반복문이 영상처리의 기본이다. 

	//구구단

	//break : 전체를 빠져나온다. 
	//continue : 넘어가는 개념

	//무한 반복문 : while(1) for(;;)
	*/

	//<7장>
	//이름과 매개변수, 반환형이 명확하게 정의되어야 한다. 
	//반환형과 매개변수가 void인 경우가 있다. 
	
	//함수 선언, 정의, call => 3가지 프레임

	//함수를 먼저 선언하고 추후에 정의하는 이유는, 가독성을 위해서이다. 
	//함수 기반으로 움직이기 때문에 구조적 이라고 이야기 한다. 

	
	//덧셈, 뺄셈, 곱셈, 나눗셈 만들기 사용자 입력 num1, num2
	/*
	int a, b;
	scanf_s("%d %d", &a, &b); -> 문자열 입력받을 경우, %s, str, sizeof(str) 이렇게 넣어줘야 한다. 

	int sumResult = sum(a, b);
	int subResult = sub(a, b);
	int mulResult = mul(a, b);
	double divResult = div(a, b);

	printf("sum = %d\n", sumResult);
	printf("sum = %d\n", subResult);
	printf("sum = %d\n", mulResult);
	printf("sum = %.1lf\n", divResult);
	*/


	//매개변수와 반환값이 모두 없는 함수
	/*
	print_line();
	printf("학번	이름	전공	학점\n");
	print_line();
	*/

	//return 0;
//}

/*
int sum(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

double div(int a, int b) {
	if (b == 0) {
		printf("다시 입력해주세요.\n");
		main();
	} 
	return a / b;
}
*/


/*
void print_line(void) {
	for (int i = 0; i < 50; i++) {
		printf("-");
	}
	printf("\n");
}
*/

