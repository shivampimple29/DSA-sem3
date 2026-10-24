import java.util.*;

public class Search {

    static int a[] = new int[5];
    static Scanner sc = new Scanner(System.in);

    public static void insert() {

        System.out.println("\n---------------Insertion---------------");
        System.out.println("\nEnter the array elements :");
        for (int i = 0; i < a.length; i++) {
            System.out.print("Element " + i + " :");
            a[i] = sc.nextInt();
        }
    }

    public static void disp() {

        System.out.println("\n---------------Display---------------\n");
        System.out.println("Entered elements are :\n");
        System.out.println();
        for (int i = 0; i < a.length; i++) {
            System.out.println("Element " + i + " : " + a[i]);
        }
        System.out.println();
    }

    public static void linear_search(int key) {
        int flag = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i] == key) {
                System.out.println(key + " is found at index " + i);
                flag++;
            }
        }
        if (flag == 0) {
            System.out.println(key + " is not present in the given array");
        }
    }

    public static void binary_search(int beg, int end, int key) {

        if (beg <= end) {
            int mid = (beg + end) / 2;

            if (a[mid] == key) {
                System.out.println(key + " is found at index " + mid);
                return;
            }

            else if (a[mid] < key) {
                binary_search(mid + 1, end, key);
            }

            else {
                binary_search(beg, mid - 1, key);
            }
        } else {
            System.out.println(key + " is not present in the given array");
        }
    }

    public static void main(String[] args) {

        insert();
        disp();

        int beg = 0;
        int end = a.length - 1;

        while (true) {
            System.out.println("\n-------------------MENU-------------------");
            System.out.println("1.Linear Search");
            System.out.println("2.Binary Search");
            System.out.println("3.Quit");
            System.out.print("\nEnter a option :");
            int option = sc.nextInt();
            int key;
            switch (option) {

                case 1:
                    System.out.print("Enter the element to search :");
                    key = sc.nextInt();
                    System.out.println("\n---------------Linear Search---------------\n");
                    linear_search(key);
                    break;

                case 2:
                    System.out.print("Enter the element to search :");
                    key = sc.nextInt();
                    System.out.println("\n---------------Binary Search---------------\n");
                    binary_search(beg, end, key);
                    break;

                case 3:
                    System.out.println("Ending the program...\n");
                    return;

                default:
                    System.out.println("INVALID INPUT ! Please enter a valid option.");
                    break;
            }
        }
    }
}