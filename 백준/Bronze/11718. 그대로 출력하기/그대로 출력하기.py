import sys

strings = []

while True:
    string = sys.stdin.readline()
    if string == '' or string == '\n' or string == ' ':
        break
    strings.append(string)

for string in strings:
    print(string, end='')
