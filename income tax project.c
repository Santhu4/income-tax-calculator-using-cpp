#include<stdio.h>
#include<string.h>
void banner();
void Add_New_Record();
void List_of_all_Records();
void Search_Records();
void Edit_Records();
void Delete_Record();

struct incometax{
	char tax_payer_name[50];
	int tax_payer_id;
	float tax_payer_income;
	float tax_to_be_paid;
	
};

int main() 
{
		banner();
 return 0;
}

void Add_New_Record()
{
	 int n;
	printf("Enter number of Tax Payer's need to insert into records = ");
	scanf("%d",&n);
	int again;
	struct incometax s[n];
	FILE* fp;
	fp = fopen("incometaxdetails.txt","w");
	
	 float income, tax;
	int i;
for(i=0;i<n;i++)			// here for loop is used to insert the data of the number of students  
	{
		printf("\nEnter Tax Payer %d Name = ",i+1);
		scanf("%s",s[i].tax_payer_name);
		printf("\nEnter Tax Payer %d id = ",i+1);
		scanf("%d",&s[i].tax_payer_id);
		printf("\nEnter Tax Payer %d Annual income = ",i+1);
		scanf("%f",&s[i].tax_payer_income);
		income = s[i].tax_payer_income;
		
	if (income <= 300000) {
        tax = 0;
    } else if (income <= 600000)
	{
        tax = (income - 300000) * 0.05;
    }
	 else if (income <= 900000) 
	{
        tax = (income - 600000) * 0.1 + 15000;
    }
	else if (income <= 1200000) 
	{
        tax = (income - 900000) * 0.15 + 30000;
    } 
	else if (income <= 1500000) 
	{
        tax = (income - 1200000) * 0.2 + 45000;
    }
	else
	{
        tax = (income - 1500000) * 0.3 + 60000;
    }
    s[i].tax_to_be_paid = tax;
		system("cls");					//it is the command used to clear the screen 
	}
	
	for(i=0;i<n;i++)						// here for loop used to display the inserted data on screen
	{
		fprintf(fp,"\nName = %s\t\tID = %d\t\tIncome = %.2f\t\tTax need to pay = %.2f",s[i].tax_payer_name,s[i].tax_payer_id,s[i].tax_payer_income,s[i].tax_to_be_paid);
	}
	fclose(fp);
	{	
	printf("\n\"Records added Successfull!!!!\"");
	}
	printf("\n\nEnter ""1"" for MAIN MENU or Any other key to EXIT  = ");
	scanf("%d",&again);
	if(again == 1)
	{
	banner();	
	}
	
}

void List_of_all_Records()
{
	FILE*fp;
	fp=fopen("incometaxdetails.txt","r");
	int again;
	char mystring[100];
	while(fgets(mystring,100,fp))
	{
	printf("%s",mystring);
	}
	fclose(fp);
	printf("\n\nEnter ""1"" for MAIN MENU or Any other key to EXIT  = ");
	scanf("%d",&again);
	if(again == 1)
	{
	banner();	
	}
}

void Search_Records()
{
    FILE *fp;
    char search_string[100];
    char line[100];
    int again;

    fp = fopen("incometaxdetails.txt", "r");
    printf("Enter ID or Name of Tax Payer: ");
    scanf("%s", &search_string);

    while(fgets(line, sizeof(line), fp)) 
	{
        if(strstr(line, search_string))
		{
            printf("\n%s", line);
            printf("""\n\nRecord founded Successfully!!!\n""");
        }
    }
	if(strstr(line, search_string)==0)
        {
        	printf("\nRecords not Found from the Database\n");
		}
    

    fclose(fp);
	printf("\n\nEnter ""1"" for MAIN MENU or Any other key to EXIT  = ");
	scanf("%d",&again);
	if(again == 1)
	{
	banner();	
	}
}
	
void Edit_Records()
{
int n;
	printf("Enter number of Tax Payer's need to Edit = ");
	scanf("%d",&n);
	int again;
	struct incometax s[n];
	FILE*fp;
	fp=fopen("incometaxdetails.txt","a");
	
	 float income, tax;
	int i;
for(i=0;i<n;i++)			// here for loop is used to insert the data of the number of students  
	{
		printf("\nEnter Tax Payer %d Name = ",i+1);
		scanf("%s",&s[i].tax_payer_name);
		printf("\nEnter Tax Payer %d id = ",i+1);
		scanf("%d",&s[i].tax_payer_id);
		printf("\nEnter Tax Payer %d income = ",i+1);
		scanf("%f",&s[i].tax_payer_income);
		income = s[i].tax_payer_income;
		
	if (income <= 300000) {
        tax = 0;
    } else if (income <= 600000)
	{
        tax = (income - 300000) * 0.05;
    }
	 else if (income <= 900000) 
	{
        tax = (income - 600000) * 0.1 + 15000;
    }
	else if (income <= 1200000) 
	{
        tax = (income - 900000) * 0.15 + 30000;
    } 
	else if (income <= 1500000) 
	{
        tax = (income - 1200000) * 0.2 + 45000;
    }
	else
	{
        tax = (income - 1500000) * 0.3 + 60000;
    }
    s[i].tax_to_be_paid = tax;
		system("cls");					//it is the command used to clear the screen 
	}
	
	for(i=0;i<n;i++)						// here for loop used to display the inserted data on screen
	{
		fprintf(fp,"\nName = %s\t\tID = %d\t\tIncome = %.2f\t\tTax need to pay = %.2f",s[i].tax_payer_name,s[i].tax_payer_id,s[i].tax_payer_income,s[i].tax_to_be_paid);
	}
	fclose(fp);	
	printf("\n\"Records edited Successfull!!!!\"");
	printf("\n\nEnter ""1"" for MAIN MENU or Any other key to EXIT  = ");
	scanf("%d",&again);
	if(again == 1)
	{
	banner();	
	}
}
void Delete_Record()
{
    FILE *fp, *temp;
    char search_string[100];
    char line[100];
    int again;

    fp = fopen("incometaxdetails.txt", "r+");
    temp = fopen("temp.txt", "w");

    printf("Enter ID or Name of Tax Payer to delete: ");
    scanf("%s", search_string);

    while(fgets(line, sizeof(line), fp)) {
        if(strstr(line, search_string)) {
            continue;
        }
        fputs(line, temp);
    }
    

    fclose(fp);
    fclose(temp);

    remove("incometaxdetails.txt");
    rename("temp.txt", "incometaxdetails.txt");

    printf("\n\"Records deleted Successfull!!!!\"");
	printf("\n\nEnter ""1"" for MAIN MENU or Any other key to EXIT  = ");
	scanf("%d",&again);
	if(again == 1)
	{
	banner();	
	}
}

void banner()
{
	int choice;
	printf("\n\n***********************************************************\n");
	printf("\n\t\t  INCOME TAX CALCULATOR        \n");
	printf("\n\n1. Add  new Tax Payer record");
	printf("\n\n2. List of all Tax Payer along with income tax to be paid");
	printf("\n\n3. Search The Tax payer Record");
	printf("\n\n4. Edit the Tax Payer Record");
	printf("\n\n5. Delete the Tax Payer Record");
	printf("\n\n6. EXIT");
	printf("\n\n***********************************************************\n");
	printf("Enter your choice(1-6) = ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			Add_New_Record();	
		break;
		case 2:
			List_of_all_Records();
		break;
		case 3:
			Search_Records();
		break;
		case 4:
			Edit_Records();
		break;
		case 5:
			Delete_Record();
		break;
		default:
			printf("ok press \"ENTER\" to exit");
	}
	
}

