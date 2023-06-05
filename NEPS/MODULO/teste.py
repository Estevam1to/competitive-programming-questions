def main():
    frase = input()
    frase2 = frase.lower().split() 
    frase3 = ""

    for palavra in frase2:
        frase3 += palavra

    pontuacao = [';', ',', '.', ':', '!', '?']

    for ponto in pontuacao:
        frase3 = frase3.replace(ponto, "")
 
    eh_palindromo = 1   
    for i in range(len(frase3) // 2):
        if frase3[i] != frase3[-(i + 1)]:
            eh_palindromo = 0
            break

    if eh_palindromo == 1:
        print("SIM")
    else:
        print("NAO")

if __name__ == "__main__":
    main()
