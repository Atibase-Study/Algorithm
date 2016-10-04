# Evaluation

## Problem
Given an unordered list of assignment statements, write a program to determine whether the assignment statements can be put in some order in which all variables can be evaluated.    
정렬되지 않은 할당문의 리스트가 있을 때, 모든 변수들이 평가받을 수 있는 할당문들의 순서를 찾아 결정하는 프로그램을 만들어라.


For our problem, an assignment statement will consist of an assignment variable, an assignment operator, and an expression, in that order.     
우리의 문제에서, 이 할당문은 할당 변수, 할당 연산자, 그리고 표현문 으로 이루어져 있다.


Statements will be evaluated one at a time, in the order you choose for them. A variable can be evaluated if and only if it has been the assignment variable of a previous assignment statement.       
이러한 Statemets 는 한번에 하나씩 평가되며, 당신은 그 순서를 선택해야 한다.? 변수들은 만약 이전 할당문에서 할당된 변수이면 평가받을 수 있다.


To simplify the problem, all the expressions are single function calls. Functions can take an arbitrary number of arguments, including zero; a function with zero arguments is always valid, and a function with variable arguments is valid as long as all of the variables are evaluatable.    
문제를 간단히 하기 위해서, 모든 expressions 는 싱글 함수 호출이다. 함수는 인자로 임의의 수를 취할 수 있으며, 아무런 인자도 없는 함수 역시 가능하다. 또한 이미 평가받은 변수를 인자로 가지는 함수 역시 유효하다.   


For example, for the following list of assignment statements:  
예를들어, 다음과 같은 할당문이 있다.


- a=f(b,c)
- b=g() 
- c=h()  

this is one order that makes every statement valid:  
이것은 모든 스테이트먼트를 유효하게 하는 순서이다.

- b=g()
- c=h()
- a=f(b,c)
This is because: (1) b and c can be evaluated because the expressions g() and h() don't depend on any variables; and (2)a can also be evaluated because expression a depends on b and c, which are evaluatable.  
왜냐하면   
	1. b 와 c 는 g() 와 h() 는 평가될 수 있는데 어떠한 변수에도 의존하지 않기 때문이다. 
	2. a 는 평가 가능한데 이는 a 가 의존하는 b 와 c 는 평가 가능하기 때문이다. 


However, the order  
그러나 다음과 같은 순서는    

b=g()    
a=f(b,c)    
c=h()    
would not be valid, because f(b, c) has variable c as an argument, but variable c has not been an assignment variable yet.     
유효하지 않다. 왜냐하면 f(b, c ) 는 b와 c 를 인자로 받고있는데 c 는 아직 할당되지 않았기 때문이다.    


Another example is: a=f(a). This list of statements can't be evaluated because the expression f(a) depends on the variable a itself, which makes it impossible to evaluate the statement.    
또다른 예제로는 : a = f(a) 이다. 이 할당문은 평가받을 수 없는데 이유는 자기 자신에게 의존하기 때문이다. 이는 불가능하다.


## Input
The first line of the input gives the number of test cases, T. T test cases follow. The first line of each test case contains an integer N: the number of assignment statements. Then, N lines follow. Each contains one assignment statement.   
첫번째 줄에는 테스트케이스 T 가 있다. T 케이스는 다음과 같다. 
각 테스트 케이스의 첫번째 줄은 정수 N 이다. N 은 할당문의 갯수이다. 그리고 다음 N 개의 줄은 각각 하나의 할당문이다.


Each assignment statement consists of three parts: the assignment variable, the assignment operator, and the expression, with no spaces in between.   



The assignment operator is always =. All expressions consist of a function name, then (, then zero or more comma-separated variable names, then ). All variables and function names consist of one or more lowercase English alphabet letters.   
할당문의 연산자는 항상 = 이다. 모든 표현식은 함수의 이름과 (, 0 개 또는 그 이상의 컴마로 이루어진 변수이름, 그리고 ) 로 이루어진다.  
모든 변수와 함수의 이름은 소문자 하나 또는 그 이상의 알파벳으로 이루어진다.  


No variable has the same name as a function.   
어떠한 변수도 함수와 같은 이름을 가지지 않는다.  


No variable will appear more than once as the assignment variable. However, variables may appear more than once in various functions (even within the same function), and functions may appear more than once.
어떠한 변수도 한 할당문에 한번 이상 나타날 수 없다. 그러나, 변수는 하나 이상의 다양한 함수에 나타날 수 있다. 그리고 그 함수도 한번 이상 나올 수 있다.  


## Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is GOOD if all variables are evaluatable or BAD otherwise.
각각의 테스트 케이스에서, 출력물은 Case #x, y, 를 포함하고 x 는 테스트 케이스 넘버 ( 1부터 시작 )와 y 는 평가 가능하면 GOOD 아니면 BAD 를 출력하라.


## Limits
- 1 ≤ T ≤ 20.
- All functions take between 0 and 10 arguments, inclusive. All variable names consist of between 1 and 20 lowercase English alphabet letters.
- 모든 함수는 0 에서 10 개의 인자를 가진다. 모든 변수이름은 1 부터 20 사이의 소문자 알파벳을 이름으로 가진다.


### Small dataset
- 1 ≤ N ≤ 100.  


### Large dataset
- 1 ≤ N ≤ 1000.  


## Sample 

### Input 
4      
3     
a=f(b,c)    
b=g()    
c=h()    
2  
a=f(b)  
b=f(a)  
2  
aaa=foo(x,y)  
bbb=bar(aaa,bbb)  
2  
x=f()  
y=g(x,x)  


### Output 
	Case #1: GOOD
	Case #2: BAD
	Case #3: BAD
	Case #4: GOOD

