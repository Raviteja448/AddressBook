#include "contact.h"
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
// defination of is_digit function:
//printf("---------------------------------------------------------------------------------\n");
int is_digit(char phone[])
{
	int flag=0;
	for (int i=0;phone[i];i++)
		if (isdigit(phone[i])==0) flag=1;//number contain any other character flag=1;
	if (strlen(phone)!=10 || flag==1)//number len=10	
	{
		//char phone_2[10];
		printf("Invalid number: \n");
		printf("Enter 10 Digits number only: \n");
		printf("Enter your number : ");
		scanf(" %[^\n]",phone);//reading same variable again 
		return is_digit(phone);//recursive call for digt contact until user gives right output

	}	
	return 1;//if valid
}
//defination for the is_Email function:
//printf("---------------------------------------------------------------------------------------\n");
int Mail(char mail[])
{
	if( (isalpha(mail[0])==0) ||  (strchr(mail,'@')==0) ||  (strstr(mail,".com")==0) )//mails contains '@' '.com' Before @ some character
	{
		//char email[20];
		printf("Invalid mail :\n");
		printf("Ex: <Name>@<domain>.com \n");
		printf("Ex: Name123@gmail.com :\n");
		printf("Enter your mail: ");
		scanf(" %[^\n]",mail);
		return Mail(mail);
	}
	return 1;//if valid
}

#if 1
//printf("Function for creating conatct: \n");
//printf("----------------------------------------------------------------------------------\n");

int createContact(AddressBook *addressBook) 
{

	while (1)
	{
		addressBook->contactCount=addressBook->contactCount+1;
		addressBook->contacts =(Contact *)realloc(addressBook->contacts,sizeof(Contact) * (addressBook->contactCount));//reallocatiing memory
		int flag=0;
		getchar();
		printf("Enter Your name: ");
		scanf("%[^\n]",addressBook -> contacts[(addressBook->contactCount)-1].name);

		//checking number is matching in of list of numbers:
		//printf("------------------------------------------------------------------------------\n");
		while(1)
		{
			flag=0;
			getchar(); 
			printf("Enter Your Mobile number: ");
			scanf("%[^\n]", addressBook->contacts[(addressBook->contactCount)-1].phone);//reading input from the user:
			is_digit(addressBook->contacts[(addressBook->contactCount)-1].phone);  //function call for the is_digit function
			for(int i=0;i<(addressBook->contactCount)-1;i++)
			{
				if (strcmp(addressBook->contacts[(addressBook->contactCount)-1].phone,addressBook->contacts[i].phone)==0)//checking into .cvs files
				{		
					printf("The Phone number is already Existed: \n");
					flag=1;
					break;
				}
			}
			if (flag==1)
				continue;//number already exist then continue process
			else
				break;
		}


		//cheching mail is having .com and @
		//printf("-----------------------------------------------------------------------------\n");


		while(1)
		{
			flag=0;
			printf("Enter your Mail: ");
			getchar(); 
			scanf("%[^\n]",addressBook->contacts[(addressBook->contactCount)-1].email);//reading mail from the user:
			Mail(addressBook->contacts[addressBook->contactCount-1].email);//function call for the mail:
			for(int i=0;i<(addressBook->contactCount)-1;i++)
			{
				if (strcmp(addressBook->contacts[(addressBook->contactCount)-1].email,addressBook->contacts[i].email)==0)
				{		
					printf("The Email  is already Existed: \n");
					flag=1;
					break;
				}
			}
			if (flag==1)
				continue;//if mail  already exist then continue process
			else
				break;
		}

		char ch_1,ch_2;
		printf("Do you want to Save This Content y/n: ");
		scanf(" %c",&ch_2);
		if (ch_2=='y')
		{
			if ((addressBook->fptr=fopen("contact.csv","w+"))==NULL)
			{
				fprintf(stderr,"Can't Open File :\n");
			}
			else
			{
				//printing into .csv file
				fprintf(addressBook->fptr,"#%d#\n",addressBook->contactCount);
				for (int i=0;i<addressBook->contactCount;i++)
				{
					fprintf(addressBook->fptr,"%s,",addressBook->contacts[i].name);
					fprintf(addressBook->fptr,"%s,",addressBook->contacts[i].phone);
					fprintf(addressBook->fptr,"%s\n",addressBook->contacts[i].email);

				}
			}
			fclose(addressBook->fptr);
			printf("Succesfully Saved into file: \n");
		  

		}
		printf("Do you want to Continue y/n: ");
		scanf(" %c",&ch_1);
		if (ch_1!='y')
		{
			//free(addressBook->fptr);
			exit(0);
		}
		else
	   	break;
	}
	printf("countCount=%d\n",(addressBook->contactCount));//printting and increasing the size of "contactCount":
	printf("Congratulations Your contact is created Succesfully : \n");
	printf("-------------------------------------------------------------------------\n");

}

