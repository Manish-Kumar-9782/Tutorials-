import java.time.LocalTime;
import java.time.ZoneId;
import java.time.temporal.ChronoUnit;

/*
 * LocalTime: it is an immutable date-time object that represents a time, 
 * often viewed as hour-minute-second. Times is represented to nanosecond
 * precision. 
 * 
 * Note: This class does not store or represent a date or time-zone. Instead, it is
 * a description of the local time as seen on a wall clock. it cannot represent 
 * an instant on the time-line without additional information such as an offset or 
 * time-zone. 
 */

/*
 * Instance Method:
   
   1. atDate(LocalDate date) -> LocalDateTime;

   2. compareTo(LocalTime other) -> int;

   3. format(DateTimeFormatter formatter) -> String;

   4. get(TemporalField field) -> int;

   5. minusHours(long hoursToSubtract) -> LocalTime;

   6. minusMinutes(long minutesToSubtract) -> LocalTime;

   7. plusHours(long hoursToAdd) -> LocalTime;

   8. plusMinutes(long minutesToAdd) -> LocalTime;
   
 */

public class Local_Time {

    public static void main(String[] args) {
        // here first of all we will get the current time
        LocalTime currentTime = LocalTime.now();
        System.out.println("Current Time: " + currentTime);

        // we can make the LocalTime object by using of() method
        // it takes the time values
        LocalTime time = LocalTime.of(12, 22, 20);
        System.out.println("Time 2: " + time);

        // we can add or subtract the Minutes
        // 1. adding 5 minute.
        System.out.println("CurrentTime + 5 Minute: " + currentTime.plusMinutes(5));
        // 2. subtracting 5 minutes.
        System.out.println("Current Time - 5 Minute " + currentTime.minusMinutes(5));

        // we can add or subtract the hours
        // 1. adding 2 hour.
        System.out.println("CurrentTime + 2 Minute: " + currentTime.plusHours(2));
        // 2. subtracting 2 hour.
        System.out.println("Current Time - 2 Minute " + currentTime.minusHours(2));

        // current time in two different zones
        ZoneId indiaZone = ZoneId.of("Asia/Kolkata");
        ZoneId japanZone = ZoneId.of("Asia/Tokyo");
        ZoneId americaZone = ZoneId.of("America/Argentina/Buenos_Aires");

        /**
         * Link for the ZonID reference
         * https://docs.oracle.com/en/java/javase/19/docs/api/java.base/java/time/ZoneId.html
         */

        System.out.println("Indian Time Zone: " + LocalTime.now(indiaZone));
        System.out.println("Japan Time Zone: " + LocalTime.now(japanZone));
        System.out.println("America Time Zone: " + LocalTime.now(americaZone));

        // Chrono units in minutes

        long bt_time1 = ChronoUnit.MINUTES.between(LocalTime.now(indiaZone), LocalTime.now(japanZone));
        System.out.println("Time (Minute) difference b/w the indian and japan zone: " + bt_time1);

        long bt_time2 = ChronoUnit.HOURS.between(LocalTime.now(indiaZone), LocalTime.now(americaZone));
        System.out.println("Time (Hours) difference b/w the indian and America zone: " + bt_time2);

        /*
         * Link for chronoUnits reference
         * https://docs.oracle.com/en/java/javase/19/docs/api/java.base/java/time/
         * temporal/ChronoUnit.html
         */

    }

}
