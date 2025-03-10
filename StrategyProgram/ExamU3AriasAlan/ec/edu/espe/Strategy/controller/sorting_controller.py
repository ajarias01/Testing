from ec.edu.espe.Strategy.model.sorting_strategy import SortingContext
from ec.edu.espe.Strategy.model.database_handler import DatabaseHandler

class SortingController:
    def __init__(self):
        self.sorting_context = SortingContext()
        self.db_handler = DatabaseHandler()

    def sort_numbers(self, data):
        self.sorting_context.set_strategy(data)
        sorted_data = self.sorting_context.sort(data)
        algorithm = self.sorting_context.strategy.__class__.__name__
        print(f"Using {algorithm}")
        print("Ordered numbers:", sorted_data)
        return sorted_data, algorithm

    def save_to_db(self, unsorted, size, algorithm, sorted_data):
        self.db_handler.save_sorting_record(unsorted, sorted_data, algorithm)
        print("Record saved in MongoDB.")