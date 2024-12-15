class Book:

    def __init__(self, book_id, title, author, subject, pages, price):
        self.book_id = str(book_id)
        self.title = title
        self.author = author
        self.subject = subject
        self.pages = pages
        self.price = price

    def __str__(self):
        return f"Book<{self.book_id}:{self.title}>"

    def __repr__(self):
        return f"Book<{self.book_id}:{self.title}>"

    def as_list(self):
        return [self.book_id, self.title, self.author, self.subject, self.pages, self.price]
