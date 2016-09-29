# Soldiers

## Problem
General Alice and General Bob are playing a war game. There are N soldiers in the game. Each soldier has two stats: attack and defense.  
장군 엘리스와 장군 밥은 전쟁게임중이다. 게임상에는 N 명의 군인이 이따. 각 군인은 두가지 상태를 가진다. ( 공격과 방어 )


Before the game starts, General Alice and General Bob will take turns selecting soldiers, with General Alice going first.    
게임이 시작되기 전에 장군 엘리스와 장군 밥은 병사를 고르는 턴을 가지고, 엘리스가 먼저 게임을 시작한다.


In each turn, a player can select one soldier, as long as that soldier either has an attack stat greater than each of the attack stats of all soldiers selected so far, or has a defense stat greater than each of the defense stats of all soldiers selected so far.     
공격스탯이 여태것 선택한 군인보다 공격 스탯이 높거나, 또는 방어 스탯이 여태것 선택한 군인의 방어 스탯보다 높다면 플레이어는 각 턴에서 한명의 군인을 선택할 수 있다.


To be precise: let Ai and Di be the attack and defense values for the i-th soldiers, for i from 1 to N, and let S be the set of soldiers that have been selected so far. Then a player can select soldier x if and only if at least one of the following is true:   
정확하게 하려면:
Ai 와 Di 를 i 번째 군인의 공격, 방어 수치라 하고, i 는 1 부터 N 까지 가지며 S 를 여태까지 선택된 군인의 수라고 한다.
만약 다음의 조건중 하나라도 만족한다면 플레이어는 군인 x 를 선택할 수 있다.  
- Ax > As for all s in S
- Dx > Ds for all s in S


If no selection can be made, then the selection process ends and the players start playing the game.  
General Alice wants to select more soldiers than General Bob, and General Bob wants to avoid that. If both players play optimally to accomplish their goals, can General Alice succeed?      
만약 어떠한 선택도 없었다면, 선택 과정은 끝나고 플레이어는 게임을 시작한다.
장군 엘리스는 장군 밥 보다 더 많은 군인을 선택하길 원하고, 장군 밥은 엘리스가 더 많은 군인을 선택하는걸 피하고 싶어한다. 
만약 두 플레이어가 그들 목적에 맞는  최적의 값을 찾았을 때, 장군 엘리스는 성공할 수 있는가?


## Input
The first line of each case contains a positive integer N, the number of soldiers. N more lines follow; the i-th of these line contains two integers Ai and Di, indicating the attack and defense stats of the i-th soldier.    
첫번째 라인은 양수 N 으로 군인의 수이다.
아래의 N 줄은 다음과 같다.
i 번째 라인은 두개의 수 Ai, Di 로 이루어지는데 이는 i 번째 군인의 공격, 방어력이다.


## Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is YES or NO, indicating whether General Alice can guarantee that she selects more soldiers than General Bob, even if General Bob plays optimally to prevent this.     
각 테스트 케이스의 첫번째 줄은 Case #x: y, 로 x 는 테스트 케이스의 넘버이고 ( 1부터 시작 ) y 는 Yes or No 이다.
이는 장군 엘리스가 장군 밥보다 더 많은 군인을 선택했는지 아닌지이다. ( 장군 밥이 최적값으로 이를 막았다고 해도 )


## Limits
- 1 ≤ T ≤ 10;
- 1 ≤ Ak, Dk ≤ 10000.


### Small dataset
- 1 ≤ N ≤ 200.


### Large dataset
- 1 ≤ N ≤ 4000.


## Sample


### Input 
3     
3     
10 2  
1 10  
10 3  
3  
10 1  
10 10  
1 10  
3  
10 2  
1 10  
4 9  


### Output 
Case #1: NO  
Case #2: YES  
Case #3: YES  


