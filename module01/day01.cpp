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
	unsigned int ��� ���� �����Ƿ� �ֻ��� ��ȣ ��Ʈ�� ������ ���ڴٴ� �ǹ�
	-> 4294967295 ��� ������ �����Ƿ� �� 11111111�� ä������. �׷��� -1�̶�� ����� �ǰ�,
	-> ��ȣ�� �����ϴ� %u �� ��������, 4294967295 �� ��µȴ�.

	��, ���� ��µǴ� max ���� �˰� �־�� �Ѵ�.
	*/

	/*
	����A�� �����ؼ� ���� �����س��� ������ ���� �����ص�
	����A�� ���� ������ �ʴ´�.
	*/

	
	/*
	int value = 10;

	char fruit[20] = "strawberry";

	printf("���� : %s\n", fruit);
	printf("����´ : %s %s\n", fruit, "jam");

	strcpy_s(fruit, "banana");
	printf("%s\n", fruit);
	*/


	//4��
	//�������ڴ� 2��, ��Ʈ�����ڴ� 1���� ����Ѵ�. 

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

	printf("�ʱ갪 a = %d, b = %d\n", a, b);
	printf("������ : (++a) * 3 = %d, ������ : (b++) * 3 = %d\n", pre, post);*/

	//��������
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


	//�� ��ȯ ������
	/*
	int a = 20, b = 3;
	double res;

	res = ((double)a) / ((double)b); //�Ǽ��� ��ȯ
	printf("a = %d, b = %d\n", a, b);
	printf("a / b�� ��� : %.1lf\n", res);

	a = (int)res; //������ ��ȯ
	printf("(int) %.1lf�� ��� : %d\n", res, a);
	*/


	//sizeof ������
	/*
	int a = 10;
	double b = 3.4;

	printf("int�� ������ ũ�� : %d\n", sizeof(a)); //4
	printf("double�� ������ ũ�� : %d\n", sizeof(b)); //8
	printf("������ ����� ũ�� : %d\n", sizeof(10)); //4
	printf("������ �ᱣ���� ũ�� : %d\n", sizeof(1.5 + 3.4)); //8 -> �Ǽ��� ����� �⺻�� double �̱� �����̴�. 
	printf("char �ڷ����� ũ�� : %d\n", sizeof(char));
	*/


	//���մ��� ������
	/*
	int a = 10, b = 20;
	int res = 2;

	a += 20;
	res *= b + 10;

	printf("a = %d, b = %d\n", a, b);
	printf("res = %d\n", res);
	*/

	
	//�޸� ������
	/*
	int a = 10, b = 20;
	int res;

	res = (++a, ++b); //= �� , �� �켱������ ���Ͽ� =�� �����Ƿ� res �� ++a ���� ����

	printf("a : %d, b : %d\n", a, b); //11, 21
	printf("res : %d\n", res); //21
	*/


	//���� ������
	/*
	int a = 10, b = 20, res;
	res = (a > b) ? a : b;
	printf("ū �� : %d\n", res);
	*/

	//��Ʈ ������
	/*
	int a = 10;
	int b = 12;

	printf("a & b : %d\n", a & b); //8  �� �� 1 �϶��� 1
	printf("a ^ b : %d\n", a ^ b); //6  ���� ���� ���̸� 0, �ٸ� ���̸� 1
	printf("a | b : %d\n", a | b); //14 �� �߿� �ϳ��� 1�̸�1
	printf("~a : %d\n", ~a); //-11		���� ������ 
	printf("a << 1 : %d\n", a << 1); //20	���� �̵� ������, �ڿ��� 0���� ä��
	printf("a >> 2 : %d\n", a >> 2); //2	������ �̵� ������, �տ��� 0���� ä�� 
	*/


	//������ �켱������ ���� ����
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

	//���� ������(++)�� ���� ������(*)���� �켱������ ����. 
	//��� > ����(>, !=) > ��(&&) ������ ������ �켱������ ����. 
	*/


	//<5��>
	//if ���� �⺻ ����
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

	
	//if�� ��ø
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


	//switch ~ case��
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
	//break �� ���� ��� m = 200�� �ְ� 100�� �ְ� ��� �����ϰ� �ȴ�. ��, break�� �����ϸ� ��� ������ �����Ѵ�. 
	*/

	
	//<6��>
	//do ~ while��
	/*
	int a = 1;
	do {
		a = a * 2;
	} while (a < 10);
	printf("a : %d\n", a); //16

	//��ø �ݺ����� ����ó���� �⺻�̴�. 

	//������

	//break : ��ü�� �������´�. 
	//continue : �Ѿ�� ����

	//���� �ݺ��� : while(1) for(;;)
	*/

	//<7��>
	//�̸��� �Ű�����, ��ȯ���� ��Ȯ�ϰ� ���ǵǾ�� �Ѵ�. 
	//��ȯ���� �Ű������� void�� ��찡 �ִ�. 
	
	//�Լ� ����, ����, call => 3���� ������

	//�Լ��� ���� �����ϰ� ���Ŀ� �����ϴ� ������, �������� ���ؼ��̴�. 
	//�Լ� ������� �����̱� ������ ������ �̶�� �̾߱� �Ѵ�. 

	
	//����, ����, ����, ������ ����� ����� �Է� num1, num2
	/*
	int a, b;
	scanf_s("%d %d", &a, &b); -> ���ڿ� �Է¹��� ���, %s, str, sizeof(str) �̷��� �־���� �Ѵ�. 

	int sumResult = sum(a, b);
	int subResult = sub(a, b);
	int mulResult = mul(a, b);
	double divResult = div(a, b);

	printf("sum = %d\n", sumResult);
	printf("sum = %d\n", subResult);
	printf("sum = %d\n", mulResult);
	printf("sum = %.1lf\n", divResult);
	*/


	//�Ű������� ��ȯ���� ��� ���� �Լ�
	/*
	print_line();
	printf("�й�	�̸�	����	����\n");
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
		printf("�ٽ� �Է����ּ���.\n");
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

