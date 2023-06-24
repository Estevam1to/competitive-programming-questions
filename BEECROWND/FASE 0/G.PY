import re
 
def verificar_sequencia_numeros(numeros):
    numeros = [int(num.replace(',', '').replace(' ', '').replace('.', '')) for num in numeros]
    for i in range(1, len(numeros)):
        if numeros[i] < numeros[i-1] + 1:
            return False
    return True
 
 
n = int(input())
numeros_formatados = []
 
for _ in range(n):
    linha = input().strip()
    numeros_formatados.extend(re.findall(r'\b\d+(?:[., ]?\d+)*\b', linha))
 
if verificar_sequencia_numeros(numeros_formatados):
    print('123')
else:
    print(':)')