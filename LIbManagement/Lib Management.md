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
1.  Improved the `BaseDatabase` initial process
    1. Added: more robust handling of initiaing `CSVReader` and `CSVWriter` instance.
    2. Added: a public access for generating the instance of `CSVReader` and `CSVWriter`.
    3. Added: Lazy Initiating the writer instance on the first load and `setup_inital`.
