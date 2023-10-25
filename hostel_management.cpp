#include <iostream>
#include<bits/stdc++.h>
#include<windows.h>
#include<MySQL.h>
#include<mysqld_error.h>
#include<sstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
const char* HOST="localhost";
const char * USER="root";
const char* PW =" ";
const char* DB="mydb";

class Hostel{
	private:
		string name;
		int bed,fee;
		public:
			Hostel(string name,int bed,int fee){
				this->name=name;
				this->bed=bed;
				this->fee=fee;
			}
			string getname(){
				return name;
			}
			int getbed(){
				return bed;
				
			}
			int getfee(){
				return fee;
			}
};
 
int main(int argc, char** argv) {
 MYSQL* conn;
 conn=mysql_init(NULL);
 //display error if actual connection nhi hora
 if(!mysql_real_connect(conn,HOST,USER,PW,DB,3306,NULL,0)){
 	cout<<"Error: "<<mysql_error(conn);
 }
 else{
 	cout<<"Logged in database"<<endl;
 	
 }
 //windows.h feature
 Sleep(3000);
 
 
 ////////////
 Hostel h("3star",5,5000);
 int intb=h.getbed();
 stringstream ss;
 ss<<intb;
 string strb=ss.str();
 ///
  int intf=h.getfee();
 stringstream ff;
 ff<<intf;
 string strf=ff.str();
 string insert = "INSERT INTO hostels(name,bed,fee)values('"+h.getname()+"','"+strb+"','"+strf+"')";
 if(mysql_query(conn,insert.c_str())){
 	cout<<"Error: "<<mysql_error(conn)<<endl;
 	
 }
 else{
 	cout<<"Data inserted";
 }
 bool exit=false;
 while(!exit){
 	//previous hide
 	system("cls");
 	cout<<"Welcome to Hostel Management System"<<endl;
 	cout<<"************************************"<<endl;
 	cout<<"1. Reserve bed: "<<endl;
 	cout<<"2.Exit: "<<endl;
 	cout<<"Enter your choice: ";
 	int val;
 	cin>>val;
 	if(val==1){
 		string n;
 		cout<<"Enter Student Nmae: ";
 		cin>>n;
 		int total;
 		string check=" SELECT bed FROM hostels WHERE name='"+h.getname()"'";
  if(mysql_query(conn,insert.c_str())){
 	cout<<"Error: "<<mysql_error(conn)<<endl;
 	
 }
 else{
   MYSQL_RES* res;
   res=mysql_store_result(conn);
   if(res){
   	MYSQL_ROW row=mysql_fetchrow(res);
   	if(row){
   		total=atoi(row[0]);
	   }
	   mysql_free_result(res);
   }
 }
 if(total>0){
 	total--;
 	stringstream zs;
 	zs<<total;
 	string strt=zs.str();
 	string update="UPDATE hostels SET bed='"+strt+"',WHERE name='"+h.getname()+"'";
 	if(mysql_query(conn,insert.c_str())){
 	cout<<"Error: "<<mysql_error(conn)<<endl;
 	
 }
 else{
 	cout<<"Bed is reserved successfully in "<<h.getname()<<" Hostel for Student "<<n<<endl;
 	cout<<"Please Pay "<<h.getfee()<<"Rupees."<<endl;
 }
 }
 else if(total==0){
 	cout<<"Sorry! No Bed Available"<<endl;
 }
 Sleep(8000);
	 }//if1
	 else if (val==2){
	 	exit=true;
	 	cout<<"Good Luck"<<endl;
	 	Sleep(3000);
	 }
///////	 
 else{
 	cout<<"Tnvalid Entry"<<endl;
 	Sleep(3000);
 }	
 }//while
 mysql_close(conn);
	return 0;
}
