package com.example.calculator;

public class Operation {

    // 공학용 계산기 계산 메소드 모음

    // 1.덧셈
    public double plus(double a , double b)
    {
        return a + b;
    }

    // 2.뺄셈
    public double minus(double a , double b)
    {
        return a - b;
    }

    // 3.나누기
    public double div(double a , double b)
    {
        return a / b;
    }

    // 4. 곱하기
    public double mul(double a , double b)
    {
        return a * b;
    }

    // 5. 나머지 연산
    public double mod(double a, double b)
    {
        return a % b;
    }
    // 6. 지수 계산
    public double exponential(double a)
    {
        return Math.exp(a);
    }

    // 7. 상용로그 계산
    public double commonLog(double a)
    {
        return Math.log10(a);
    }

    // 8. 거듭 제곱
    public double power(double a , double b) {
        return Math.pow(a, b);
    }

    // 9. 팩토리얼
    public double factorial(double a)
    {
        if(a <= 1) {
            return 1;
        }
        else
        {
            return a*factorial(a-1);
        }
    }
}

