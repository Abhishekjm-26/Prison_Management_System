#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>

#include "prison.cpp"

using namespace std;

int main()
{
	int ch,check;
	cout<< "				==========================================================\n";
	cout<< "				---------FILE STRUCTURES LABORATORY MINI PROJECT----------\n";
	cout<< "				==========================================================\n";
	cout<< "				---PRISON MANAGEMENT SYSTEM USING RELATIVE RECORD NUMBER--\n";
	cout<< "				==========================================================\n";
	cout<< "				4JN18IS001 - ABHISHEK J M && 4JN18IS002 - ADARSH N INAMDAR\n";
	cout<< "				==========================================================\n";
	while(1)
	{
			check = P.owner_authen();
					if (check == 1)
					{
						do
						{ 
							cout<<"\n";
							cout<<"			-------------------------------------------------\n\n";
						cout	<< "				$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       " << endl
							<< "         			1.Add Prisoner" << endl
             					<< "         			2.View Prisoners" << endl
             					<< "         			3.Find Prisoner" << endl
             					<< "         			4.Erase Prisoner" << endl
             					<< "         			5.Exit" << endl
             					<< "				$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       " << endl;
							cout	<< "			--------------------------------------------------\n\n";
							cout<<"ENTER YOUR CHOICE\n";
							cin>>ch;
							switch(ch)
							{
								case 1:	P.readprison();
										P.packprison();
										P.write_prison_to_file();
										break;
								case 2:	P.display_prison_rrn_list();
										break;
								case 3:	P.create_prison_rrn_list();
										break;
								case 4:	P.remove_prison_rrn_list();
										break;
								default : 	break;
							}
						}while(ch<5);
					}
					else{
						cout<<"				Invalid Login\n";
					}
				break;
	}
}
			
			