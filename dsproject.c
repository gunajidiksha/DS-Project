#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int SSN;
    char Name[50];
    char Department[50];
    char Designation[50];
    float Salary;
    long PhoneNumber;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

int isSSNUnique(int ssn) {
    struct node* temp = head;

    while (temp != NULL) {
        if (temp->SSN == ssn) {
            return 0;  // SSN already exists
        }
        temp = temp->next;
    }

    return 1;  // SSN is unique
}

int isPhoneNumberUnique(long phoneNumber) {
    struct node* temp = head;

    while (temp != NULL) {
        if (temp->PhoneNumber == phoneNumber) {            
            printf("Enter another phone no. : ");
            return 0;  // Phone number already exists
        }
        temp = temp->next;
    }
    // printf("\n");

    return 1;  // Phone number is unique
}

void insertEnd() {
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // printf("Enter SSN: ");
    // scanf("%d", &p->SSN);

    do {
        printf("Enter SSN: ");
        scanf("%d", &p->SSN);

        if (!isSSNUnique(p->SSN)) {
            printf("SSN already exists. Please enter a unique SSN.\n");
        }
    } while (!isSSNUnique(p->SSN));

    // Validate unique phone number
    do {
        printf("Enter Phone Number: ");
        scanf("%ld", &p->PhoneNumber);

        if (!isPhoneNumberUnique(p->PhoneNumber)) {
            printf("\n Phone number already exists.\n"); 
            // printf("Please enter a unique phone number.\n");
        }
    } while (!isPhoneNumberUnique(p->PhoneNumber));

    printf("Enter Name: ");
    scanf("%s", p->Name);
    printf("Enter Department: ");
    scanf("%s", p->Department);
    printf("Enter Designation: ");
    scanf("%s", p->Designation);
    printf("Enter Salary: ");
    scanf("%f", &p->Salary);

    p->next = NULL;

    if (head == NULL) {
        p->prev = NULL;
        head = p;
    } else {
        struct node* temp;
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }

    printf("Employee added at the end successfully.\n");
}

void insertFront() {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // printf("Enter SSN: ");
    // scanf("%d", &p->SSN);

    do {
        printf("Enter SSN: ");
        scanf("%d", &p->SSN);

        if (!isSSNUnique(p->SSN)) {
            printf("SSN already exists. Please enter a unique SSN.\n");
        }
    } while (!isSSNUnique(p->SSN));

    // Validate unique phone number
    do {
        printf("Enter Phone Number: ");
        scanf("%ld", &p->PhoneNumber);

        if (!isPhoneNumberUnique(p->PhoneNumber)) {
            printf("Phone number already exists.");
            printf("Please enter a unique phone number.\n"); 
        }
    } while (!isPhoneNumberUnique(p->PhoneNumber));

    printf("Enter Name: ");
    scanf("%s", p->Name);
    printf("Enter Department: ");
    scanf("%s", p->Department);
    printf("Enter Designation: ");
    scanf("%s", p->Designation);
    printf("Enter Salary: ");
    scanf("%f", &p->Salary);

    p->prev = NULL;

    if (head == NULL) {
        p->next = NULL;
        head = p;
    } else {
        p->next = head;
        head->prev = p;
        head = p;
    }

    printf("Employee added at the front successfully.\n");
}

void display()
{
    if (head == NULL)
    {
        printf("DLL is empty.\n");
        return;
    }

    struct node* temp;
    temp = head;
    printf("\nEmployee DLL:\n");

    while (temp != NULL)
    {
        printf("SSN: %d, Name: %s, Department: %s, Designation: %s, Salary: %.2f, Phone: %ld\n",
               temp->SSN, temp->Name, temp->Department, temp->Designation, temp->Salary, temp->PhoneNumber);
        temp = temp->next;
    }
}

void countNodes()
{
    int count = 0;
    struct node* temp;
    temp = head;

    while (temp != NULL)
    {
        count=count+1;
        temp = temp->next;
    }

    printf("Number of nodes in DLL: %d\n", count);
}

void deleteEnd()
{
    if(head==NULL)
    {
        printf("DLL is empty\n");
        return;
    }
    struct node* temp=head;
    struct node* prev=NULL;

    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }

    if(prev==NULL)
    {
        free(temp);
        head=NULL;
    }
    else
    {
        prev->next=NULL;
        free(temp);
    }

    printf("Employee deleted from the end successfully.\n");
}

void deleteFront()
{
    if(head==NULL)
    {
        printf("Doubly ended queue is empty.\n");
        return;
    }
    struct node* temp;
    temp=head;

    if(temp->next==NULL)
    {
        free(temp);
        head=NULL;
    }
    else
    {
        head=temp->next;
        head->prev=NULL;
        free(temp);
    }
    printf("Employee dequeued from the front successfully.\n");

}

void dequeueFront()
{
    if(head==NULL)
    {
        printf("Doubly ended queue is empty.\n");
        return;
    }
    struct node* temp;
    temp=head;

    if(temp->next==NULL)
    {
        free(temp);
        head=NULL;
    }
    else
    {
        head=temp->next;
        head->prev=NULL;
        free(temp);
    }
    printf("Employee dequeued from the front successfully.\n");
}

void dequeueEnd()
{
    if(head==NULL)
    {
        printf("Doubly ended queue is empty.\n");
        return;
    }
    struct node* temp=head;
    struct node* prev=NULL;

    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }

    if(prev==NULL)
    {
        free(temp);
        head=NULL;
    }
    else
    {
        prev->next=NULL;
        free(temp);
    }

    printf("Employee deleted from the end successfully.\n");

}


int main()
{
    int choice;

    do{
        printf("\nMenu\n");
        printf("1.Create DLL by end insertion\n");
        printf("2.Display DLL and count nodes\n");
        printf("3.Insert at end\n");
        printf("4.Delete at end\n");
        printf("5.Insert at front\n");
        printf("6.Delete at front\n");
        printf("7.Demonstrate DLL as a Doubly ended queue at front end \n");
        printf("8.Demonstrate DLL as a Doubly ended queue at rear end\n");
        printf("9.Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:insertEnd();
                   break;
            case 2:display();
                   countNodes();
                   break;
            case 3:insertEnd();
                   break;
            case 4:deleteEnd();
                   break;
            case 5:insertFront();
                   break;
            case 6:deleteFront();
                   break;
            case 7:dequeueFront();
                   break;
            case 8:dequeueEnd11111();
                   break;
            case 9:printf("Exiting Program\n");
                   break;

            default:printf("Invalid choice\n");
        }
    }
    while(choice!=9);
    return 0;
}