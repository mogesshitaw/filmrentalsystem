#include <iostream>
#include<fstream>
#include <string>
#include<windows.h>
using namespace std;
int count1=0,countrent=0;
// Structure to represent a film
struct Film {
    string title;
    int part;
    string type;
    Film *next;
}*head=NULL;
// Structure to represent rented films
struct RentedFilm {
    string title;
    int part;
    string type;
    string rentalDate;
    string returnDate;
    float rentPrice;
    string Name;
    string  id;
    RentedFilm *link;
}*start=NULL;
HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
void addFilm(string ,int ,string );
void storte_film_to_file();
void retrivefilm_to_file();
void deleteFilm();
void displayAllFilms();
void displayFilmByTitle(string );
void displayFilmsByType(string);
void rent_of_film(string ,int ,string ,string ,string ,float ,string ,string);
void addrentFilm(string ,int );
void storte_rent_film_to_file();
void retrive_rent_film_to_file();
 void displayRentedFilms();
 void displayUnrentedFilms();
 void sortdata();
 void line1();
 void line2();
 void line3();
 struct Film *createnode(){
 	Film *node=new Film;
 			cout<<"\npleace enter the  data \n";
    		cout<<"\nenter film title >>";
           		cin.ignore();
      			getline(cin,node->title);
			  	cout<<"\nenter part of film>>";
				cin>>node->part;
				cout<<"\nenter type of film>>";
				cin.ignore();
				getline(cin,node->type);
				node->next=NULL;				
				return node;	 	
 }
 void in_at_beg()
 {
 	Film *temp;
 	temp=createnode();
 	if(head==NULL)
 	{
 		head=temp;
	 }
	 else
	 {
	 	temp->next=head;
	 	head=temp;
	 }
 }
 void at_the_end()
 {
 	Film *temp,*temp1;
 	temp=createnode();
 	if(head==NULL)
 	{
 		head=temp;
	 }
	 else
	 {
	 	temp1=head;
	 	while(temp1->next != NULL)
	 	{
	 		temp1=temp1->next;
		 }
		 temp1->next=temp;
	 }
 }
 void at_specfic_position()
 {
 		int pos,count=1;
 	cout<<"Enter you want specific position"<<endl;
 	cin>>pos;
 	Film *temp,*temp1,*temp2;
 	temp=createnode();
 	temp1=head;
 	while(count<pos)
 	{
 	 temp2=temp1;
	  temp1=temp1->next;
	  count++;	
	 }
	 temp2->next=temp;
	 temp->next=temp1;	
 }
