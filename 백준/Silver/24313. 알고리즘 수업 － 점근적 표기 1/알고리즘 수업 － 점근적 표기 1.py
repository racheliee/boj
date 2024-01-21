temp = input()
fn = temp.split()
fn1 = int(fn[0])
fn2 = int(fn[1])

c = int(input())
n0 = int(input())

if(fn1 <= c):
    if(fn1*n0+fn2 > c*n0):
        print(0)
    else:
        print(1)
else:
    print(0)