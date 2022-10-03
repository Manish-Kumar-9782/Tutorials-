class Student {

	String name;
	int age;
	double height;

	Student(String name, int age, double height) {

		this.name = name;
		this.age = age;
		this.height = height;
	}

	public void display() {
		//
		System.out.println("Name: \t" + this.name);
		System.out.println("Age: \t" + this.age);
		System.out.println("Height: \t" + this.height);
	}

};

public class Main {

	public static void main(String[] args) {
		// here we need to perform some action on the student
		System.out.println("Hello world");

		Student st = new Student("komal", 21, 5.6);

		st.display();
	}
}