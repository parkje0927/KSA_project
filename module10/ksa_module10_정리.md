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

<hr>

### 2. GAN의 발전(1) : DCGAN
- GAN 의 문제
	+ very unstable training
	+ uncontrollable result

#### DCGAN의 기본원리
- Convolution 연산
	+ 주어진 함수에 g(kernel, filter)를 곱해서 더하는 연산
	+ edge detector : 왼쪽과 오른쪽 차이가 큰 경우 활용
	+ vertical detector
	+ horizontal detector 

- Convolution의 주요 속성
	+ size(kernel의 크기) : 3X3, 4X4, 5X5, etc
	+ stride(kernel의 적용 단위) : 1, 2, 3, etc => 몇 칸씩 건너서 할 것인지
	+ padding(입력 영상의 주변) : None, 0, 1, etc => 0이면 연산의 크기가 줄어들지 않는다.

- Convolution 연산
	+ 1x28x28 : grayscale 28X28 사이즈
	+ 5x5x5 : 5X5 사이즈 필터를 5개 사용한다 => 5가지 다른 성분을 뽑아낸다. 5X5의 경우에는 왼쪽, 오른쪽으로 2픽셀씩 공간이 필요하므로 총 4픽셀을 잃어버린다. 이는 주연이 아닌 조연이므로 상관 없다.
	+ torch.nn.Conv2d(in_channels, out_channels, kernel_size, stride = 1, padding = 0, 등,,, ) -> Conv2d(3, 10, 5, 1, 2) : 커널 사이즈는 5x5, stride는 한 칸씩, padding은 0

- Transposed Convolution
	+ Inverse Convolution with 3x3 filter
	+ 영상의 크기가 커지는 연산
	+ DConvolution 결과(복원된)와 원본이 같다고 보장할 수는 없다. 

#### DCGAN의 개념
- DCGAN
	+ binary 보다 더 품질이 향상된 이미지를 얻을 수 있다. 
	+ a strong candidate for unsupervised learning
	+ walk in the latent space 
	+ GAN + Convolutional layer

#### DCGAN의 구성 요소(1) : generator
- gen block
	+ parameter : input_channels, output_channels, kernel, stride, final_layer
	+ components for internal : transposed convolution + batch norm + ReLU
	+ conponents for final : transposed convolution + tanh

#### DCGAN의 구성 요소(2) : discriminator
- disc block
	+ parameter : input_channels, output_channels, kernel, stride, final_layer
	+ components for internal : convolution + batch norm + LeakyReLU
	+ conponents for final : convolution

#### DCGAN의 구성 요소(3) : loss 함수 
- fake.detach() : detach 는 gpu에서 cpu로 바꿔서 사용하겠다 이런 의미인데, cpu로 사용 시 이를 제거하고 사용해야할 수도 있다. 

#### DCGAN의 구성 요소(4) : 훈련
- gen block 계산 
	+ H_out = (H_in - 1) * stride - 2 * padding + dilation * (kernel_size - 1) + output_padding + 1
	+ 1) H_in = 1 / kernel_size, stride = 3, 2 -> 3x3
	+ 2) H_in = 3 / kernel_size, stride = 4, 1 -> 6x6
	+ 3) H_in = 6 / kernel_size, stride = 3, 2 -> 13x13
	+ 4) H_in = 13 / kernel_size, stride = 4, 1 -> 28x28


<hr>


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

#### WGAN의 개념
- GAN의 목적
	+ Pdata(x) 와 P(z) 를 최대한 비슷하게 만들자 -> 이 둘의 거리를 최소로 만들자

- cross entropy를 이용한 distribution의 거리 측정의 문제 -> gradient close to zero -> gradient vanishing
	+ 해결책 : Earth Mover's Distance
	+ 두 분포의 차이를 두 분포 사이의 거리로 정의
	+ 하나의 분포를 다른 분포로 옮기는 작업을 earth move로 간주

- Wasserstein distance
	+ Earth Mover's Distance를 이용해서 정의
	+ Discriminator -> Critic

- WassersteinGAN의 loss 함수
	+ Generator : minimize the distance
	+ Critic : maximize the distance 
	+ Gradient exploding : Gradient가 큰 경우, gradient descent method를 이용해서 구하는 값이 지나치게 커져서 수렴하기 못하는 경우
	+ Gradient 의 절대값이 1에 가까운 상태를 유지할 것

- integer(8bit, 32bit, 32bit) => giga

#### WGAN의 개념(4) : gradient penalty 설계
- gradient의 크기를 1이하로 유지 -> critic의 학습 능력을 제한
- Gradient 가 1에 가까운 수로 나올 수 있도록 regularization을 이용
- G(z)와 x를 보간해서 𝑥hat 생성 -> G(z)의 품질을 높여서 critic의 학습 속도를 조절

