from ec.edu.espe.Strategy.utils.mongodb_connection import MongoDBConnection



class DatabaseHandler:
    def __init__(self):
        self.connection = MongoDBConnection()

    def save_sorting_record(self, unsorted, sorted_list, algorithm):
        record = {
            "unsorted": str(unsorted),
            "size": len(unsorted),
            "sort_algorithm": algorithm,
            "sorted": str(sorted_list)
        }
        self.connection.insert_record(record)