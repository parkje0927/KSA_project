# KSA 인공지능 수강생 정보 검색 콘솔

### 목적
C언어를 기반으로 KSA 인공지능 수강생들의 정보를 검색할 수 있는 콘솔 개발

### 팀 정보
해당 프로젝트에 참여한 팀원

* 팀장 : 박정현 / https://github.com/parkje0927
* 팀원 : 박규란 / https://github.com/gyulhana
* 팀원 : 이윤수 / https://github.com/lys1026z

### 설계 세부 설명

* data.txt
각 행으로 구분된 수강생 25명과 해당 인원의 이름, 매칭 기업, 연락처 등 총 7개의 정보를','로 구분한 파일 

* data.h
수강생 관련 7개 정보를 구조체로 선언한 헤더 파일

 	+ 이름 name
 	+ 기업 comp
 	+ 성별 s
 	+ 연락처 tel
 	+ 이메일 email
 	+ 생년월일 birth
 	+ 전공 major

* main.txt
while 구문 안에서 scanf와 strcmp를 활용해 이용자가 입력한 정보와 기존 데이터의 문자열 비교를 통해 이용자가 입력한 정보에 해당하는 모든 수강생 정보를 출력한다. 총 7개의 정보를 선택해 검색을 반복적으로 수행할 수 있도록 하며 종료 희망시 검색 종료를 가능하게 한다.

 	+ 1 매칭기업
 	+ 2 이름
 	+ 3 성별
 	+ 4 연락처
 	+ 5 이메일
 	+ 6 생년월일
 	+ 7 전공
 	+ 8 검색 종료

* sub.txt
data.txt를 읽기 모드로 불러와 수강생의 각 정보들을 strcpy를 이용해 구조체에 저장하고 정상적으로 저장되었는지 출력하여 확인한다.
