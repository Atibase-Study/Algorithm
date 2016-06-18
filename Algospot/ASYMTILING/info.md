# 비대칭 타일링

## 문제 정보
* 시간 제한
	- 1000 ms
* 메모리 제한
	- 65536 kb

## 문제 
![img](http://algospot.com/media/judge-attachments/99b44b86e82ea246a21867a6970aedfb/13.png)
![img](http://algospot.com/media/judge-attachments/eabd9fdeb757541289354b1dde1357f0/12.png)
![img](http://algospot.com/media/judge-attachments/56f26d8f5217e108489083aa594fca16/11.png)

![img](http://algospot.com/media/judge-attachments/b60ba1f71aaa61dde733d5088c75b82b/10.png)
![img](http://algospot.com/media/judge-attachments/03beebe7a6a34a588d0742a71e6d63e4/09.png)
![img](http://algospot.com/media/judge-attachments/71701ba4f30e767b1894c86b216a5daa/07.png)

그림과 같이 2 * n 크기의 직사각형을 2 * 1 크기의 타일로 채우려고 합니다. 타일들은 서로 겹쳐서는 안 되고, 90도로 회전해서 쓸 수 있습니다. 단 이 타일링 방법은 좌우 대칭이어서는 안 됩니다. 위 그림은 2 * 5 크기의 직사각형을 채우는 비대칭 타일링 방법 6가지를 보여줍니다. 다음의 2가지는 좌우대칭이기 때문에 세지 않습니다.

![img](http://algospot.com/media/judge-attachments/25c64a7a37ecfc8c5b2691d24c237510/14.png)
![img](http://algospot.com/media/judge-attachments/c9dec0372bcc0b198a30305af57364fa/08.png)

n 이 주어질 때 가능한 비대칭 타일링 방법의 수를 계산하는 프로그램을 작성하세요. 방법의 수는 매우 클 수 있으므로, 1,000,000,007 로 나눈 나머지를 출력합니다.

### 입력

입력의 첫 줄에는 테스트 케이스의 수 C (1 <= C <= 50) 가 주어집니다. 그 후 각 줄에 사각형의 너비 n (1 <= n <= 100) 이 주어집니다.

### 출력

각 테스트 케이스마다 한 줄에 비대칭 타일링 방법의 수를 1,000,000,007 로 나눈 나머지를 출력합니다.


## 예제 입력

~~~
3
2
4
92
~~~


## 예제 출력  

~~~
0
2
913227494
~~~

## 링크
https://algospot.com/judge/problem/read/ASYMTILING
