class BubbleSort:
    def sort(self, data):
        n = len(data)
        for i in range(n):
            for j in range(0, n-i-1):
                if data[j] > data[j+1]:
                    data[j], data[j+1] = data[j+1], data[j]
        return data

class InsertionSort:
    def sort(self, data):
        for i in range(1, len(data)):
            key = data[i]
            j = i - 1
            while j >= 0 and key < data[j]:
                data[j + 1] = data[j]
                j -= 1
            data[j + 1] = key
        return data

class QuickSort:
    def sort(self, data):
        if len(data) <= 1:
            return data
        pivot = data[len(data) // 2]
        left = [x for x in data if x < pivot]
        middle = [x for x in data if x == pivot]
        right = [x for x in data if x > pivot]
        return self.sort(left) + middle + self.sort(right)

class SortingContext:
    def __init__(self):
        self.strategy = None

    def set_strategy(self, data):
        size = len(data)
        if size >= 2 and size <= 5:
            self.strategy = BubbleSort()
        elif size >= 6 and size <= 10:
            self.strategy = InsertionSort()
        elif size > 10:
            self.strategy = QuickSort()
        else:
            raise ValueError("The size of the array must be greater than 1.")

    def sort(self, data):
        return self.strategy.sort(data)