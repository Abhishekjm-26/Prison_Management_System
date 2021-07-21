#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;


class prison
{
	int run_array[100],no_of_recs;
	string prison_id,buffer;
	string prison_name;
    	int count,addrun_array[100];
	public :void readprison();
	void packprison();
	void write_prison_to_file();
	void create_prison_rrn_list();
	int searchprison(int);
	int removeprison(int);
	void remove_prison_rrn_list();
	void display_prison_rrn_list();
	int owner_authen();
}P;
int prison::owner_authen() {
	char o_username[20], o_password[20];
	char o_user[20] = "prison", o_pass[20] = "24680";
	cout << endl << endl;
	cout.width(25);
	cout<< "				Enter Admin ID and Password\n"; 
	cout<< "				---------------------------\n";
	cout<< "				Admin ID: ";
	cin >> o_username;
	cout<< "				---------------------------\n";
	cout << "				Password: ";
	cin >> o_password;
	cout<< "				---------------------------\n";
	if (strcmp(o_username, o_user) == 0 && strcmp(o_password, o_pass) == 0)
		return 1;
	else
		return 0;
}
void prison::readprison()
{
	cout << "\tEnter Prison ID :";
    	cin >> prison_id;
    	cout << "\tEnter Prison Name  :";
    	cin >> prison_name;
}
void prison::packprison()
{
	buffer.erase();
	buffer+=prison_id+"|"+prison_name+"$\n";
}
void prison::write_prison_to_file()
{
	fstream fp;
	fp.open("prison.txt",ios::out |ios::app);
	fp<<buffer;
	buffer.erase();
	fp.close();
}
void prison::create_prison_rrn_list()
{
	ifstream ifile;
	ifile.open("prison.txt");
	if(ifile)
	{
		std::ifstream ifs("prison.txt",std::ios::ate);
		if(ifs.tellg() == 0)
		{
			cout<<"No Records Inserted\n";
		}
		else
		{
			int posec,rrn=1;
			fstream fp;
			fp.open("prison.txt",ios::in);
			no_of_recs=0;
			cout<<"\n RRN NO \t RECORD\n";
			do
			{
				posec=fp.tellg();
     				run_array[no_of_recs++]=posec;
     				getline(fp,buffer);
     				if(fp.eof())
     				break;
     				cout<<"\n"<<rrn<<"\t"<<buffer;
     				rrn++;
			}while(1);
			buffer.erase();
			fp.close();
			cout<<"\n\nENTER THE RRN \n";
			cin>>rrn;
			P.searchprison(rrn);
		}
	}
	else{
		cout<<"\nError! Records not inserted\n";
	}
}
void prison::display_prison_rrn_list()
{
	ifstream ifile;
	ifile.open("prison.txt");
	if(ifile)
	{
		std::ifstream ifs("prison.txt",std::ios::ate);
		if(ifs.tellg() == 0)
		{
			cout<<"No Records Inserted\n";
		}
		else
		{
			int posec,rrn=1;
			fstream fp;
			fp.open("prison.txt",ios::in);
			no_of_recs=0;
			cout<<"\n RRN NO \t RECORD\n";
			do
			{
				posec=fp.tellg();
     				run_array[no_of_recs++]=posec;
     				getline(fp,buffer);
     				if(fp.eof())
     				break;
     				cout<<"\n"<<rrn<<"\t"<<buffer;
     				rrn++;
			}while(1);
			buffer.erase();
			fp.close();		
		}
	}
	else{
		cout<<"\nError! Records not inserted\n";
	}
}


int prison::searchprison(int rrn)
{
    int pos,pos1 = 0,i=0;
    if(rrn<=0 ||rrn>=no_of_recs){
    	cout<<"\n RECORD NOT FOUND ";
    	return 0;
    }
    else
    {
		pos=run_array[rrn-1];
        	fstream fp;
        	fp.open("prison.txt",ios::in);
        	fp.seekg(pos,ios::beg);
        	getline(fp,buffer);
        	if(buffer[0] == '*')
        	{
        		cout<<"\nRecord Not Found";
        		return 0;
        	}
        	cout<<"\n RECORD FOUND \n";
        	cout<<buffer;
        	pos1=fp.tellg();
        	return pos1;
        	buffer.erase();
        	fp.close();
    }
}
void prison::remove_prison_rrn_list()
{
	ifstream ifile;
	ifile.open("prison.txt");
	if(ifile)
	{
		std::ifstream ifs("prison.txt",std::ios::ate);
		if(ifs.tellg() == 0)
		{
			cout<<"No Records Inserted\n";
		}
		else
		{
			int posec,rrn=1;
			fstream fp;
			fp.open("prison.txt",ios::in);
			no_of_recs=0;
			cout<<"\n RRN NO \t RECORD\n";
			do
			{
				posec=fp.tellg();
     				run_array[no_of_recs++]=posec;
     				getline(fp,buffer);
     				if(fp.eof())
     				break;
     				cout<<"\n"<<rrn<<"\t"<<buffer;
     				rrn++;
			}while(1);
			buffer.erase();
			fp.close();	
			cout<<"\n\nENTER THE RRN \n";
			cin>>rrn;
			P.removeprison(rrn);
		}
	}
	else{
		cout<<"\nError! Records not inserted\n";
	}
}
int prison::removeprison(int rrn)
{
	fstream fp;
	char mark='*',t;
	int pos,flag=0;
	pos=searchprison(rrn);
	if(pos)
	{
		fp.open("prison.txt",ios::in|ios::out);
		pos-=2;
		t=fp.get();
		while(t!='$'&&pos!=0)
		{
			pos--;
			fp.seekp(pos,ios::beg);
			t=fp.get();
		}
		if(pos!=0)
			fp.seekp(pos+2,ios::beg);
		else
			fp.seekp(pos,ios::beg);
		fp.put(mark);
		flag=1;
		cout<<"\nRecord has been deleted\n";
	}
	fp.close();
	if(!flag)
		return 0;
	else
		return 1;
}

