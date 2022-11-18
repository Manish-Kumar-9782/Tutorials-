package LibManage;
import javax.lang.model.type.NullType;
import java.time.LocalDate;
import java.time.Period;
import java.time.temporal.ChronoField;
import java.time.temporal.ChronoUnit;
import java.util.Arrays;
import java.util.Scanner;

class PersonEntry{

    RegisteredPerson person;
    LocalDate issueDate;
    LocalDate returnDate;
    boolean isFined;
    double fineAmount;

    PersonEntry(RegisteredPerson person, LocalDate issueDate, LocalDate returnDate,
                boolean isFined, double fineAmount){
        this.person = person;
        this.issueDate = issueDate;
        this.returnDate = returnDate;
        if(isFined){
            this.isFined = true;
            this.fineAmount = fineAmount;
        }
    }
}

public class RegisteredBook extends Book{

    String department;

    static RegisteredBook bookDatabase[];
    static RegisteredBook allIssuedBook[];
    static int countBook;
    static int issueCountBook;

    static{
        countBook = 0;
        issueCountBook = 0;
        bookDatabase = new RegisteredBook[10];
        allIssuedBook = new RegisteredBook[10];
    }

    static String tableFormat = "%-15s %-30s %-30s %-25s %-10s";
    private  PersonEntry issuedPerson[] = new PersonEntry[10]; // to store the entries.
    private int nPersonEntries = 0; // to count the entries
    private Person currentIssuedPerson;
    private  boolean availability=true;
    private  boolean returnStatus = true;
    private  LocalDate issuedDate;
    final int validDays = 15;
    final double perDayFine = 10;

    RegisteredBook(String department,
                   String title, String author, String publisher, int pages, double price){
            super(title, author, publisher, pages, price, department);
            RegisteredBook.bookDatabase[RegisteredBook.countBooks++] = this;
    }

    public void issueBook(){

        RegisteredPerson person = RegisteredPerson.searchPerson();

        if (person != null){
            issuedDate = LocalDate.now();
            this.currentIssuedPerson = person;
//      adding a new entry to the issuedPerson
            this.issuedPerson[this.nPersonEntries++]  = new PersonEntry(person,
                    issuedDate, null, false, 0);

//      here we need to verify that current book is already exist in the database.

            /*
            *   Now here wee need to check two things
            *
            * 1. is our array database is empty or not.
            * 2. current book is availability.
            *
            * */
            if(this.availability){
                if(RegisteredBook.issueCountBook>0) {
                    for (int i = 0; i < RegisteredBook.issueCountBook; i++) {
                        if (!RegisteredBook.allIssuedBook[i].equals(this)) {
                            System.out.println("Book added to the issued book database.");
                            this.finalize_issue_book();
                        } else {
                            System.out.println("Book is already exist in issued Database.");
                        }
                    }
                }
                else{
                    this.finalize_issue_book();
                }
            }
            else {
                System.out.println("This book is not available right now:");
                int rdays = this.getRemainValidReturnedDays();
                System.out.println("You can get this book after "+ rdays +" days.");
            }

        }
        else {
            System.out.println("person entry is not found..");
        }
    }

//    returnBook is not currently in use
    public void returnBook(){
        LocalDate currentTime = LocalDate.now();
//        currentTime - issuedDate
        if(Period.between(this.issuedDate, currentTime).get(ChronoUnit.DAYS) > this.validDays ){
        // we will apply the fine
            int diff_day = (int)Period.between(this.issuedDate, currentTime).get(ChronoUnit.DAYS) - this.validDays;
            int FineAmount = diff_day*10;
            this.finalize_return_book((RegisteredPerson) this.currentIssuedPerson,
                    this, issuedDate, currentTime,
                    true, FineAmount);
        }
        else {
            this.finalize_return_book((RegisteredPerson) this.currentIssuedPerson,
                    this, issuedDate, currentTime,
                    false, 0);
        }

        }


    static RegisteredBook searchBook(){
//        this will search the book by using the primary key.
        int pk=0;
        Display.clScreen();
        System.out.println("Enter Book Primary Key: ");
        Scanner scan = new Scanner(System.in);
        pk = scan.nextInt();

        for(int i=0; i<RegisteredBook.countBooks; i++){

            if(RegisteredBook.bookDatabase[i].pk == pk){
                RegisteredBook.bookDatabase[i].inline_display();
                return RegisteredBook.bookDatabase[i];
            }
        }
        return null;
    }
//    BookName, NumberOfIssuedPerson, CurrentIssuedPerson, LastIssueDate, LastIssueDataValidity,
    void inlineDisplay(){
        System.out.println(String.format(RegisteredBook.tableFormat, this.title,this.nPersonEntries,
                this.currentIssuedPerson.name, this.issuedDate, this.validDays));
    }

    static void getHeading(){
        System.out.println(String.format(RegisteredBook.tableFormat, "BookName", "NumberOfIssuedPerson",
                "CurrentIssuedPerson", "LastIssueDate", "LastIssueDataValidity"));
    }
    static void showDatabase(){
        RegisteredBook.getHeading();
        for (int i=0; i<RegisteredBook.issueCountBook; i++){
            RegisteredBook.allIssuedBook[i].inlineDisplay();
        }
    }

    // getRemainValidReturnedDays
    private int getRemainValidReturnedDays(){

        int rdays = 0;
        if (!this.availability){
            int iday = this.issuedDate.get(ChronoField.DAY_OF_YEAR);

            int cday = LocalDate.now().get(ChronoField.DAY_OF_YEAR);

//            to varify the current year
            if (!((cday-iday) <0) ){
                System.out.println("return days: ");
                System.out.println("issue iday: " + iday);
                System.out.println("issue Cday: " + cday);
                rdays = this.validDays - (cday-iday);
            }
        }

        return rdays;
    }

    private void finalize_issue_book(){
        RegisteredBook.allIssuedBook[RegisteredBook.issueCountBook++] = this;
        this.availability = false;
        this.returnStatus = false;
    }

    private  void finalize_return_book(RegisteredPerson person,RegisteredBook bk,
                                       LocalDate issueDate, LocalDate returnDate,
                                       boolean isFined, double fineAmount){
        person.returnBook(bk, issueDate, returnDate, isFined, fineAmount);
        this.availability = true;
        this.returnStatus = true;
    }

}
