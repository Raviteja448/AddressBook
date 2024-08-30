#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact *contacts;
    int contactCount;
	FILE *fptr;
} AddressBook;
//function prototypes
//create contact
int createContact(AddressBook *addressBook);
//search contact
void searchContact(AddressBook *addressBook);
//edit contact:
void editContact(AddressBook *addressBook);
//delete contact
void deleteContact(AddressBook *addressBook);
//list contacts
void listContacts(AddressBook *addressBook);
//intilize function
int initialize(AddressBook *addressBook);

#endif
