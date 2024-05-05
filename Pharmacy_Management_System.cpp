#include<iostream>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<string>
#include<stdio.h>
#include<iomanip>


using namespace std;

HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

//Structures
struct stock
{
	int quantity;		//stock quantity
	string name;	    //medicine name
	float price;		//price
	string med_code;	//medicine code
	stock *next;		//next medicine address
};
stock* head=NULL;
stock* current;

struct order{
	string name;
	int quantity;
	int price;
	int tPrice;
	order *next;
};
order *orderhead=NULL;

// All Functions Declaration

void front();

void authenticationPage();
void Login();
void Signup();

void HomePage();

void defaultStock();
void AddStock(string name,int quan, float pri);
void AddStockScreen();

void ViewStock();
void ViewStockScreen();

void UpdateStock(string name,int exQuan);
void UpdateStockScreen();

void PlaceOrder(int target,int quan);
void BuyMedicineScreen();
void pushOrder(string name,int price, int quantity, int tPrice);
void check(string name,int quan);

void bill();

void DeleteStockScreen();
void DeleteStock(string name);

void SearchStockScreen();
void SearchStock(string name);
void BuySearchMedicine(stock *c,int quan);

//variables
int amount=0; //total amount in bill
int cbill=false; //for bill generation

//main
int main()
{
	front();
	defaultStock();
	authenticationPage();
}

//Front Page
void front(){
	cout << "\n\n\n";
    Sleep(300);
	    
    SetConsoleTextAttribute(h,5);
    cout<<"\t\t\t\t========================================================"<<endl;
    Sleep(500);
    cout<<"\t\t\t\t             PHERMACY MANAGEMENT SYSTEM"<<endl;
    Sleep(500);
    cout<<"\t\t\t\t========================================================="<<endl;
    Sleep(500);
    
    SetConsoleTextAttribute(h,6);
    
    cout<<"\n\n\n\t   GROUP MEMBERS:";
    cout << "\n\n";
    Sleep(500);
    cout << "\t          NAME                       SYSTEM ID            ROLL NO\n\n";
    Sleep(300);
    cout << "\t   1. NAFEESA YOUSAF              NUML-F22-38910          FL21503\n\n";
    Sleep(300);
	cout << "\t   2. MUHAMMAD ABU HURAIRA        NUML-F22-61255          FL21535\n\n";
    Sleep(300);
	cout << "\t   3. MUHAMMAD BILAL              NUML-F23-88991          FL23847\n\n";
    cout << "\n\n";
    
    SetConsoleTextAttribute(h,7);
    Sleep(200);
    cout<<"\t\t\t\t\t\t\t\t\t   SUBMITED TO:   DR. JAWERIA KANWAL \n";
    cout<<"\t\t\t\t\t\t\t\t\t   SUBMITED DATE: 20/12/2023 ";
	cout << "\n\n";
	SetConsoleTextAttribute(h,6);
	cout<<"\n\n\nPress any key to continue...";
    getche();
    SetConsoleTextAttribute(h,7);
}

// Authentication Page
void authenticationPage(){
    system("CLS");
    cout << endl;
    SetConsoleTextAttribute(h,10);
    cout << "\t\t\t=============================================" << endl;
    cout << "\t\t\t                 STOCK MANAGER               \t\t\t " << endl;
    cout << "\t\t\t=============================================" << endl;
    cout << endl;
    SetConsoleTextAttribute(h,7);
choice:
    cout << endl;
    Sleep(300);
    char choice;
    cout << "\n\t\t\t 1. Login \t\t\t\n";
    cout << "\t\t\t 2. Sign Up \t\t\t\n";
    SetConsoleTextAttribute(h,6);
    cout << "\t\t\t Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case '1':
        Login();
        break;
    case '2':
        Signup();
        break;
    default:
        cout << "\t\t\t Invalid Choice!";
        cout<<"\n\n\tPress any key to retry: ";
        getche();
        authenticationPage();
        break;
    }
    SetConsoleTextAttribute(h,7);
}

