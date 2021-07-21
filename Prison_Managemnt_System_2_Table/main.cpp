#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>

#include "prison.cpp"
#include "inmate.cpp"

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
			cout<<"\n";
			cout<<"			-------------------------------------------------\n\n";
			cout	<< "				$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       " << endl	
				<<"			 		1:PRISON"	<<	endl
				<<"			 		2:INMATE"	<<	endl
				<<"			 		3:LOGOUT"	<<	endl
				<< "				$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       " << endl;
			cout	<< "			--------------------------------------------------\n\n";			
			cout<<" ENTER YOUR CHOICE \n";
			cin>>ch;
			switch(ch)
			{
				case 1:	cout<<"					PRISON\n";
						cout<<"					------\n";
						int ch1;
						check = P.owner_authen();
						if (check == 1)
						{
							do
							{
								cout<<"\n";
								cout<<"			-------------------------------------------------\n\n";
								cout	<< "				$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       " << endl
									<< "         			1.Add Prison"		<<	endl
             							<< "         			2.View Prison"		<< 	endl
             							<< "         			3.Find Prison"		<< 	endl
             							<< "         			4.Erase Prison"		<< 	endl
             							<< "         			5.Exit"			<< 	endl
             							<< "				$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       " << endl;
								cout	<< "			--------------------------------------------------\n\n";
									cout<<"ENTER YOUR CHOICE\n";
									cin>>ch1;
									switch(ch1)
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
							}while(ch1<5);
						}
						break;
					
				case 2:	cout<<"					INMATE\n";
						cout<<"					------\n";
						int ch2;
						check = I.owner_authen();
						if (check == 1)
						{
							do
							{
								cout<<"\n";
								cout<<"			-------------------------------------------------\n\n";
								cout	<< "				$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       " << endl
									<< "         			1.Add Inmate"		<<	endl
             							<< "         			2.View Inmate"		<< 	endl
             							<< "         			3.Find Inmate"		<< 	endl
             							<< "         			4.Erase Inmate" 		<< 	endl
             							<< "         			5.Exit"			<< 	endl
             							<< "				$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       " << endl;
								cout	<< "			--------------------------------------------------\n\n";
									cout<<"ENTER YOUR CHOICE\n";
									cin>>ch2;
									switch(ch2)
									{
										case 1:	I.readinmate();
												I.packinmate();
												I.write_inmate_to_file();
												break;
										case 2:	I.display_inmate_rrn_list();
												break;
										case 3:	I.create_inmate_rrn_list();
												break;
										case 4:	I.remove_inmate_rrn_list();
												break;
										default : 	break;
									}
							}while(ch2<5);
						}
						break;
					
				case 3:	cout<<"TQ FOR USING THE APPLICATION\n";
						break;
				}
		}
}
				
				
	
		
			
