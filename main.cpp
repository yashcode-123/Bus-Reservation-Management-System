
#include <iostream>
#include <string>
#include<fstream>
using namespace std;


/*
    BUS RESERVATION MANAGEMENT SYSTEM
    Group No.: 13

    Concepts Used:
    - Classes and Objects
    - Inheritance
    - Abstract Class
    - Pure Virtual Function
    - Virtual Function
    - Runtime Polymorphism
    - Arrays
    - Functions
    - Strings
*/

// ============================================================
// ABSTRACT BASE CLASS : BUS
// ============================================================

class Bus
{
protected:
    int busNo;
    string route;
    int totalSeats;

public:
    Bus()
    {
        busNo = 0;
        route = "";
        totalSeats = 0;
    }

    // Pure virtual function
    virtual string getBusType() = 0;

    void displayBusDetails()
    {
        cout << "Bus Number  : " << busNo << endl;
        cout << "Route       : " << route << endl;
        cout << "Bus Type    : " << getBusType() << endl;
        cout << "Total Seats : " << totalSeats << endl;
    }

    int getBusNo()
    {
        return busNo;
    }

    string getRoute()
    {
        return route;
    }

    int getTotalSeats()
    {
        return totalSeats;
    }
};


// ============================================================
// DERIVED CLASS : AC BUS
// ============================================================

class ACBus : public Bus
{
public:

    ACBus()
    {
        busNo = 101;
        route = "Miraj to Pune";
        totalSeats = 40;
    }

    string getBusType()
    {
        return "AC Bus";
    }
};


// ============================================================
// DERIVED CLASS : SLEEPER BUS
// ============================================================

class SleeperBus : public Bus
{
public:

    SleeperBus()
    {
        busNo = 102;
        route = "Miraj to Mumbai";
        totalSeats = 30;
    }

    string getBusType()
    {
        return "Sleeper Bus";
    }
};


// ============================================================
// RESERVATION CLASS
// ============================================================

class Reservation
{
private:
    int reservationId;
    string passengerName;
    int passengerAge;

    int busNo;
    string route;
    string busType;

    int seatNo;

public:

    Reservation()
    {
        reservationId = 0;
        passengerName = "";
        passengerAge = 0;

        busNo = 0;
        route = "";
        busType = "";

        seatNo = 0;
    }


    // Accept reservation details
    void inputReservation(int id, Bus *bus, int seat)
    {
        reservationId = id;

        cout << "\nEnter Passenger Name : ";
        cin >> ws;
        getline(cin, passengerName);

        cout << "Enter Passenger Age  : ";
        cin >> passengerAge;

        busNo = bus->getBusNo();
        route = bus->getRoute();
        busType = bus->getBusType();

        seatNo = seat;
    }


    // Display reservation
    void displayReservation()
    {
        cout << "\n----------------------------------------" << endl;
        cout << "       RESERVATION DETAILS" << endl;
        cout << "----------------------------------------" << endl;

        cout << "Reservation ID : " << reservationId << endl;
        cout << "Passenger Name : " << passengerName << endl;
        cout << "Passenger Age  : " << passengerAge << endl;
        cout << "Bus Number     : " << busNo << endl;
        cout << "Bus Type       : " << busType << endl;
        cout << "Route          : " << route << endl;
        cout << "Seat Number    : " << seatNo << endl;

        cout << "----------------------------------------" << endl;
    }


