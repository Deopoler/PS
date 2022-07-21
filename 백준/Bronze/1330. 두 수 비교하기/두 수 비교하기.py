input_value = input("").split(" ")
A = int(input_value[0])
B = int(input_value[1])
if (A > B):
    print(">")
elif (A == B):
    print("==")
else :
    print("<")