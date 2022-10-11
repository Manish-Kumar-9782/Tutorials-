import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoField;

/*
 * LocalDateTime: it is an immutable date-time object that represents a date 
 * time, often viewed as year-month-day-hour-minute-second. Other date and 
 * time fields, such as day-of-year, day-of-week and week-of-year, can 
 * also be accessed. Time is represented to nanosecond precision.  
 */

public class Local_Date_Time {

    public static void main(String[] args) {

        // first we will get the current LocalDateTime object
        LocalDateTime dateTime = LocalDateTime.now();
        System.out.println("Current LocalDateTime: " + dateTime);

        // Now we will set the Formatting
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy hh:mm");
        System.out.println("Current LocalDateTime: " + dateTime.format(formatter));

        // Use of ChronoField to retrieve the selected information from the
        // time object.

        System.out.println("Day of week: " + dateTime.get(ChronoField.DAY_OF_WEEK));
        System.out.println("Day of month: " + dateTime.get(ChronoField.DAY_OF_MONTH));
        System.out.println("Day of year: " + dateTime.get(ChronoField.DAY_OF_YEAR));
        System.out.println("Hour of day: " + dateTime.get(ChronoField.HOUR_OF_DAY));
        System.out.println("Minute of day: " + dateTime.get(ChronoField.MINUTE_OF_DAY));

    }

}
