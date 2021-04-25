#include "ManagementSystem.h"

int main()
{
	boolean isExit = False;

	// "COLOR BACKGROUND_COLOR + FOREGROUND_COLOR"
	system("COLOR 01");  
	printf("        CUSTOMER ACCOUNT BANK MANAGEMENT SYSTEM\n");

	while (!isExit)
	{
		MainMenu();
		char* userInput = GetUserInput();
		int input = atoi(userInput);

		switch (input)
		{
			case 1: // Create new account
				CreateNewAccount();
				break;
			case 2: // Update information of existing account 
				UpdateAccountInfo();
				break;
			case 3: // For transactions
				Transaction();
				break;
			case 4: // Check detail of existing account 
				CheckAccountDetails();
				break;
			case 5: // Remove existing account 
				RemoveAccount();
				break;
			case 6: // View customer list
				ViewCustomers();
				break;
			case 7: // Exit
				isExit = True;
				break;
			default:
				printf("Invalid choice, please try again.\n");
				break;
		}
		// reset any variable that needs to be resetted
		Reset();
		free(userInput);
	}
}