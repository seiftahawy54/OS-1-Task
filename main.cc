#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

// Handle system function prototype.
void systemInit();
void handleSystem(int);
string _getPermissionsFileName ();
int _promptUser(string);
string _buildPermissionArguments (int,int,int);

// Start files and folders lister.
void listFilesAndFolders()
{
	system("ls -l");
}
// End files and folders lister.
// Start premissions changer.
void changeFilesPermissions()
{
	// List files & folders
	cout<< "\n\n";
	system("ls -l");

	// Check if this is a valid name
	string name = _getPermissionsFileName();

	// get permission values
	int read, write, excute;

	read = _promptUser("read");
	write = _promptUser("write");
	excute = _promptUser("excute");

	// Build and exute command
	string command = "chmod ";
	command +=_buildPermissionArguments(read, write, excute);
	command += " " + name;

	// system accepts const strings, so this function returns a const string version of "that"
	system(command.c_str());
	cout<< endl << "Permissions changed for " + name + " successfully !\n\n";
}
int _promptUser(string prompt){
	string response;
	do{
		cout<< "You want to " + prompt + " this file ? [Y/N]\t";
		cin>> response;
	} while(response != "Y" && response != "y" && response != "N" && response != "n");
	
	if (response == "Y" || response == "y"){
		return 1;
	}else{
		return 0;
	}
}

string _buildPermissionArguments (int read, int write, int excute){
	string command = "";
	
	if(read == 0) command += '-';
	else command += '+';
	command += "r";

	if(write == 0) command += '-';
	else command += '+';
	command += "w";

	if(excute == 0) command += '-';
	else command += '+';
	command += "x";

	return command;
}

string _getPermissionsFileName (){
	string command;
	string name;

	int result;
	do {
		cout<< "Please enter a valid file name !"<<endl;
		cin>>name;
		
		command = "[ -f \"" + name + "\" ]";
		// system accepts const strings, so this function returns a const string version of "that"
		result = system(command.c_str());
	}
	while (result != 0);	// '0' tells that it returned successfully

	return name;
}

// End premissions changer.

// Start files manager
void initFileManagement()
{
    char s[10];
	char command[100];
	int choose;
	do
	{
		cout << "please, enter your operation : \n" << endl;
		cout << "1_to make directory.\n";
		cout << "2_to remove directory.\n";
		cout << "3_to make file.\n";
		cout << "4_to remove file.\n";
		cout << "5_to exist.\n";
		scanf("%d",&choose);
	switch(choose)
	{
	case 1 :
		cout << "enter your directory name : ";
		cin >> s;
		strcpy(command,"mkdir");
		strcat(command," ");
		strcat(command,s);
		system(command);
		break;
	case 2 :
		cout << "enter your directory name you want remove : ";
		cin >> s;
		strcpy(command,"rmdir");
		strcat(command," ");
		strcat(command,s);
		system(command);
		break;
	case 3 :
		cout << "enter your file name with extention : ";
		cin >> s;
		strcpy(command,"touch");
		strcat(command," ");
		strcat(command,s);
		system(command);
		break;
	case 4 :
		cout << "enter your file name you want remove : ";
		cin >> s;
		strcpy(command,"rm");
		strcat(command," ");
		strcat(command,s);
		system(command);
		break;
	}
	}while(choose!=5);
}
// End files manager
// Start symblic link files

void symbolicLinkFiles()
{
    // Files variabls.
    string firstFile, secondFile, command;
    // Prompting user to enter file to link
    cout << "Please enter first file\n" << endl;
    cin >> firstFile;
    // Prompting user to enter file to destination
    cout << "Please enter second file\n" << endl;
    cin >> secondFile;
    // Concatenate command.
    command += "ln -s " + firstFile + " " + secondFile;
    // covert the string command into array of characters.
    const char * cmd = command.c_str();
    // Make system call.
    system(cmd);
}

// End symblic link files
// Start Files handler function
void handleSystem(int num)
{
    while (true)
	{
		// handle system function
		if (num == 1)
		{
			listFilesAndFolders();
		}
		else if (num == 2)
		{
			changeFilesPermissions();
		}
		else if (num == 3)
		{
			initFileManagement();
		}
		else if (num == 4)
		{
			symbolicLinkFiles();
		}
		else if (num == 5)
		{
			cout << "Thanks for using our program <3" << endl;
			break;
		}
		else
		{
			cout << "\nPlease enter valid choice!\n" << endl;
			systemInit();
		}

		systemInit();
	}
}
// End Files handler function

void systemInit()
{
    // starting the main program.
    // Promting user to enter choices.
    cout << "Welcome in your file manager, Enter your choice please : \n" << endl;
    cout << "1. List files/directories.\n2. Change permissions of files.\n3. Make/delete files/directories\n4. Create symbolic link files.\n5. To Exit" << endl;
    
    // task number choice.
    int taskNum = 0;
    cin >> taskNum;

    // Pass the number to the function "handlesystem"
    handleSystem(taskNum);
}

// Main function to start executing the program.
int main()
{
    // System initiallizing function.
    systemInit();

    return 0;
}