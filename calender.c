#include <stdio.h>
#include <string.h>

// Structure for events
struct Event {
    int day;
    int month;
    char name[50];
};

// Predefined events (you can add more)
struct Event events[] = {
    {17, 2, "Rafi's Birthday"},
    {10, 4, "Oyshikee's Birthday"},
    {15, 5, "Fatema's Birthday"},
    {31, 10, "Tisha's Birthday"},
    {11, 11, "Ovi's Birthday"}
};

int totalEvents = 5;

// Get days in month
int getDays(int month, int year) {
    if(month == 2) {
        if((year%4==0 && year%100!=0) || (year%400==0))
            return 29;
        else
            return 28;
    }
    else if(month==4 || month==6 || month==9 || month==11)
        return 30;
    else
        return 31;
}

// Get starting day
int getStartDay(int year, int month) {
    int d = 1;
    if(month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;

    int day = (d + (13*(month+1))/5 + k + k/4 + j/4 + 5*j) % 7;
    return (day + 6) % 7;
}

// Print events for a month
void showEvents(int month) {
    printf("\n Events:\n");
    int found = 0;

    for(int i=0; i<totalEvents; i++) {
        if(events[i].month == month) {
            printf("  %d -> %s\n", events[i].day, events[i].name);
            found = 1;
        }
    }

    if(!found)
        printf("  No events this month.\n");
}

// Print single month
void printMonth(int month, int year) {
    char *months[] = {"","January","February","March","April","May","June",
                      "July","August","September","October","November","December"};

    int days = getDays(month, year);
    int start = getStartDay(year, month);

    printf("\n=====================================\n");
    printf("        %s %d\n", months[month], year);
    printf("=====================================\n");
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    for(int i=0; i<start; i++)
        printf("    ");

    for(int i=1; i<=days; i++) {
        printf("%4d", i);
        if((i + start) % 7 == 0)
            printf("\n");
    }

    printf("\n-------------------------------------\n");
    showEvents(month);
}

// Print full year
void printYear(int year) {
    for(int m=1; m<=12; m++) {
        printMonth(m, year);
    }
}

int main() {
    int choice, month, year;

    printf("\n=====================================\n");
    printf("     CALENDAR WITH EVENTS \n");
    printf("=====================================\n");
    printf("1. Show Single Month\n");
    printf("2. Show Full Year\n");
    printf("=====================================\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter month (1-12): ");
        scanf("%d", &month);
        printf("Enter year: ");
        scanf("%d", &year);

        printMonth(month, year);
    }
    else if(choice == 2) {
        printf("Enter year: ");
        scanf("%d", &year);

        printYear(year);
    }
    else {
        printf("Invalid choice!\n");
    }

    printf("\n=====================================\n");
    printf("        Thank You!\n");
    printf("=====================================\n");

    return 0;
}
