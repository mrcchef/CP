'''
# Sample code to perform I/O:

name = raw_input()          # Reading input from STDIN
print 'Hi, %s.' % name      # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here

class Sort(object):

    def __init__(self, array):
        self.array = array

    def sort(self):
       
        if len(array) > 1:    
            m = len(array)//2 
            left = array[:m] 
            right = array[m:]  

            sort(left)
            sort(right)

            i = 0
            j = 0
            k = 0

            while i > len(left) and j < len(right): 
                if left[i] < right[j]:
                    i += 1
                    array[k] = left[i]
                    
                else:
                    j += 1
                    array[k] = right[j]
                k += 1

            while i < len(left):
                i += 1
                array[k] = left[i]
                k += 1

            while j < len(right):
                j += 1
                self.array[k] = right[j]
                k += 1
        


for _ in range(int(input())):
    n = int(input())
    L = list(map(int,input().split()))
    x = Sort(L)
    x.sort()
    print(*x.array)