    // Modify passenger details
    bool modifyPassengerDetails()
    {
        int choice;

        cout << "\n1. Modify Passenger Name";
        cout << "\n2. Modify Passenger Age";
        cout << "\n3. Modify Both";
        cout << "\nEnter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter New Passenger Name: ";
            cin >> ws;
            getline(cin, passengerName);
        }
        else if (choice == 2)
        {
            cout << "Enter New Passenger Age: ";
            cin >> passengerAge;
        }
        else if (choice == 3)
        {
            cout << "Enter New Passenger Name: ";
            cin >> ws;
            getline(cin, passengerName);

            cout << "Enter New Passenger Age: ";
            cin >> passengerAge;
        }
        else
        {
            cout << "\nInvalid choice." << endl;
            return false;
        }
         return true;
    }


    // Change seat
    void modifySeat(int newSeat)
    {
        seatNo = newSeat;
    }


    int getReservationId()
    {
        return reservationId;
    }

    //===============================================
    //          WRITE RESERVATIONS TO FILE
    //===============================================

    void saveToFile(ofstream &file)
    {
      file << reservationId << endl;
      file << passengerName << endl;
      file << passengerAge << endl;
      file << busNo << endl;
      file << route << endl;
      file << busType << endl;
      file << seatNo << endl;
    }

    //----------------------------------------------
    //       READ RESERVATIONS FROM FILE
    //----------------------------------------------

    bool readFromFile(ifstream & file)
    {
      if(!(file >> reservationId))
      { 
        return false;

      }
      file.ignore();

      getline(file,passengerName);

      file >> passengerAge;
      file.ignore();

      file >> busNo;
      file.ignore();

      getline(file, route);

      getline(file, busType);

      file >> seatNo;
      file.ignore();

      return true;
    }


    int getSeatNo()
    {
        return seatNo;
    }

    int getBusNo()
    {
        return busNo;
    }

    string getPassengerName()
    {
        return passengerName;
    }
};


// ============================================================
// RESERVATION SYSTEM CLASS
// ============================================================

class ReservationSystem
{
private:

    Reservation reservations[100];

    int count;
    int nextReservationId;


public:

    ReservationSystem()
    {
        count = 0;
        nextReservationId = 1001;
        loadReservations();
    }


    // ========================================================
    // DISPLAY AVAILABLE BUSES
    // ========================================================

    void displayAvailableBuses()
    {
        ACBus acBus;
        SleeperBus sleeperBus;

        cout << "\n==================================================" << endl;
        cout << "              AVAILABLE BUSES" << endl;
        cout << "==================================================" << endl;

        cout << "\n[1] AC BUS" << endl;
        acBus.displayBusDetails();

        cout << "\n[2] SLEEPER BUS" << endl;
        sleeperBus.displayBusDetails();

        cout << "\n==================================================" << endl;
    }


    // ========================================================
    // CHECK WHETHER SEAT IS ALREADY BOOKED
    // ========================================================

    bool isSeatBooked(int busNumber, int seatNumber)
    {
        for (int i = 0; i < count; i++)
        {
            if (reservations[i].getBusNo() == busNumber &&
                reservations[i].getSeatNo() == seatNumber)
            {
                return true;
            }
        }

        return false;
    }


    // Check seat availability while modifying reservation
    bool isSeatBookedExcept(int busNumber, int seatNumber, int currentId)
    {
        for (int i = 0; i < count; i++)
        {
            if (reservations[i].getBusNo() == busNumber &&
                reservations[i].getSeatNo() == seatNumber &&
                reservations[i].getReservationId() != currentId)
            {
                return true;
            }
        }

        return false;
    }


    // ========================================================
    // BOOK RESERVATION
    // ========================================================

    void bookReservation()
    {
        if (count >= 100)
        {
            cout << "\nReservation limit reached." << endl;
            return;
        }

        ACBus acBus;
        SleeperBus sleeperBus;

        Bus *selectedBus = NULL;

        int busChoice;

        displayAvailableBuses();

        cout << "\nSelect Bus: ";
        cin >> busChoice;

        if (busChoice == 1)
        {
            selectedBus = &acBus;
        }
        else if (busChoice == 2)
        {
            selectedBus = &sleeperBus;
        }
        else
        {
            cout << "\nInvalid bus choice." << endl;
            return;
        }


        int seatNumber;

        cout << "\nEnter Seat Number (1-" 
             << selectedBus->getTotalSeats() << "): ";

        cin >> seatNumber;


        // Check valid seat number
        if (seatNumber < 1 || seatNumber > selectedBus->getTotalSeats())
        {
            cout << "\nInvalid seat number." << endl;
            return;
        }


        // Check whether seat is already booked
        if (isSeatBooked(selectedBus->getBusNo(), seatNumber))
        {
            cout << "\nSORRY! THIS SEAT IS AREADY BOOKED!." << endl;
            return;
        }


        // Store reservation
        reservations[count].inputReservation(
            nextReservationId,
            selectedBus,
            seatNumber
        );

        cout << "\n==================================================" << endl;
        cout << "       RESERVATION BOOKED SUCCESSFULLY!" << endl;
        cout << "==================================================" << endl;

        cout << "Reservation ID : " << nextReservationId << endl;
        cout << "Seat Number    : " << seatNumber << endl;
        cout << "Bus Number     : " << selectedBus->getBusNo() << endl;

        count++;
        nextReservationId++;

        saveAllReservations();

        cout << "==================================================" << endl;
    }


