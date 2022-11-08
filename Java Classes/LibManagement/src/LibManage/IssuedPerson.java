package LibManage;

import java.time.LocalDate;

public class IssuedPerson extends Person{

    RegisteredBook issuedBooks[];

    RegisteredBook currentIssuedBook;
    LocalDate currentIssuedBookIssuedDate;
    LocalDate currentIssuedBookReturnedDate;
    boolean hasFine = false;
    int fineAmount = 0;

    IssuedPerson(RegisteredBook book, LocalDate issuedDate, String name, int age, double height, Address adrs){
        super(name, age, height, adrs);

        currentIssuedBook = book;
        currentIssuedBookIssuedDate = issuedDate;
    }

    public void returnBook(RegisteredBook book){

    }
}
