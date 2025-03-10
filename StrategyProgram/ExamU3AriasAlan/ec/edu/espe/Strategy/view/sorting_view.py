import tkinter as tk
from tkinter import messagebox
from ec.edu.espe.Strategy.controller.sorting_controller import SortingController

class SortingView:
    def __init__(self, root):
        self.root = root
        self.root.title("Sorting Application")
        
        self.label = tk.Label(root, text="Enter numbers separated by commas:")
        self.label.pack()
        
        self.entry = tk.Entry(root, width=50)
        self.entry.pack()
        
        self.sort_button = tk.Button(root, text="Sort", command=self.perform_sorting)
        self.sort_button.pack()
        
        self.controller = SortingController()

    def perform_sorting(self):
        user_input = self.entry.get()
        try:
            numbers = list(map(int, user_input.split(',')))
            if len(numbers) < 2:
                messagebox.showerror("Error", "Please enter at least two numbers.")
                return
            
            unsorted_str = ', '.join(map(str, numbers))
            sorted_numbers, algorithm = self.controller.sort_numbers(numbers)
            sorted_str = ', '.join(map(str, sorted_numbers))
    
            messagebox.showinfo("Sorting Result", 
                                f"Unsorted: {unsorted_str}\nSize: {len(numbers)}\nAlgorithm: {algorithm}\nSorted: {sorted_str}")
            self.controller.save_to_db(unsorted_str, len(numbers), algorithm, sorted_str)
        except ValueError:
            messagebox.showerror("Error", "Invalid input. Enter integers separated by commas.")

if __name__ == "__main__":
    root = tk.Tk()
    app = SortingView(root)
    root.mainloop()

