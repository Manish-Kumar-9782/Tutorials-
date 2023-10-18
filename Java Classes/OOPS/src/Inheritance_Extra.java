import java.time.LocalDate;

enum Gender {Male,Female,Other};

class AadharNumber{
    private String number;
    AadharNumber(String number){
        this.number = number;
    }

    @Override
    public String toString(){
        return this.number;
    }
}
class Address{
    private String addressLine;
    private String tehsil;
    private String city;
    private String state;
    private String country;
    private int pincode;

    public Address(String addressLine, String tehsil, String city, String state,
                   String country, int pincode) {
        this.addressLine = addressLine;
        this.tehsil = tehsil;
        this.city = city;
        this.state = state;
        this.country = country;
        this.pincode = pincode;
    }

    @Override
    public  String toString(){
        return this.addressLine + ", "
                + this.tehsil + ", "
                + this.city + ", "
                + this.state + ", "
                + this.pincode + ", "
                + this.country;
    }
}


class PersonX {
    private String name;
    private LocalDate dob;
    private Address address;
    private Gender gender;
    private AadharNumber aadharNumber;


    public PersonX(String name, LocalDate dob, Address address, Gender gender, AadharNumber aadharNumber) {
        this.name = name;
        this.dob = dob;
        this.address = address;
        this.gender = gender;
        this.aadharNumber = aadharNumber;
    }

    @Override
    public String toString(){
        return "Name: " + this.name + "\n"
                + "DOB: " + this.dob + "\n"
                + "Address: " + this.address + "\n"
                + "Gender: " + this.gender + "\n"
                + "AadharNumber: " + this.aadharNumber;
    }
}


