package com.example.calculator;

import java.util.List;
import java.util.Stack;

public class CalculatorFunction extends FunctionParent {

    public Stack<String> finalStack = new Stack<>();    //최종적으로 계산 시 필요한 Stack
    Operation operation = new Operation();

    @Override
    void init() {
        if (finalStack.size() >= 1) {
            finalStack.clear();
        }
    }

    @Override
    Boolean isOperation(String s) {
        return super.isOperation(s);
    }

    public Double getResult(List<String> outputList) {
        Double num1 = 0.0;
        Double num2 = 0.0;
        String temp = null;
        this.init();

        for (int i=0;i<outputList.size();i++) {
            String str = outputList.get(i);

            if (isOperation(str)) {
                if (str.equals("+") && finalStack.size() > 1) {
                    num2 = Double.parseDouble(finalStack.pop());
                    num1 = Double.parseDouble(finalStack.pop());
                    temp = String.valueOf(operation.plus(num1, num2));
                    finalStack.add(temp);
                } else if (str.equals("-") && finalStack.size() > 1) {
                    num2 = Double.parseDouble(finalStack.pop());
                    num1 = Double.parseDouble(finalStack.pop());
                    temp = String.valueOf(operation.minus(num1, num2));
                    finalStack.add(temp);
                } else if (str.equals("*") && finalStack.size() > 1) {
                    num2 = Double.parseDouble(finalStack.pop());
                    num1 = Double.parseDouble(finalStack.pop());
                    temp = String.valueOf(operation.mul(num1, num2));
                    finalStack.add(temp);
                } else if (str.equals("/") && finalStack.size() > 1) {
                    num2 = Double.parseDouble(finalStack.pop());
                    num1 = Double.parseDouble(finalStack.pop());
                    temp = String.valueOf(operation.div(num1, num2));
                    finalStack.add(temp);
                } else if (str.equals("m") && finalStack.size() > 1) {
                    num2 = Double.parseDouble(finalStack.pop());
                    num1 = Double.parseDouble(finalStack.pop());
                    temp = String.valueOf(operation.mod(num1, num2));
                    finalStack.add(temp);
                } else if (str.equals("l") && finalStack.size() > 0) {
                    num2 = Double.parseDouble(finalStack.pop());
                    temp = String.valueOf(operation.commonLog(num2));
                    finalStack.add(temp);
                } else if (str.equals("^") && finalStack.size() > 1) {
                    num2 = Double.parseDouble(finalStack.pop());
                    num1 = Double.parseDouble(finalStack.pop());
                    temp = String.valueOf(operation.power(num1, num2));
                    finalStack.add(temp);
                } else if (str.equals("e") && finalStack.size() > 0) {
                    num2 = Double.parseDouble(finalStack.pop());
                    temp = String.valueOf(operation.exponential(num2));
                    finalStack.add(temp);
                } else if (str.equals("!") && finalStack.size() > 0) {
                    num2 = Double.parseDouble(finalStack.pop());
                    temp = String.valueOf(operation.factorial(num2));
                    finalStack.add(temp);
                }
            } else {
                finalStack.push(str);
            }
        }

        if (finalStack.isEmpty()) {
            return 0.0;
        } else {
            return Double.parseDouble(finalStack.get(0));
        }
    }
}
