package LibManage;

import java.time.LocalDate;
import java.util.Scanner;

class BookEntry{

    RegisteredBook book;
    LocalDate issueDate;
    LocalDate returnDate;
    boolean isFined;
    double fineAmount;

    BookEntry(RegisteredBook bk, LocalDate issueDate, LocalDate returnDate,
              boolean isFined, double fineAmount){

        this.book = bk;
        this.issueDate = issueDate;
        this.returnDate = returnDate;
        this.isFined = isFined;
        this.fineAmount = fineAmount;
    }
}

public class RegisteredPerson extends Person{

    private BookEntry issuedBooks[]  = new BookEntry[10];
    private int nBookEntries = 0;
    private static int LIBID = 10000;
    private int libId = 0;
    RegisteredBook currentIssuedBook;
    LocalDate currentIssuedBookIssuedDate;

    RegisteredPerson(String name, int age, double height, Address adrs){
        super(name, age, height, adrs);
        this.libId = RegisteredPerson.LIBID++;
    }

    static RegisteredPerson searchPerson(){
        int libid = 0;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Student LibId: ");
        libid = scan.nextInt();
        for (int i=0; i<Registration.countPerson; i++){
            if(Registration.registrations[i].libId == libid){
                return Registration.registrations[i];
            }
        }
        return null;
    }

    @Override
    void inline_display() {
        System.out.printf((Person.tableFormat) + "%n", this.libId, this.name, this.age,  this.height);
    }

    public void returnBook(RegisteredBook book, LocalDate issueDate, LocalDate returnDate,
                           boolean isFined, double fineAmount){

//        BookEntry(bk, issueDate, returnDate, isFined, fineAmount);
            // if fined then enter the amount of fine.
            this.issuedBooks[this.nBookEntries++] =  new BookEntry(book, issueDate, returnDate,
            isFined,fineAmount);
    }

}
