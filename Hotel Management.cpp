#include <iostream>
#include <string>
using namespace std;

struct Room {
    int number;
    string bookingName;
    int price;
    bool isBooked;
};

int main() {
    const int TOTAL_ROOMS = 10;
    Room hotel[TOTAL_ROOMS];
    // Initialize rooms
    for (int i = 0; i < TOTAL_ROOMS; ++i) {
        hotel[i].number = i + 1;
        //Example Pricing
        hotel[i].price = 100 + i * 10; 
        hotel[i].isBooked = false;
    }

    int choice;
    do {
        cout << "\n----- Hotel Management System -----\n";
        cout << "1. View Rooms\n2. Book Room\n3. Cancel Booking\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < TOTAL_ROOMS; ++i) {
                cout << "Room " << hotel[i].number 
                     << " -- " << (hotel[i].isBooked ? "Booked" : "Available")
                     << " -- Price: " << hotel[i].price << "\n";
            }
        }
        else if (choice == 2) {
            int rnum;
            string name;
            cout << "Enter room number to book: ";
            cin >> rnum;
            cout << "Enter booking name: ";
            cin >> name;

            if (rnum < 1 || rnum > TOTAL_ROOMS) {
                cout << "Invalid room number.\n";
            }
            else if (hotel[rnum - 1].isBooked) {
                cout << "Room already booked.\n";
            }
            else {
                hotel[rnum - 1].isBooked = true;
                hotel[rnum - 1].bookingName = name;
                cout << "Room " << rnum << " booked under " << name << ".\n";
            }
        }
        else if (choice == 3) {
            int rnum;
            cout << "Enter room number to cancel: ";
            cin >> rnum;

            if (rnum < 1 || rnum > TOTAL_ROOMS) {
                cout << "Invalid room number.\n";
            }
            else if (!hotel[rnum - 1].isBooked) {
                cout << "Room is not booked.\n";
            }
            else {
                hotel[rnum - 1].isBooked = false;
                hotel[rnum - 1].bookingName = "";
                cout << "Booking canceled for room " << rnum << ".\n";
            }
        }
        else if (choice != 4) {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    cout << "Goodbye!\n";
    return 0;
}
