#include<iostream>
using namespace std;

int x = 100;

void create(int arr[], int &n)
{
    cout << "Enter number of elements: ";
    cin >> n;
    cout<<"Enter "<<n<<"elements : ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
}

void display(int arr[], int n)
{
    cout<<"Elements are : ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
        }
        cout <<"\n";
}

void insert(int arr[], int &n)
{
    if (n==x)
    {
        cout<<"Array is full\n";
        return;
    }
    
    int element, pos;
    cout << "Enter element to insert: ";
    cin >> element;
    cout << "Enter position to insert element (0-based index): ";
    cin >> pos;

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    n++;
    cout<<"Element inserted\n";
}

void delete_element(int arr[], int &n)
{
    if (n == 0) {
        cout << "Array is empty. Nothing to delete.\n";
        return;
    }
    int pos;
    cout << "Enter position of element to delete (0-based index): ";
    cin >> pos;
     int deleted = arr[pos];
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element " << deleted << " deleted from position " << pos << ".\n";
}

void linear_search(int arr[], int n)
{
     int element;
    cout << "Enter element to search: ";
    cin >> element;
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            cout << "Element " << element << " found at position " << i << ".\n";
            return;
        }
        else cout << "Element not found.\n";
    }
}

int main() {
    int arr[x];
    int n = 0;
    
    int choice;
    do {
        cout << "\n——————MENU——————\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create(arr, n);
                break;
            case 2:
                display(arr, n);
                break;
            case 3:
                insert(arr, n);
                break;
            case 4:
                delete_element(arr, n);
                break;
            case 5:
                linear_search(arr, n);
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}