#include "contact.h"
#include<stdlib.h>
int main(int argc,char *argv[])
{
	//all function calls should be inside the main
	AddressBook s1;//creating structure variable
	
	s1.fptr;//creationg structure pointer
	if ((s1.fptr=fopen("contact.csv","r"))==NULL)//opening .csv file
	{
		fprintf(stderr,"Can't Open File :\n");
		return 1;
	}
	char str1[100];
	char *ch;
	fscanf(s1.fptr,"%[^\n]",str1);//reading first line(size)
	ch=strtok(str1+1,"#");//storing in ch 
	int n=atoi(ch);//converting char to int
	s1.contacts =(Contact *)malloc(sizeof(Contact)*n);//allocating dynamic memory
	char lines[100];
	for(int i=0;fscanf(s1.fptr," %[^\n]",lines)!=EOF;i++)//reading remaining names phone emails
	{	
		strcpy(s1.contacts[i].name,strtok(lines,","));
		strcpy(s1.contacts[i].phone,strtok(NULL,","));
		strcpy(s1.contacts[i].email,strtok(NULL,","));
	}
	s1.contactCount=n;//storing count of .csv membes, in contact_Count
fclose(s1.fptr);
//free(s1.contacts);
	while(1)
	{
		//text showing to user:
		printf("Adress Book Menu: \n");
		printf("1.Create contact \n");
		printf("2.Search contact \n");
		printf("3.Edit contact \n");
		printf("4.Delete contact \n");
		printf("5.List All contacts \n");
		printf("6.Exit\n");
		printf("Enter Your choice : ");
		int num;
		scanf("%d",&num);
		if(num==6)
		{
			printf("Your exited: \n");
			//free(s1.contacts);
			break;
		}
		switch(num)
		{
			case 1:	
				createContact(&s1);//function calls:
				break;
			case 2:	
				searchContact(&s1);
				break;
			case 3: 
				editContact(&s1);
				break;
			case 4: 
				deleteContact(&s1);
				break;
			case 5:
				listContacts(&s1);
				break;	

		}
	}
	
}

