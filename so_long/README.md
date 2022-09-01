# so_long

### 참고자료
[영어 서브젝트](https://cdn.intra.42.fr/pdf/pdf/35923/en.subject.pdf)<br>
[한글 서브젝트](./ko_sub.md)<br>
[so_long 가이드](https://techdebt.tistory.com/29)<br>
[mlx 윈도우 띄우기](https://velog.io/@jen133/miniLibX)<br>

<br>

## 파일 목록
| 파일 | 함수 | 목적 |
|:--:|:--:|:--:|
| [main.c](./README_main.md) |  | main 함수 |
| [so_long_util.c](./README_so_long_util.md) |  | util 함수 |
| [init_game.c](./README_init_game.md) |  | 게임 구조체를 초기화 한다. |
| [read_file.c](./README_read_file.md) |  | 파일을 읽어와 일차원 배열로 만든다. |
| [check.c](./README_check.md) |  | 읽어온 맵의 유효성을 검사한다. |
| [draw_map.c](./README_draw_map.md) |  | 맵을 화면에 출력한다. |

<br><br>

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
- 우리 프로젝트에서 후킹은 마우스 클릭 또는 자판 입력을 감지하는것을 뜻한다.
- KEY_PRESS (02) : 키를 누르는 입력
- X_EVENT_KEY_RELEASE (03) : 키를 눌렀다 때는 입력
<br><br>

### xpm file 사용
- 이유 : mlx 라이브러리에서 png 파일을 image로 변환하는 함수인 mlx_png_file_to_image 함수 자체의 구현에서 메모리 누수 및 여러 문제들이 발생해서 xpm file 변환 함수를 사용하는 것이 좋다.
<br><br>

### mlx_xpm_file_to_image
- void * mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)
- mlx포인터, 파일 주소, 가로 세로 크기를 가져와서 메모리에 올리고 해당 메모리의 주소를 반환한다
<br><br>

### mlx_put_image_to_window
- int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)
- 이미지를 받아서 띄울 포인터들을 인자로 받고 윈도우 안에서의 좌표를 지정해서 해당 윈도우에 띄워준다
<br><br>
