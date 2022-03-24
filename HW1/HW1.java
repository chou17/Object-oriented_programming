import java.io.*;
import java.util.Scanner;

public class HW1 {
    public static void main(String args[]) throws IOException {
        double length1 = 0.0;
        double length2 = 0.0;
        double length3 = 0.0;

        double semiperimeter = 0.0;
        double area = 0.0;
        double result = 0.0;

        int n = 1;

        Scanner scanner = new Scanner(System.in);
        try (FileWriter writer = new FileWriter("java_result.txt")) {
            while (true) {
                System.out.print("Please enter the lengths of the triangle:");
                length1 = scanner.nextInt();
                length2 = scanner.nextInt();
                length3 = scanner.nextInt();

                if (length1 == -1 && length2 == -1 && length3 == -1) {
                    break;
                } else if ((length1 <= 0 || length2 <= 0 || length3 <= 0) || !(length1 + length2 > length3
                        && length2 + length3 > length1 && length3 + length1 > length2)) {
                    System.out.println("The input is not legal.");
                    writer.write("Question " + (n++) + " inputs are, length1 = " + length1 + ", length2 = " + length2
                            + ", length3 = " + length3 + ". The input is not legal.\r\n");
                    continue;
                }
                semiperimeter = ((length1 + length2 + length3) / 2);
                area = Math.sqrt(semiperimeter * (semiperimeter - length1) * (semiperimeter - length2)
                        * (semiperimeter - length3));
                result = Math.round(area * 10000.0) / 10000.0;
                System.out.println("The area of this triangle is: " + result);
                writer.write("Question " + (n++) + " inputs are, length1 = " + length1 + ", length2 = " + length2
                        + ", length3 = " + length3 + ". The area of this triangle is " + result + ".\r\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
