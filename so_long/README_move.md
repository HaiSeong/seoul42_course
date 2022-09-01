
## move.c

<br>

### get_p_position : 맵을 읽어서 현제 P의 위치를 알아낸다.

<br><br>

## move 함수들
- if (game->map[next] == 'E' && game->c_cnt == 0) : 코인을 다먹고 출구로 가는 경우 -> 게임 종료
- if (game->map[next] == 'C') : 코인을 먹는 경우 -> 지금 위치를 0으로, 다음 위치를 P로 바꾼다. 코인 갯수를 하나 줄이고 음직임을 하나 늘린다.
- if (game->map[next] == '0') : 빈 공간으로 가는 경우 -> 지금 위치를 0으로, 다음 위치를 P로 바꾼다. 음직임을 하나 늘린다.

### move_w : 위로 이동하는 함수
- next = now - game->map_width
<br><br>

### move_s : 아래로 이동하는 함수
- next = now + game->map_width
<br><br>

### move_d : 오른쪽으로 이동하는 함수
- next = now + 1
<br><br>

### move_s : 왼쪽으로 이동하는 함수
- next = now - 1
<br><br>