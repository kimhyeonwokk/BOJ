import sys
from collections import deque

N, M, K = map(int,input().split())
graph = []
# 1번 윗면 2번 북족 3번 동쪽 4번 서쪽 5번 남쪽 6번 아래면
dice = [0,1,2,3,4,5,6]
# 0  1  2  3
# 북 동 남 서
direction = 1
# 전 후
change_dice = [
    [[6,5],[5,1],[1,2],[2,6]],
    [[4,1],[1,3],[6,4],[3,6]],
    [[2,1],[1,5],[5,6],[6,2]],
    [[1,4],[3,1],[4,6],[6,3]],
]
dx = [-1,0,1,0]
dy = [0,1,0,-1]
pos = [0,0]
score = 0
map_score = [[0 for i in range(M)] for j in range(N)]
#print(map_score)
def cal_score():
    for i in range(N):
        for j in range(M):
            dq_stack = deque()
            if map_score[i][j] == 0:
                value = graph[i][j]
                dq_set = set()
                dq_set.add(str(i)+" "+str(j))
                dq_stack.append([i,j])
                while len(dq_stack) != 0:
                    dq_pop = dq_stack.popleft()
                    x, y = dq_pop[0], dq_pop[1]
                    for dx_,dy_ in zip(dx,dy):
                        new_x = x + dx_
                        new_y = y + dy_
                        if new_x >= 0 and new_x < N and new_y >= 0 and new_y < M:
                            if graph[new_x][new_y] == value and map_score[new_x][new_y] == 0:
                                map_score[new_x][new_y] = 1
                                dq_set.add(str(new_x) + " " + str(new_y))
                                dq_stack.append([new_x,new_y])

                value = len(dq_set) * value
                for i_ in dq_set:
                    split_ = i_.split(" ")
                    map_score[int(split_[0])][int(split_[1])] = value




for _ in range(N):
    graph.append(list(map(int,input().split())))

cal_score()
answer = 0
for index,i in enumerate(range(K)):
    new_x = dx[direction] + pos[0]
    new_y = dy[direction] + pos[1]
    if new_x >= 0 and new_x < N and new_y >= 0 and new_y < M:
        pass
    else:
        direction = (direction + 2) % 4
        new_x = dx[direction] + pos[0]
        new_y = dy[direction] + pos[1]
    pos[0] = new_x
    pos[1] = new_y

    # 주사위 굴리기
    dict_prev = dice.copy()
    for i in change_dice[direction]:
        dice[i[1]] = dict_prev[i[0]]

    # A > B
    if dice[6] > graph[pos[0]][pos[1]]:
        direction = (direction + 1) % 4
    elif dice[6] < graph[pos[0]][pos[1]]:
        direction = direction - 1
        if direction == -1:
            direction = 3
    answer += map_score[pos[0]][pos[1]]
    #print(pos[0]+1,pos[1]+1,"방향",direction,"아래",dice[6])
print(answer)
