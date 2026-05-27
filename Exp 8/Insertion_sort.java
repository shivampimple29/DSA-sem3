import java.util.Scanner;

public class Insertion_sort {
    public static void insert(int a[], int n) {
        Scanner sc = new Scanner(System.in);
        System.out.println();
        for (int i = 0; i < n; i++) {
            System.out.print("element " + (i + 1) + " :");
            a[i] = sc.nextInt();
        }
        sc.close();
    }

    public static void display(int a[], int n) {

        System.out.println();
        for (int i = 0; i < n; i++) {
            System.out.println("element " + (i + 1) + " :" + a[i]);
        }
    }

    // time complexity : O(n^2)
    public static void I_sort(int a[], int n) {

        int curr, prev;

        for (int i = 1; i < n; i++) {
            curr = a[i];
            prev = i - 1;

            while (prev >= 0 && a[prev] > curr) {

                a[prev + 1] = a[prev];
                prev--;
            }
            a[prev + 1] = curr;

        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of array elements :");
        int num = sc.nextInt();
        int arr1[] = new int[num];
        insert(arr1, num);
        System.out.println("\narray before Insertion sorting : ");
        display(arr1, num);
        System.out.println("\narray after Insertion sorting    : ");
        I_sort(arr1, num);
        display(arr1, num);
        sc.close();
    }
}