#endif
//printf("-----------------------------------------------------------------------\n");
//completed  create contact function:



//function defination for the list of all contacts:
//printf("------------------------------------------------------------------------\n");

#if 1

void listContacts(AddressBook *addressBook) 
{
	int i;
	printf("\t\t\t-------------------------------------------------------------------------------\n");
	printf("%32s%32s%32s\n","Name: ","Phoneno: ","Mail: ");
	printf("\t\t\t-------------------------------------------------------------------------------\n");
	for (i=0;i<addressBook->contactCount;i++)
	{
		printf("%32s",addressBook->contacts[i].name);//name
		printf("%32s",addressBook->contacts[i].phone);//phone
		printf("%32s\n",addressBook->contacts[i].email);//email
	}
	printf("\t\t\t-------------------------------------------------------------------------------\n");

}
#endif
//list of contact function is completed:
//printf("-----------------------------------------------------------------------------\n");



//function definiation for the Search contact function:
//printf("----------------------------------------------------------------------------------\n");
#if 1
void searchContact(AddressBook *addressBook) 
{
	int flag=0;
	while(1)
	{
		int choice;
		char str[20];
		printf("Search By :\n1.Name:\n2.Phone No:\n3.Mail:\n");
		printf("Enter Your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the name : ");
				scanf(" %[^\n]",str);
				for (int i=0;i<addressBook->contactCount;i++)
				{
					if (strcmp(str,addressBook->contacts[i].name)==0)//checking name exist are not
					{
						printf("----------------------------------------------------------------------------------------\n");
						printf("Display the details: \n");
						printf("Name:\t\tPhone No:\t\tGmail:\n");
						printf("%s\t\t",addressBook->contacts[i].name);
						printf("%s\t\t",addressBook->contacts[i].phone);
						printf("%s\n",addressBook->contacts[i].email);
						flag=1;
						printf("----------------------------------------------------------------------------------------\n");
					}
				}
				break;
			case 2:
				printf("Enter the Phone No: ");
				scanf(" %[^\n]",str);
				is_digit(str);	//function call for is_digit:
				for (int i=0;i<addressBook->contactCount;i++)
				{
					if (strcmp(str,addressBook->contacts[i].phone)==0)//checking number exist are not
					{
						printf("----------------------------------------------------------------------------------------\n");
						printf("Display the details: \n");
						printf("Name:\t\tPhone No:\t\tGmail:\n");
						printf("%s\t\t",addressBook->contacts[i].name);
						printf("%s\t\t",addressBook->contacts[i].phone);
						printf("%s\n",addressBook->contacts[i].email);
						flag=1;
						printf("----------------------------------------------------------------------------------------\n");
					}
				}
				break;
			case 3:
				printf("Enter Your mail: ");
				scanf(" %[^\n]",str);
				Mail(str);
				for (int i=0;i<addressBook->contactCount;i++)
				{
					if (strcmp(str,addressBook->contacts[i].email)==0)//checking mail existed are not
					{
						printf("----------------------------------------------------------------------------------------\n");
						printf("Details of the Person: \n");
						printf("Name:\t\tPhone No:\t\tGmail:\n");
						printf("%s\t\t",addressBook->contacts[i].name);
						printf("%s\t\t",addressBook->contacts[i].phone);
						printf("%s\n",addressBook->contacts[i].email);
						flag=1;
						printf("----------------------------------------------------------------------------------------\n");
					}
				}
				break;
			default:
				printf("Invalid input: \n");
				continue;

		}
		if (flag!=1)
		{
			printf("Your enter Details is Not Found: \n");
			continue;
		}
		char ch_;
		printf("Do you want continue  y/n: ");//continue to process
		scanf(" %c",&ch_);
		if (ch_ != 'y')
		{
			exit(0);
		}
		else
			break;
	}

	//printf("----------------------------------------------------------------------------------------\n");
}
//search function is completed:
//printf("-----------------------------------------------------------------------------------\n");
#endif


