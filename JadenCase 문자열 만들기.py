def solution(s):
    answer = ""
    s = s.lower()
    check = False
    for i in range(len(s)):
        if s[i] == " ":
            check = False
            answer += s[i]
        elif check == False:
            check = True
            parsing = s[i]
            parsing = parsing.upper()
            answer += parsing
        else:
            answer += s[i]
    return answer
