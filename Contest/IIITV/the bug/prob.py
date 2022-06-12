import heapq
from functools import cmp_to_key

# 1) heap
# 2) python
# 3) comparators
# 4) Job scheduling 

# 5) Hauffman encoding 
# 6)  
 
def getJobSchedule(vals):
    # sorting the array on the
    # basis of their deadlines
    def compareJob(a, b):
        if a[1] < b[1]:
            return -1
        else:
            return 1
 
    # correct line, original array ko change kiya
    # vals.sort(key=cmp_to_key(compareJob))
 
    # buggy line, original array ko change ni kiya, modified array return kiya but wo modified array store ni kiya
    sorted(vals, key=cmp_to_key(compareJob))
 
    answer = []
    maxHeap = []
 
    # correct line
    # for i in range(n - 1, -1, -1):
 
    # buggy line
    # range ka 2nd argument se -(skip value) tak jata he range
    # aur intial index galat he to index out of bound  milega
    for i in range(len(vals), 0, -1):
 
        if i == 0:
            availableSlot = vals[i][1]
        else:
            availableSlot = vals[i][1] - vals[i - 1][1]
 
        # correct line
        # heapq.heappush(maxHeap, (-vals[i][2], vals[i][1], vals[i][0]))
 
        # buggy line
        # method ka name galat he
        # maxheap use karte he job scheduling mai lekin default implementation ye heapq wali minheap/min priority queue ki he, jisko max mai convert karna padta he
        # logical error ye he ki maxheap banta he acc. to the profit of jobs ie vals[i][2], to wo set ka 1st element hona chahiye
        heapq.push(maxHeap, (vals[i][1], vals[i][2], vals[i][0]))
 
        while availableSlot and maxHeap:
            # correct line
            # profit, deadline, job_id = heapq.heappop(maxHeap)
 
            # buggy line
            # yaha pe bhi method name and order of elements jo heap mai push kiye he usko acc to upar wali buggy line ke kar raha hu
            deadline, profit, jobId = heapq.pop(maxHeap)
 
            availableSlot -= 1
 
            answer.append([jobId, deadline])
 
    def compareJob(a, b):
        if a[1] < b[1]:
            return -1
        else:
            return 1
 
    # correct line, original array ko change kiya
    # answer.sort(key=cmp_to_key(compareJob))
 
    # buggy line, original array ko change ni kiya, modified array return kiya but wo modified array store ni kiya
    # same bug upar wala
    sorted(answer, key=cmp_to_key(compareJob))
 
    return answer
 
 
# ---------------------------------------------------------------------------------
 
 
class Node:
    def __init__(self, probability, symbol, left=None, right=None):
        self.probability = probability
        self.symbol = symbol
        self.left = left
        self.right = right
        self.code = ''
 
 
codes = {}
 
 
def getCodes(node, val=''):
    # correct line
    # newVal = val + str(node.code)
    # buggy line, galat tareke se method use kiya
    newVal = val + node.code.str()
 
    if(node.left):
        getCodes(node.left, newVal)
    if(node.right):
        getCodes(node.right, newVal)
 
    # correct line
    # if(not node.left and not node.right):
    # buggy line
    # logically galat he
    # yato inner paranthesis hata lo ya phir and ko or karlo
    if(not (node.left and node.right)):
        codes[node.symbol] = newVal
 
    return codes
 
 
def calculateProbability(data):
    symbols = {}
    for element in data:
        # correct line
        # if symbols.get(element) == None:
        # small bug, method ka name galat he
        if symbols.find(element) == None:
            symbols[element] = 1
        else:
            symbols[element] += 1
    return symbols
 
 
# correct line
# def getEncodedStr(data, coding):
#     encoding_output = []
#     for c in data:
#         encoding_output.append(coding[c])
 
#     string = ''.join([str(i) for i in encoding_output])
#     return string
 
# buggy line
# list ki jagah dict use karte he join() mai to "keys" join ho jati he naki "values"
def getEncodedStr(data, coding):
    encodedOutput = {}
    for c in data:
        encodedOutput[c] = coding[c]
 
    string = ''.join(encodedOutput)
    return string
 
 
def Huffman_Encoding(data):
    symbol_with_probs = calculateProbability(data)
    symbols = symbol_with_probs.keys()
 
    nodes = []
 
    for symbol in symbols:
        nodes.append(Node(symbol_with_probs.get(symbol), symbol))
 
    # correct line
    # while len(nodes) > 1:
    # buggy line, > ki jagah >=
    while len(nodes) >= 1:
        # correct line
        # nodes = sorted(nodes, key=lambda x: x.probability)
        # buggy line, jaisa pehle kara he
        sorted(nodes, key=lambda x: x.probability)
 
        # correct line
        # right = nodes[0]
        # left = nodes[1]
        # small bug, right left ulte ho gae
        right = nodes[1]
        left = nodes[0]
 
        left.code = 0
        right.code = 1
 
        newNode = Node(left.probability+right.probability, left.symbol +
                       right.symbol, left, right)
 
        nodes.remove(left)
        nodes.remove(right)
        nodes.append(newNode)
 
    huffman_encoding = getCodes(nodes[0])
    encoded_output = getEncodedStr(data, huffman_encoding)
    return encoded_output
 
 
# ---------------------------------------------------------------------------------
 
 
t = int(input())  # number of test cases
 
vals = [[x, y, z] for x, y, z in [input().split() for _ in range(t)]]
# description of jobs
 
jobSchedule = getJobSchedule(vals)
 
# jobId, deadline
stringifiedJobScheduled = ""
 
for job in jobSchedule:
    stringifiedJobScheduled += str(job[0]) + " " + str(job[1]) + " "
 
encodedStrJobSchedule = Huffman_Encoding(stringifiedJobScheduled)
print("Encoded string form of job schedule", encodedStrJobSchedule)