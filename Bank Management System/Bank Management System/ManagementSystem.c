#include "ManagementSystem.h"

#pragma region BANK ACCOUNT MANAGEMENT SYSTEM
void MainMenu()
{
	int block = 177;
	printf("         %c%c%c%c%c WELCOME TO THE MAIN MENU %c%c%c%c%c%c\n\n", block, block, block, block, block, block, block, block, block, block, block);
	printf("1. Create new account\n");
	printf("2. Update information of existing account\n");
	printf("3. For transactions\n");
	printf("4. Check detail of existing account\n");
	printf("5. Remove existing account\n");
	printf("6. View customer list\n");
	printf("7. Exit\n\n\n\n");
	printf("Enter your choice: ");
}

// Create new account
void CreateNewAccount()
{
	int block = 177;
	int dd = 0, mm = 0, yyyy = 0; // dob
	int age = 0; // age
	char* name = NULL, *phone_number = NULL, *residential_address = NULL;

	//printf("\n");
	printf("         %c%c%c%c%c CREATE NEW BANK ACCOUNT %c%c%c%c%c\n\n", block, block, block, block, block, block, block, block, block, block);

	// Ask for name, dob, hp, residential address

	// Naming process
	boolean correct_name = False; // check if the format of the name is acceptable
	while (!correct_name)
	{
		printf("Enter your name: ");
		name = GetUserInput();

		if (CheckStringLength(name) > MAX_NAME)
		{
			printf("Name too long.\n");
			free(name);
			continue;
		}
		if (!CheckName(name))
		{
			printf("Name contain special characters\n"); 
			continue;
		}

		// Confirm input from user
		if (!Confirmation("name", name))
		{
			free(name);
			continue;
		}
		correct_name = True; // to break out of the look
	}

	// DOB process
	boolean correct_dob = False;
	while (!correct_dob)
	{
		printf("Enter your Date of Birth (DD/MM/YYYY): ");
		char* dob = GetUserInput();
		char c_dd[2] = { dob[0], dob[1] };
		char c_mm[2] = { dob[3], dob[4] };
		char c_yyyy[4] = { dob[6], dob[7], dob[8], dob[9] };

		dd = atoi(c_dd);
		mm = atoi(c_mm);
		yyyy = atoi(c_yyyy);

		if (!CheckValidDate(dd, mm, yyyy))
		{
			printf("Invalid Date of Birth.\n");
			free(dob);
			continue;
		}

		// Confirm input from user
		if (!Confirmation("Date of Birth", dob))
		{
			free(dob);
			continue;
		}
		correct_dob = True;
		free(dob);
	}

	// Age process
	age = CalculateAge(dd, mm, yyyy);

	// Phone number process
	boolean correct_phone_number = False;
	while (!correct_phone_number)
	{
		printf("Enter your phone number: ");
		phone_number = GetUserInput();

		if (CheckStringLength(phone_number) != MAX_PHONE_NUMBER)
		{
			printf("Incorrect phone number\n");
			free(phone_number);
			continue;
		}

		// Confirm input from user
		if (!Confirmation("phone number", phone_number))
		{
			free(phone_number);
			continue;
		}
		correct_phone_number = True;
	}

	// Residential address
	boolean correct_residential_address = False;
	while (!correct_residential_address)
	{
		printf("Enter your residential address: ");
		residential_address = GetUserInput();

		if (!Confirmation("residential address", residential_address))
		{
			free(residential_address);
			continue;
		}

		correct_residential_address = True;
		printf("%s", residential_address);
	}

	// generate a bank acc number for this customer

	// generate a verification number (3 digits, for removing of account)

	// amount to be deposit to the account

	// save into data base

	// Free memories after saving to db
	free(name);
}

// Update information of existing account 
void UpdateAccountInfo()
{
	// Only able to change name, hp and residential address
}

// For transactions
void Transaction()
{
	// deposit / withdraw / transfer
}

// Check detail of existing account
void CheckAccountDetails()
{
	// return the sum of money in bank account based on account number
}

// Remove existing account 
void RemoveAccount()
{
	// Remove an account number based on account number
	// Verification process, ask for name, hp number and verification code
}

// View customer list
void ViewCustomers()
{

}

