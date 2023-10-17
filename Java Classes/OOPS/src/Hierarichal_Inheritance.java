class Car {

    protected int number_of_wheels;
    protected int number_of_doors;
    protected int number_of_seats;

    public Car(){
        this.number_of_seats = 4;
        this.number_of_doors = 4;
        this.number_of_wheels = 4;
    }

    public Car(int wheels, int doors, int seats){
        this.number_of_doors  = doors;
        this.number_of_wheels = wheels;
        this.number_of_seats = seats;
    }

    @Override
    public String toString() {
        return "Car{doors:" + this.number_of_doors + ", "
                + "wheels: " + this.number_of_wheels + ", "
                + "seats: "+ this.number_of_seats + "}";
    }
}


class HyundaiCar extends  Car{

    private String type;
    private int fuelCapacity;

    public HyundaiCar(){
        this.type = "Diesel";
        this.fuelCapacity = 12;
    }

    @Override
    public String toString() {
        return "BMWCar{doors:" + this.number_of_doors + ", "
                + "wheels: " + this.number_of_wheels + ", "
                + "seats: " + this.number_of_seats + ", "
                + "type: " + this.type + ", "
                + "fuelCapacity: "+ this.fuelCapacity + "}";
    }

}

class BMWCar extends  Car{

    private Boolean solarCharge;
    private int batteryCapacity;

    public BMWCar(){
        this.batteryCapacity = 120000;
        this.solarCharge = true;
        this.number_of_seats =2;
        this.number_of_doors = 2;
    }

    @Override
    public String toString() {
        return "BMWCar{doors:" + this.number_of_doors + ", "
                + "wheels: " + this.number_of_wheels + ", "
                + "seats: " + this.number_of_seats + ", "
                + "solarCharge: " + this.solarCharge + ", "
                + "BatteryCapacity: "+ this.batteryCapacity + "}";
    }

}