//function definition of add new film from either file or user
void addFilm(string title,int part,string type) {
    Film *temp,*film=new Film;
    film->title=title;
    film->part=part;
    film->type=type;
	film->next=NULL;

	if(head==NULL)
	{
	   head=film;
	}
	else
	{
	   temp=head;
	   while(temp->next != NULL)
	   {  
	   	temp=temp->next;}
	       temp->next=film;
     }  

	 
}
void storte_film_to_file()
{
    ofstream file1;
	file1.open("films.dat",ios::app);
	if(file1.is_open())
	{
	Film *temp=head;
	while(temp != NULL)
	{				
   file1<<temp->title<<" "<<temp->part<<" "<<temp->type<<endl;
   
 temp=temp->next;
	}
	file1.close();
	cout<<"film is stored in file"<<endl;	
	}
	else
	{
		cout<<"\t\tunable to open file "<<endl;
	}
}
//function to retrive film to file
void retrivefilm_to_file()
{   
	struct Film f;
    ifstream ifile;
    ifile.open("films.dat");
    if(ifile.is_open())
    {
    	while(ifile>>f.title>>f.part>>f.type)
    	{   	
  		 addFilm(f.title,f.part,f.type);
		}	
		ifile.close();
	
			}
			else
			{
				//cout<<"\t\tunable to open file"<<endl;
				cout<<endl;
			} 
}
void deleteFilm(string title,int part) {
			   Film *temp,*temp1;
			   		  if(head->title== title&&head->part==part)
  	  {  	  	
				temp=head;
  	    		head=head->next;
  	    		delete temp;}
  	    else{
    		temp=head;
    	   while( temp->title !=title || temp->part!=part)
    	   {
    			temp1=temp;
    			temp=temp->next;
    			if(temp==NULL)
    			{
    			cout<<"\t\t*************************************"<<endl;
				cout<<"\t\tyou enter error"<<endl;
				cout<<"\t\t*************************************"<<endl;
    			return;}
    		}
    			temp1->next=temp->next;
    			delete temp; }
    			cout<<"\t\t*************************************"<<endl;
 				cout<<"\n\t\tdelete sucessfully\n"<<endl;
 				cout<<"\t\t*************************************"<<endl;
    			}
				
	void tempofilefilms()
    			{
    				//function to create temporary file for deleting
    			ofstream file1;
   				ifstream ifile1("films.dat");
   				if(ifile1.is_open())
    		{
	 			file1.open("tempfile.dat");	 			 					
				Film *temp3=head;
    			while(temp3!=NULL)
   			{
   				file1<<" "<<temp3->title<<" "<<temp3->part<<" "<<temp3->type<<endl;
   				temp3=temp3->next;   			
			}
    			ifile1.close();
    			file1.close();
   				remove("films.dat");
   				rename("tempfile.dat","films.dat") ;
	}}

  void displayAllFilms() {

			Film *temp;
			int no=1; 
			SetConsoleTextAttribute(color,12);		
			line1();
    		if(head==NULL)
    	{	
		SetConsoleTextAttribute(color,14);
		cout<<"\t\t film is not found "<<endl;}
   		else {
    		temp=head;
    		while(temp !=NULL)
   		{       
   			SetConsoleTextAttribute(color,14);
   			cout<<"\t\t            DATA NUMBER "<<no<<endl;	
   			line2();
   			SetConsoleTextAttribute(color,11);
   		cout<<"\t\t  Title of film :"<<temp->title<<endl;
   			line3();
 		 cout<<" \t\t part of film  :"<<temp->part<<endl;
 			line3();
  			cout<<"\t\t Type of film  :"<<temp->type<<endl; 
  			line3();
  		    temp=temp->next;
			no++;	
    }}
    SetConsoleTextAttribute(color,12);	
	line1();
}
//Function to display a single film based on title
 void displayFilmByTitle(string title) {
    		Film *temp;
    		int no=1,flag=0;
    		SetConsoleTextAttribute(color,12);	line1();
    		if(head==NULL)
    	{	
			SetConsoleTextAttribute(color,14);cout<<"\t\t film  is not found"<<endl;}
    	else {
    		temp=head;
    		while(temp != NULL)
    	{
    		if(temp->title==title)
    	{   
			SetConsoleTextAttribute(color,14);			
   			cout<<"\t\t            DATA NUMBER "<<no<<endl;	
   			cout<<"\t\t*************************************"<<endl;
   			 SetConsoleTextAttribute(color,11);
   			cout<<"\t\t  Title of film :"<<temp->title<<endl;
   			cout<<"\t\t------------------------------------"<<endl;
 			cout<<"\t\t  part of film  :"<<temp->part<<endl;
 			cout<<"\t\t------------------------------------"<<endl;
  			cout<<"\t\t  Type of film  :"<<temp->type<<endl; 
  			cout<<"\t\t------------------------------------"<<endl;
  			flag=1;
  			no++;
		}
  		    temp=temp->next;
			
		}
			if(flag==0)	
		{
			SetConsoleTextAttribute(color,14);
			cout<<"\t\tthis type is not found"<<endl;
		}}	
		SetConsoleTextAttribute(color,12);	line1();
}
void displayFilmsByType(string type) {
    		Film *temp;
    		int no=1,flag=0;
    		SetConsoleTextAttribute(color,12);
   			line1();
    		if(head==NULL)
    	{	
			SetConsoleTextAttribute(color,14);
			cout<<"\t\t film is not found"<<endl;}
    	else {
    		temp=head;
    	
    		while(temp != NULL)
    	{
    		if(temp->type==type)
    	{
   			SetConsoleTextAttribute(color,14);
   			cout<<" \t\t           DATA NUMBER "<<no<<endl;	
   			cout<<"\t\t*************************************"<<endl;
   			 SetConsoleTextAttribute(color,11);
   			cout<<"\t\t  Title of film :"<<temp->title<<endl;
   			cout<<"\t\t------------------------------------"<<endl;
 			cout<<"\t\t  part of film  :"<<temp->part<<endl;
 			cout<<"\t\t------------------------------------"<<endl;
  			cout<<" \t\t Type of film  :"<<temp->type<<endl; 
  			cout<<"\t\t------------------------------------"<<endl;
  			flag=1;
  			no++;
		}
  		    temp=temp->next;
			
		}
		if(flag==0)	
		{
			SetConsoleTextAttribute(color,14);
			cout<<"\t\tthis type is not found"<<endl;
		}}
		SetConsoleTextAttribute(color,12);	
    line1();
}
//function definition of rent film from either file or user
void rent_of_film(string t,int p,string ty,string re,string ret,float Price,string name,string id)
{
RentedFilm *temp1, *temp=new RentedFilm;
temp->title=t;
temp->part=p;
temp->type=ty;
temp->rentalDate=re;
temp->returnDate=ret;
temp->rentPrice=Price;
temp->Name=name;
temp->id=id;
temp->link=NULL;

if(start==NULL)
{
	start=temp;
	
}
else
{
	temp1=start;	
	while(temp1->link != NULL)
	{	
	temp1=temp1->link;
	}
	temp1->link=temp;
}
}
// Function to rent a film
void addrentFilm(string title,int  part) {
    RentedFilm *Rfilm=new RentedFilm;
    Rfilm->title=title;
    Rfilm->part=part;
    Film *temp;
    
	int found=0;    
    temp=head;
        while(temp!=NULL)
        { 
    	 	if(temp->title==Rfilm->title && temp->part==Rfilm->part)
        	{   
        		Rfilm->type=temp->type;
        		cout<<"Enter rental date"<<endl;
        		cin.ignore();
        		getline(cin,Rfilm->rentalDate);
        		cout<<"Enter return date"<<endl;
        		getline(cin,Rfilm->returnDate);
        		cout<<"Enter price of rent film"<<endl;
        		cin>>Rfilm->rentPrice;
        		cout<<"Enter the name of who want to rent film"<<endl;
        	    cin.ignore();
        		getline(cin,Rfilm->Name);
        		cout<<"Enter person id"<<endl;
        	getline(cin,Rfilm->id); 		
      	rent_of_film(Rfilm->title,Rfilm->part,Rfilm->type,Rfilm->rentalDate,Rfilm->returnDate,Rfilm->rentPrice,Rfilm->Name,Rfilm->id);
        		found=1;
        		return;
			}
				
			temp=temp->next;			
			}			
			   if(found==0){
			   SetConsoleTextAttribute(color,14);
        	   cout<<"\t\tThis movioe is not found"<<endl;
			}
        else{SetConsoleTextAttribute(color,14);			
		  cout<<"\t\tThis film  is rented successfully!!"<<endl; 	}        		
        }
 void storte_rent_film_to_file(){
 				ofstream file;
 				file.open("rentedFilm.dat",ios::app);
 				if(file.is_open())
 				{
 				
 				RentedFilm *temp=start;
 				while(temp!=NULL){
 				file<<" "<<temp->title<<" "<<temp->part<<" "<<temp->type<<" "<<temp->rentalDate<<" "<<temp->returnDate<<" "<<temp->rentPrice<<" "<<temp->Name<<" "<<temp->id<<endl;
		  		temp=temp->link;
		   }
	    		file.close();
	 	   }
      else {
      			SetConsoleTextAttribute(color,14);
	    		cout<<"\t\tunable to open file"<<endl;
		   }}
		   //function to retrive file to rented film
   void retrive_rent_film_to_file(){
   	    RentedFilm rent;
   	    ifstream ifile;
   	    ifile.open("rentedFilm.dat");
   	    if(ifile.is_open()){  
   	    	
   		while(ifile>>rent.title>>rent.part>>rent.type>>rent.rentalDate>>rent.returnDate>>rent.rentPrice>>rent.Name>>rent.id)
   		{
   			rent_of_film(rent.title,rent.part,rent.type,rent.rentalDate,rent.returnDate,rent.rentPrice,rent.Name,rent.id); 
		  				
   		}		
		   ifile.close();
	   }
	   else {
	   		SetConsoleTextAttribute(color,14);
	    	cout<<"\t\tUnable to open file"<<endl;}
   }
   // Function to return a film
   void returnFilm(string title,int part)
  		{   
  	      	string Name;
   	     	RentedFilm *temp2,*temp1;
   			if(start->title== title&& start->part==part)
  	   {
		    temp2=start;
  	    	start=start->link;
  	    	delete temp2;}
  	  else{
    		temp2=start;
    	   while( temp2->title !=title || temp2->part!=part)
    	   {
    			temp1=temp2;
    			temp2=temp2->link;
    			if(temp2==NULL)
    			{SetConsoleTextAttribute(color,14);
				cout<<"\t\t this movoie is not found"<<endl;
    				return;}
    		}
    			temp1->link=temp2->link;
    			delete temp2; }
    			SetConsoleTextAttribute(color,14);
    			cout<<"\t\tThis film is returned sucessfully\n"<<endl;
				ofstream file1;
   				ifstream ifile1;
				 ifile1.open("rentedFilm.dat");
   				if(ifile1.is_open())
    		{
	 			file1.open("tempfile.dat");	 			 	    					
				RentedFilm *temp=start;
 				while(temp!=NULL)
 			{				 
 				file1<<" "<<temp->title<<" "<<temp->part<<" "<<temp->type<<" "<<temp->rentalDate<<" "<<temp->returnDate<<" "<<temp->rentPrice<<" "<<temp->Name<<" "<<temp->id<<endl;
		  		temp=temp->link;
		    }
				ifile1.close();
    			file1.close();
    			remove("rentedFilm.dat");
  			rename("tempfile.dat","rentedFilm.dat") ;
			}
			}  
   void displayRentedFilms() {
    		RentedFilm*temp;
    		SetConsoleTextAttribute(color,12);   
			line1();
    		if(start==NULL)
    		{
    		SetConsoleTextAttribute(color,14);
			cout<<"\t\tnot film found"<<endl;}
    	else
    	{
    		
    		int no=1;
    		temp=start;
    	while(temp != NULL)
    	{  
			SetConsoleTextAttribute(color,14);   	
   			cout<<"\t\t           DATA NUMBER "<<no<<endl;	
   			cout<<"\t\t*************************************"<<endl;
   			 SetConsoleTextAttribute(color,11);
   			cout<<"\t\t  Title of film :"<<temp->title<<endl;
   			cout<<"\t\t------------------------------------"<<endl;
   				cout<<"\t\t  part of film  :"<<temp->part<<endl;
 			cout<<"\t\t------------------------------------"<<endl;
  			cout<<"\t\t  Type of film  :"<<temp->type<<endl; 
  			cout<<"\t\t------------------------------------"<<endl;
    	    cout<<"\t\t  rental date   :"<<temp->rentalDate<<endl;
    	    cout<<"\t\t------------------------------------"<<endl;
    		cout<<"\t\t return date  :"<<temp->returnDate<<endl;
            cout<<"\t\t------------------------------------"<<endl;
            cout<<"\t\t  rental price :"<<temp->rentPrice<<endl;
 	    	cout<<"\t\t------------------------------------"<<endl;
    		cout<<"\t\t  rental person name :"<<temp->Name<<endl;
    	 	cout<<"\t\t------------------------------------"<<endl;
    		cout<<"\t\t  person id :"<<temp->id<<endl;
    		cout<<"\t\t------------------------------------"<<endl;
    		no++;
   			temp=temp->link;
        }
        } 
        SetConsoleTextAttribute(color,12);     
		line1();
		}
		void displayUnrentedFilms()  {
    		RentedFilm *Rfilm;
            Film *temp;
    			SetConsoleTextAttribute(color,12); 
  			line1();
    			if(start==NULL)
    			{SetConsoleTextAttribute(color,14);
   		 		cout<<"\t\tRented film is not found"<<endl;}
		else{
			   int no=1,flag,found=0;;   			
    		   temp=head;    				
    		   while(temp != NULL)  
    	{	   Rfilm=start;           
    		   while(Rfilm!= NULL){  
    				 flag=0;
    			if(Rfilm->title !=temp->title &&Rfilm->part!=temp->part) {		
		      	flag=1;
		         	}
		         	else if(Rfilm->title ==temp->title)
		         	{if(Rfilm->part!=temp->part){
		         		flag=1;}
		         		else 
		         		{flag=0;
		         		break;}}
				else
				{ 
					flag=0;
			    	break;
			    		}	
  		Rfilm=Rfilm->link;}
			if(flag==1){	   		   			   		     		   			   		  
			SetConsoleTextAttribute(color,14);
   			cout<<"\t\t          DATA NUMBER "<<no<<endl;
			SetConsoleTextAttribute(color,11);	
   			cout<<"\t\t*************************************"<<endl;
   		    cout<<"\t\t  Title of film :"<<temp->title<<endl;
   	        cout<<"\t\t------------------------------------"<<endl;
   	        cout<<"\t\t  part of film  :"<<temp->part<<endl;
 			cout<<"\t\t------------------------------------"<<endl;
  			cout<<"\t\t  Type of film  :"<<temp->type<<endl; 
  			cout<<"\t\t------------------------------------"<<endl;
  			no++;
  			found=1;
		    temp=temp->next; 	}	
		else
		{			    	
  	    	temp=temp->next;	
		}
			}
			if(found==0)
			{SetConsoleTextAttribute(color,14); 
				cout<<"\t\tunrented film is not found"<<endl;}
			}
		SetConsoleTextAttribute(color,12); 
		line1();	
		}
