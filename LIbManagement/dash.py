from BookDB import BookDatabase
from tabulate import tabulate


class Dashboard:

    def __init__(self):

        self.db = BookDatabase()
        self.db.load()

        self._active_len = 0
        self._interactive_options = ["A:Add", "U:Update", "D:Delete", "Q:Quit"]
        self._active_command = None
        self._active_book_id = None

        self._actions = {
            "a": self.add_entry,
            "u": self.update_entry,
            "d": self.delete_entry
        }

    def _gen_option_row(self):
        return "\t".join(self._interactive_options)

    def _set_row_len(self, table):
        self._active_len = table.find("\n")

    def _gen_sep_row(self):
        return "=" * self._active_len

    def _get_table(self):
        books = self.db.getAll()
        return tabulate((book.as_list() for book in books),
                        headers=self.db.headers, tablefmt='grid')

    def display_sep(self):
        print(self._gen_sep_row())

    def display_interactive_options(self):
        print(self._gen_option_row())

    def get_command(self):

        cmds = ['a', 'u', 'd', 'q']

        cmd = input("Action: ").lower()

        if cmd not in cmds:
            print("Invalid command. Please try again.")
            return None

        self._active_command = cmd

        if cmd in ['u', 'd']:
            self._active_book_id = input("Book ID: ")

    def display_data(self):
        table = self._get_table()
        self._set_row_len(table)
        print(table)

    def _get_entry_fields(self, skip=None, edit=True):
        # skip is a list of some fields ot be skipped.
        skip = skip or []

        if not isinstance(skip, (str, list)):
            raise TypeError(
                "skip must be a list, set, tuple or string (for single filed)")

        if isinstance(skip, str):
            skip = ([skip] + [self.db.id_key]) if edit else set([skip])
        else:

            skip = (skip + [self.db.id_key]) if edit else set(skip)

        skip = skip if isinstance(skip, set) else set(skip)
        fields = set(self.db.headers).difference(skip)
        re_ordered_fields = [
            filed for filed in self.db.headers if filed not in skip]
        return re_ordered_fields

    def _get_entry(self, skip=None, edit=True):

        current_fields = self._get_entry_fields(skip, edit)

        bk = {}
        for field in current_fields:
            bk[field] = input(f"Please enter {field:15s}:")

        return bk

    def delete_entry(self):
        book_id = self._active_book_id
        if book_id is None:
            print("Now book is selected to update, select a book by a book id")
            return
        self.db.delete(book_id)

    def update_entry(self):
        book_id = self._active_book_id
        if book_id is None:
            print("Now book is selected to update, select a book by a book id")
            return

        entry = self._get_entry(edit=True)
        # filter out the fields that are not changed..
        entry = {key: value for key, value in entry.items() if value != ''}
        self.db.update(book_id, **entry)

    def add_entry(self):
        entry = self._get_entry(skip=self.db.id_key)
        self.db.insert(**entry)

    def process_command(self):
        action = self._actions.get(self._active_command)
        if action is None:
            return
        action()  # call the action function

    def init(self):
        while True:
            self.display_data()
            self.display_sep()
            self.display_interactive_options()
            self.display_sep()
            self.get_command()

            if self._active_command == 'q':
                break
            else:
                self.process_command()


if __name__ == "__main__":
    dashboard = Dashboard()
    dashboard.init()
    # dashboard.add_entry()
