import java.util.ArrayList;
import java.util.Scanner;

interface Department {
    static String deptName = null;
    static String deptHead = null;

    void printDepartmentDetails();
}

class Hostel {
    String hostelName;
    String hostelLocation;
    int numberOfRooms;

    public void getHostelDetails(String name, String location, int rooms) {
        this.hostelName = name;
        this.hostelLocation = location;
        this.numberOfRooms = rooms;
    }

    public void printHostelDetails() {
        System.out.println("Hostel Name: " + hostelName);
        System.out.println("Hostel Location: " + hostelLocation);
        System.out.println("Number of Rooms: " + numberOfRooms);
    }
}

class Student extends Hostel implements Department {
    String studentName;
    int regdNo;
    String electiveSubject;
    double avgMarks;

    public void getDepartmentDetails(String deptName, String deptHead) {
        this.deptName = deptName;
        this.deptHead = deptHead;
    }

    public void getStudentDetails(String studentName, int regdNo, String electiveSubject, double avgMarks) {
        this.studentName = studentName;
        this.regdNo = regdNo;
        this.electiveSubject = electiveSubject;
        this.avgMarks = avgMarks;
    }

    public void printDepartmentDetails() {
        System.out.println("Department Name: " + deptName);
        System.out.println("Department Head: " + deptHead);
    }

    public void printStudentDetails() {
        System.out.println("Student Name: " + studentName);
        System.out.println("Registration Number: " + regdNo);
        System.out.println("Elective Subject: " + electiveSubject);
        System.out.println("Average Marks: " + avgMarks);
    }
}
 
public class Driver {
    public static void main(String[] args) {
        ArrayList<Student> students = new ArrayList<Student>();
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Admit new student");
            System.out.println("2. Migrate a student");
            System.out.println("3. Display the details of a student");
            System.out.print("\nEnter your choice: ");
            int choice = sc.nextInt();

            if (choice == 1) {
                Student student = new Student();
                sc.nextLine();

                System.out.print("\nEnter Hostel Name: ");
                String hostelName = sc.nextLine();
                System.out.print("Enter Hostel Location: ");
                String hostelLocation = sc.nextLine();
                System.out.print("Enter Number of Rooms: ");
                int numberOfRooms = sc.nextInt();
                student.getHostelDetails(hostelName, hostelLocation, numberOfRooms);

                sc.nextLine();
                System.out.print("\nEnter Department Name: ");
                String deptName = sc.nextLine();
                System.out.print("Enter Department Head: ");
                String deptHead = sc.nextLine();
                student.getDepartmentDetails(deptName, deptHead);

                System.out.print("\nEnter Student Name: ");
                String studentName = sc.nextLine();
                System.out.print("Enter Registration Number: ");
                int regdNo = sc.nextInt();
                sc.nextLine();
                System.out.print("Enter Elective Subject: ");
                String electiveSubject = sc.nextLine();
                System.out.print("Enter Average Marks: ");
                double avgMarks = sc.nextDouble();
                student.getStudentDetails(studentName, regdNo, electiveSubject, avgMarks);

                students.add(student);
            } else if (choice == 2) {
                System.out.print("\nEnter the Registration Number of the student to be migrated: ");
                int regdNo = sc.nextInt();

                for (int i = 0; i < students.size(); i++) {
                    if (students.get(i).regdNo == regdNo) {
                        students.remove(i);
                        break;
                    }
                }
            } else if (choice == 3) {
                System.out.print("\nEnter the Registration Number of the student to be displayed: ");
                int regdNo = sc.nextInt();

                for (int i = 0; i < students.size(); i++) {
                    if (students.get(i).regdNo == regdNo) {
                        students.get(i).printHostelDetails();
                        students.get(i).printDepartmentDetails();
                        students.get(i).printStudentDetails();
                        break;
                    }
                }
            } else {
                break;
            }
        }
    }
}
