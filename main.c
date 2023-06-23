/*Name: Songram Kumar Ghosh
ID: 2311684642
Section: 6
*/
// This is a C program for a project of cricket stadium ticket management
// The program allows the user to book, cancel, view and modify tickets
// The program also keeps track of the available seats and the total revenue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of seats and the ticket price
#define MAX_SEATS 1000
#define TICKET_PRICE 50

// Declare a global array of seats and a global variable for revenue
int seats[MAX_SEATS];
int revenue = 0;

// Declare the functions for the menu options
void book_ticket();
void cancel_ticket();
void view_ticket();
void modify_ticket();
void display_seats();
void display_revenue();

// The main function displays the menu and calls the corresponding functions
int main(void)
{
    int choice;
    printf("Welcome to the cricket stadium ticket management system.\n");
    printf("Please choose an option from the menu below:\n");
    printf("1. Book a ticket\n");
    printf("2. Cancel a ticket\n");
    printf("3. View a ticket\n");
    printf("4. Modify a ticket\n");
    printf("5. Display the available seats\n");
    printf("6. Display the total revenue\n");
    printf("7. Exit the program\n");
    scanf("%d", &choice);
    while (choice != 7)
    {
        switch (choice)
        {
        case 1:
            book_ticket();
            break;
        case 2:
            cancel_ticket();
            break;
        case 3:
            view_ticket();
            break;
        case 4:
            modify_ticket();
            break;
        case 5:
            display_seats();
            break;
        case 6:
            display_revenue();
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
        printf("Please choose another option from the menu:\n");
        scanf("%d", &choice);
    }
    printf("Thank you for using the cricket stadium ticket management system.\n");
    return 0;
}

// The book_ticket function allows the user to book a ticket for a seat number
// The function checks if the seat is available and updates the array and the revenue accordingly
void book_ticket()
{
    int seat_number;
    printf("Please enter the seat number you want to book (1 to %d):\n", MAX_SEATS);
    scanf("%d", &seat_number);
    if (seat_number < 1 || seat_number > MAX_SEATS)
    {
        printf("Invalid seat number. Please try again.\n");
        return;
    }
    if (seats[seat_number - 1] == 1)
    {
        printf("Sorry, this seat is already booked. Please choose another one.\n");
        return;
    }
    seats[seat_number - 1] = 1;
    revenue += TICKET_PRICE;
    printf("You have successfully booked a ticket for seat number %d.\n", seat_number);
}

// The cancel_ticket function allows the user to cancel a ticket for a seat number
// The function checks if the seat is booked and updates the array and the revenue accordingly
void cancel_ticket()
{
    int seat_number;
    printf("Please enter the seat number you want to cancel (1 to %d):\n", MAX_SEATS);
    scanf("%d", &seat_number);
    if (seat_number < 1 || seat_number > MAX_SEATS)
    {
        printf("Invalid seat number. Please try again.\n");
        return;
    }
    if (seats[seat_number - 1] == 0)
    {
        printf("Sorry, this seat is not booked. Please choose another one.\n");
        return;
    }
    seats[seat_number - 1] = 0;
    revenue -= TICKET_PRICE;
    printf("You have successfully canceled your ticket for seat number %d.\n", seat_number);
}

// The view_ticket function allows the user to view a ticket for a seat number
// The function checks if the seat is booked and displays the ticket details accordingly
void view_ticket()
{
    int seat_number;
    printf("Please enter the seat number you want to view (1 to %d):\n", MAX_SEATS);
    scanf("%d", &seat_number);
    if (seat_number < 1 || seat_number > MAX_SEATS)
    {
        printf("Invalid seat number. Please try again.\n");
        return;
    }
    if (seats[seat_number - 1] == 0)
    {
        printf("Sorry, this seat is not booked. Please choose another one.\n");
        return;
    }
    printf("Here are the details of your ticket for seat number %d:\n", seat_number);
    printf("Seat number: %d\n", seat_number);
    printf("Ticket price: %d\n", TICKET_PRICE);
}

// The modify_ticket function allows the user to modify a ticket for a seat number
// The function checks if the seat is booked and allows the user to change the seat number accordingly
void modify_ticket()
{
    int old_seat_number, new_seat_number;
    printf("Please enter the seat number you want to modify (1 to %d):\n", MAX_SEATS);
    scanf("%d", &old_seat_number);
    if (old_seat_number < 1 || old_seat_number > MAX_SEATS)
    {
        printf("Invalid seat number. Please try again.\n");
        return;
    }
    if (seats[old_seat_number - 1] == 0)
    {
        printf("Sorry, this seat is not booked. Please choose another one.\n");
        return;
    }
    printf("Please enter the new seat number you want to book (1 to %d):\n", MAX_SEATS);
    scanf("%d", &new_seat_number);
    if (new_seat_number < 1 || new_seat_number > MAX_SEATS)
    {
        printf("Invalid seat number. Please try again.\n");
        return;
    }
    if (seats[new_seat_number - 1] == 1)
    {
        printf("Sorry, this seat is already booked. Please choose another one.\n");
        return;
    }
    seats[old_seat_number - 1] = 0;
    seats[new_seat_number - 1] = 1;
    printf("You have successfully modified your ticket from seat number %d to %d.\n", old_seat_number, new_seat_number);
}

// The display_seats function displays the available seats in the stadium
// The function uses a loop to print the seat numbers and their status
void display_seats()
{
    int i;
    printf("Here are the available seats in the stadium:\n");
    for (i = 0; i < MAX_SEATS; i++)
    {
        if (seats[i] == 0)
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

// The display_revenue function displays the total revenue generated by the ticket sales
// The function prints the revenue variable
void display_revenue()
{
    printf("The total revenue generated by the ticket sales is %d.\n", revenue);
}
