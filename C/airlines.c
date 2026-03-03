#include <stdio.h>
#include <string.h>
typedef struct{
char name[20];
int ID;
int status;
} Seat;

void listtakenSeat(Seat *arr, int *size);
void assignSeat(Seat *arr, int *size);
void removeSeat(Seat *arr, int *size);

int main(){
    int choice; int size = 0;
    Seat list[5] = {0};

    printf("NTU AIRLINES SEATING RESERVATION PROGRAM: \n");
    printf("1: listTakenSeat()\n");
    printf("2: assignSeat()\n");
    printf("3: removeSeat()\n");
    printf("4: quit\n");

    for (int i = 0; i<5; i++){
        if (list[i].status != 0){
            size += 1;
        }
    }

    do{
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice){
            case 1: printf("listtakenSeat():\n");
                    listtakenSeat(list, &size);
                    break;
            
            case 2: printf("assignSeat(): \n");
                    assignSeat(list, &size);
                    
                    break;
            
            case 3: printf("removeSeat(): \n");
                    removeSeat(list, &size);
                    break;
        }
    } while (choice != 4);
    return 0;
}

void listtakenSeat(Seat *arr, int *size){
    if (*size == 0){
        printf("The seat assignment list is empty\n");
    } else {
        for (int i=0; i<5; i++){
            if (arr[i].status == 1){
                printf("Customer name: %s\n", arr[i].name);
                printf("Seat number (ID): %d\n", arr[i].ID);
            }
        }
    }
}



void assignSeat(Seat *arr, int *size){
    char dummy; char *p;
    int id;

    if (*size >= 5){
        printf("The plane is full\n");
        return;
    }

    printf("Enter the seat number: \n");
    do{
        scanf("%d", &id);
        while ((dummy = getchar()) != '\n' && dummy != '\0');
        if (id < 1 || id > 5){
            printf("Please enter a seat number between 1 and 5\n");
            
        }else if (arr[id-1].status == 1){
            printf("Occupied! Please choose another seat\n");

        }else{
            arr[id-1].ID = id;
            printf("Enter customer name: \n");
            fgets(arr[id-1].name, 20, stdin);

            if (p = strchr(arr[id-1].name, '\n')) *p = '\0';
            arr[id-1].status = 1;

            printf("The seat has been assigned successfully\n");
            *size += 1;
            break;
            }
    }while (1);
}


void removeSeat(Seat *arr, int *size){
    int seatID;
    if (*size == 0){
        printf("All the seats are vacant\n");
        return;
    }
    printf("Enter the seat number: \n");
    do{
        scanf("%d", &seatID);
        if (seatID < 1 || seatID > 5){
            printf("Please enter a seat number between 1 and 5\n");
            
        }else if (arr[seatID-1].status == 0){
            printf("Empty! Enter another seat number for removal\n");
        
        }else if (arr[seatID-1].ID == seatID){
            arr[seatID-1].ID = 0;
            arr[seatID-1].status = 0;
            memset(arr[seatID-1].name, 0, 20);
            *size -= 1;
            
            printf("Removal is successful\n");
            break;
        }
    }while(1);
}
