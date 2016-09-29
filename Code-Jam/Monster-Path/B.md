# Safe Squares

## Problem
Codejamon trainers are actively looking for monsters, but if you are not a trainer, these monsters could be really dangerous for you. You might want to find safe places that do not have any monsters!    
Codejamon 트레이너는 몬스터를 매우 활발하게 찾아다닌다. 하지만 만약 당신이 트레이너가 아니면, 
 이러한 몬스터들은 실제로 너에게 매우 위험한 존재이다.
 너는 아마도 어떠한 몬스터가 없는 안전한 공간을 원할것이다!


Consider our world as a grid, and some of the cells have been occupied by monsters. We define a safe square as a grid-aligned D × D square of grid cells (with D ≥ 1) that does not contain any monsters. Your task is to find out how many safe squares (of any size) we have in the entire world.    
우리의 세상이 격자라고 가정할 때, 어떤 셀들은 몬스터들에 의해 점유된 셀이다.
우리는 몬스터가 없는 셀들로 이루어진 D x D 의 격자 공간을 안전광장 이라고 정의한다. ( D >= 1 )
당신의 임무는 전체 세계에서 이러한 안전 광장을 찾는 것이다.


## Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line with three integers, R, C, and K. The grid has R rows and C columns, and contains K monsters.    
첫번째 줄은 테스트 케이스 수 T 이다.
그다음 줄은 3 개의 정수 R, C, K 로 이루어져 있다.
R 은 행 C 는 열, K 는 포함된 몬스터의 수이다.


K more lines follow; each contains two integers Ri and Ci, indicating the row and column that the i-th monster is in. (Rows are numbered from top to bottom, starting from 0; columns are numbered from left to right, starting from 0.)     
그다음 K 개의 줄은 다음과 같다; 각 줄은 두개의 정수 Ri 와 Ci 로 이루어지는데
( Ri, Ci ) 공간에 i 번째 몬스터가 있다는 것이다.
행은 위부터 아래로, 열은 왼쪽부터 오른쪽으로 0 부터 증가한다.



## Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and 
y is the the total number of safe zones for this test case.    
y 는 각 테스트 케이스에서 안전광장의 수이다.



## Limits
- 1 ≤ T ≤ 20.
- (Ri, Ci) != (Rj, Cj) for i != j. (No two monsters are in the same grid cell.)
- 0 ≤ Ri < R, i from 1 to K
- 0 ≤ Ci < C, i from 1 to K


### Small dataset
- 1 ≤ R ≤ 10.
- 1 ≤ C ≤ 10.
- 0 ≤ K ≤ 10.


### Large dataset
- 1 ≤ R ≤ 3000.
- 1 ≤ C ≤ 3000.
- 0 ≤ K ≤ 3000.


## Sample

### Input 
2  
3 3 1  
2 1  
4 11 12  
0 1  
0 3  
0 4  
0 10  
1 0  
1 9   
2 0  
2 4  
2 9  
2 10  
3 4  
3 10  


### Output 
Case #1: 10  
Case #2: 51  


The grid of sample case #1 is:
     
0 0 0  
0 0 0  
0 1 0  
   
Here, 0 represents a cell with no monster, and 1 represents a cell with a monster. It has 10 safe squares: 8 1x1 and 2 2x2.

The grid of sample case #2 is:
   
0 1 0 1 1 0 0 0 0 0 1  
1 0 0 0 0 0 0 0 0 1 0  
1 0 0 0 1 0 0 0 0 1 1  
0 0 0 0 1 0 0 0 0 0 1  

Note that sample case #2 will only appear in the Large dataset. It has 51 safe squares: 32 1x1, 13 2x2, 5 3x3, and 1 4x4.
