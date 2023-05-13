import sys

def input():
    return sys.stdin.readline().rstrip()

N, K = map(int,input().split())
a,b,c,d = map(int,input().split())
A = []
B = []
C = []
D = []

for i in range(N):
    t,u = input().split()
    u = int(u)
    if t == "A":
        A.append(u)
    elif t == "B":
        B.append(u)
    elif t == "C":
        C.append(u)
    elif t == "D":
        D.append(u)

A.sort()
B.sort()
C.sort()
D.sort()

for i in range(K):
    max_char = "A"
    max_value = (a+A[-1])/a
    if (B and (b+B[-1])/b > max_value):
        max_char = "B"
        max_value = (b+B[-1])/b
    if (C and (c+C[-1])/c > max_value):
        max_char = "C"
        max_value = (c+C[-1])/c
    if (D and (d+D[-1])/d > max_value):
        max_char = "D"
        max_value = (d+D[-1])/d

    if max_char == "A":
        print(f"A {A[-1]}")
        a += A[-1]
        A.pop()
    if max_char == "B":
        print(f"B {B[-1]}")
        b += B[-1]
        B.pop()
    if max_char == "C":
        print(f"C {C[-1]}")
        c += C[-1]
        C.pop()
    if max_char == "D":
        print(f"D {D[-1]}")
        d += D[-1]
        D.pop()
    