class Employee {
   String name;
   
   //getter method
   String get emp_name {
      return name;
   }
   //setter method
   void set emp_name(String name) {
      this.name = name;
   }
   //function definition
   void result() {
      print(name);
   }
}
void main() {
   //object creation
   Employee emp = new Employee();
   emp.name = "employee1";
   emp.result(); //function call
}
