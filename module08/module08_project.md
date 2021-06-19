## **Object detection** 모델을 이용한 객체 탐지 모델 만들기

날짜 : 2021.06.20

작성자 : 박정현

---

### 모델

- Single Shot Multibox Detector(SSD) 사용

### 설계 문서

1. 데이터 취득 방법
- 수업시간에 활용했던 데이터를 이용

2. 학습 데이터 전처리 방법과 결과 이미지
- **csv_merge.py** : 11종의 앵무새 데이터 train, test, val을 하나의 train.csv, test.csv, val.csv 로 merge 
- **image_merge.py** : 11종의 앵무새 데이터의 모든 image 를 하나의 폴더에 merge
- **parrot_h5.py** : train.csv, test.csv, val.csv을 통해 h5 파일 생성

3. 모델 선정 및 학습
- vgg 모델 선정
- tensorflow-gpu = 1.15.5 로 변경하여 학습 진행

4. 모델 개선
- batch_size를 1로 수정하고, learning_rate 역시 0.001 에서 0.00001로 수정

5. 모델 평가
- 성능 문제로 epoch을 모두 돌려보지는 못하였으나 loss, val_loss가 계속 감소하는 것을 알 수 있음

6. 테스트 결과(mean Average Precision 값, 테스트 결과 이미지

![결과](https://github.com/parkje0927/KSA_project/blob/master/module08/%EA%B2%B0%EA%B3%BC.png)
