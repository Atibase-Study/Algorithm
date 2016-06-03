## Problem

- https://code.google.com/codejam/contest/4314486/dashboard#s=p2

You are so excited about the 2016 Code Jam World Finals that you just moved to New York. You have brought along J different jackets (numbered 1 through J), P different pairs of pants (numbered 1 through P), and S different shirts (numbered 1 through S). You have at least as many shirts as pairs of pants, and at least as many pairs of pants as jackets. (J ≤ P ≤ S.)

Every day, you will pick one jacket, one pair of pants, and one shirt to wear as an outfit. You wash all of your garments every night so all of your garments are available to use each day.

In New York, the Fashion Police officers are always watching and keeping track of what everyone wears every day. If they find out that you have worn the exact same outfit twice, you will immediately be taken to the Fashion Jail on 5th Avenue for a mandatory makeover; you definitely want to avoid that! You will also immediately be taken to Fashion Jail if they find out that you have worn the same two-garment combination more than K times in total. A combination consists of a particular jacket worn with a particular pair of pants, a particular jacket worn with a particular shirt, or a particular pair of pants worn with a particular shirt. For example, in the set of outfits (jacket 1, pants 2, shirt 3) and (jacket 1, pants 1, shirt 3), the combination (jacket 1, shirt 3) appears twice, whereas the combination (pants 1, shirt 3) only appears once.

You will wear one outfit per day. Can you figure out the largest possible number of days you can avoid being taken to Fashion Jail and produce a list of outfits to use each day?

### Input

The first line of the input gives the number of test cases, T. T test cases follow; each consists of one line with four integers J, P, S, and K.

### Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is an integer: the maximum number of days you will be able to avoid being taken to Fashion Jail. Then output y more lines, each of which consists of three integers: the numbers of the jacket, pants, and shirt (in that order) for one day's outfit. The list of outfits can be in any order, but the outfits must not cause you to go to Fashion Jail as described in the statement above.

If multiple answers are possible, you may output any of them.

### Limits

    1 ≤ T ≤ 100.
    1 ≤ J ≤ P ≤ S.
    1 ≤ K ≤ 10.
    Small dataset

    S ≤ 3.
    Large dataset

    S ≤ 10.

## Sample


### Input 

    4
    1 1 1 10
    1 2 3 2
    1 1 3 2
    1 2 3 1

### Output 

    Case #1: 1
    1 1 1
    Case #2: 4
    1 1 2
    1 2 3
    1 2 1
    1 1 1
    Case #3: 2
    1 1 2
    1 1 1
    Case #4: 2
    1 1 3
    1 2 1

### 예제 설명

The sample output displays one set of answers to the sample cases. Other answers may be possible.

In Case #1, even though the Fashion Police officers have set a lenient K value of 10, there is only one possible outfit that you can form, so you can only avoid Fashion Jail for one day.

In Case #2, adding any other outfit would cause you to go to Fashion Jail:

Adding 1 1 3 would use the combination (jacket 1, pants 1) more than 2 times.  
Adding 1 2 2 would use the combination (jacket 1, pants 2) more than 2 times.  
In this case, any set of 5 outfits would include at least one fashion violation.

Note that the numbers of the jacket, pants, and shirt within an individual outfit do not have to be in nondecreasing order in the same way that J, P, and S do.

In Case #3, you have only one jacket + pants combination which you must keep reusing, so no matter which shirts you wear, you cannot form more than K = 2 different outfits.

In Case #4, another possible maximally large set of outfits is:

1 2 2  
1 1 1  

### 한글 해석

- 답안 제출용 링크 https://code.google.com/codejam/contest/4314486/dashboard#s=p2

코드잼 대회 때문에 뉴욕에 갔더니.. 거기엔 패션 경찰이 있어서 똑같은 옷을 입으면 성형수술 센터로 보내버린다. --;  
옷은 세가지 재킷, 바지, 셔츠 이다. 재킷 <= 바지 <= 셔츠 의 값을 가진다.  
세 옷을 같이 입으면 안되고,  재킷과 셔츠, 셔츠와 바지, 바지와 재킷은 각각 지정한 값 K만큼만 같이 입을 수 있다.  

예를 들어 1, 2, 3 이라고 한다면, 재킷은 1벌, 바지는 2벌, 셔츠는 3벌이고,

1 1 1  
1 1 2  
1 1 3  
1 2 1  
1 2 2  
1 2 3  
총 6가지의 조합이 가능하지만, 뒤에 K 란 값으로 두 종료 옷에 대한 반복 정도를 제한한다.  
예를 들이 K가 2 이면,  같은 재킷과 바지는 두번 까지만 입을 수 있고 세번은 못입니다.  
위의 예에서 1,1 과 1, 2 가 각각 3번씩 나왔는데 두번까지만 허용된다.

이렇게 몇가지의 옷을 입을 수 있는지 최대값과  
그 예를 나열하라..  
예는 여러가지가 있다면 한가지만 하면 된다.  


입력값 설명

첫번째 입력값은 테스트 케이스의 갯수 T이다.  
두번쨰 입력값은 J, P, S, K 중 J, P, S는 각각 재킷, 팬츠, 셔츠, 그리고 K 이다.  
J <= P <= S 이고, J, P, S는 모두 한번의 조합만 나올 수 있다.  
즉 완전히 같은 옷을 두번 입으면 안된다.  
셋 중 둘, 재킷과 팬츠, 재킷과 셔츠, 셔츠와 팬츠 같이, 3종류 옷 중 두 종류 옷은 K번 허용된다.  

예) 1,1,1 이 두번 나오면 안된다.  
1 2 3 2 일 경우  
1 2 1  
1 2 2  
1 2 3 같이 J와 P가 3번 연속으로 나오면 안된다.  

    Case #2: 4
    1 1 2
    1 2 3
    1 2 1
    1 1 1
    
모든 답은 Case #x: 으로 시작하고, x는 입력값 번호로 1부터 순서대로 증가한다.  
먼저 최대 가짓수가 나오고 그 뒤에 각각을 출력 한다.  
순서는 상관없다. 답이 여러가지이면 한가지만 제출 하면 된다.  
