
abstract class Automobile{

    private int tyres;
    private int speed;
    private int seats;
    private String fuelType;
    private int fuelCapacity;


    public Automobile(int tyres, int speed, int seats, String fuelType, int fuelCapacity) {
        this.tyres = tyres;
        this.speed = speed;
        this.seats = seats;
        this.fuelType = fuelType;
        this.fuelCapacity = fuelCapacity;
    }

    abstract  public void start();
    abstract public void move();
    abstract public void stop();
}

class CarX extends Automobile{


    public CarX(int tyres, int speed, int seats, String fuelType, int fuelCapacity){
        super(tyres, speed, seats, fuelType, fuelCapacity);
    }

    public void start(){
        System.out.println("Car starting...");
        System.out.println("Car started..");
    }

    public void move(){
        System.out.println("Car is moving...");
    }

    public void stop(){
        System.out.println("Car stopped to move...");
    }
}