package com.example.calculator;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class PriorityFunction extends FunctionParent {

    public List<String> outputList = new ArrayList<>();                    //inputList 의 후위 연산식이 저장 될 list
    public Stack<String> postfixOperationStack = new Stack<>();            //inputList 를 후위 연산식으로 만드는데 필요한 Stack
    CalculatorFunction calculatorFunction = new CalculatorFunction();

    @Override
    Boolean isOperation(String s) {
        return super.isOperation(s);
    }

    @Override
    void init() {
        if (!outputList.isEmpty()) {
            outputList.clear();
        }
        outputList = new ArrayList<>();
    }

    //후위 연산식 만드는 클래스
    public Double makePostfixOperation(List<String> inputList) {
        this.init();

        for (int i=0;i<inputList.size();i++) {
            String str = inputList.get(i);

            if (isOperation(str)) {
                if (str.equals("(")) {
                    postfixOperationStack.push(str);
                } else if (str.equals(")")) {
                    String tempTop = postfixOperationStack.pop();
                    while (true) {
                        if (tempTop.equals("(")) {
                            break;
                        }
                        outputList.add(tempTop);
                        tempTop = postfixOperationStack.pop();
                    }
                } else {
                    while (!postfixOperationStack.isEmpty()
                            && operationPriorityMap.get(postfixOperationStack.peek()) >= operationPriorityMap.get(str)) {
                        outputList.add(postfixOperationStack.pop());
                    }
                    postfixOperationStack.push(str);
                }
            } else {
                outputList.add(str);
            }
        }

        //stack 에 남아 있는 것 출력
        while (true) {
            if (postfixOperationStack.isEmpty()) {
                break;
            }
            outputList.add(postfixOperationStack.pop());
        }

        for (int i=0;i<outputList.size();i++) {
            System.out.println(outputList.get(i));
        }

        return calculatorFunction.getResult(outputList);
    }
}
