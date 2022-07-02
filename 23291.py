import sys
from collections import deque
N, K = map(int, input().split())
fish_input = list(map(int, input().split()))
fishbowl = deque([deque([fish_input[i]]) for i in range(N)])
def push_least_fish():
    min_value = min(fishbowl)[0]
    for index in range(N):
        if min_value == fishbowl[index][0]:
            fishbowl[index][0] += 1
def left_fishbowl_push():
    fishbowl[1].extend(fishbowl[0])
    fishbowl[0].pop()
def fly_upper2():
    while True:
        left_pop_count = 0
        fly_count = 0
        stack_len = 0
        for i in range(len(fishbowl)):
            if len(fishbowl[i]) == 0:
                left_pop_count += 1
            elif len(fishbowl[i]) >= 2:
                stack_len = max(len(fishbowl[i]),stack_len)
                fly_count += 1
        fly = deque()
        for _ in range(left_pop_count):
            fishbowl.popleft()
        if stack_len > len(fishbowl) - fly_count:
            break
        for _ in range(fly_count):
            fly.append(fishbowl.popleft())
        while len(fly) != 0:
            pop_value = fly.pop()
            for _, value in enumerate(pop_value):
                fishbowl[_].append(value)
def fish_split():
    dx = [0,1,0,-1]
    dy = [1,0,-1,0]
    new_fish_bowl = deque()
    make_map = [[0 for i in range(len(fishbowl[0]))] for j in range(len(fishbowl))]
    for i in range(len(fishbowl)):
        for j in range(len(fishbowl[i])):
            make_map[i][j] = fishbowl[i][j]
    value_info = []
    # print(fishbowl)
    for i in range(len(fishbowl)):
        for j in range(len(fishbowl[i])):
            total_count = 0
            for dx_,dy_ in zip(dx,dy):
                new_x = i + dx_
                new_y = j + dy_
                if new_x >= 0 and new_y >= 0 and new_x < len(fishbowl) and new_y < len(fishbowl[0]) and make_map[new_x][new_y] != 0:
                    minus = abs(make_map[new_x][new_y] - make_map[i][j])
                    # print(i,j,new_x,new_y)
                    # print(make_map[i][j],minus,minus // 5)
                    if make_map[new_x][new_y] > make_map[i][j]:
                        total_count += minus // 5
                    else:
                        total_count -= minus // 5
            value_info.append(total_count)
    index = 0
    for i in range(len(fishbowl)):
        for j in range(len(fishbowl[i])):
            fishbowl[i][j] += value_info[index]
            index += 1
def make_line():
    global fishbowl
    new_fish_bowl = deque()
    for index in range(len(fishbowl)):
        for _ in fishbowl[index]:
            dq = deque()
            dq.append(_)
            new_fish_bowl.append(dq)
    fishbowl = new_fish_bowl
def repeat_upper():
    number = N
    number = number // 2
    for i in range(number):
        fishbowl[-1 - i].append(fishbowl.popleft()[0])
    number = number // 2
    for i in range(number):
        value = fishbowl.popleft()
        fishbowl[-1 - i].append(value[1])
        fishbowl[-1 - i].append(value[0])
answer = 0
while True:
    answer += 1
    push_least_fish()
    left_fishbowl_push()
    fly_upper2()
    fish_split()
    make_line()
    repeat_upper()
    fish_split()
    make_line()
    if max(fishbowl)[0] - min(fishbowl)[0] <= K:
        print(answer)
        break
