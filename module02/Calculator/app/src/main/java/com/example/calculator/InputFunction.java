package com.example.calculator;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class InputFunction extends FunctionParent {

    public List<String> inputList = new ArrayList<>();  //계산기에 입력한 input 을 list 로 저장
    PriorityFunction priorityFunction = new PriorityFunction();

    @Override
    void makeOperationPriority() {
        operationPriorityMap = new HashMap<>();
        operationPriorityMap.put("(", 0);
        operationPriorityMap.put("+", 1);
        operationPriorityMap.put("-", 1);
        operationPriorityMap.put("*", 2);
        operationPriorityMap.put("/", 2);
        operationPriorityMap.put("m", 2);
        operationPriorityMap.put("^", 2);
        operationPriorityMap.put("l", 3);
        operationPriorityMap.put("e", 3);
        operationPriorityMap.put("!", 3);
    }

    @Override
    void init() {
        if (!inputList.isEmpty()) {
            inputList.clear();
        }
        inputList = new ArrayList<>();
    }

    @Override
    Boolean isOperation(String s) {
        return super.isOperation(s);
    }

    public Double makeInputStringToList(String input) {
        this.makeOperationPriority();
        this.init();

        int lastIndex = 0;

        for (int i=0;i<input.length();i++) {
            char c = input.charAt(i);
            String str = Character.toString(c);

            if (inputList.isEmpty()) {
                inputList.add(str);
            } else {
                lastIndex = inputList.size() - 1;

                if (isOperation(str)) {
                    inputList.add(str);
                } else {
                    if (isOperation(inputList.get(lastIndex))) {
                        inputList.add(str);
                    } else {
                        inputList.set(lastIndex, inputList.get(lastIndex) + str);
                    }
                }
            }
        }

        return priorityFunction.makePostfixOperation(inputList);
    }
}
