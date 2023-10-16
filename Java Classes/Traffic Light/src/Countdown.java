import java.time.Instant;
import java.time.Duration;

public class Countdown {

    Duration countdown_time = null;

    public Countdown(int hour, int min, int sec){

        int TotalSeconds = hour*3600 + min*60 + sec;

        // Now creating the duration with seconds.
        this.countdown_time = Duration.ofSeconds(TotalSeconds);
    }

    public Countdown(int sec){
        // Now creating the duration with seconds.
        this.countdown_time = Duration.ofSeconds(sec);
    }

    public void start(){

        Instant end_time = Instant.now();
        end_time = end_time.plus(this.countdown_time);

        while(true){
            Instant current = Instant.now();
            if(current.isBefore(end_time)){

                try{
                    // time duration in b/w the two Instant.
                    Duration diff_t = Duration.between(current, end_time);
                    System.out.print("CountDown: "+ diff_t.getSeconds() + "\r");
                    Thread.sleep(1000);
                }
                catch (Exception e){
                    System.out.println("Exception occured: " + e);
                }
            }
            else break;
        }
    }

}
