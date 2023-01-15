import java.util.Scanner;

public class tutorsession {

    private String student_name; 
    private String tutor_name; 
    private int cost; // Cost of the tutoring session 

    tutorsession(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the name of the tutor: ");
        this.tutor_name = scan.nextLine();

        System.out.println("Enter the name of the student: ");
        this.student_name = scan.nextLine();

        System.out.println("Enter the cost of the tutoring session: ");
        this.cost = scan.nextInt();

        // Function to set the student name 
        void setStudentName(String student_name){
            this.student_name = student_name;
        }

        // Function to get the student name 
        String getStudentName(){
            return student_name;
        }

        // Function to set the tutor name 
        void setTutorName(String tutor_name){
            this.tutor_name = tutor_name;
        }

        // Function to get the tutor name 
        String getTutorName(){
            return tutor_name;
        }

        // Function to set the cost of the tutoring session
        void setCost(int cost){
            this.cost = cost;
        }

        // Function to get the cost of the tutoring session 
        String getCost(){
            return cost;
        }
    }
    
}
