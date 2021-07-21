#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class inmate
{
	int run_array[100],no_of_recs;
	string pid,iid,iname,nationalism,crime,hstatus,datein,buffer;
	string age;
	int count,addrun_array[100];
	public :void readinmate();
	void packinmate();
	void write_inmate_to_file();
	void create_inmate_rrn_list();
	int searchinmate(int);
	int removeinmate(int);
	void display_inmate_rrn_list();
	void remove_inmate_rrn_list();
	int owner_authen();
}I;
int inmate::owner_authen() {
	char o_username[20], o_password[20];
	char o_user[20] = "inmate", o_pass[20] = "24680";
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
void inmate::readinmate()
{
	cout << "\tEnter Prison ID  :";
    	cin >> pid;
	cout << "\tEnter Inmate ID  :";
    	cin >> iid;
	cout << "\tEnter Inmate Name  :";
    	cin >> iname;
	cout << "\tEnter Age :";
    	cin >> age;
	cout << "\tEnter Nationalism :";
    	cin >> nationalism;
	cout << "\tEnter Crime :";
    	cin >> crime;
	cout << "\tEnter Heath Status :";
    	cin >> hstatus;
	cout << "\tEnter the Date In :";
    	cin >> datein;
}
void inmate::packinmate()
{
	buffer.erase();
	buffer+=pid+"|"+iid+"|"+iname+"|"+age+"|"+nationalism+"|"+crime+"|"+hstatus+"|"+datein+"$\n";
}
void inmate::write_inmate_to_file()
{
	fstream fp;
	fp.open("inmate.txt",ios::out |ios::app);
	fp<<buffer;
	buffer.erase();
	fp.close();
}
void inmate::create_inmate_rrn_list()
{
	ifstream ifile;
	ifile.open("inmate.txt");
	if(ifile)
	{
		std::ifstream ifs("inmate.txt",std::ios::ate);
		if(ifs.tellg() == 0)
		{
			cout<<"No Records Inserted\n";
		}
		else
		{
			int poimt,rrn=1;
			fstream fp;
    			fp.open("inmate.txt",ios::in);
    			no_of_recs=0;
    			cout<<"\n RRN NO \t RECORD\n";
    			do
    			{
     				poimt=fp.tellg();
     				run_array[no_of_recs++]=poimt;
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
			I.searchinmate(rrn);
		}
	}
	else{
		cout<<"\nError! Records not inserted\n";
	}
}
void inmate::display_inmate_rrn_list()
{
	ifstream ifile;
	ifile.open("inmate.txt");
	if(ifile)
	{
		std::ifstream ifs("inmate.txt",std::ios::ate);
		if(ifs.tellg() == 0)
		{
			cout<<"No Records Inserted\n";
		}
		else
		{
			int poimt,rrn=1;
			fstream fp;
    			fp.open("inmate.txt",ios::in);
    			no_of_recs=0;
    			cout<<"\n RRN NO \t RECORD\n";
    			do
    			{
     				poimt=fp.tellg();
     				run_array[no_of_recs++]=poimt;
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

int inmate::searchinmate(int rrn)
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
        	fp.open("inmate.txt",ios::in);
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
void inmate::remove_inmate_rrn_list()
{
	ifstream ifile;
	ifile.open("inmate.txt");
	if(ifile)
	{
		std::ifstream ifs("inmate.txt",std::ios::ate);
		if(ifs.tellg() == 0)
		{
			cout<<"No Records Inserted\n";
		}
		else
		{
			int poimt,rrn=1;
			fstream fp;
    			fp.open("inmate.txt",ios::in);
    			no_of_recs=0;
    			cout<<"\n RRN NO \t RECORD\n";
    			do
    			{
     				poimt=fp.tellg();
     				run_array[no_of_recs++]=poimt;
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
			I.removeinmate(rrn);	
		}	
	}
	else{
		cout<<"\nError! Records not inserted\n";
	}
}
int inmate::removeinmate(int rrn)
{
	fstream fp;
	char mark='*',t;
	int pos,flag=0;
	pos=searchinmate(rrn);
	if(pos)
	{
		fp.open("inmate.txt",ios::in|ios::out);
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

