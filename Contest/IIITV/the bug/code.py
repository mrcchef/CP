class Sort(object):

    def __init__(self, array):
        self.array = array

    def sort(self):
        if len(self.array) > 1:
            m = len(self.array)//2
            left = self.array[:m]
            right = self.array[m:]

            leftsorter = Sort(left)
            leftsorter.sort()
            rightsorter = Sort(right)
            rightsorter.sort()

            i = 0
            j = 0
            k = 0

            while i < len(left) and j < len(right):
                if left[i] < right[j]:
                    self.array[k] = left[i]
                    i += 1
                else:
                    self.array[k] = right[j]
                    j += 1
                k += 1

            while i < len(left):
                self.array[k] = left[i]
                i += 1
                k += 1

            while j < len(right):
                self.array[k] = right[j]
                j += 1
                k += 1



for _ in range(int(input())):
    n = int(input())
    L = list(map(int,input().split()))
    x = Sort(L)
    x.sort()
    print(*x.array)