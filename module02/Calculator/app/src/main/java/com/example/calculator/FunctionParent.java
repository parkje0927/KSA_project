package com.example.calculator;

import java.util.HashMap;
import java.util.Map;

public class FunctionParent {

    public static Map<String, Integer> operationPriorityMap = new HashMap<>();    //연산자 우선순위 저장한 map

    //연산자 여부 확인하는 메소드
    Boolean isOperation(String s) {
        if (s.equals(")")) {
            return true;
        }
        return operationPriorityMap.containsKey(s);
    }

    //연산자 우선순위 만드는 메소드
    void makeOperationPriority() {}

    //초기화 메소드
    void init() {}
}


