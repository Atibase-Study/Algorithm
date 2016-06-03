## Problem

- https://code.google.com/codejam/contest/4314486/dashboard#s=p0

A small fire started in the senate room, and it needs to be evacuated!

There are some senators in the senate room, each of whom belongs to of one of N political parties. Those parties are named after the first N (uppercase) letters of the English alphabet.

The emergency door is wide enough for up to two senators, so in each step of the evacuation, you may choose to remove either one or two senators from the room.

The senate rules indicate the senators in the room may vote on any bill at any time, even in the middle of an evacuation! So, the senators must be evacuated in a way that ensures that no party ever has an absolute majority. That is, it can never be the case after any evacuation step that more than half of the senators in the senate room belong to the same party.

Can you construct an evacuation plan? The senate is counting on you!

### Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of two lines. The first line contains a single integer N, the number of parties. The second line contains N integers, P1, P2, ..., PN, where Pi represents the number of senators of the party named after the i-th letter of the alphabet.

### Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the evacuation plan. The plan must be a space-separated list of instructions, in the order in which they are to be carried out, where each instruction is either one or two characters, representing the parties of the senators to evacuate in each step.

It is guaranteed that at least one valid evacuation plan will exist. If multiple evacuation plans are valid, you may output any of them.

### Limits

    1 ≤ T ≤ 50.
    No party will have an absolute majority before the start of the evacuation.
    1 ≤ Pi ≤ 1000, for all i.
    Small dataset

    2 ≤ N ≤ 3.
    sum of all Pi ≤ 9.
    Large dataset

    2 ≤ N ≤ 26.
    sum of all Pi ≤ 1000.
    
### Sample


### Input 

    4
    2
    2 2
    3
    3 2 2
    3
    1 1 2
    3
    2 3 1

### Output 

    Case #1: AB BA
    Case #2: AA BC C BA
    Case #3: C C AB
    Case #4: BA BB CA

### 예제 설명
The sample output displays one set of answers to the sample cases. Other answers may be possible.

In Case #1, there are two senators from each of the parties A and B. If we remove one from each party every time, the perfect balance is maintained until evacuation is complete.

Case #2 proceeds as follows:

Initially in the room: 3 A, 2 B, 2 C.  
Evacuate AA. Still in the room: 1 A, 2 B, 2 C.  
Evacuate BC. Still in the room: 1 A, 1 B, 1 C.  
Evacuate C. Still in the room: 1 A, 1 B.  
Evacuate AB. Evacuation complete!  
Note that it would not be valid to begin the evacuation with BC, which would leave 3 A, 1 B, and 1 C in the room; party A would have an absolute majority (3 out of 5 = 60%).  

For Case #3, note that CC AB would also be a valid answer, and C C AB is also valid even though it requires three evacuation steps instead of two.


## 한글 해석
국회의원실에 불이 나서 대피 해야 한다. 대피는 2명 씩 할 수 있다.  
문제는 역시 이들이 국회의원이라, 특정 정당 인원이 국회의원실에 있는 국회의원 수의 과반수가 되면, 불이 나 있는 상황이라 하더라도 법을 통과시켜 버린다.  
함부로 법 처리를 하지 못하도록, 특정 정당의 의원이 과반수가 되지 않는 선으로 모두 무사히 대피시켜라  

입력  
처음에는 입력값의 수 T가 온다.  
그 다음에는 정당의 수N이 오고  
그 뒤에 각 정당의 의원 수가 온다.  
각 정당은 알파벳 순서대로 A, B, C 라 명하며 최대 Z까지 올 수 있다.    


    4  
    2  
    2 2  
    3  
    3 2 2  
    3  
    1 1 2  
    3  
    2 3 1  
    
위의 예에는 입력값의 수가 4, 그 뒤에 첫번째 입력으로 정당이 2, 첫번째 A정당에 2명, B정당에 2명이다.  
그 뒤엔 정당이 3, A정당에 3명, B정당에 2명, C정당에 2명이다.  
최대 입력값은 위의 limit을 참고하라,  

출력값은 

    Case #1: AB BA
    Case #2: AA BC C BA
    Case #3: C C AB
    Case #4: BA BB CA

먼저 Case #x: 로 X는 입력 예제에 대한 순서로 1부터 단조 증가한다.  
그 뒤에 그 방을 나가는 각 정당 의원을 나열한다.(최대 2명, 순서 상관 없음)  
결과값에 대한 것은 다음에서 확인 

- https://code.google.com/codejam/contest/4314486/dashboard#s=p0
