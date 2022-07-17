import itertools
a,b=map(int,input().split())
print("""
""".join([" ".join(map(str,i))for i in itertools.permutations(range(1,a+1),b)]))