void count(){
Film *temp=head;
while(temp !=NULL){
count1++;
temp=temp->next;
}
RentedFilm *rent=start;
while(rent != NULL)
{
	countrent++;
	rent=rent->link;
}}
void Update_film(string title,int part)
{
Film *temp;
if(head==NULL)
{cout<<"film is not found"<<endl;
return;	}
else
{
	temp=head;
	while(temp!=NULL){
		if(temp->title==title&&temp->part==part)
		{
			cout<<"\nenter film title >>";
           	cin.ignore();
      		getline(cin,temp->title);
			cout<<"\nenter part of film>>";
			cin>>temp->part;
			cout<<"\nenter type of film>>";
				cin.ignore();
			getline(cin,temp->type);
		}
		temp=temp->next;
	}
cout<<"updeted successfull"<<endl;		
}}
void sortBypart() {
    if (head == NULL) {
        return;
    }

    bool swapped;
    Film* current;
    Film* last = NULL;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->part > current->next->part && current->title==current->next->title) {
                Film* temp = current->next;
                current->next = temp->next;
                temp->next = current;

                if (current == head) {
                    head = temp;
                } else {
                    Film* previous = head;
                    while (previous->next != current) {
                        previous = previous->next;
                    }
                    previous->next = temp;
                }

                swapped = true;
            } else {
                current = current->next;
            }
        }
        last = current;
    } while (swapped);

    
    cout << "Films sorted by part!" << endl;
}
void line1(){
	cout<<"\t";
	for(int i=1;i<64;i++)
	{cout<<"@";	}
	cout<<endl;
}
void line2(){
	cout<<"\t";
	for(int i=1;i<50;i++)
	{cout<<"*";	}
	cout<<endl;
}
void line3(){
	cout<<"\t";
	for(int i=1;i<40;i++)
	{cout<<"-";	}
	cout<<endl;
}
void mainmenu() {
          char ch;
          int   chance=3  ,choice,flag=1 ;
          while (flag) {
          	SetConsoleTextAttribute(color,12);	
        cout << "\t****************************************************"<<endl;
          	cout<<"\t\t    MAIN MENU"<<endl;
        cout << "\t****************************************************"<<endl;
          	SetConsoleTextAttribute(color,6);
          	line1();
        cout << "\t@ \tPRESS 1. ADD NEW FILM                                 @" << endl;
        cout << "\t@ \tPRESS 2. Delete a film                                @" << endl;
        cout << "\t@ \tPRESS 3. Rent film                                    @" << endl;
        cout << "\t@ \tPRESS 4. Return film                                  @" << endl;
        cout << "\t@ \tPRESS 5. Display inmformation                         @" << endl; 
		cout << "\t@ \tPRESS 6. Update film                                  @" << endl;
		cout << "\t@ \tPRESS 7. Sort all input film                          @" << endl;  
        cout << "\t@ \tPRESS 0. Exit                                         @" << endl;
        line1();	
        SetConsoleTextAttribute(color,10);
        cout << " \t\tEnter your choice: ";
        cin>>choice;;
       	system("cls");
        switch (choice) {
        case 1:{
          add:  system("cls");
		           	retrivefilm_to_file();		
					char n;
					cout<<"\t \tPlease insert your choice position"<<endl;
					cout << "\t \tPRESS 1. At the beginning " << endl;
        			cout << "\t \tPRESS 2. At the end " << endl;
        			cout << "\t \tPRESS 3. At specific position " << endl;
        			cout<<" \t\tenter your choice :";
        		q1:	cin>>n;
        			if(n=='1')
        			{ 
					in_at_beg();  			
					}
					else if(n=='2'){
					at_the_end();
					}
					else if(n=='3'){
						at_specfic_position();
					}
					else{
		                 chance--;
			             cout<<"invalid answer,please try again,you have "<<chance<<" chance"<<endl;		  
			             if(chance==0)
			       {
			   	         cout<<"your chance is finished"<<endl;
			   	         chance=3;
			   	         goto option;
			   	         }  
					     goto q1;
				   }
			   		      
					char ch1;
				    cout<<" do you want to save in file?your answer yes(y) or no(n)"<<endl;
				    cin>>ch1;
				    if(ch1=='y'||ch1=='Y')
			   		{
					     if(head->next==NULL)
					     storte_film_to_file(); 
					     else 
					     tempofilefilms();
					     cout<<"\tfilm is saved"<<endl;
					   	head=NULL;
                	}
			   		else{
			   			cout<<"This film is not save in file"<<endl;
					   }
					   char ch;
                	cout<<" do you want to add other new film ?your answer yes(y) or no(n)"<<endl;
         adnew:	cin>>ch;
                	if(ch=='y'||ch=='Y')
                	{goto add;}
                	else if(ch=='n'||ch=='N')
                	{goto option;}
                	else{
               chance--;
			   cout<<"invalid answer,please try again,you have "<<chance<<" chance"<<endl;		  
			   if(chance==0)
			   {
			   	cout<<"your chance is finished"<<endl;
			   	chance=3;
			   	goto option;}
			   	goto adnew;	
			   	}	
			   	head=NULL;
                	break;
				}
        case 2:{					
        		    retrivefilm_to_file();
        		    string title,ch;
 					int part;
 					cout<<"\t\tPRESS 1,DELETING  BY USING TITLE AND PART FROM FILE \n\t\tPRESS 2,DELETING ALL FROM FILE\n\t\t choice your option"<<endl;
 					cin>>ch;
 					if(ch=="1"){			
  					cout<<"\nenter the title of film you wnt to delete >"<<endl;
  					cin.ignore();
    				getline(cin,title);
    				cout<<" \nenter part of film you want to delete >"<<endl;
  					cin>>part;
                    deleteFilm(title,part);
                    tempofilefilms();
                    head=NULL;}
                    else if(ch=="2")
                    {	remove("films.dat");
                    cout<<"\t\tall film are deleted successfully!!"<<endl;
                    head=NULL;}
                    else
                    {cout<<"invalid choice"<<endl;}
					break;
				} 
		case 3:{	
	            	retrivefilm_to_file();
					string title ,ch;
					int  part;
					SetConsoleTextAttribute(color,10);
    			    cout<<"\nEnter title of film you want to rent > "<<endl;					
        		    cin.ignore();
    			    getline(cin,title);
    			    cout<<" Enter part of film you want to delete >"<<endl;
  				   cin>>part;
    			    addrentFilm(title,part);			  
    			    storte_rent_film_to_file();   			    
    			    start=NULL;	    			  
                	break;
				}
		case 4:{  		
			       retrive_rent_film_to_file();
					string title;
  	    			int part;
   					cout<<"\nenter the title of the film you want to return >"<<endl;
    				cin.ignore();
    				getline(cin,title);
    				cout<<" \nenter part of film you want to return >"<<endl;
    				cin>>part;
    				returnFilm( title,part);
    	//	remove("rentedFilm.dat");
    				start=NULL;
					break;
				}
		case 5:{
			char  k;
		do{
			SetConsoleTextAttribute(color,12);line2();
		cout<<"\t\t          Display menu"<<endl;line2();
		SetConsoleTextAttribute(color,7);line1();	
		cout << "\t@ \tPRESS 1. Display all films in store                   @" <<endl;	
		cout << "\t@ \tPRESS 2. Display rented films                         @" << endl;   
        cout << "\t@ \tPRESS 3. Display unrented films                       @" << endl;         
        cout << "\t@ \tPRESS 4. Display a single film by title               @" <<endl;
        cout << "\t@ \tPRESS 5. Display films by type                        @" << endl;
        cout << "\t@ \tPRESS 6. Display total number of film and rented film @" << endl;
        cout << "\t@ \tPRESS 7. Back to main menu \t                      @" << endl;   
        line1();
        SetConsoleTextAttribute(color,10);
        cout << " \t\tEnter your choice: ";
display:  cin>>k;
        	system("cls");
   if(k=='1'){
        	        system("cls");	             			
					retrivefilm_to_file();
                    displayAllFilms();
                    head=NULL;								
				}
   else if(k=='2'){system("cls");
					retrive_rent_film_to_file();
					displayRentedFilms();
					start=NULL;}
   else if(k=='3'){system("cls");	
					retrivefilm_to_file();
		    		retrive_rent_film_to_file();
		    		displayUnrentedFilms(); 
		    		start=NULL;
		    		head=NULL;			
			}
    else if(k=='4'){
				
        			retrivefilm_to_file();
        			string title;
 			   	    cout<<"\nenter title of film you want to display ."<<endl;
    				cin.ignore();
    				getline(cin,title);
    		    	displayFilmByTitle(title);
    		    	head=NULL;
				
				}
   else  if(k=='5'){
					
        			retrivefilm_to_file();
        			string type;
 			   	 cout<<"enter title of film you want to display ."<<endl;
    				cin.ignore();
    				getline(cin,type);
    				displayFilmsByType(type);
    				head=NULL;
				}        
				
     else if(k=='6'){
    		        retrivefilm_to_file();
    		    	retrive_rent_film_to_file();
    		        count();
    		        cout<<" total number of all film is    "<<count1<<endl;
    		        cout<<" total number of rented film is    "<<countrent<<endl;
    		        head=NULL;
    		    	start=NULL;
		}
		else if(k=='7'){
			mainmenu();
			}
		else 
		{chance--;
			   cout<<"invalid answer,please try again,you have "<<chance<<" chance"<<endl;		  
			   if(chance==0)
			   {
			   	cout<<"your chance is finished"<<endl;
			   	chance=3;
			   	goto option;
			   	} goto display; }
			   	}while(k!=6);
		
		break;
		}
		case 6:{
			retrivefilm_to_file();
			string title;
			int part;
			cout<<"Enter title of film you want to update"<<endl;
			cin.ignore();
			getline(cin,title);
			cout<<"Enter part of film you want to update"<<endl;
			cin>>part;
			Update_film( title,part);
			tempofilefilms();
			head=NULL;
			break;
		}
		case 7:{
		            retrivefilm_to_file();
		            sortBypart();
		            tempofilefilms();
		            head=NULL;
			         break;}
              o:  case 0:
              SetConsoleTextAttribute(color,12);
                	cout<<"*************************************"<<endl;
            		cout<<"thank you for using"<<endl;
            		cout<<"*************************************"<<endl;
                	exit(1);
            default:
            		cout<<"*************************************"<<endl;
               		cout << "Invalid choice!,please try again." <<endl;
               		cout<<"*************************************"<<endl;
			   }
	option:   SetConsoleTextAttribute(color,9);
			   cout<<"do you want to choice other option from main menu? your answer yes(y) or no (n)"<<endl;
			again:   cin>>ch;
			   if(ch=='y'||ch=='Y')
			   {flag=1;}
			   else if(ch=='n'||ch=='N')
			   {
			   flag=0;
			   goto o;
			   }
			   else
			   {SetConsoleTextAttribute(color,14);
			   	chance--;
			   cout<<"invalid answer,please try again,you have "<<chance<<" chance"<<endl;
			  
			   if(chance==0)
			   {
			   	cout<<"your chance is finished"<<endl;
			   	flag=0;
			     chance=3;
			   	goto o;
			   }
			    goto again;
			   }}
			}
			       int main()
				{ char ch;
			  SetConsoleTextAttribute(color,13);			     
				 cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
				 cout<<"\t@     WELCOME TO THIS HOUSE OF FILM RENTAL                    @"<<endl;
				 cout<<"\t@               MIZAN TEPI UNIVERSITY                         @"<<endl;
				 cout<<"\t@          SCHOOL OF COMPUTING AND INFORMATIC                 @"<<endl;
				 cout<<"\t@                 TECHNOLOY                                   @"<<endl;
				 cout<<"\t@                                                             @"<<endl;
				 cout<<"\t@            DEVELOPED BY                                     @"<<endl;
			   	 cout<<"\t@";
			   	 SetConsoleTextAttribute(color,14);
			   	 cout<<"                 MOGES SHITAW AWOKE                          ";
			   	 SetConsoleTextAttribute(color,13);
			   	 cout<<"@"<<endl;
				 cout<<"\t@         FROM COMPUTER SCINCE DEPARTMENT                     @"<<endl;					 
				 cout<<"\t@           THANK YOU FOR ALL USING !!!                       @"<<endl; 			 
				 cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
				  SetConsoleTextAttribute(color,10);
				 cout<<"\t\tenter any key :";
				 cin>>ch;
       			 system("cls");
       			 if(ch)
                 mainmenu();
                  return 0;
				
			}

