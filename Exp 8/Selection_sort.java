
import java.util.Scanner;

public class Selection_sort {

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
    public static void S_sort(int a[], int n) {

        for (int i = 0; i < a.length - 1; i++) {
            int min = i;
            for (int j = i + 1; j < a.length; j++) {
                if (a[min] > a[j]) {
                    min = j;
                }
            }
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of array elements :");
        int num = sc.nextInt();
        int arr1[] = new int[num];
        insert(arr1, num);
        System.out.println("\narray before Selection sorting : ");
        display(arr1, num);
        System.out.println("\narray after Selection sorting    : ");
        S_sort(arr1, num);
        display(arr1, num);
        sc.close();
    }
}
