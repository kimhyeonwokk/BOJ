import sys
from collections import deque
import copy
# input 처리
sys.stdin = open("input.txt","rt")
# 물고기 수 M, 상어 마법 연습 S
M, S = map(int,input().split())
# 초기 입력 fish_pos
fish_pos = deque()
for _ in range(M):
    fish_pos.append(list(map(int,input().split())))
# 상어 위치
sx, sy = map(int,input().split())

# dx, dy
dx = [0, 0, -1,-1,-1, 0, 1, 1, 1]
dy = [0,-1, -1, 0, 1, 1, 1, 0,-1]
fish_map = [[[] for i in range(5)]for j in range(5)]
smell_map = [[0 for i in range(5)]for j in range(5)]
def check_range(new_x, new_y):
    if new_x >= 1 and new_x <= 4 and new_y >= 1 and new_y <= 4:
        return True
    else:
        return False

def rotete_direction(x,y,dire):
    first = dire
    while check_range(x+dx[dire], y + dy[dire]) == False or (sx == x + dx[dire] and sy == y + dy[dire]) or smell_map[x+dx[dire]][y+dy[dire]] < 0:
        dire -= 1
        if dire == 0:
            dire = 8
        if first == dire:
            return x, y , first
    x = x + dx[dire]
    y = y + dy[dire]
    return x, y, dire

def print_map(map_):
    for i in map_[1:5]:
        print(i[1:5])
    print("_"*20)

def move_fish():
    global  fish_map
    # print(fish_pos)
    fish_original = fish_map
    fish_map_after = [[[] for i in range(5)] for j in range(5)]
    for i in range(1,5):
        for j in range(1,5):
            arr = fish_map[i][j]
            for value in arr:
                x,y,dire = value[0] , value[1],value[2]
                x,y,dire = rotete_direction(x,y,dire)
                fish_map_after[x][y].append([x,y,dire])
    fish_map = fish_map_after
    return fish_original, fish_map

def move_shark(fish_map,fish_original):
    # 상1, 좌2, 하3, 우4
    global fish_pos
    global sx,sy
    shark_move = deque()
    dx_shark = [0,-1,0,1,0]
    dy_shark = [0,0,-1,0,1]
    x, y = [0] *3, [0] * 3
    for i in range(1,5):
        x[0] = sx + dx_shark[i]
        y[0] = sy + dy_shark[i]
        if check_range(x[0],y[0]) == False:
            continue
        for j in range(1,5):
            x[1] = x[0] + dx_shark[j]
            y[1] = y[0] + dy_shark[j]
            if check_range(x[1], y[1]) == False:
                continue
            for k in range(1,5):
                x[2] = x[1] + dx_shark[k]
                y[2] = y[1] + dy_shark[k]
                if check_range(x[2], y[2]) == False:
                    continue
                count = 0
                for move in set(zip(x,y)):
                    count = count + len(fish_map[move[0]][move[1]])
                x_ = x.copy()
                y_ = y.copy()
                if len(shark_move) == 0:
                    shark_move.append([x_,y_,count])
                elif shark_move[0][2] < count:
                    shark_move.appendleft([x_,y_,count])
    sx = shark_move[0][0][2]
    sy = shark_move[0][1][2]

    for i in range(1,5):
        for j in range(1,5):
            if smell_map[i][j] < 0:
                smell_map[i][j] += 1

    for move in zip(shark_move[0][0],shark_move[0][1]):
        if len(fish_map[move[0]][move[1]]) > 0:
            smell_map[move[0]][move[1]] = -2
            fish_map[move[0]][move[1]].clear()
    for i in range(1,5):
        for j in range(1,5):
            fish_map[i][j].extend(fish_original[i][j])


for i in fish_pos:
    fish_map[i[0]][i[1]].append(i)
for i in range(S):
    fish_original, fish_map = move_fish()
    move_shark(fish_map,fish_original)
answer = 0
for i in range(1,5):
    for j in range(1,5):
       answer += len(fish_map[i][j])
print(answer)