//Signup
void Signup(){
	int f=0;
    system("CLS");
    cout << endl;
    SetConsoleTextAttribute(h,10);
    cout << "\t\t\t=============================================" << endl;
    cout << "\t\t\t                SIGN UP 	             \t\t\t " << endl;
    cout << "\t\t\t=============================================" << endl;
    cout << endl;
    SetConsoleTextAttribute(h,7);
    string username, password;
    string un, pw;
	Sleep(300);
    cout << "\t\t\t Registration: " << endl;
    cout << endl;
    cout << "\t\t\t Enter a username: ";
    cin>>username;
    cout << "\t\t\t Enter a password: ";
    cin>>password;
    ofstream file;
    file.open("User Authentication.txt",ios::app);
    file.close();
    ifstream read("User Authentication.txt");

while(!read.eof())
	{
		getline(read, un);
		getline(read, pw);
    	if (un == username && pw == password)
    	{
      		f=1;
    	}
	}
    if (f==1)
    {
        cout << "\t\t\t You Already Have an Account" << endl;
        cout << endl;
        cout << "\t\t\tPress Any key to Continue...";
        getche();
        Sleep(500);
        authenticationPage();
    }
    else
    {
        ofstream file;
        file.open("User Authentication.txt",ios::app);//***
        file << username<<endl
             << password<<endl;
        file.close();
        cout << "\n\t\t\t Your account is being created. Please wait";
        for (int i = 1; i <= 6; i++)
        {
            cout << ".";
            Sleep(300);
        }
        cout << endl;
        cout << "\t\t\t Welcome " << username << "!" << endl;
        Sleep(1000);
        authenticationPage();
    }
}

// Login
void Login(){
	int f=0;
    system("CLS");
    cout << endl;
    SetConsoleTextAttribute(h,10);
    cout << "\t\t\t=============================================" << endl;
    cout << "\t\t\t                  LOGIN	              \t\t\t " << endl;
    cout << "\t\t\t=============================================" << endl;
    cout << endl;
	SetConsoleTextAttribute(h,7);
    string username, password;
    string un, pw;
    cout << "\t\t\t Enter a username: ";
    cin>>username;
    cout << "\t\t\t Enter a password: ";
    cin>>password;

    ifstream read("User Authentication.txt");
	if (!read.is_open()) {
        cout << "\n\n\t\t\tPlease create an account first.";
        SetConsoleTextAttribute(h,6);
        cout<<"\n\nPress any key to continue... ";
		getche();
		authenticationPage();
    } 
    else{
    	while(!read.eof())
	{
		getline(read, un);
		getline(read, pw);
   		if (un == username && pw == password)
    	{
       		f=1;
    	}
	}
	if(f==1)
	{
		cout << "\t\t\t Successfully logged in!" << endl;
        cout << endl;
        Sleep(1000);
        HomePage();
	}
	else
    {
        cout << endl;
        cout << "\t\t\t Invalid login!" << endl;
        cout<<"\n\n\tPress any key to retry: ";
        getche();
        authenticationPage();
    }
	}	
}

//  HomePage
void HomePage(){
	system("CLS");
    cout << endl;
    SetConsoleTextAttribute(h,13);
    cout << "\t\t\t==============================================================" << endl;
    cout << "\t\t\t           		HOME PAGE        \t\t\t " << endl;
    cout << "\t\t\t==============================================================" << endl;
    cout << endl;
    Sleep(300);
    SetConsoleTextAttribute(h,7);
    char c;
    cout<<"\n\n\t\t1. Add New Stock";
    cout<<"\n\n\t\t2. View Stock";
	cout<<"\n\n\t\t3. Update Stock";
    cout<<"\n\n\t\t4. Delete Stock";
	cout<<"\n\n\t\t5. Buy Medicine";
    cout<<"\n\n\t\t6. Search Medicine";
    SetConsoleTextAttribute(h,6);
    cout<<"\n\n\t\t\tEnter your Choice: ";
    cin>>c;
    switch(c)
    {
    	case '1':
    		AddStockScreen();
    		break;
    	case'2':
    		ViewStockScreen();
    		break;
    	case '3':
    		UpdateStockScreen();
    		break;
    	case '4':
    		DeleteStockScreen();
    		break;
    	case '5':
    		BuyMedicineScreen();
    		break;
    	case '6':
    		SearchStockScreen();
    		break;
    	default:
			cout<<"\n\n\t\tINVALID CHOICE!\n\t\tPress any key to retry: ";
    		getche();
    		HomePage();
    		break;
	}
    SetConsoleTextAttribute(h,7);
}

//Default Stock
void defaultStock(){
	AddStock("Panadol", 50, 10);
	AddStock("Cestonil" , 100, 300);
	AddStock("Brufen", 250, 120);
	AddStock("Acefyl", 120, 135);
	AddStock("Trikuf", 10, 230);
	AddStock("Rigix", 50, 175);
	AddStock("Bronochol", 76, 190);
}

