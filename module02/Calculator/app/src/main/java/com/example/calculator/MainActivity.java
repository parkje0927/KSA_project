package com.example.calculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ScrollView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    //필드 생성
    Button btn1 , btn2 , btn3 , btn4, btn5, btn6, btn7, btn8, btn9 , btn0;  //피연산자
    Button btnPlus , btnMinus , btnDiv , btnMulti , btnLog , btnFac , btnInvolution , btnExp , btnMod;      //연산자
    Button btnEqual , btnReset , btnDot , btnDel , btnLeftParenthesis ,btnRightParenthesis;

    TextView outExDis , historyDis;    // 텍스트 외부 표현 및 history view
    ScrollView scrollView;

    InputFunction inputFunction;  // InputFunction class 호출
    History history; // History class 호출

    String input;       // 입력
    String operExpress; // 출력
    String hisData;    // history data
    double result;     // 결과값

    @Override
    protected void onCreate(Bundle saveInstanceState){
        super.onCreate(saveInstanceState);
        setContentView(R.layout.activity_main);

        init();

        //버튼 리스너 호출
        setNumListener();
        setOperListener();
    }

    void init(){

        // 피연산자 버튼 ( 0 ~ 9 )
        btn1 = (Button) findViewById(R.id.btn1);
        btn2 = (Button) findViewById(R.id.btn2);
        btn3 = (Button) findViewById(R.id.btn3);
        btn4 = (Button) findViewById(R.id.btn4);
        btn5 = (Button) findViewById(R.id.btn5);
        btn6 = (Button) findViewById(R.id.btn6);
        btn7 = (Button) findViewById(R.id.btn7);
        btn8 = (Button) findViewById(R.id.btn8);
        btn9 = (Button) findViewById(R.id.btn9);
        btn0 = (Button) findViewById(R.id.btn0);

        //연산자
        btnPlus = (Button)findViewById(R.id.btnPlus);      // 더하기
        btnMinus = (Button)findViewById(R.id.btnMinus);    // 빼기
        btnMulti = (Button)findViewById(R.id.btnMulti);     // 곱
        btnDiv = (Button)findViewById(R.id.btnDivision);        // 나누기
        btnLog = (Button)findViewById(R.id.btnLog);        // 상용로그
        btnExp = (Button)findViewById(R.id.btnExp);        // 지수
        btnMod = (Button)findViewById(R.id.btnMod);        // 나머지 연산
        btnInvolution = (Button)findViewById(R.id.btnInvolution);    // 거듭제곱
        btnFac = (Button)findViewById(R.id.btnFactorial);   //팩토리얼

        //기타 버튼
        btnReset = (Button)findViewById(R.id.btnReset);    //리셋
        btnEqual = (Button)findViewById(R.id.btnEqual);    // '='
        btnDel = (Button)findViewById(R.id.btnDel);        // 삭제
        btnDot = (Button)findViewById(R.id.btnDot);        // '.'
        btnLeftParenthesis = (Button)findViewById(R.id.btnLeftParenthesis);     // '('
        btnRightParenthesis = (Button)findViewById(R.id.btnRightParenthesis);   // ')'

        // activity_main 에 텍스트뷰 및 히스토리 뷰 id 설정이 필요
        outExDis = (TextView)findViewById(R.id.operationView);    // 입력 결과 view
        historyDis = (TextView)findViewById(R.id.histroyView);   // history view
        scrollView = (ScrollView) findViewById(R.id.history);

        inputFunction = new InputFunction();
        history = new History();

        //변수 초기화
        operExpress = "";
        input = "";
        result = 0.0;
    }

    // 리스너
    //버튼을 눌렀을 때 -> TextView
    void setNumListener(){

        View.OnClickListener NumListener = new View.OnClickListener(){
            @Override
            public void onClick(View view) {

                /**   id 상수값으로 코드 줄이는 방법 생각해보기   **/
                switch (view.getId()){
                    case R.id.btn0:
                        input += "0";
                        operExpress += "0";
                        break;

                    case R.id.btn1:
                        input += "1";
                        operExpress += "1";
                        break;

                    case R.id.btn2:
                        input += "2";
                        operExpress += "2";
                        break;

                    case R.id.btn3:
                        input += "3";
                        operExpress += "3";
                        break;

                    case R.id.btn4:
                        input += "4";
                        operExpress += "4";
                        break;

                    case R.id.btn5:
                        input += "5";
                        operExpress += "5";
                        break;

                    case R.id.btn6:
                        input += "6";
                        operExpress += "6";
                        break;

                    case R.id.btn7:
                        input += "7";
                        operExpress += "7";
                        break;

                    case R.id.btn8:
                        input += "8";
                        operExpress += "8";
                        break;

                    case R.id.btn9:
                        input += "9";
                        operExpress += "9";
                        break;

                }
                //operExpressionDisplay에 연산식 출력
                outExDis.setText(operExpress);
            }
        };
        btn0.setOnClickListener(NumListener);
        btn1.setOnClickListener(NumListener);
        btn2.setOnClickListener(NumListener);
        btn3.setOnClickListener(NumListener);
        btn4.setOnClickListener(NumListener);
        btn5.setOnClickListener(NumListener);
        btn6.setOnClickListener(NumListener);
        btn7.setOnClickListener(NumListener);
        btn8.setOnClickListener(NumListener);
        btn9.setOnClickListener(NumListener);
    }

    //연산 리스너
    void setOperListener() {
        View.OnClickListener OperationListener = new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                switch (view.getId()) {
                    case R.id.btnPlus:
                        input += "+";
                        operExpress += "+";
                        break;

                    case R.id.btnMinus:
                        input += "-";
                        operExpress += "-";
                        break;

                    case R.id.btnMulti:
                        input += "*";
                        operExpress += "*";
                        break;

                    case R.id.btnDivision:
                        input += "/";
                        operExpress += "/";
                        break;

                    case R.id.btnMod:
                        input += "m";
                        operExpress += "mod";
                        break;

                    case R.id.btnInvolution:
                        input += "^";
                        operExpress += "^";
                        break;

                    case R.id.btnLog:
                        input += "l";
                        operExpress += "log";
                        break;

                    case R.id.btnExp:
                        input += "e";
                        operExpress += "exp";
                        break;

                    case R.id.btnFactorial:
                        input += "!";
                        operExpress += "!";
                        break;

                    case R.id.btnLeftParenthesis:
                        input += "(";
                        operExpress += "(";
                        break;

                    case R.id.btnRightParenthesis:
                        input += ")";
                        operExpress += ")";
                        break;

                    case R.id.btnDot:
                        input += ".";
                        operExpress += ".";
                        break;

                    case R.id.btnEqual:
                        operExpress += "=";
                        result = inputFunction.makeInputStringToList(input);

                        //show history
                        hisData = history.makeHistory(operExpress + result);
                        historyDis.append(hisData);
                        scrollView.fullScroll(View.FOCUS_DOWN);

                        operExpress = result + "";
                        input = result + "";
                        break;

                    case R.id.btnDel:
                        if (input.length() - 1 >= 0) {
                            input = input.substring(0, input.length() - 1);
                            operExpress = input;
                        }
                        break;

                    case R.id.btnReset:
                        input = "";
                        operExpress = "";
                        outExDis.setText("");
                        break;
                }

                //operExpressionDisplay에 연산식 출력
                outExDis.setText(operExpress);

            }
        };

        btnPlus.setOnClickListener(OperationListener);
        btnMinus.setOnClickListener(OperationListener);
        btnMulti.setOnClickListener(OperationListener);
        btnDiv.setOnClickListener(OperationListener);
        btnMod.setOnClickListener(OperationListener);
        btnInvolution.setOnClickListener(OperationListener);
        btnLog.setOnClickListener(OperationListener);
        btnExp.setOnClickListener(OperationListener);
        btnFac.setOnClickListener(OperationListener);
        btnLeftParenthesis.setOnClickListener(OperationListener);
        btnRightParenthesis.setOnClickListener(OperationListener);
        btnDot.setOnClickListener(OperationListener);
        btnEqual.setOnClickListener(OperationListener);
        btnReset.setOnClickListener(OperationListener);
        btnDel.setOnClickListener(OperationListener);
    }
}