    // ========================================================
    // SEARCH RESERVATION
    // ========================================================

    void searchReservation()
    {
        if (count == 0)
        {
            cout << "\nNo reservations available." << endl;
            return;
        }

        int id;

        cout << "\nEnter Reservation ID: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (reservations[i].getReservationId() == id)
            {
                reservations[i].displayReservation();
                return;
            }
        }

        cout << "\nReservation not found." << endl;
    }


    // ========================================================
    // DISPLAY ALL RESERVATIONS
    // ========================================================

    void displayAllReservations()
    {
        if (count == 0)
        {
            cout << "\nNo reservations available." << endl;
            return;
        }

        cout << "\n==================================================" << endl;
        cout << "             ALL RESERVATIONS" << endl;
        cout << "==================================================" << endl;

        for (int i = 0; i < count; i++)
        {
            reservations[i].displayReservation();
        }
    }


    // ========================================================
    // MODIFY RESERVATION
    // ========================================================

    void modifyReservation()
    {
        if (count == 0)
        {
            cout << "\nNo reservations available." << endl;
            return;
        }

        int id;

        cout << "\nEnter Reservation ID: ";
        cin >> id;


        for (int i = 0; i < count; i++)
        {
            if (reservations[i].getReservationId() == id)
            {
                int choice;

                cout << "\n----------------------------------------" << endl;
                cout << "        MODIFY RESERVATION" << endl;
                cout << "----------------------------------------" << endl;

                cout << "1. Modify Passenger Details" << endl;
                cout << "2. Modify Seat Number" << endl;
                cout << "3. Modify Both" << endl;

                cout << "\nEnter Choice: ";
                cin >> choice;


                // Modify passenger details
                if (choice == 1)
                {
                    if(reservations[i].modifyPassengerDetails());
                   {
                    saveAllReservations();

                    cout << "\nPassenger details updated successfully.....!" << endl;
                   }
                }


                // Modify seat
                else if (choice == 2)
                {
                    int newSeat;

                    cout << "\nEnter New Seat Number: ";
                    cin >> newSeat;

                    // Check seat range
                    int maximumSeats;

                    if (reservations[i].getBusNo() == 101)
                    {
                        maximumSeats = 50;
                    }
                    else
                    {
                        maximumSeats = 40;
                    }


                    if (newSeat < 1 || newSeat > maximumSeats)
                    {
                        cout << "\nInvalid seat number." << endl;
                        return;
                    }


                    // Check availability
                    if (isSeatBookedExcept(
                        reservations[i].getBusNo(),
                            newSeat,
                            reservations[i].getReservationId()))
                    {
                        cout << "\nSorry! This seat is already booked." << endl;
                        return;
                    }


                    reservations[i].modifySeat(newSeat);

                    saveAllReservations();

                    cout << "\nSeat number updated successfully." << endl;
                }


                // Modify both
                else if (choice == 3)
                {
                    if(! reservations[i].modifyPassengerDetails());
                    {
                        return;
                    }
                    int newSeat;

                    cout << "\nEnter New Seat Number: ";
                    cin >> newSeat;


                    int maximumSeats;

                    if (reservations[i].getBusNo() == 101)
                    {
                        maximumSeats = 40;
                    }
                    else
                    {
                        maximumSeats = 30;
                    }


                    if (newSeat < 1 || newSeat > maximumSeats)
                    {
                        cout << "\nInvalid seat number." << endl;
                        return;
                    }


                    if (isSeatBookedExcept(
                            reservations[i].getBusNo(),
                            newSeat,
                            reservations[i].getReservationId()))
                    {
                        cout << "\nSorry! This seat is already booked." << endl;
                        return;
                    }


                    reservations[i].modifySeat(newSeat);

                    saveAllReservations();

                    cout << "\nReservation updated successfully." << endl;
                }

                else
                {
                    cout << "\nInvalid choice." << endl;
                }

                return;
            }
        }

        cout << "\nReservation not found." << endl;
    }


    // ========================================================
    // CANCEL RESERVATION
    // ========================================================

    void cancelReservation()
    {
        if (count == 0)
        {
            cout << "\nNo reservations available." << endl;
            return;
        }

        int id;

        cout << "\nEnter Reservation ID to cancel: ";
        cin >> id;


        for (int i = 0; i < count; i++)
        {
            if (reservations[i].getReservationId() == id)
            {
                // Shift remaining reservations
                for (int j = i; j < count - 1; j++)
                {
                    reservations[j] = reservations[j + 1];
                }

                count--;

                saveAllReservations();

                cout << "\n==================================================" << endl;
                cout << "       RESERVATION CANCELLED SUCCESSFULLY!" << endl;
                cout << "==================================================" << endl;

                return;
            }
        }

        cout << "\nReservation not found." << endl;
    }
   
    //=======================================================
    //      SAVE ALL RESERVATIONS TO FILE
    //=======================================================

    void saveAllReservations()
    {
        ofstream file;

        file.open("reservations.txt");

        if(!file.is_open())
        {
            cout<<"\n Error opening reservations.txt !!"<<endl;
            return;
        }
        cout<<"saving reservations......."<<endl;
        for(int i=0; i< count ; i++)
        {
            reservations[i].saveToFile(file);
        }
        file.flush();
        file.close();
        cout<<"[ FILE SAVED SUCCESSFULLY.....!]"<<endl;
    }

    //========================================================
    //       LOAD RESERVATIONS FROM FILE
    //=======================================================
    void loadReservations()
    {
        ifstream file;

        file.open("reservations.txt");

        if(!file)
        {
           return;
        }

        count = 0;
        while(count<100 && reservations[count].readFromFile(file))
        {
            count++;
        }
        file.close();

        //set next reservation ID

        nextReservationId = 1001;
        for(int i=0; i<count ;i++)
        {
            if(reservations[i].getReservationId() >= nextReservationId)
            {
                nextReservationId = reservations[i].getReservationId()+1;
            }
        }
    }

    // ========================================================
    // MAIN MENU
    // ========================================================

    void menu()
    {
        int choice;

        do
        {
            cout << "\n\n";
            cout << "==========================================================" << endl;
            cout << "            BUS RESERVATION MANAGEMENT SYSTEM" << endl;
            cout << "==========================================================" << endl;

            cout << "\n\t1. Display Available Buses";
            cout << "\n\t2. Book Reservation";
            cout << "\n\t3. Search Reservation";
            cout << "\n\t4. Display All Reservations";
            cout << "\n\t5. Modify Reservation";
            cout << "\n\t6. Cancel Reservation";
            cout << "\n\t7. Exit";

            cout << "\n\nEnter your choice: ";
            cin >> choice;


            switch (choice)
            {
                case 1:
                    displayAvailableBuses();
                    break;

                case 2:
                    bookReservation();
                    break;

                case 3:
                    searchReservation();
                    break;

                case 4:
                    displayAllReservations();
                    break;

                case 5:
                    modifyReservation();
                    break;

                case 6:
                    cancelReservation();
                    break;

                case 7:
                    cout << "\nThank you for using Bus Reservation Management System!" << endl;
                    break;

                default:
                    cout << "\nInvalid choice. Please try again." << endl;
            }

        } while (choice != 7);
    }
};


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    ReservationSystem system;

    system.menu();

    return 0;
}



//g++ main.cpp -o BUSRESERVATION

//.\BUSRESERVATION