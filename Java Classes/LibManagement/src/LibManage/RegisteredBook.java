package LibManage;
import javax.lang.model.type.NullType;
import java.time.LocalDate;
import java.time.temporal.ChronoField;
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
    static int countBook;

    static{
        countBook = 0;
        bookDatabase = new RegisteredBook[10];
    }
    private  PersonEntry issuedPerson[] = new PersonEntry[10];
    private int nPersonEntries = 0;
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
            this.availability = false;
            this.returnStatus = false;
            this.currentIssuedPerson = person;
//      adding a new entry to the issuedPerson
            this.issuedPerson[this.nPersonEntries++]  = new PersonEntry(person,
                    issuedDate, null, false, 0);
        }
        else {
            System.out.println("person entry is not found..");
        }
    }

    public void returnBook(){
        LocalDate currentTime = LocalDate.now();
//        currentTime - issuedDate
        if (currentTime.get(ChronoField.YEAR)  == issuedDate.get(ChronoField.YEAR)){
            int totalDays = currentTime.get(ChronoField.DAY_OF_YEAR)  - issuedDate.get(ChronoField.DAY_OF_YEAR);
            if((validDays-totalDays) < 0){
//                if negative then it means fine should be applied
                    double fineAmount = (validDays - totalDays)* this.perDayFine;

            }
            else{
//              if non-negative then it means no fine

            }
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


}
