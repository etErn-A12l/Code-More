
infix_ex = ""

postfix_ex = []

brackets = ['(',')','{','}','[',']']

operands = ['-','+','*','/']

infix_ex = input("Enter the Infix Expression: ")

stack = []

temp = infix_ex
i = 0
while(i < len(temp)):
    
    if temp[i] not in brackets and temp[i] not in operands:
        postfix_ex.append(temp[i])
    elif temp[i] == '('