//function defintaion for Edit contatc:
//printf("-----------------------------------------------------------------------------------\n");

#if 1
void editContact(AddressBook *addressBook) 
{
	char str[20],phone[10],email[20];
	while (1)
	{
		int choice;
		printf("Edit By: \n1.Name\n2.Phone\n3.Mail\n");
		printf("Enter Your choice: ");
		scanf("%d",&choice);
		if(choice != 1 && choice != 2 && choice != 3)
		{ printf("Invalid input :\n"); continue; }
		//if user wants Edit the name:
		else if (choice==1)
		{
			while (1)
			{
				int flag=0,k,l;
				printf("Enter Name of  Editing Contact : ");
				scanf(" %[^\n]",str);
				for (int i=0;i<addressBook->contactCount;i++)
				{
					if (strcmp(str,addressBook->contacts[i].name)==0)
					{
						flag++;
						if (flag==1) k=i ;
					}
				}
				if (flag==0) 
				{
					printf("The name is not Present : \n");
					continue;
				}
				else if (flag==1)
				{
					printf("New Name: ");//if not exist asking again
					scanf(" %[^\n]",addressBook->contacts[k].name);
					break;
				}

				//printf("--------------------------------------------------------------------------------------------------\n");
				//name contains more than one then we area asking user mobile number 
				if (flag>1)
				{
					printf("The Enterd Name More Than one : \n");
					while(1)
					{
						printf("Please Enter Your Mobile number: ");
						scanf(" %[^\n]",phone);
						(is_digit(phone));//function call for is_digit:
						int count=0,k;
						for (int i =0;i<addressBook->contactCount;i++)
						{
							if (strcmp(phone,addressBook->contacts[i].phone)==0)
							{
								if (flag==1)k=i;//index storing in "k"
								count++;
							}	

						}
						if (count==0)
						{
							printf("Number Not Matched: \n");
							continue;
						}
						else if (count==1)
						{
							printf("New Name: ");//if not number existed asking again
							scanf(" %[^\n]",addressBook->contacts[k].name);
							break;
						}
					}
				}
				break;
			}//edit Name loop
			printf("The Details Edited Succesfully: \n");
		}//edit name Condition



		//User Wants to Edit the Phone number:
		else if (choice==2)//asking details from the user to edit phone number
		{
			while (1)
			{
				int flag_2=0,k=0;
				printf("Enter your Phone No: ");
				scanf(" %[^\n]",phone);
				is_digit(phone);//function call for is_digit function
				for (int j=0;j<addressBook->contactCount;j++)
				{
					//	checking other contacts with new contact
					if (strcmp(phone,addressBook->contacts[j].phone)==0)
					{
						flag_2++;
						k=j;
					}
				}
				if (flag_2==0)
				{
					printf("the number is Not Exist: \n");
					continue;
				}

				if (flag_2==1)
				{
					while(1)
					{
						int count=0;
						printf("New Number: ");
						scanf(" %[^\n]",addressBook -> contacts[k].phone);
						is_digit(addressBook->contacts[k].phone);
						for (int j=0;j<addressBook->contactCount;j++)
						{
							//compare new number with all other numbers except it self
							if (strcmp(addressBook->contacts[k].phone,addressBook->contacts[j].phone)==0 && k!=j)
								count++;
						}
						if (count!=0)
						{
							printf("The Number is Already Exist: \n");
							continue;
						}
						else
							break;

					}
				}
				break;
			}

			printf("The detailed Edited SuccesFully : \n");
		}

		//if user wants to Edit the mail 

		else if (choice==3)//  we are asking details from the user editing the Mail:
		{
			while (1)
			{
				int flag_2=0,k=0;
				printf("Enter your Mai ID : ");
				scanf(" %[^\n]",email);
				Mail(email);//function call for is_digit function
				for (int j=0;j<addressBook->contactCount;j++)
				{
					//	checking other Mails with new Mail
					if (strcmp(email,addressBook->contacts[j].email)==0 )
					{
						flag_2++;
						k=j;

					}

				}
				if (flag_2==0)
				{
					printf("the Mail is Not existed: \n");
					continue;
				}
				else if (flag_2!=0)
				{
					while(1)
					{
						int count=0;
						printf("New Mail: ");
						scanf(" %[^\n]",addressBook -> contacts[k].email);
						Mail(addressBook->contacts[k].email);
						for (int j=0;j<addressBook->contactCount;j++)
						{
							//new mail with other mail checking except itself
							if (strcmp(addressBook->contacts[k].email,addressBook->contacts[j].email)==0 && k!=j)
								count++;
						}
						if (count!=0)
						{
							printf("The Mail is Already Exist: \n");
							continue;//exist then continue 
						}
						else
							break;

					}
				}
				break;
			}

			printf("The detailed Edited SuccesFully : \n");


		}


		char ch_,ch_2;
		printf("Do you want to Save This Content y/n: ");
		scanf(" %c",&ch_2);
		if (ch_2=='y')
		{
			if ((addressBook->fptr=fopen("contact.csv","w+"))==NULL)
			{
				fprintf(stderr,"Can't Open File :\n");
			}
			else
			{
				//save into .csv file
				fprintf(addressBook->fptr,"#%d#\n",addressBook->contactCount);
				for (int i=0;i<addressBook->contactCount;i++)
				{
					fprintf(addressBook->fptr,"%s,",addressBook->contacts[i].name);
					fprintf(addressBook->fptr,"%s,",addressBook->contacts[i].phone);
					fprintf(addressBook->fptr,"%s\n",addressBook->contacts[i].email);
				}
			}
			fclose(addressBook->fptr);
			printf("Succesfully Saved into file: \n");
		}


		printf("Do you want continue  y/n: ");
		scanf(" %c",&ch_);
		if (ch_ != 'y')
		{
			//free(addressBook->fptr);
			exit(0);
		}
		else break;//breaking outer loop



		printf("--------------------------------------------------------------------------------------------\n");
	}
}
//End of Edit comtact function :
//printf("-----------------------------------------------------------------------------------------\n");
#endif




