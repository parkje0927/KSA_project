### 비정형 데이터 
#### 1. aws
##### vscode 사용법
- 1) 인스턴스를 생성
	+ ubuntu 18.04
	+ 프리티어로 진행
	+ 포트번호 22 확인 후 계속 진행
- 2) key pair 생성 & 보안 
	+ 새로 만들기
	+ 이름을 작성한 뒤에 다운로드를 진행
	+ 보안 -> 보안 그룹 -> 인바운드 규칙 생성 -> 사용자 지정 tcp, 위치무관으로 생성
- 3) pem 파일 ssh 에 복사하기
	+ cp pem키파일이있는위치 ~/.ssh/ -> cd ~/.ssh/ -> chmod 600 ~/.ssh/pem키파일
	+ (참고) https://www.overtop.co.kr/m/363
	+ (참고) https://soobarkbar.tistory.com/m/223
- 4) vs code
	+ remote ssh 다운로드
	+ Open ssh configuration file -> 내용 추가 
	+ Connect to Host
	+ open folder -> python 파일 추가(ex: run.py)
- 5) pip3 install
	+ sudo apt update
	+ sudo apt install python3-pip
	+ pip3 install flask
	+ sudo ufw allow 9001
	+ python3 run.py
- 참고
	+ https://github.com/KangDoHyeong/KSA_NLP

---