// Add Stock Screen
void AddStockScreen(){
	string name,med_code;
	int quan;
	float price;
	char c='y';
	system("CLS");
    cout << endl;
    SetConsoleTextAttribute(h,13);
    cout << "\t\t\t==============================================================" << endl;
    cout << "\t\t\t           		ADD STOCK        \t\t\t " << endl;
    cout << "\t\t\t==============================================================" << endl;
    cout << endl;
    Sleep(300);
    while(c=='Y'||c=='y'){
    SetConsoleTextAttribute(h,7);
    cout<<"\n\tEnter Medicine Name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"\n\tEnter Quantity: ";
    cin>>quan;
    cout<<"\n\tEnter Price: ";
    cin>>price;
    AddStock(name,quan,price);
    SetConsoleTextAttribute(h,6);
    cout<<"\nAdd More medicine? (y/n): ";
    cin>>c;
	}
    HomePage();
}

// Add Stock
void AddStock(string name, int quan, float pri) {
    bool duplicate = false;
    current=head;
    while (current!=NULL) {
        if (strcasecmp(current->name.c_str(), name.c_str())==0) {
            duplicate=true;
            break;
        }
        current=current->next;
    }

    if (!duplicate) {
        stock *newstock=new stock;
        newstock->name=name;
        newstock->price=pri;
        newstock->quantity=quan;
        newstock->next=NULL;

        if (head==NULL) {
            head=newstock;
        } else {
            current=head;
            while (current->next != NULL) {
                current=current->next;
            }
            current->next=newstock;
        }
    } 
	else{
        cout<<"\n\n\tThe medicine is already in stock";
    }
}

//View Stock
void ViewStock(){
	current=head;
	int i=1;
	while(current!=NULL)
	{	
	SetConsoleTextAttribute(h,7);
	cout << "\t| " << left << setw(4) << i << " | " << setw(13)  << current->name << " | "
             << setw(8) << current->quantity << " | " << setw(5) << current->price << " |\n";		current=current->next;
	i++;
	}	
}

//View Stock Screen
void ViewStockScreen(){
	system("CLS");
    cout << endl;
    SetConsoleTextAttribute(h,13);
    cout << "\t\t\t==============================================================" << endl;
    cout << "\t\t\t           		VIEW STOCK        \t\t\t " << endl;
    cout << "\t\t\t==============================================================" << endl;
    cout << endl;
    Sleep(300);
    SetConsoleTextAttribute(h,6);
	cout << "\n\t| S.No |   Medicine    | Quantity | Price |\n";
	ViewStock();
    SetConsoleTextAttribute(h,6);
	cout<<"\n\n\nPress any key to continue...";
    getche();
    HomePage();
}

//Update Stock Screen
void UpdateStockScreen(){
	string name;
	int quan;
	system("CLS");
    cout << endl;
    SetConsoleTextAttribute(h,13);
    cout << "\t\t\t==============================================================" << endl;
    cout << "\t\t\t           		Update STOCK        \t\t\t " << endl;
    cout << "\t\t\t==============================================================" << endl;
    cout << endl;
    Sleep(300);
    SetConsoleTextAttribute(h,6);
	cout << "\n\t| S.No |   Medicine    | Quantity | Price |\n";
    ViewStock();
    cout<<"\n\n\tEnter Medicine Nmae: ";
    cin.ignore();
    getline(cin,name);
    cout<<"\n\tEnter the stock value you want to update: ";
    cin>>quan;
    UpdateStock(name,quan);
    SetConsoleTextAttribute(h,6);
	cout<<"\n\n\nPress any key to continue...";
    getche();
    HomePage();
}

//Update Stock
void UpdateStock(string name,int exQuan){
	current=head;
	bool found=false;
	while(current!=NULL){
		if(stricmp(current->name.c_str(),name.c_str())==0){
			found =true;
			break;
		}
		current=current->next;
	}
	if(found==true){
		current->quantity+=exQuan;
		cout<<"\n\n\tStock Updated";
}
else{
	cout<<"\n\n\tThe requested medicine is not in stock";
	SetConsoleTextAttribute(h,6);
}
	
}

