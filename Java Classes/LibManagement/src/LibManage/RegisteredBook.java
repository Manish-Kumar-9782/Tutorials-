package LibManage;
import java.time.LocalDate;
import java.time.temporal.ChronoField;

public class RegisteredBook extends Book{

    String department;
    private  String issuedPerson[];
    private Person currentIssuedPerson;
    private  boolean availability=true;
    private  boolean returnStatus = true;
    private  LocalDate issuedDate;
    final int validDays = 15;

    RegisteredBook(String department,
                   String title, String author, String publisher, int pages, double price){
            super(title, author, publisher, pages, price, department);
    }

    public void issueBook(IssuedPerson person){
        issuedDate = LocalDate.now();
        availability = false;
        returnStatus = false;
        currentIssuedPerson = person;
    }

    public void returnBook(IssuedPerson person){
        LocalDate currentTime = LocalDate.now();
//        currentTime - issuedDate
        if (currentTime.get(ChronoField.YEAR)  == issuedDate.get(ChronoField.YEAR)){
            int totalDays = currentTime.get(ChronoField.DAY_OF_YEAR)  - issuedDate.get(ChronoField.DAY_OF_YEAR);
            if((validDays-totalDays) < 0){
//                if negative then it means fine should be applied

            }
            else{
//              if non-negative then it means no fine

            }
        }
    }
}
