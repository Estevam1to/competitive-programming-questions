n = input()

two_digits =int(n[-2:])

if two_digits % 4 == 0:
    print("S")
else:
    print("N")

sum_digits = sum(int(digit) for digit in n)

if(sum_digits % 9 == 0 ):
    print("S")
else:
    print("N")

if two_digits % 25 == 0:
    print("S")
else:
    print("N")