//Buy Medicine Screen
void BuyMedicineScreen(){
	int quan;
	string name;
	char c='y';
	system("CLS");
    cout << endl;
    SetConsoleTextAttribute(h,13);
    cout << "\t\t\t==============================================================" << endl;
    cout << "\t\t\t           		BUY STOCK        \t\t\t " << endl;
    cout << "\t\t\t==============================================================" << endl;
    cout << endl;
    Sleep(300);
    SetConsoleTextAttribute(h,6);
	cout << "\n\t| S.No |   Medicine    | Quantity | Price |\n";
    ViewStock();
    while(c=='y'||c=='Y'){
    	SetConsoleTextAttribute(h,7);
    	cout<<"\n\n\tEnter Medicine: ";
    	cin.ignore();
    	getline(cin,name);
    	cout<<"\n\tEnter Quantity: ";
    	cin>>quan;
    	check(name,quan);
    	SetConsoleTextAttribute(h,6);
    	cout<<"\nBuy More medicine? (y/n): ";
    	cin>>c;
	}	
	if(cbill==true){
		cout<<"\n\n\tPress any key to Generate bill: ";
    	getche();
    	bill();	
	}
	cout<<"\n\nPress any key to continue... ";
	getche();
	HomePage();
}

//Order Stack
void check(string name,int quan){
	current=head;
	int totalprice;
	bool found=false;
	while(current!=NULL){
		if(stricmp(current->name.c_str(),name.c_str())==0){
			found =true;
			break;
		}
		current=current->next;
	}
	if(found==true){
	if(current->quantity==0){
		cout<<"\n\n\tMedicine out of stock"<<endl;
	}
	else if(current->quantity<quan){
		cout<<"\n\n\tInsufficient stock available"<<endl;
	}
	else if(quan<0){
		cout<<"\n\n\tInvalid Quantity"<<endl;
	}
	else if(quan==0){
	}
	else{
		current->quantity-=quan;
		totalprice=quan*current->price;
		pushOrder(current->name,current->price, quan,totalprice);
		SetConsoleTextAttribute(h,6);
		cbill=true;
	}
	}
	else{
	cout<<"\n\n\tThe requested medicine is not in stock.";
	SetConsoleTextAttribute(h,6);
	}
}

//Place Order
void pushOrder(string name,int price, int quantity, int tPrice){
	order *neworder= new order;
	neworder->name=name;
	neworder->price=price;
	neworder->quantity=quantity;
	neworder->tPrice=tPrice;
	neworder->next=NULL;
	if(orderhead==NULL){
		orderhead=neworder;
	}
	else{
		order *currentorder=orderhead;
		while(currentorder->next!=NULL){
			currentorder=currentorder->next;
		}
		currentorder->next=neworder;
	}	
}

//Pop order
void popOrder(){
    if(orderhead==NULL){
        cout << "No Placed orders!" << endl;
        return;
    }
    order *prev=NULL;
    order *currentorder=orderhead;

    while(currentorder->next!=NULL){
        prev=currentorder;
        currentorder=currentorder->next;
    }
	SetConsoleTextAttribute(h,7);
     cout << "\n\t| " << left<<setw(20) << currentorder->name << " | " << setw(5) << currentorder->price << " | "
             << setw(8) << currentorder->quantity << " | " << setw(6) << currentorder->tPrice << "  |\n";
        
	amount +=currentorder->tPrice;
	
    if(prev!=NULL){
        prev->next=NULL;
    } else {
        orderhead=NULL;
    }
    delete currentorder;
}

//Generate Bill
void bill() {
	system("CLS");
    system("CLS");
    cout << endl;
    SetConsoleTextAttribute(h,13);
    cout << "\t\t\t==============================================================" << endl;
    cout << "\t\t\t           		FINAL BILL        \t\t\t " << endl;
    cout << "\t\t\t==============================================================" << endl;
    cout << endl<<endl;
    Sleep(300);
    SetConsoleTextAttribute(h,6);
    cout << "\t|===================================================|\n";
    cout << "\t| Medicine Name        | Price | Quantity | Amount  |\n";
    cout << "\t|----------------------|-------|----------|-------- |\n";

    
    while(orderhead != NULL) {
        popOrder(); 
    }
    
    SetConsoleTextAttribute(h,6);
    cout << "\n\t|===================================================|\n";
    SetConsoleTextAttribute(h,7);
    cout<<"\n\t\tTotal Bill : "<<amount;
    amount=0;
    cbill=false;
cout<<"\n\n";
SetConsoleTextAttribute(h,6);
	cout<<"\n\n\nPress any key to continue...";
    getche();
    HomePage();
}

