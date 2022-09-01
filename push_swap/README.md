### 참고 자료
[한글 서브젝트](./ko_sub.md)<br>
[영어 서브젝트](https://cdn.intra.42.fr/pdf/pdf/49387/en.subject.pdf)<br>
[그리디 알고리즘 설명](https://techdebt.tistory.com/27) (케이크)
[소스코드](https://github.com/JeonYoungHo-youjeon/push_swap/blob/master/push_swap.h)<br>
[libft사용하기(cc -L -l](https://velog.io/@hidaehyunlee/외부-라이브러리-GCC로-컴파일-하기)<br>
[libft사용하기(make -C 옵션)](https://wiki.kldp.org/KoreanDoc/html/GNU-Make/GNU-Make-5.html)<br>
[tester](https://github.com/LeoFu9487/push_swap_tester)

<br>

### 방법 설명

<br>

- 처음 상태 : 무작위 순서의 정수 배열이 스택 a에 저장되어있다.

<img src="./img/0.png">

<br>

- copy 스택 생성 : a스택을 복사한 copy 스택을 만든다. copy스택을 버블정렬으로 정렬하고 피벗 2개를 찾는다.

<img src="./img/1.png">

<br>

- 나누기 : 피벗을 기준으로 3개의 그룹으로 나눈다.

<img src="./img/2.png">

<br>

- 3개 정렬 : 3개를 제외하고 모두 b로 넘겨서 나머지 3원소를 정렬한다.

<img src="./img/3.png">

<br>

- 그리디 알고리즘 : 반복문을 이용해서 b가 빌때까지 그리디 알고리즘을 사용해 b의 원소를 a로 옮긴다.

<img src="./img/4.png">
<img src="./img/5.png">
<img src="./img/6.png">

<br>

- 정리 : ra 또는 rra를 사용해서 a를 정리해 마무리 한다.

<img src="./img/7.png">

<br>

### 파일 목록

| file name | functions | explanation |
|:--:|:--:|:--:|
| [ft_doubly_circular_list.c](./README_dc.md) | ft_dc_lstnew<br>ft_dc_lstadd_front<br>ft_dc_lstdel_front<br>ft_dc_lstsize<br>ft_dc_lstclear | 이중 연결 리스트 자료형을 사용하기위한 함수들 |
| [swap.c<br>push.c<br>rotate.c<br>reverse_rotate.c](./README_stack.md) | sa, sb, ss,<br>pa, pb,<br> ra, rb, rr,<br>rra, rrb, rrr<br>  | [규칙 보기](https://github.com/HaiSeong/seoul42_course/blob/main/push_swap/ko_sub.md#v1-게임-규칙)|
| [push_swap.c](./README_push_swap.md) | ft_free_strs,<br>make_a,<br>main | main함수가 있는 파일 |
| [push_swap_util.c<br>libft](./README_push_swap_util.md) | ft_atolli,<br>ft_split_isspace,<br>ft_isspace | util 함수들 |
| ft_error.c | ft_error,<br>ft_error_exit,<br>ft_error_free_a_exit,<br>ft_error_free_a_copy_exit | 에러처리 함수 |
| [sorting_before.c](./README_sort_before.md) | copy_a,<br>bubble_sort,<br>check,<br>get_small_pivot,<br>get_big_pivot | 정렬 전 필요한 함수들 |
| [sorting.c](./README_sort.md) | sort2,<br>sort3,<br>move_all_b,<br>organize_stack | 정렬 관련 함수들 |
| [calculate_cost1.c<br>calculate_cost2.c](./README_cal_cost.md) | get_ra_cost,<br>set_cost_info_a,<br>set_cost_info_b,<br>cal_sum_cost1,<br>cal_sum_cost2,<br>get_best_cost | b에서 a로 넘기는 최저 비용고 정보를 구하는 함수 |
| [rotate_best_cost.c](./README_rotate_best.md) | rotate_best_cost,<br>rotate1,<br>rotate2,<br>rotate3,<br>rotate4<br> | 최적의 상태로 돌리는 함수 |
