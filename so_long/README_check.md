
## check.c

<br>

### check_lines : 파일이 직사각형인지 검사한다.
- '\n'을 기준으로 split한다.
- 첫 줄의 길이가 맵의 넓이이고 반복문으로 가로길이가 모두 같은지 검사한다.
- 반복문을 나왔을때 i가 맵의 높이가 된다
<br><br>

### del_newline : 기존 map의 '\n'을 제거한다.
- 인덱스 변수 두개를 이용해서 개행이 아닌 문자만 복사한다.
- 개행이 연속으로 두번있으면 맵 오류다.
<br><br>

### check_wall : 가장자리가 모두 '1'인지 검사한다.
- map_width를 이용해서 좌표를 구한다.
<br><br>

### check_object : 맵의 각 원소를 검사한다.
- C, E, P의 갯수를 구한다.
- "0, 1, C, E, P" 가 아닌 문자가 있으면 오류
- 'C', 'E'는 한개이상, P는 한개여야한다.
<br><br>

### check : 맵을 검사한다.
- 위의 함수들을 모두 실행한다.
<br><br>

