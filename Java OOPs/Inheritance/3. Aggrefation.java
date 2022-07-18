
/*
	In this section we will see that how aggregation concept works in the java.

	To understance the Clear view of the aggregation HAS-A Relation type bound.
	we will use A Employee and A Addresss class to define it's address.

	Since Address can contain many attributes. thats why we will use it as diffent class.
*/


class Address{

	String country;
	String state;
	String city;
	String town;
	String street;
	int plotNo;
	int pincode;

	Address(String country, String state, String city, String town, String street, int plotNo, int pincode){

		this.country = country;
		this.state = state;
		this.city = city;
		this.town = town;
		this.street = street;
		this.plotNo = plotNo;
		this.pincode = pincode;
	}

	String getAddress(){

		return this.plotNo +" "+ this.street + " "+ this.town + " "+ this.city + " " + this.state+ " "+ this.country + ", Pincode " + this.pincode;
	}

}

class Employee{

	int id;
	String name;
	Address address;

	Employee(int id, String name, Address address){

		this.id = id;
		this.name  = name;
		this.address = address;
	}

	void display(){

		System.out.println("id: "+ this.id);
		System.out.println("name: "+ this.name);
		System.out.println("address: "+ address.getAddress());
	}
}


// Now we will use the Employee class to create some employee

class Main{

	public static void main(String args[]){

		Employee emp1 = new Employee(101, "Manish Kumar",
			new Address("India", "Rajasthan", "Jaipur", "Jagatpura", "luniwas", 21, 302017));

		emp1.display();
	}

}


/*
Output:
	id: 101                                                                                
	name: Manish Kumar                                                                     
	address: 21 luniwas Jagatpura Jaipur Rajasthan India, Pincode 302017  


Note: in this Address instance created inside the Employee which has the HAS-A Relationship
and it is called Aggreagation.
*/