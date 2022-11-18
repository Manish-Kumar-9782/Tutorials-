package LibManage;

import java.time.LocalDate;
import java.time.Period;
import java.time.temporal.ChronoUnit;
import java.util.concurrent.TimeUnit;

public class Test {

    public static void main(String[] args) {
        LocalDate time1 = LocalDate.now();

        LocalDate time2 = LocalDate.of(2022, 11, 20);

        System.out.println("Diff: " + Period.between(time1, time2).get(ChronoUnit.DAYS));

        System.out.println("Date 1:"+ time1);
        System.out.println("Date 2: "+ time2);
    }
}
