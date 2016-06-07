# 동적 계획법 ( Dynamic Programming )

* 어원
	- 동적 계획법의 고안자인 Richard E. Bellman 은 dynamic 이라는 단어가 멋있어서 선택했다고.....


## 동적 계획법이란?
* 동적 계획법
	- 어떤 문제가 주어졌을 대 이를 작은 부분으로 쪼개어 답을 구하고, 이 부분 문제의 답을 기반으로
	전체 문제의 답을 구하는 방법.
* 분할 계획법과의 차이점
	- Bottom-Up
		- 문제를 제일 작은 부분부터 큰 문제로 올라가는 Bottom-Up 방식이다.
		- 분할 정복은 문제를 큰 부분에서 작은 작업으로 나누는 Top-Down 방식이다.
	- Memoization
		- 작은 문제로 나눈 부분의 답을 계산하고, 이 계산값을 토대로 더 큰 문제의 답을 구한다.
		- 동일한 계산의 반복 수행을 제거하여 프로그램 실행 속도를 빠르게 한다.


### 메모이제이션 ( Memoization )
* 메모이제이션을 적용할 수 있는 경우
	1. 부분 문제의 의존도
		- ![DP1-IMG]( https://github.com/Atibase-Study/Algorithm/blob/master/Presentation/img/dp1-mk.jpg )
			- 출처 : 프로그래밍 대회에서 배우는 알고리즘 문제해결 전략
		- (a) 는 각 문제들이 서로 연관이 없기 대문에, 단순하게 재귀 호출을 통해 문제를 분해해도
		한 부분 문제를 한번만 해결하게 된다.
		- (b) 는 나눠진 각 문제들이 같은 부분 문제에 의존하기 때문에, 재귀 호출을 통해 각 문제를 해결하면
		중복되는 부분 문제 ( Overlapping subproblems ) 가 많이 발생한다.
	2. 참조적 투명성 ( Referential Transparency )
		- 함수의 반환 값이 그 입력 값만으로 결정되어야 한다.
		- 입력이 고정되어 있을 때 그 결과가 항상 같은 함수들을 참조적 투명함수 라고 한다.
```c++
// a 와 b 는 각각 [0, 2500) 구간 안의 정수
// 반환 값은 항상 int 형 안에 들어가는 음의 정수
int someObscureFunction( int a, int b );
```  

	- someObscureFunction() 은 한 번 계산하는 데 굉장ㅇ히 시간이 오래 걸리는 참조적 투명 함수라 가정

* 메모이제이션 구현 패턴
	- 동적 계획법은 가장 흔한 문제 유형 중 하나이기 때문에 메모이제이션은 굉장히 자주 구현된다.
		- 그런 만큼 한 가지 패턴을 정해두고 항상 같은형태로 구현하면 작성하기도, 버그를 찾기도 쉬워진다.
	
* 메모이제이션의 시간 복잡도 분석


## 동적 계획법의 적용
* 외발 뛰기 ( ID : JUMPGAME )
	- https://algospot.com/judge/problem/read/JUMPGAME
* 삼각형 위의 최대 경로 ( ID : TRIANGLEPATH )
	- https://algospot.com/judge/problem/read/TRIANGLEPATH
* 최대 증가 부분 수열 ( ID : LIS )
	- https://algospot.com/judge/problem/read/LIS
* 합친 LIS ( ID : JLIS )
	- https://algospot.com/judge/problem/read/JLIS

