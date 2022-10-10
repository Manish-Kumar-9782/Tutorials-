import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Locale;

/*
 * Instance method of LocalDate
 * 
 * 1. atTime(int hour, int minute) -> LocalDateTime
 * 
 * 2. compareTo(ChronoLocalDate other) -> int
 * 
 * 3. equals(Object obj) -> boolean
 * 
 * 4. format(DateTimeFormatter formatter) -> String
 * 
 * 5. get(TemporalField field) -> int
 * 
 * 6. isLeapYear() -> boolean
 * 
 * 7. minusDays(long daysToSubtract) -> LocalDate
 * 
 * 8. minusMonths(long monthsToSubtract) -> LocalDate
 * 
 * 9. plusDays(long daysToAdd) -> LocalDate
 * 
 * 10. plusMonths(long monthsToAdd) -> LocalDate
 * 
 * 11. getDayofMonth() -> int
 * 
 * 12. getDayOfWeek() -> DayOfWeek
 * 
 * 13. getDayOfYear() -> int
 * 
 * 14. getMonth() -> int
 * 
 * 15. getMonthValue() -> int
 * 
 * 16. getYear() -> int
 * 
 * 17. lengthOfMonth() -> int
 * 
 * 18. lengthOfYear() -> int
 */

public class Local_Date {
    public static void main(String[] args) {
        System.out.print("\033[H\033[2J");
        // the above line to clear the console.

        // first of all we will get the current date.
        LocalDate today = LocalDate.now();

        System.out.println("Today Date: " + today);

        // Now we can add or minus a day by using the plusDays() & minusDays()
        // methods

        LocalDate yesterday = today.minusDays(1);
        System.out.println("Yesterday: " + yesterday);

        // tomorrow date
        LocalDate tomorrow = today.plusDays(1);
        System.out.println("Tomorrow: " + tomorrow);

        // Now if we want to minus the months
        LocalDate previousMonth = today.minusMonths(1);
        System.out.println("Previous Month: " + previousMonth);

        // Now if we want to plus the months
        LocalDate nextMonth = today.plusMonths(1);
        System.out.println("Next Month: " + nextMonth);

        // Now we will make a new date of today and compare it with today
        LocalDate date = LocalDate.of(2022, 9, 30);
        // Now we will match the date and today
        System.out.println("today is equal to date: " + today.equals(date));

        // Testing that this year is a leap year
        System.out.println("Is This year is leapYear: " + today.isLeapYear());

        // Adding our date with a time (like 2017-01-13T01:50:09)
        // for that we need to use atTime() method.
        System.out.println("LocalDateTime: " + today.atTime(10, 30, 30));

        // Date Time formatting by using the DateTimeFormatter Class
        System.out.println("\n---------------------------------");
        System.out.println("Date Formatting");
        System.out.println("ISO_DATE :" + today.format(DateTimeFormatter.ISO_DATE));
        System.out.println("ISO_LOCAL_DATE :" + today.format(DateTimeFormatter.ISO_LOCAL_DATE));

        // formatting by using the DateTimeFormatter.ofPattern("yyyy MM dd")
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("uuuu-LL-dd", Locale.US);
        // Now this formatter will be used by the DateTime object.
        String text = today.format(formatter);

        System.out.println("date format1: " + LocalDate.parse(text, formatter));

    }

}
