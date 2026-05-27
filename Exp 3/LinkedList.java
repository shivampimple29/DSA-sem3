public class LinkedList {

    // Node class represents an individual element in the linked list
    static class Node {
        int data;
        Node next;

        // Constructor for Node
        Node(int d) {
            data = d;
            next = null;
        }
    }

    // 'head' is the starting point of the linked list
    Node head; // Default initialized to null

    // 1. Method to create a list (insertion at the end/append)
    public void createList(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
        } else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
        System.out.println("Value " + data + " added to the list.");
    }

    // 2. Method for insertion at the beginning
    public void insertBegin(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
        System.out.println("Value " + data + " inserted at the beginning.");
    }

    // 3. Method for insertion in between (at a specific 1-based position)
    public void insertBetween(int data, int position) {
        if (position < 1) {
            System.out.println("Invalid position. Position must be 1 or greater.");
            return;
        }

        Node newNode = new Node(data);

        if (position == 1) { // Insert at the beginning
            newNode.next = head;
            head = newNode;
            System.out.println("Value " + data + " inserted at position " + position + ".");
            return;
        }

        Node current = head;
        for (int i = 1; i < position - 1 && current != null; i++) {
            current = current.next;
        }

        if (current == null) {
            System.out.println("Position " + position + " is beyond the end of the list. Insertion failed.");
        } else {
            newNode.next = current.next;
            current.next = newNode;
            System.out.println("Value " + data + " inserted at position " + position + ".");
        }
    }

    // 4. Method for deletion at the end
    public void deleteEnd() {
        if (head == null) {
            System.out.println("List is EMPTY (UNDERFLOW). Cannot delete from end.");
            return;
        }
        if (head.next == null) { // Only one node in the list
            System.out.println("Deleted node is " + head.data);
            head = null;
            return;
        }
        Node current = head;
        Node previous = null;
        while (current.next != null) {
            previous = current;
            current = current.next;
        }
        System.out.println("Deleted node is " + current.data);
        previous.next = null;
    }

    // 5. Method for deletion at the beginning
    public void deleteBegin() {
        if (head == null) {
            System.out.println("List is EMPTY (UNDERFLOW). Cannot delete from beginning.");
            return;
        }
        int deletedData = head.data;
        head = head.next;
        System.out.println("Deleted node is " + deletedData);
    }

    // 6. Method for deletion at a specific 1-based position
    public void deleteBetween(int position) {
        if (head == null) {
            System.out.println("List is EMPTY (UNDERFLOW). Cannot delete.");
            return;
        }

        if (position < 1) {
            System.out.println("Invalid position. Position must be 1 or greater.");
            return;
        }

        if (position == 1) { // Delete from the beginning
            deleteBegin();
            return;
        }

        Node current = head;
        Node previous = null;
        for (int i = 1; i < position && current != null; i++) {
            previous = current;
            current = current.next;
        }

        if (current == null) {
            System.out.println("Position " + position + " is beyond the end of the list. Deletion failed.");
        } else {
            System.out.println("Deleted node is " + current.data + " from position " + position + ".");
            previous.next = current.next;
        }
    }

    // 7. Method to search a given value in the list
    public void search(int data) {
        int position = 0;
        Node current = head;
        if (head == null) {
            System.out.println("List is EMPTY. Cannot search.");
            return;
        }
        while (current != null) {
            position++;
            if (current.data == data) {
                System.out.println("Value " + data + " found at position " + position + ".");
                return;
            }
            current = current.next;
        }
        System.out.println("Value " + data + " not found in the list.");
    }

    // 8. Method to count total nodes in the list
    public int countNodes() { // Changed to return int, more useful
        int count = 0;
        Node current = head;
        while (current != null) {
            count++;
            current = current.next;
        }
        System.out.println("Total number of nodes in the list: " + count);
        return count; // Returning the count
    }

    // 9. Method to display the contents of the list
    public void display() {
        if (head == null) {
            System.out.println("\nList is EMPTY (UNDERFLOW)");
            return;
        }
        Node current = head;
        int i = 1;
        System.out.println("\n--- Current List Content ---");
        while (current != null) {
            System.out.println("Node " + i + " value is : " + current.data);
            current = current.next;
            i++;
        }
        System.out.println("---------------------------\n");
    }

    // Main method to test the LinkedList operations
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int choice, n, val, pos;

        while (true) {
            System.out.println("\nList of Choices : ");
            System.out.println("1.  Create a List (insertion at the end/append)");
            System.out.println("2.  Insertion at the beginning");
            System.out.println("3.  Insertion in between (at a specific position)");
            System.out.println("4.  Deletion at the end");
            System.out.println("5.  Deletion at the beginning");
            System.out.println("6.  Deletion at index/before/after");
            System.out.println("7.  Search a given value in the list");
            System.out.println("8.  Count total nodes in the list");
            System.out.println("9.  Display the contents of the list");
            System.out.println("10. Quit");
            System.out.print("\nEnter a choice :");

            if (scanner.hasNextInt()) {
                choice = scanner.nextInt();
            } else {
                System.out.println("Invalid input. Please enter a number.");
                scanner.next(); // Consume the invalid input
                continue;
            }

            switch (choice) {
                case 1:
                    System.out.print("\nEnter number of nodes for the linked list : ");
                    if (scanner.hasNextInt()) {
                        n = scanner.nextInt();
                        for (int i = 0; i < n; i++) {
                            System.out.print("Enter the value to be added to the node " + (i + 1) + ": ");
                            if (scanner.hasNextInt()) {
                                val = scanner.nextInt();
                                list.createList(val);
                            } else {
                                System.out.println("Invalid input. Please enter an integer.");
                                scanner.next();
                                i--; // Decrement i to re-enter value for current node
                            }
                        }
                    } else {
                        System.out.println("Invalid input. Please enter a number.");
                        scanner.next();
                    }
                    break;

                case 2:
                    System.out.print("\nEnter the value to be inserted at the beginning: ");
                    if (scanner.hasNextInt()) {
                        val = scanner.nextInt();
                        list.insertBegin(val);
                    } else {
                        System.out.println("Invalid input. Please enter an integer.");
                        scanner.next();
                    }
                    break;

                case 3:
                    System.out.print("\nEnter the value to be inserted: ");
                    if (scanner.hasNextInt()) {
                        val = scanner.nextInt();
                        System.out.print("Enter the position to insert (1-based): ");
                        if (scanner.hasNextInt()) {
                            pos = scanner.nextInt();
                            list.insertBetween(val, pos);
                        } else {
                            System.out.println("Invalid input for position. Please enter an integer.");
                            scanner.next();
                        }
                    } else {
                        System.out.println("Invalid input for value. Please enter an integer.");
                        scanner.next();
                    }
                    break;

                case 4:
                    list.deleteEnd();
                    break;

                case 5:
                    list.deleteBegin();
                    break;

                case 6:
                    System.out.print("\nEnter the position to delete (1-based): ");
                    if (scanner.hasNextInt()) {
                        pos = scanner.nextInt();
                        list.deleteBetween(pos);
                    } else {
                        System.out.println("Invalid input for position. Please enter an integer.");
                        scanner.next();
                    }
                    break;

                case 7:
                    System.out.print("\nEnter the value to search: ");
                    if (scanner.hasNextInt()) {
                        val = scanner.nextInt();
                        list.search(val);
                    } else {
                        System.out.println("Invalid input. Please enter an integer.");
                        scanner.next();
                    }
                    break;

                case 8:
                    list.countNodes();
                    break;

                case 9:
                    list.display();
                    break;

                case 10:
                    System.out.println("Exiting program.");
                    scanner.close(); // Close the scanner
                    return;

                default:
                    System.out.println("\nInvalid choice\n");
                    break;
            }
        }
    }
}
