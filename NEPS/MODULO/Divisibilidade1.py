def main():
    n = input()

    if int(n[-1]) % 2 == 0:
        print("S")
    else:
        print("N")

    digt_sum = sum(int(digit) for digit in n)

    if digt_sum % 3 == 0:
        print("S")
    else:
        print("N")

    if int(n[-1]) % 5 in [0,5]:
        print("S")
    else:
        print("N")

if __name__ == "__main__":
    main()