//delete specific stock Screen
void DeleteStockScreen(){
	string name;
	char c='y';
	system("CLS");
    cout << endl;
    SetConsoleTextAttribute(h,13);
    cout << "\t\t\t==============================================================" << endl;
    cout << "\t\t\t           		DElETE STOCK        \t\t\t " << endl;
    cout << "\t\t\t==============================================================" << endl;
    cout << endl;
    Sleep(300);
    SetConsoleTextAttribute(h,6);
	cout << "\n\t| S.No |   Medicine    | Quantity | Price |\n";
    ViewStock();
    while(c=='y'||c=='Y'){
    	SetConsoleTextAttribute(h,7);
    	cout<<"\n\n\tEnter Name: ";
    	cin.ignore();
    	getline(cin,name);
    	SetConsoleTextAttribute(h,6);
    	cout<<"\nDo you want to delete this medicine record? (y/n): ";
    	cin>>c;
    	if(c=='y'|| c=='Y')
    	DeleteStock(name);
    	else{
    	cout<<"\n\nPress any key to continue... ";
    	getche();
    	HomePage();	
		}
	}
}

//Delete Specific Medicine
void DeleteStock(string name) {
    SetConsoleTextAttribute(h, 7);
    bool found=false;
    if (head == NULL) {
        cout << "No Stock Available!" << endl;
        SetConsoleTextAttribute(h, 6);
        cout << "\n\nPress Any key to continue: ";
        getche();
        HomePage();
    } 
	else {
        current = head;
        stock *prev = NULL;
        while(current!=NULL){
		if(stricmp(current->name.c_str(),name.c_str())==0){
			found =true;
			break;
		}
		prev=current;
		current=current->next;
		}
		if(found==true){
            cout << "\n\n\tName: " << current->name << endl
                 << "\tPrice: " << current->price << endl
                 << "\tQuantity: " << current->quantity << endl;

            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next; 
            }

            delete current;
            cout << "\n\n\tThis Stock is Deleted";
        }
		else {
		cout<<"\n\nThe requested medicine is not in stock";		
	    }
}
    SetConsoleTextAttribute(h, 6);
    cout << "\n\nPress Any key to continue... ";
    getche();
    HomePage();
}

//search Specific Medicine
void SearchStockScreen(){
	string name;
	system("CLS");
    cout << endl;
    SetConsoleTextAttribute(h,13);
    cout << "\t\t\t==============================================================" << endl;
    cout << "\t\t\t           		Search STOCK        \t\t\t " << endl;
    cout << "\t\t\t==============================================================" << endl;
    cout << endl;
    Sleep(300);
    SetConsoleTextAttribute(h,7);
    cout<<"\n\n\tEnter medicine name: ";
    cin.ignore();
    getline(cin,name);
    SearchStock(name);
}

//Search Stock
void SearchStock(string name){
	char c;
	int quan;
	bool found =false;
	current=head;
	while(current!=NULL){
		if(stricmp(current->name.c_str(),name.c_str())==0){
			found=true;
			break;
		}
		current=current->next;
	}
	
	if(found==true){
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\tMedicine details ";
		SetConsoleTextAttribute(h,7);
		cout<<"\n\n\t    Name: "<<current->name
			<<"\n\n\t    Quantity: "<<current->quantity
			<<"\n\n\t    Price: "<<current->price;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\nDo you want to buy this medicine record?(y/n) ";
		cin>>c;
		if(c=='Y'||c=='y'){
			SetConsoleTextAttribute(h,7);
			cout<<"\n\nEnter quantity: ";
			cin>>quan;
			BuySearchMedicine(current,quan);
		}
		else{
		}
		
	}
	else{
	SetConsoleTextAttribute(h,6);
	cout<<"\n\t\tThe requested medicine is not in stock";	
	}
	SetConsoleTextAttribute(h,6);
	cout << "\n\nPress Any key to continue... ";
    getche();
    HomePage();
}


//Buy Medicine-Search
void BuySearchMedicine(stock *c,int quan){
	int totalprice=0;
	if(c->quantity==0){
		cout<<"\n\n\tMedicine out of stock"<<endl;
	}
	else if(c->quantity<quan){
		cout<<"\n\n\tInsufficient stock available"<<endl;
	}
	else{
		c->quantity-=quan;
		totalprice=quan*current->price;
		pushOrder(c->name,c->price, quan,totalprice);
		cout<<"\n\nPress any key to Generate bill: ";
		getche();
		bill();
	}
}
