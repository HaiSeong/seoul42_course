# so_long

### 참고자료
[영어 서브젝트](https://cdn.intra.42.fr/pdf/pdf/35923/en.subject.pdf)<br>
[한글 서브젝트](./ko_sub.md)<br>
[so_long 가이드](https://techdebt.tistory.com/29)<br>
[mlx 윈도우 띄우기](https://velog.io/@jen133/miniLibX)<br>

<br>

## mlx 함수 정리

### mlx_init
- void * mlx_init(void)
- 나의 소프트웨어와 OS의 디스플레이를 연결해준다.
<br><br>

### mlx_new_window
- void * mlx_new_window(void mlx_ptr, int size_x, int size_y, char *title)
- 디스플레이에 새로운 윈도우를 띄우는 함수. 앞서 받아온 포인터와 가로 세로 크기, 그리고 창의 제목을 받아서 띄운다
<br><br>

### mlx_loop
- int mlx_loop(void *mlx_ptr)
- 디스플레이에 새로운 윈도우를 띄우는 함수. 앞서 받아온 포인터와 가로 세로 크기, 그리고 창의 제목을 받아서 띄운다.
<br><br>

### mlx_hook
> 후킹(영어: hooking)은 소프트웨어 공학 용어로, 운영 체제나 응용 소프트웨어 등의 각종 컴퓨터 프로그램에서 소프트웨어 구성 요소 간에 발생하는 함수 호출, 메시지, 이벤트 등을 중간에서 바꾸거나 가로채는 명령, 방법, 기술이나 행위를 말한다. 출처: [위키백과](https://ko.wikipedia.org/wiki/%ED%9B%84%ED%82%B9)
- 우리 프로젝트에서 후킹은 마우스 클릭또는 자판 입력을 감지하는것을 뜻한다.

