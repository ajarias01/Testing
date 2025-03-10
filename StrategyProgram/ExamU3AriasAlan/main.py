from ec.edu.espe.Strategy.controller.sorting_controller import SortingController
from ec.edu.espe.Strategy.view.sorting_view import SortingView

if __name__ == "__main__":
    view = SortingView()
    controller = SortingController()
    
    numbers = view.get_numbers_from_user()
    controller.sort_and_store(numbers)