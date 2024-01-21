given = input().split()

n = int(given[0])
b = int(given[1])

base_b = []

while n > 0:
    base_b.append(n%b)
    n = n // b #floor division

for num in base_b[::-1]:
    if num > 9:
        print(chr(num+55), end='')
    else:
        print(num, end='')