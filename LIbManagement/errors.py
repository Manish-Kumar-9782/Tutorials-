class DirectoryCreationError(Exception):
    ...


class FileCreationError(Exception):
    ...


class FileOpenError(Exception):
    ...


class FileCloseError(Exception):
    ...


class FileSaveError(Exception):
    ...


class DbIOError(Exception):
    ...


class DBIntegrityError(Exception):
    ...


class ValidationResult:
    def __init__(self):
        self.result = {
            "file": {
                "status": "error",
                "message": "File not checked"
            },
            "data_dir": {
                "status": "error",
                "message": "Data directory not checked"
            }
        }

    def add(self, key, status, message=None):
        self.result[key]["status"] = status
        self.result[key]["message"] = message

    def get_result(self):
        return self.result