//function defination for the Delete contact:
//printf("---------------------------------------------------------------------------------------\n");
#if 1
void deleteContact(AddressBook *addressBook) 
{
	while(1)
	{
		int choice,flag=0;
		char str[20];
		printf("delete By :\n1.Name:\n2.Phone No:\n3.Mail:\n");
		printf("Enter Your choice: ");
		scanf(" %d",&choice);
		switch(choice)
		{
			//by using name deleting
			case 1:
				printf("Enter the name : ");
				scanf(" %[^\n]",str);
				for (int i=0;i<addressBook->contactCount;i++)
				{
					if (strcmp(str,addressBook->contacts[i].name)==0)
					{
						printf("Display the details: \n");
						printf("Name:\t\tPhone No:\t\tGmail:\n");
						printf("%s\t\t",addressBook->contacts[i].name);
						printf("%s\t\t",addressBook->contacts[i].phone);
						printf("%s\n",addressBook->contacts[i].email);
						flag=1;
					}

				}

				if (flag==0)
				{
					printf("The Details is Not Existed: \n");
					continue;
				}

				char ch_1;
				printf("Do you want to Delete y/n: ");
				scanf(" %c",&ch_1);
				if (ch_1=='y')
				{
					//over writing all details abd reallocate last byte
					for (int i=0;i<addressBook->contactCount;i++)
					{
						if (strcmp(str,addressBook->contacts[i].name)==0 && i <(addressBook->contactCount-1))
						{
							for (int j=i;j<addressBook->contactCount;j++)
								addressBook->contacts[j]=addressBook->contacts[j+1];
							break;
						}
					}
					addressBook->contactCount=addressBook->contactCount -1;
					addressBook->contacts =(Contact *)realloc(addressBook->contacts,sizeof(Contact) * ((addressBook->contactCount)));//reallocatiing memory
					//flag=1;
				}
				else
				{ 
					flag=0;
					break;
				}
				break;
			case 2:
				printf("Enter the Phone No: ");
				scanf(" %[^\n]",str);
				is_digit(str);	//function call for is_digit:
				for (int i=0;i<addressBook->contactCount;i++)
				{
					if (strcmp(str,addressBook->contacts[i].phone)==0)
					{
						printf("Display the details: \n");
						printf("Name:\t\tPhone No:\t\tGmail:\n");
						printf("%s\t\t",addressBook->contacts[i].name);
						printf("%s\t\t",addressBook->contacts[i].phone);
						printf("%s\n",addressBook->contacts[i].email);
						flag=1;
					}
				}
				if (flag==0)
				{
					printf("The Details is Not Existed: \n");
					continue;
				}
				char ch_2;
				printf("Do you want to Delete y/n: ");
				scanf(" %c",&ch_2);
				if (ch_2=='y')
				{
					//over writing all details abd reallocate last byte
					for (int i=0;i<addressBook->contactCount;i++)
					{
						if (strcmp(str,addressBook->contacts[i].phone)==0 && i<(addressBook->contactCount-1))
						{
							for (int j=i;j<addressBook->contactCount;j++)
								addressBook->contacts[j]=addressBook->contacts[j+1];
							break;
						}
					}
					addressBook->contactCount=addressBook->contactCount -1;
					addressBook->contacts =(Contact *)realloc(addressBook->contacts,(addressBook->contactCount) * sizeof(Contact) );//reallocatiing memory
					flag=1;
				}
				else
				{ 
					flag=0;
					break;
				}
				break;//fall through case
			case 3:
				printf("Enter Your mail: ");
				scanf(" %[^\n]",str);
				Mail(str);
				for (int i=0;i<addressBook->contactCount;i++)
				{
					if (strcmp(str,addressBook->contacts[i].email)==0)
					{
						printf("Details of the Person: \n");
						printf("Name:\t\tPhone No:\t\tGmail:\n");
						printf("%s\t\t",addressBook->contacts[i].name);
						printf("%s\t\t",addressBook->contacts[i].phone);
						printf("%s\n",addressBook->contacts[i].email);
						flag=1;
					}
				}
				if (flag==0)
				{
					printf("The Details is Not Existed: \n");
					continue;
				}

				if (flag!=0)
				{
					char ch_3;
					printf("Do you want to Delete y/n: ");
					scanf(" %c",&ch_3);
					if (ch_3=='y')
					{
						//over writing all details abd reallocate last byte
						for (int i=0;i<addressBook->contactCount;i++)
						{
							if (strcmp(str,addressBook->contacts[i].email)==0 && i<(addressBook->contactCount-1))
							{
								for (int j=i;j<addressBook->contactCount;j++)
									addressBook->contacts[j]=addressBook->contacts[j+1];
								break;
							}
						}
						addressBook->contactCount=(addressBook->contactCount) - 1;
						addressBook->contacts =(Contact *)realloc(addressBook->contacts,sizeof(Contact) * (addressBook->contactCount));//reallocatiing memory
						//flag=1;
					}
					else
					{ 
						flag=0;
						break;
					}

				}
				break;
			default:
				{
					printf("Invalid input: \n");
					continue;
				}

		}


		if (flag==0)
		{
			printf("Your Details is Not Deleted: \n");
			continue;
		}
		else
		{
			printf("Your Details is  Deleted: \n");

		char ch_2;
		printf("Do you want to Save This Content Into File y/n: ");
		scanf(" %c",&ch_2);
		if (ch_2=='y')
		{
			if ((addressBook->fptr=fopen("contact.csv","w+"))==NULL)
			{
				fprintf(stderr,"Can't Open File :\n");
			}
			else
			{
				//save into .csv file
				fprintf(addressBook->fptr,"#%d#\n",addressBook->contactCount);
				for (int i=0;i<addressBook->contactCount;i++)
				{
					fprintf(addressBook->fptr,"%s,",addressBook->contacts[i].name);
					fprintf(addressBook->fptr,"%s,",addressBook->contacts[i].phone);
					fprintf(addressBook->fptr,"%s\n",addressBook->contacts[i].email);

				}
			
			}
			fclose(addressBook->fptr);

		  }
			printf("Your details is Succesfully saved  into file: \n");
		
		}

		char ch_1;
		printf("Do you want continue  y/n: ");
		scanf(" %c",&ch_1);
		if (ch_1!='y')
		{
			//free(addressBook->fptr);
			exit(0);
		}
		else break;
		printf("------------------------------------------------------------------------------------\n");



	}
}
#endif
//end of delete contact function:
//printf("---------------------------------------------------------------------------------\n");
