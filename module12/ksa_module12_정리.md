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

<hr>

#### 2. 딥러닝 기반의 자연어 처리 모델
##### BERT 란 무엇인가?
- BERT : Bidirectional Encoder Representations from Transformers
	+ 자연어 : bidirectional / sequential & symbolic data
	+ 자연어에서 특히 양방향 정보를 학습하고 이해하는 모델이다.
	+ Transformers : first transduction model only use self-attention on input/output reprs
- seq2seq
	+ Input Sequence 를 입력으로 받고 Output Sequence를 출력하는 모델(AutoEncoder)
	+ AutoEncoder 와 다를 게 없다. 
	+ Encoder layer : Context Vector 를 획득
	+ Decoder layer : 획득된 Context Vector 를 입력으로 다음 state 를 예측
- Attention 
	+ Encoder 가 token(단어) 마다 이해한 내용을 Key
	+ Decoder 입장에서 단어(token) 한 개당 하나씩 정리해서 넘겨달라 -> Query를 가지고 중요한 Key를 찾을 것이다. -> Dot Product 연산을 해서 찾을 건데 [1, vec_size] . [vec_size, 1] 처럼 계산하면 사이즈가 1(스칼라) 인 유사도(score) 가 된다. <br>
	Dot Product(내적)를 한다는 것은 한 벡터를 다른 벡터에 정사용한 것의 길이를 곱하는 건데 Query 벡터에 각 Key 벡터를 정사영하여 그 길이를 곱하는 것. 두 벡터 사이의 각도(alpha)가 커질수록 방향이 다른 것이니 두 벡터는 덜 비슷한 벡터이다. 비슷한 방향이면 Dot Product 의 결과 값이 크다. <br>
	이 유사도에 Softmax를 취하면 0 ~ 1 사이의 값이 된다. 그리고 이 score를 기존의 Key 벡터에 곱하여 Value를 만든다. -> 기존의 각 Key 벡터에 유사도 값을 곱하면 어떤 Key 벡터는 희미해지고, 어떤 Key 벡터는 비교적 값을 잃지 않는다. -> 모든 Value 벡터를 더해서 입력으로 쓴다. 
	+ 어텐션 메커니즘은 인코더가 단어 단위로 정리한 벡터 중에서 디코더가 중요한 벡터를 골라서 쓰는 방법이다.
	+ 어텐션 메커니즘을 시각화해볼 수 있다. 
- Transformer
	+ Transformer는 RNN의 Recurrent Unit을 제거하고 Multi Layer Perceptron과 Attention만 사용하는 새로운 형식의 뉴럴 네트워크이다. 요즘 대부분 자연어 처리 테스크에 적용되고 있다. 
	+ 유독 Transformer부터는 Word2Vec 같은 워드 임베딩 기법을 거의 사용하지 않는다. 대신 주로 Embedding Layer(nn.Embedding)을 사용한다. Embedding Layer는 각 단어(토큰)에 대한 벡터를 가지고 있는 일종의 맵핑 테이블인데, BackPropagation으로 각 단어(토큰)의 벡터가 업데이트 된다.
	+ Self-Attention : 하나의 문장에 각각 다른 Weight를 곱해서 Query, Key, Value 텐서를 만든다. 벡터가 아닌 텐서인 이유는 RNN과 달리 동시에 여러 토큰을 계산하기 때문! (Transformer는 병렬적이다.)
	+ Multi-head Attention : 여러 head 를 나눔 -> 하나만 만드는 것보다 다양한 경우의 수를 고려 -> 앙상블 효과
	+ Self-Attention is not Symmetrics!
	+ Attention as the routing of multiple local information
	+ Masked Multi-head Attention : 해당 부분 계산 금지를 위해 역삼각형 마스킹을 추가함
	+ Encoder-Decoder Attention = Cross Attention
- BERT
	+ MLM : 단어를 MASK로 랜덤하게 변경하고 원래 토큰 맞추기
	+ NSP : 두 문장을 SEP으로 연결해서 입력, 연결된 문장인지 아닌지 맞추기
	+ Transformer Encoder만 사용하여 만든 Encoder Langauge Model
	+ Activation 함수는 ReLU가 아닌 GeLU를 사용해서 성능을 개선
	<br>
	+ 이후에 원하는 태스크의 데이터셋으로 모델을 Fine-tuning 해서 사용
- BART 
	+ 다양한 Noise 방법으로 학습

- 참고
	+ https://github.com/jinmang2/ksa_nlp




