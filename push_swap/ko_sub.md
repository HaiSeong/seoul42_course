## Push_swap

Because Swap_push isn’t as natural

Swap_push는 자연스럽지 못하니...

Staff pedago pedago@42.fr

스태프 pedago pedago@42.fr

Summary: This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

요약: 이 프로젝트를 통해 여러분은 주어진 어떠한 스택에 대하여 제한된 명령어 집합을 가능한 한 적게 사용하여 정렬할 수 있다. 성공적으로 프로젝트를 끝내기 위해서는 다양한 유형의 알고리즘을 조작하고 최적화 된 데이터 정렬에 가장 적합한 솔루션을 선택해야 한다.

## Contents

| Chapter | Contents | Page |
|:---:|:---|:---:|
| I | [__Foreword__](#Foreword) | 2 |
| II | [__Introduction__](#Introduction) | 4 |
| III | [__Goals__](#Goals) | 5 |
| IV | [__General Instructions__](#General-Instructions) | 6 |
| V | [__Mandatory part__](#Mandatory-part) | 7 |
| V.1 | [__Game rules__](#V1-Game-rules) | 7 |
| V.2 | [__Example__](#V2-Example) | 9 |
| V.3 | [__The "push_swap" program__](#V3-The-push_swap-program) | 10 |
| VI | [__Bonus part__](#Bonus-part) | 11 |
| VI.1 | [__The "checker" program__](#VI1-The-checker-program) | 12 |
| VII | [__Submission and peer correction__](#Submission-and-correction) | 13 |

## Foreword

## 머리말

- `C`

  ```c
  #include <stdio.h>
  
  int main(void)
  {
  		printf("hello, world\n");
  		return 0;
  }
  ```

- `ASM`

  ```as
  cseg segment
  assume cs:cseg, ds:cseg
  org 100h
  main proc
  jmp debut
  mess db 'Hello world!$'
  debut:
  mov dx, offset mess
  mov ah, 9
  int 21h
  ret
  main endp
  cseg ends
  end main
  ```

- `LOLCODE`

  ```lolcode
  HAI
  CAN HAS STDIO?
  VISIBLE "HELLO WORLD!"
  KTHXBYE
  ```

- `PHP`

  ```php
  <?php
    echo "Hello world!";
  ?>
  ```

- `BrainFuck`

  ```BrainFuck
  ++++++++++[>+++++++>++++++++++>+++>+<<<<-]
  >++.>+.+++++++..+++.>++.
  <<+++++++++++++++.>.+++.------.--------.>+.>.
  ```

- `C#`

  ```c#
  using System;
  
  public class HelloWorld {
  		public static void Main () {
  				Console.WriteLine("Hello world!");
  		}
  }
  ```

- `HTML5`

  ```html
  <!DOCTYPE html>
  <html>
  		<head>
  			<meta charset="utf-8">
  			<title>Hello world !</title>
  		</head>
  		<body>
  			<p>Hello World !</p>
  		</body>
  </html>
  ```

- `YASL`

  ```yasl
  "Hello world!"
  print
  ```

- `OCaml`

  ```ocaml
  let main () =
  	print_endline "Hello world !"
  
  let _ = main ()
  ```

## Introduction

## 서론

The `Push_swap` project is a very simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

`Push_swap` 프로젝트는 매우 간단하고 효과적인 알고리즘인 정렬에 관한 프로젝트이다. 정수값들의 집합, 2개의 스택 그리고 두 스택을 조작하기 위한 명령어 집합이 주어진다.

Your goal ? Write a program in C called `push_swap` which calculates and displays on the standard output the smallest program using `Push_swap` instruction language that sorts the integer arguments received.

목표는? `push_swap` 이라는 프로그램을 C언어로 작성하는 것이다. 입력 받은 정수 인자들을 정렬하는 `push_swap` 명령어를 사용하여 가장 작은 프로그램을 계산하고 표준 출력에 출력한다.

Easy?

쉬워보이죠?

We’ll see about that...

일단 봅시다...

## Goals

## 목표

To write a sorting algorithm is always a very important step in a coder’s life, because it is often the first encounter with the concept of [complexity](https://en.wikipedia.org/wiki/Analysis_of_algorithms).

정렬 알고리즘을 작성하는 것은 코더의 인생에서 언제나 가장 중요한의미를 가진다. 이는 여기에서 흔히 [**복잡도**](https://en.wikipedia.org/wiki/Analysis_of_algorithms)라는 개념과 처음 마주하기 때문이다.

Sorting algorithms, and their complexities are part of the classic questions discussed during job interviews. It’s probably a good time to look at these concepts because you’ll have to face them at one point.

정렬 알고리즘과 그 복잡도는 취업 면접에서 전형적인 질문 중 하나이다. 언젠간 마주칠 날이 있을 것이기 때문에 이번에 이 개념을 보는 것도 좋을 것이다.

The learning objectives of this project are rigor, use of C and use of basic algorithms. Especially looking at the complexity of these basic algorithms.

이 프로젝트의 목적은 정밀하게 알고리즘을 생각하고, C언어를 사용하여 이를 활용하는 것이다. 특별히 그 기본 알고리즘의 복잡도에 대해서 살펴본다.

Sorting values is simple. To sort them the fastest way possible is less simple, especially because from one integers configuration to another, the most efficient sorting algorithm can differ.

값들을 정렬하는 것은 간단하다. 가능한 가장 빠른 방법으로 정렬하는 것은 덜 간단하다. 특히 초기값들의 순서에 따라 가장 효율적인 알고리즘이 다를 수도 있기 때문이다.

## General Instructions

## 공통 지침

* • This project will only be corrected by actual human beings. You are therefore free to organize and name your files as you wish, although you need to respect some requirements listed below.
* 이 프로젝트는 실제 사람에게만 평가될 것이다. 그러므로 파일 이름을 원하는대로 설정해도 된다. 그렇다하여도 아래에 있는 요구사항들을 준수하여야 한다.
* The executable file must be named `push_swap`.
* 실행 파일의 이름은 `push_swap`으로 지어야 한다.
* You must submit a `Makefile`. That `Makefile` needs to compile the project and must contain the usual rules. It can only recompile the program if necessary.
* `Makefile`을 제출해야 한다. `Makefile`은 반드시 프로젝트를 컴파일해야 하고 기본적인 rule들을 포함해야 한다. 프로그램이 필요시에만 재컴파일 돼야 한다.
* If you are clever, you will use your library for this project, submit also your folder `libft` including its own `Makefile` at the root of your repository. Your `Makefile` will have to compile the library, and then compile your project.
* 여러분이 재치있게 해냈다면 이 프로젝트에 라이브러리를 포함할 것이다. `libft` 폴더와 그 안에 자체 `Makefile`을 넣어서 제출해라. `Makefile`은 라이브러리와 프로젝트 모두 컴파일해야 한다.
* Global variables are forbidden
* 전역 변수의 사용은 금지되어 있다.
* Your project must be written in `C` in accordance with the Norm
* 프로젝트는 Norm에 기반한 C로 작성돼야 한다.
* You have to handle errors in a sensitive manner. In no way can your program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).
* 여러분은 세심하게 에러를 처리해야 하며, 작성된 프로그램은 예상치 못한 방식으로 종료되면 안된다. (Segmentation fault, bus error, double free 등)
* Neither program can have any `memory leaks`.
* 모든 프로그램은 메모리 누수가 나서는 안 된다.
* Within your mandatory part you are allowed to use the following functions:
* 필수 파트에서는 다음 함수들의 사용이 허용된다.
  - `write`
  - `read`
  - `malloc`
  - `free`
  - `exit`
- You can ask questions on the forum & Slack...
* 포럼과 슬랙에 질문을 할 수 있다.

## Mandatory Part

## 필수 파트

### V.1. Game rules

### V.1. 게임 규칙

- The game is composed of 2 [stacks](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) named `a` and `b`.

- 이 게임은 `a`와 `b`라는 이름의 두 개의 스택으로 이루어져 있다.

- To start with:

- 게임은 다음과 같은 상태에서 시작한다.

  - `a` contains a random number of either positive or negative numbers without any duplicates.
  - `a`는 서로 중복되지 않는 음수 혹은 양수인 난수들을 포함한다.
  - `b` is empty
  - `b`는 비어있다.

- The goal is to sort in ascending order numbers into stack `a`.

- 목표는 스택 `a`에 오름차순으로 수를 정렬하는 것이다.

- To do this you have the following operations at your disposal:

- 이를 위해 다음 연산들을 수행할 수 있다.

  `sa` : `swap a` - swap the first 2 elements at the top of stack `a`. Do nothing if there is only one or no elements).

  `sa` : `swap a` - 스택 `a`의 가장 위에 있는 두 원소(혹은 첫 번쨰 원소와 두 번째 원소)의 위치를 서로 바꾼다.

  `sb` : `swap b` - swap the first 2 elements at the top of stack `b`. Do nothing if there is only one or no elements).

  `sb` : `swap b` - 스택 `b`의 가장 위에 있는 두 원소(혹은 첫 번쨰 원소와 두 번째 원소)의 위치를 서로 바꾼다.

  `ss` : `sa` and `sb` at the same time.

  `ss` : `sa`와 `sb`를 동시에 실행한다.

  `pa` : `push a` - take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty.

  `pa` : `push a` - 스택 `b`에서 가장 위(탑)에 있는 원소를 가져와서, 스택 `a`의 맨 위(탑)에 넣는다. 스택 `b`가 비어 있으면 아무 것도 하지 않는다.

  `pb` : `push b` - take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty.
  
  `pb` : `push b` - 스택 `a`에서 가장 위(탑)에 있는 원소를 가져와서, 스택 `b`의 맨 위(탑)에 넣는다. 스택 `a`가 비어있으면 아무 것도 하지 않는다.
  
  `ra` : `rotate a` - shift up all elements of stack `a` by 1. The first element becomes the last one.
  
  `ra` : `rotate a` - 스택 `a`의 모든 원소들을 위로 1 인덱스 만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
  
  `rb` : `rotate b` - shift up all elements of stack `b` by 1. The first element becomes the last one.
  
  `rb` : `rotate b` - 스택 `b`의 모든 원소들을 위로 1 인덱스 만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
  
  `rr` : `ra` and `rb` at the same time.
  
  `rr` : `ra`와 `rb`를 동시에 실행한다.
  
  `rra` : `reverse rotate a` - shift down all elements of stack `a` by 1. The last element becomes the first one.
  
  `rra` : `reverse rotate a` - 스택 `a`의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
  
  `rrb` : `reverse rotate b` - shift down all elements of stack `b` by 1. The last element becomes the first one.
  
  `rrb` : `reverse rotate b` - 스택 `b`의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
  
  `rrr` : `rra` and `rrb` at the same time.
  
  `rrr` : `rra`와 `rrb`를 동시에 실행한다.

### V.2. Example

### V.2. 예시

To illustrate the effect of some of these instructions, let’s sort a random list of integers. In this example, we’ll consider that both stack are growing from the right.

몇몇 명령어의 동작을 그려보기 위해 랜덤한 정수들의 리스트를 정렬해보자. 이 예시에서는 두 스택 모두 오른쪽에서부터 자라난다고 간주한다.

```
-------------------------------------------------------------------------------
Init a and b:
2
1
3
6
5
8
_ _
a b
-------------------------------------------------------------------------------
Exec sa:
1
2
3
6
5
8
_ _
a b
-------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
-------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
-------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
-------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
-------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
-------------------------------------------------------------------------------
```

This example sort integers from a in 12 instructions. Can you do better ?

이 예시는 스택 `a`에 있는 정수들을 12번의 명령어들을 통해 정렬한 것이다. 더 잘할 수 있겠는가?

### V.3. The "push_swap" program

### V.3. "push_swap" 프로그램

- You have to write a program named `push_swap` which will receive as an argument the stack `a` formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
- `push_swap`이라는 이름의 프로그램을 작성해야 한다. 이 프로그램은 스택 `a`에 들어갈 값들을 정수 리스트의 형태로 포맷팅하여 인자로 받는다. 첫 번째 인자는 스택의 탑이 된다(순서에 유의해라).
- The program must display the smallest list of instructions possible to sort the stack `a`, the smallest number being at the top.
- 프로그램은 반드시 스택 `a`를 정렬하는데 가능한 가장 작은 개수의 명령어 리스트를 출력해야 한다.
- Instructions must be separaed by a `’\n’` and nothing else.
- 명령어들은 `'\n'`으로만  구분되어야 한다.
- The goal is to sort the stack with the minimum possible number of operations. During defence we’ll compare the number of instructions your program found with a maximum number of operation tolerated. If your program either displays a list too big or if the list isn’t sorted properly, you’ll get no points
- 목표는 가능한 적은 개수의 명령어 집합으로 스택을 정렬하는 것이다. 평가 도중에는 프로그램에서 도출한 명령어의 수와 허용된 최대 작업수를 비교한다. 프로그램에 너무 큰 리스트가 표시되거나 목록이 제대로 정렬되지 않은 경우 점수를 얻지 못한다.
- In case of error, you must display `Error` followed by a `’\n’` on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.
- 에러의 경우에는, `Error`와 줄바꿈을 표준 에러에 출력해야 한다. 에러는 다음 예시들을 포함한다: 일부 인자가 정수가 아니거나, 정수 범위를 초과하거나, 중복이 있는 경우이다.

```
$> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$> ./push_swap 0 one 2 3
Error
$>
```

During the defence we’ll provide a binnary to properly check your program. It will work as follows:
평가 시 우리가 제공한 바이너리를 사용하여 여러분이 작성한 프로그램을 아래와 같이 사용할 것이다.

```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$>
```

If your program `checker_OS` displays `KO`, it means that your `push_swap` came up with a list of instructions that doesn’t sort the list. The `checker_OS` program is available in the resources of the project on the intranet. You can find in the bonus section of this document a description of how it works.

`checker_OS` 프로그램이 `KO`를 출력하면, `push_swap`의 명령어 리스트가 정수 리스트를 정렬하지 못했음을 의미한다. `checker_OS` 프로그램은 인트라넷 프로젝트에 있다. 이 문서의 보너스 파트에서 동작 방식에 대한 설명을 찾을 수 있다.

## Bonus Part

## 보너스 파트

We will look at your bonus part if and only if your mandatory part is EXCELLENT. This means that your must complete the mandatory part, beginning to end, and your error management needs to be flawless, even in cases of twisted or bad usage. If that’s not the case, your bonuses will be totally IGNORED.

보너스 파트는 필수 파트가 **완벽해야만** 평가될 것이다. 이 말은 필수 파트가 처음부터 끝까지 완벽하고, 잘못된 사용과 이상한 사용에도 에러 관리에 문제가 없는 것을 의미한다. 그런 경우가 아니라면 보너스는 **완벽히 무시될 것이다.**

How interesting could it be to code yourself your own checker? Vvvvvvery interesting!!

자신의 checker를 코딩하는 것이 얼마나 흥미로울까? 매~우 흥미로울 것이다!

### VI.1. The "checker" program

### VI.1. "checker" 프로그램

- Write a program named `checker`, which will get as an argument the stack `a` formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given `checker` stops and displays nothing
- `checker`라는 이름의 프로그램을 작성해야 한다. 이 프로그램은 정수의 리스트 형태로된 스택 `a`를 인자로 받을 것이다. 첫 번째 인자가 스택의 탑이 될 것이다(순서에 유의해라). 인자가 주어지지 않는다면 `checker` 프로그램은 종료되고 화면에 아무 것도 출력하지 않는다.
- `Checker` will then wait and read instructions on the standard input, each instruction will be followed by `’\n’`. Once all the instructions have been read, `checker` will execute them on the stack received as an argument.
- `checker`는 그 뒤에 대기하고 명령어들을 표준입력으로 읽는다. 각각의 명령어들은 `'\n'` 뒤에 나올 것이다. 명령어를 읽으면 `checker`는 인자로 받은 스택에 실행할 것이다.
- If after executing those instructions, stack `a` is actually sorted and `b` is empty, then checker must display `"OK"` followed by a `’\n’` on the standard output. In every other case, checker must display `"KO"` followed by a `’\n’` on the standard output.
- 명령어들을 실행하고 나서 스택 `a`가 정렬 되었고, 스택 `b`는 비어있는 상태이면 `checker`는 `"OK"`와 줄바꿈을 표준 출력에 출력한다. 모든 다른 케이스에 `checker`는 반드시 `"KO"`와 줄바꿈을 표준 출력에 출력한다.
- In case of error, you must display `Error` followed by a `’\n’` on the **standard error**. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction don’t exist and/or is incorrectly formatted.
- 에러가 난 경우에는, `Error`와 줄바꿈을 **표준에러**에 출력해야 한다. 에러는 다음과 같은 예시들을 포함한다: 몇몇 인자가 정수가 아님, 일부 인자가 정수보다 큼, 입력에 중복이 있음, 명령어가 존재하지 않거나 / 제대로 포맷되어 있지 않음.

> :information_source: Thanks to the `checker` program, you will be able to check if the list of instructions you’ll generate with the program `push_swap` is actually sorting the stack properly.

> :information_source: `checker` 프로그램 덕분에 `push_swap` 프로그램으로 생성할 명령어 목록이 실제로 스택을 올바르게 정렬하고 있는지 확인할 수 있다.

```
$> ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$> ./checker 3 2 1 0
sa
rra
pb
KO
$> ./checker 3 2 one 0
Error
$>
```

## Submission and peer correction

## 제출과 동료 평가

Submit your work on your `GiT` repository as usual. Only the work on your repository will be graded.

평소와 같이 git repo에 작업물을 제출한다. repo 안에 있는 작업물만이 채점될 것이다.

Good luck to all!

모두 행운을 빈다.
