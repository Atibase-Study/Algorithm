# Monster Path

## Problem

Codejamon is a mobile game in which monster trainers walk around in the real world to catch monsters. You have an old smartphone with a short battery life, so you need to choose your path carefully to catch as many monsters as possible.   
codejamon 은 모바일 게임으로, 현실에서 돌아다니며 몬스터를 잡는 트레이너를 플레이한다.
당신은 오래되고 배터리 수명이 짧은 스마트폰을 가지고 있기때문에, 당신은 가능한 몬스터를 많이 잡을 수 있는 경로를
조심스럽게 선택해야 한다.


Suppose the Codejamon world is a rectangular grid with R rows and C columns. Rows are numbered from top to bottom, starting from 0; columns are numbered from left to right, starting from 0. You start in the cell in the Rsth row and the Csth column. You will take a total of S unit steps; each step must be to a cell sharing an edge (not just a corner) with your current cell.    
Codejamon 세계가 R 열과 C 행 으로 이루어진 사각형이라고 가정해보자. 열은 맨 위 0 부터 아래로 숫자가 부여된다. 행을 왼쪽에서 오른쪽으로 0 부터 숫자가 부여된다. 당신은 Rs 번째 행과 Cs 번째 열에서 출발한다. 당신을 총 S 번의 한 걸음을 갈 수 있다; 
각 걸음은 현재 당신이 위치한 셀과 모서리를 공유하는 셀로만 갈 수 있다. ( 코너는 제외, 즉 대각선 불가 )


Whenever you take a step into a cell in which you have not already caught a monster, you will catch the monster in that cell with probability P if the cell has a monster attractor, or Q otherwise.     
언제든 이전에 몬스터를 잡은적 없었던 셀로 걸음을 옮길 때, 만약 그 셀에 monster attractor 가 있다면 P 의 확률로
몬스터를 만나고 없다면 Q 의 확률로 몬스터를 만날 수 있다.


If you do catch the monster in a cell, it goes away, and you cannot catch any more monsters in that cell, even on future visits. If you do not catch the monster in a cell, you may still try to catch the monster on a future visit to that cell. The starting cell is special: you have no chance of catching a monster there before taking your first step.     
만약 셀에서 몬스터를 어떻게던 잡으면, 다시는 그 셀에서 몬스터를 잡지 못한다. 미래에도.
만약 어떤 셀에서 몬스터를 잡은적이 없다면, 당신은 여전히 그 셀에서 몬스터를 잡을 확률을 가진다.
처음 시작하는 셀은 특별한데, 이 셀은 당신이 첫 걸음을 때기 전까지는 몬스터를 잡을 수 있는 그 어떤 찬스도 없다.


If you plan your path optimally before making any move, what is the maximum possible expected number of monsters that you will be able to catch?   
만약에 당신의 당신의 길을 최적으로 계획하여 움직인다면, 당신이 잡을 수있는 최적의 몬스터 수는 몇마리일까?


The battery can only support limited steps, so hurry up!   
배터리는 오직 제한된 걸음안에서만 동작하니 빨리 서둘러라.


## Input

The first line of the input gives the number of test cases, T. T test cases follow.    
첫번째 줄은 테스트 케이스 수 T


Each test case starts with a line of five integers: R, C, Rs, Cs and S. R and C are the numbers of rows and columns in the grid; Rs and Cs
are the numbers of the row and column of your starting position, and S is the number of steps you are allowed to take.    
각 테스트 케이스는 5 개의 정수 R, C, Rs, Cs, S 로 나타낸다.
R 은 행의 수, C 는 열의 수, Rs 와 Cs 는 시작 포인트 지점, S 는 당신에게 허용된 최대 걸음수이다.


The next line contains two decimals P and Q, where P is the probability of meeting a monster in cells with a monster attractor, and Q is the probability of meeting a monster in cells without a monster attractor. P and Q are each given to exactly four decimal places.    
그다음 줄은 소수로 P 는 monster attractor 가 있는 셀에서 몬스터를 만날 확률이고, Q 는 monster attractor 가 없을 때 몬스터를 만날 확률이다.
P 와 Q 는 정확히 소수점 4자리 이다.


Each of the next R lines contains contains C space-separated characters; the j-th character of the i-th line represents the cell at row i and column j. Each element is either . (meaning there is no attractor in that cell) or A (meaning there is an attractor in that cell).     
그다음 R 행은 C 개의 문자-스페이스로 이루어져있다; 각 i 번째 줄의 j 번째 문자열은 i 행 j 열 셀을 나타낸다. 
. 은 attractor 가 없는 셀이고 A 는 attractor 가 있는 셀이다.


## Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the largest possible expected number of monsters that the player can catch in the given amount of steps.    
각 테스트 케이스 출력물의 줄에는  Case #x: y 를 포함하며 
x 는 케이스 넘버로 1 부터 시작하고 
y 는 주어진 스텝에서 플레이어가 몬스터를 잡을 수 있는 확률 중 가장 큰 확률의 총합이다.


y will be considered correct if y is within an absolute or relative error of 10^(-6) of the correct answer. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.    
y 는 소수점 오차  10 의 -6 승까지 나타낸다.


## Limits
- 1 ≤ T ≤ 100.  
- 0 ≤ Rs < R.
- 0 ≤ Cs < C.
- 0 ≤ Q < P ≤ 1.


#### Small dataset
- 1 ≤ R ≤ 10.
- 1 ≤ C ≤ 10.
- 0 ≤ S ≤ 5.


#### Large dataset
- 1 ≤ R ≤ 20.
- 1 ≤ C ≤ 20.
- 0 ≤ S ≤ 9.


## Sample

### Input 
 
2  
4 4 0 0 5  
0.8000 0.2000  
. . . .  
. . . .  
. . A .  
. A . A  
10 10 9 1 4  
0.6121 0.1000  
. . A A . . . . . .  
A . . . . . . . . .  
. . A . . . . A . .  
. . . A A . . . . .  
. A A A . . . . . A  
A . A A . . . . A .  
. A . . . . . A . .  
. . . . A A . . . .  
. . A . . . A . . A  
. . . . A . . A . .  


### Output
Case #1: 1.6000000  
Case #2: 1.0495336  



In Case #1, one of the best paths is (0,0)->(0,1)->(0,2)->(1,2)->(2,2)->(2,3). On this path, the expected number of monsters that you will catch is 0.2 + 0.2 + 0.2 + 0.8 + 0.2 = 1.6. Remember that there is no chance of catching a monster before taking your first step, which is why there are five probabilities in the calculation, not six.     
케이스 1 에서 최적의 패스는 (0,0)->(0,1)->(0,2)->(1,2)->(2,2)->(2,3) 이다.
각 패스에서 몬스터 잡을 확률은 0.2 + 0.2 + 0.2 + 0.8 + 0.2 = 1.6 이다.
당신이 첫 걸음을 때기 전까지는 몬스터를 잡을 수 있는 확률이 없다는것을 명심하고,
따라서 위의 예제는 확률이 6 개가 아니라 5 개로 계산된다.



In Case #2, one of the best paths is (9,1)->(9,2)->(8,2)->(8,3)->(8,2). On this path, the expected number of monsters that you will catch is 0.1 + 0.6121 + 0.1 + 0.23743359 = 1.04953359. Since we accept results within an absolute or relative error of 10-6 of the correct answer (1.04953359), 1.0495336 is accepted.    
최적의 경로는 위와 같고 답은 다음과 같다.
우리는 오차를 10^(-6) 까지 나타내기 대문에 1.04953359 가 아닌 1.0495336 으로 나타낸다.
