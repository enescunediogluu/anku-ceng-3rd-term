import re

table = [['State', 'id', '+', '*', '(', ')', '$', 'E', 'T', 'F'],
          [0, 'S5', 0, 0, 'S4', 0, 0, 1, 2, 3],
          [1, 0, 'S6', 0, 0, 0, 'accept', 0, 0, 0],
          [2, 0, 'R2', 'S7', 0, 'R2', 'R2', 0, 0, 0],
          [3, 0, 'R4', 'R4', 0, 'R4', 'R4', 0, 0, 0],
          [4, 'S5', 0, 0, 'S4', 0, 0, 8, 2, 3],
          [5, 0, 'R6', 'R6', 0, 'R6', 'R6', 0, 0, 0],
          [6, 'S5', 0, 0, 'S4', 0, 0, 0, 9, 3],
          [7, 'S5', 0, 0, 'S4', 0, 0, 0, 0, 10],
          [8, 0, 'S6', 0, 0, 'S11', 0, 0, 0, 0],
          [9, 0, 'R1', 'S7', 0, 'R1', 'R1', 0, 0, 0],
          [10, 0, 'R3', 'R3', 0, 'R3', 'R3', 0, 0, 0],
          [11, 0, 'R5', 'R5', 0, 'R5', 'R5', 0, 0, 0]
          ]

dictionary = {}
headerList = ['State', 'id', '+', '*', '(', ')', '$', 'E', 'T', 'F']

grammer = {}
grammer['R1'] = ('E', ['E', '+', 'T'])
grammer['R2'] = ('E', ['T'])
grammer['R3'] = ('T', ['T', '*', 'F'])
grammer['R4'] = ('T', ['F'])
grammer['R5'] = ('F', ['(', 'E', ')'])
grammer['R6'] = ('F', ['id'])

for row in table:
    key = row[0]
    value = row[1:]
    dictionary[key] = value

inputText = input("Enter your string:\n")

stack = [0]
buffer = re.findall(r'[\w]+|[\+\-\*\(\)/]', inputText)
buffer.append('$')
actions = []

def findAction():
    stackLast = stack[-1]
    bufferFirst = headerList.index(buffer[0])-1

    action = dictionary[stackLast][bufferFirst]
    return action


def shift(action):
    if len(buffer) > 0:
        temp = buffer.pop(0)
        stack.append(temp)
        stack.append(int(action[1]))


def reduce(action):
    global stack  
    stack.pop()

    rule = grammer[action]
    if len(rule[1]) == 1:
        temp = rule[1][0]
        convert = rule[0]
        tempIndex = stack.index(temp)
        stack[tempIndex] = convert
        
    elif len(rule[1]) == 3:
        convert = rule[0]
        if len(stack) >= 3:
            index1 = stack.index(rule[1][0])
            index2 = stack.index(rule[1][2])
            valIndex = stack.index(rule[1][1])
            if index1 < valIndex < index2:
                stack = stack[:index1] + [convert] + stack[index2 + 1:]


    if len(stack) >= 2: 
        if type(stack[-1]) == str:
            temp = dictionary[stack[-2]][headerList.index(stack[-1])-1]
            stack.append(temp)

    
def applyAction(action):
    if action[0] == 'S':
        shift(action)
    else:
        reduce(action)

while True:
    action = findAction()
    actions.append(action)
    if action == 0:
        print("INVALID string entered. SYNTAX ERROR!")
        break
    elif action == 'accept':
        print("VALID string entered. ACCEPTED!")
        break
    else:
        applyAction(action)