// Using this function to reset everything back to normal
void Reset()
{
	printf("\n");
}
#pragma endregion
#pragma region USER RELATED FUNCTIONS
// Get user input (dynamically increase the size of the string)
char* GetUserInput()
{
	int c;
	char* userInput = (char*)malloc(sizeof(char));
	userInput[0] = '\0';
	for (int i = 0; (c = getchar()) != '\n' && c != -1; i++)
	{
		userInput = (char*)realloc(userInput, (i + 2) * sizeof(char)); // realloc mem
		userInput[i] = (char)c;
		userInput[i + 1] = '\0';
	}
	return userInput;
}

// Check if there are any special characters in the name
boolean CheckName(char name[])
{
	for (int i = 0; name[i] != '\0'; ++i)
	{
		// Only allow spaces and alphbets
		if(name[i] != ' ' && (name[i] < 'A' || name[i] > 'Z') && (name[i] < 'a' || name[i] > 'z'))
			return False; // name is invalid
	}
	return True; // the name is valid
}

// Check the length of the string
int CheckStringLength(char* str)
{
	int len = 0;
	for (int i = 0; str[i] != '\0'; ++i)
		++len;
	return len;
}
// Confirm input from user
boolean Confirmation(char* str1, char* str2)
{
	// Confirm with user
	while (True)
	{
		printf("Is your %s %s? (Y/N)\n", str1, str2);
		char* confirmation = GetUserInput();

		if (!strcmp(confirmation, "N") || !strcmp(confirmation, "n"))
		{
			free(confirmation);
			return False; // N
		}
		if (strcmp(confirmation, "Y") && strcmp(confirmation, "y"))
		{
			free(confirmation);
			continue;
		}
		free(confirmation);
		return True; // Y
	}
}
#pragma endregion
#pragma region TIME RELATED FUNCTIONS
// Check if the date is a valid day
boolean CheckValidDate(int dd, int mm, int yyyy)
{
	// Check birthdate with today's date

	if (mm < JAN || mm > DEC)
		return False;
	// For months with 31 days
	if ((dd >= 1 && dd <= 31) && mm == JAN || mm == MAR || mm == MAY || mm == JUL || mm == AUG || mm == OCT || mm == DEC) 
		return True;
	// For months with 30 days only
	if ((dd >= 1 && dd <= 30) && mm == APR || mm == JUN || mm == SEP || mm == NOV)
		return True;
	if ((dd >= 1 && dd <= 28) && mm == FEB) // For the month of Feb
		return True;
	if (dd == 29 && mm == FEB && yyyy % 4 == 0) // check for leap years
		return True;
	return False;
}

// Calculate the age of customer
int CalculateAge(int dd, int mm, int yyyy)
{
	int age = 0;
	int tdy_dd = 0, tdy_mm = 0, tdy_yyyy = 0;
	char time_str[30] = { '\0' };

	time_t curr_time;
	time(&curr_time);

	// copy curr_time to time_str
	strcpy(time_str, ctime(&curr_time));

	char tdy_cdd[2] = { time_str[8],time_str[9] };	
	char tdy_cmm[4] = { time_str[4], time_str[5], time_str[6], '\0' };
	char tdy_cyyyy[4] = { time_str[20], time_str[21], time_str[22], time_str[23] };

	// convert str to int
	tdy_dd = atoi(tdy_cdd);
	tdy_mm = GetMonth(tdy_cmm);
	tdy_yyyy = atoi(tdy_cyyyy);

	// calculate the age
	age = tdy_yyyy - yyyy;
	if (tdy_dd < dd || tdy_mm < mm)
		--age;
	return age;
}

// Get int value of the month
int GetMonth(char mm[])
{
	if (!strcmp(mm, "Jan")) return JAN;
	if (!strcmp(mm, "Feb")) return FEB;
	if (!strcmp(mm, "Mar")) return MAR;
	if (!strcmp(mm, "Apr")) return APR;
	if (!strcmp(mm, "May")) return MAY;
	if (!strcmp(mm, "Jun")) return JUN;
	if (!strcmp(mm, "Jul")) return JUL;
	if (!strcmp(mm, "Aug")) return AUG;
	if (!strcmp(mm, "Sep")) return SEP;
	if (!strcmp(mm, "Oct")) return OCT;
	if (!strcmp(mm, "Nov")) return NOV;
	if (!strcmp(mm, "Dec")) return DEC;
}
#pragma endregion