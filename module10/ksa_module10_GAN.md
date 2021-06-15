## Module10 : 비지도 학습(GAN과 시각지능)

### 0. Intro
- AI = Algorithm + data 
	+ Computer Vision(시각 지능) = 인식, 생성(GAN)
	+ 자연어 처리
	+ Data Science 

### 1. GAN의 기본 : Vanila GAN
#### GAN의 기본 원리
- 배경
	+ 배경1 : Adversarial Search(적대적 탐색)에 대한 오랜 연구가 존재
	+ 게임이론의 알고리즘으로 서로 반대되는 입장의 두 player가 서로 입장을 바꾸어 가면서 play함으로써 최적의 해를 찾아가는 과정
	+ 배경2 : 심층 학습의 discriminative model이 중점적으로 발전해 옴
	+ 배경3 : 심층 학습에서 generative model에 대한 개념이 떠오름(VAE:variational auto encoder)
	
#### GAN의 개념
- 생성자와 판별자의 대립과 경쟁을 통해서 모델을 훈련시켜서 사용자가 만족할만한 수준의 결과를 생성하는 생성 모델
- GAN의 훈련이 끝나면 마지막 parameter 를 저장한 generator를 이용해서 다양한 샘플을 생성

#### GAN의 구성 요소(1) : generator
- n개의 generator block으로 구성됨
- linear layer, batch norm, ReLU 함수로 구성

#### GAN의 구성 요소(2) : discriminator
- 입력을 받아서 real/fake를 판정하는 모듈
- classifier와 유사한 역할을 수행함
- 음수일 때 ReLU는 0을 return, but 이런 위험을 Leaky ReLU는 이런 위험을 감소시킴
- 입력 : 784, 출력 : 1

#### GAN의 구성 요소(3) : loss 함수
- Binary Cross Entropy 
	+ y가 1인 경우 -> log*h
	+ y가 0인 경우 -> log - log*h
	+ 최대한 y, h가 비슷하면 좋겠다. 
	+ BCE가 최대화되길 원함
	+ y가 1인 경우 -> 평균
	+ y가 0인 경우 -> generator를 생성하는 x, fake로 만들어진 데이터

- Binary Cross Entropy(2)
	+ generator 관점과 discriminator 관점이 서로 다르다. 
	+ discriminator는 진짜를 진짜로, 가짜를 가짜로 판별하는 정도가 max인 것이 좋다.
	+ generator는 y가 0일 때만 적용되므로, 가짜를 진짜로 판정하길 원한다. 따라서 min인 것이 좋다.
	+ BCE를 최대화하는 방향으로만 최적화하기 때문에 훈련이 비교적 쉽다. 
	+ GAN loss 함수는 역할에 따라서 다른 의미를 추구, max와 min 방향으로 최적화하기 때문에 훈련이 어렵다. 이를 극복하는 것이 가장 어렵고 중요한 문제이다. 

- optimizer	
	+ GAN loss 함수 최적화하기 위해서는 세타가 중요(수십만개)
	+ Gradient dist 와 유사한 가장 좋은 알고리즘은 Adam 이다. 
	+ class로 정의된 Generator 를 선언한다. 
	+ device = cpu or gpu
	+ generator 의 파라미터를 다 가져와서 optimize 하라 

- disc loss & gen loss
	+ generator의 경우에는 loss함수가 2번
	
#### Training
- GAN 훈련의 어려움
	+ discriminator(D) 는 max, generator(G)는 min을 추구
	+ 초기에는 log(1-D(z)))를 사용하지 말고 D(G(z))를 최대화시키는 방향으로 훈련시킬 것
	+ D(G(z))가 값이 더 크기 때문에 gradient가 소실되는 경우를 피할 수 있다. 
	+ D 먼저 훈련, 그 다음에 G 훈련하고 이를 반복한다. 

### 2. GAN의 발전(1) : DCGAN
### 3. GAN의 발전(2) : WGAN
#### WGAN의 기본 원리 : Entropy
- 정보 이론	
	+ m : 정보를 포함하는 message
	+ p(m) : m의 확률
	+ I(m) : m에 대한 self-information

- entropy의 개념
	+ 메시지 m의 집합 M에 대한 정보량의 평균값 
	+ 같은 메시지라도 균등하게 나타난다면 많은 에너지를 써야 한다. 

- cross entropy
	+ 두 확률 분포 p, q에 대해서 q를 이용해서 p를 설명할 때 필요한 정보량


  
### 4. GAN의 발전(3) : CGAN
### 5. 