#### DCGAN_CelebA
- MNIST
	+ 1x1x10 -> 28x28x1
- CelebA
	+ 1x1x10 -> 64x64x3 (ConvTransposed2d 를 통해)
	+ 64x64x3 -> 1x1x1 (Conv2d 를 통해)
- ConvTransposed2d, Conv2d 의 stride, kernel_size, padding 을 조절

##### generator
- H_out = (H_in - 1) * stride - 2 * padding + dilation * (kernel_size - 1) + output_padding + 1
- dilation => 1만 주고, output_padding => 0만 주고 있으므로 위 식은 다음과 같이 바뀐다.
- H_out = (H_in - 1) * stride - 2 * padding + (kernel_size - 1) + 1
- if) stride = 2, padding = 1, kernel_size = 4
- H_out = (H_in - 1) * 2 - 2 + (4 - 1) + 1 = 2 * H_in
- 1 -> 2 / 2 -> 4 / 4 -> 8 / 8 -> 16 / 16 -> 32 / 32 -> 64 => 6개의 Generator block 을 붙여야 한다 
- 1 -> (H_in - 1) * 2 - 2 * padding + (4 - 1) + 1 = 4 -> padding = 0

##### discriminator
- if) stride = 2, kernel_size = 4, padding = 1
- 64 -> floor((64 + 2 * padding - kernel_size) / 2 + 1) -> floor((64 + 2 * 1 - 4) / 2 + 1) = 32
- 32 -> floor((32 + 2 * 1 - 4) / 2 + 1) = 16


<hr>
  

### 4. GAN의 발전(3) : CGAN
#### CGAN의 개념
- Conditional GAN
- latent vector(noise vector), condition vector(one-hot vector)

#### CGAN의 구성요소(1) : generator
- parameter: input_channels, output_channels, kernel, stride, final_layer- components for internal	+ transposed convolution + batch norm + ReLU- components for final	+ Transposed convolution + tanh

#### CGAN의 구성요소(2) : discriminator

#### CGAN의 구성요소(3) : class input 생성
- Latent vector와 one-hot vector의 concatenation

#### CGAN의 구성요소(4) : loss 함수
- class를 고려해서 loss 함수 생성

#### CGAN의 구성요소(5) : training


<hr>


### 5. GAN의 응용(1) : pix2pix
#### pix2pix의 개념
- 한 영상으로부터 새로운 스타일의 영상을 생성하는 기법
- pix2pix -> cycleGAN -> gauGAN
#### pix2pix의 배경
- Conditional GAN을 발전시킴
#### pix2pix의 구조
- G는 스케치 (x)에서 컬러 영상 (G(x))를 생성- D는 합성된 컬러 영상 G(x), 또는 실제 컬러 영상 (y)와 x를 비교해서 fake/real 을 판별
#### pix2pix의 구성 요소 (1): generator
- 같은 shape 끼리 concate를 한다. 
- U-Net : Convolutional Networks for Biomedical Image Segmentation
	+ endocer-decoder 구조
	+ deconv-net 이라고도 불리움
	+ x -> encoder -> latent vector -> decoder -> y

	+ forward pass : encoder의 정보를 decode에 전달
	+ backward pass : encoder의 gradient flow를 개선
	+ 학습을 위해 encoder에서 뽑은 정보를 decoder에 전달

- U-Net 구조를 이용한 generator(1)
	+ 256x256x3 -> 1x1x512
	+ 8 개의 encoder block	+ 각 encoder block은 conv – batch norm – Leaky ReLU로 구성	+ 256 x 256 x 3 -> 1 x 1 x 512

- U-net 구조를 이용한 generator (2)	+ 8 개의 decoder block	+ 각 dencoder block은 transposed conv – batch norm – ReLU로 구성	+  1 x 1 x 512 -> 512 x 512 x 3

- U-net 구조를 이용한 generator (3)	+ 8 개의 en-block을 가진 encoder와 8 개의 de-block을 가진 decoder	+ 512 x 512 x 3 -> 512 x 512 x 3	+ Skip connection
	
#### pix2pix의 구성 요소 (2): discriminator
- PatchGAN 구조를 사용	+ 전통적 GAN에서는 discriminator가 전체 영상에 대해서 Real/Fake를 판정함	+ PatchGAN에서는 영상을 patch로 분할하여 각 영역의 Real/Fake를 판정함
	+ prediction의 값이 0에 가까우면 fake
	+ prediction의 값이 1에 가까우면 real#### pix2pix의 구성 요소 (3): loss 함수#### pix2pix의 구현#### pix2pix의 한계와 극복
- Paired image에서만 적용 가능 => unpaired image-to-image translation

### 6. GAN의 응용(2) : CycleGAN




























