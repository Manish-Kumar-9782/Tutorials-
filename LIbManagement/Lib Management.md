## Sections in LibManagement

1. show all available menu options
   * show books (Table format)
   * add book
   * delete book
   * update book
   * view detail for individual book

CSV Module Changes 13/12/2024

1. refactored the `Utility.__checkDataDir__` method and renamed to `Utility._check_data_dir`.
2. refactored the `Utility.__createDataDir__` method and renamed to `Utility._create_data_dir`.
3. refactored the `Utility.__createFile__` method and renamed to `Utility._create_file`.
4. refactored the `Utility.__check_file` method and renamed to `Utility._check_file`.
5. refactored the `Utility.__openFile__`, `Utility.__closeFile__` method with more error handling.
6. Improved `check` and `create` methods with better error message with dict result.
7. refactored the `Utility.checkIntegrity` method and renamed to `Utility.check_integirty`.
   1. Improved the Error handling.
   2. Applied sequential checking of directory and file.
   3. Maintained the Error handling and raising for futhur handling and clear message.
8. Add `CSVBase` class as the parent of `CSVWriter` and `CSVReader` for common initial setup operation.
9. Removed the `set_headers` and related attributes from `CSVReader` and `CSVWriter` and moved to `CSVBase` class.

Base  Database Module Changes 13/12/2024

1. Improved the `BaseDatabase` initial process
   1. Added: more robust handling of initiaing `CSVReader` and `CSVWriter` instance.
   2. Added: a public access for generating the instance of `CSVReader` and `CSVWriter`.
   3. Added: Lazy Initiating the writer instance on the first load and `setup_inital`.



Add new features to BookDatabase class in BookDB.py 14/12/2024

- Added a consistent key for book_id in the headers.
- Added a method to retrieve a book by its ID (get).
- Added a method to update an existing book's information (update).
- Added a method to delete a book from the database (delete).
- Added validation in the insert method to ensure keys match defined headers.
- Added error handling for invalid keys during book insertion.
- Added a sample book insertion in the main execution block.


Enhance library management system with new features and improvements

- **BookDB.py**:

  - Added a consistent identifier for books using 'book_id' in headers.
  - Implemented methods to retrieve (get) and update (update) book details.
  - Added a method to delete books from the database (delete).
  - Enhanced the insert method to validate book information against defined headers.
  - Introduced error handling for invalid keys during book insertion with BookFieldKeyError.
  - Updated the main execution block to demonstrate book insertion functionality.
- **Utility.py**:

  - Refactored import statements for consistency and clarity.
  - Cleaned up code formatting for better readability.
- **bk.py**:

  - Modified the Book class to ensure 'book_id' is stored as a string.
  - Added a method to return book details as a list (as_list).
- **books_db.csv**:

  - Updated the CSV file to reflect the new 'book_id' header for consistency with the code.
- **errors.py**:

  - Added new exception classes: BookFieldKeyError and EntryNotFound for better error handling.
- **main.py**:

  - Updated the main execution logic to load the new book database and handle user interactions.

This commit introduces significant enhancements to the library management system, improving functionality and error handling across multiple components.
