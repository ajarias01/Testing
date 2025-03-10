class SortingView:
    def get_numbers_from_user(self):
        try:
            size = int(input("Enter the number of numbers to sort: "))
            numbers = []
            for i in range(size):
                num = int(input(f"Enter the number {i+1}: "))
                numbers.append(num)
            return numbers
        except ValueError:
            print("Invalid input, please enter integers.")
            return self.get_numbers_from_user()