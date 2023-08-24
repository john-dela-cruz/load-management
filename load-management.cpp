#include<iostream>
#include<fstream>

using namespace std;

int main(){
	
	int choice;
	
	while(choice != 3){ // Loop for the menu
		cout << "1 - Load Management" << endl;
		cout << "2 - Check Balance" << endl;
		cout << "3 - Exit" << endl;
		
		cout << "Enter Choice: ";
		cin >> choice;
		
		if(choice == 1){ // Condition for choice 1
			ofstream file;
			file.open("load.txt",ios::app);
			
			int load;
			string mobileNo;
			int confirm;
			
			cout << "Load: ";
			cin >> load;
			cout << "Mobile Number: ";
			cin >> mobileNo;
			cout << "Confirm[1/0]: ";
			cin >> confirm;
			
			if(confirm == 1){
				cout << mobileNo << " has been successfully loaded with PHP" << load << endl;
				
				file << mobileNo << endl;
				file << load << endl;
			}
			else if(confirm == 2){
				cout << "Sorry, your was not registered!" << endl;
			}
			else{
				cout << "Input Invalid" << endl;
			}
			
			file.close();
		}
		else if(choice == 2){ // Condition for choice 2
			ifstream file;
			file.open("load.txt",ios::in);
			
			string mobileNo;
			string userMobile;
			int load;
			
			cout << "Enter your number: ";
			cin >> userMobile;
			
			if(file.is_open())
			{
				while(!file.eof()){
					file >> mobileNo;
					file >> load;
					
					if(mobileNo == userMobile)
					{
						cout <<"The user's mobile "<< userMobile << " has PHP" << load << " balance." << endl;
						break;	
					}
					else if(file.eof() && mobileNo != userMobile)
					{
						cout <<"The user's mobile is not registered!" << endl;
					}
				}
			}
			
			file.close();
		}
		else if(choice == 3){ // Condition for choice 3
			cout << "Thank you for using the system!" << endl;
		}
		else{ // Condition for catching errors
			cout << "Input Invalid" << endl;
		}
	}
}
