#include <iostream>
#include <string>
using namespace std;
static int adder = 0;
class Product
{
public:
	void createProduct(string name, double price){
		this->name = name;
		this->price = price;
	}
	string getName(){
		return name;
	}
	double getPrice(){
		return price;
	}
private:
	string name;
	double price;
};
class Customer
{
public:
	//Creating a new customer with Its name and address
	void createCustomer(string name, string address){
		this->name = name;
		this->address = address;
	}
	//Displays info about customer
	void displayDetails(){
		cout << "Name of the Reciever -> " << name << endl;
		cout << "Delivery Address -> " << address << endl;
	}
private:
	string name;
	string address;
};
class Manage
{
public:
	void checkoutOrder(Product *bp){
		double total = 0.0;
		for (int i = 0; i < adder; i++)
		{
			cout << "Number: " << i;
			cout << " || Name: " + bp[i].getName() + "  Price: $" << bp[i].getPrice() << endl;
		}
		for (int i = 0; i < adder; i++)
		{
			total += bp[i].getPrice();
		}
		cout << "Number of products: "<< adder << endl;
		cout << "Total to pay: $" << total << endl;
	}
	void add(Product *p, Product *bp, int chosenElem){
		bp[adder] = p[chosenElem];
		cout << "Number: " << adder << " || Name: " + bp[adder].getName() + "  Price: $" << bp[adder].getPrice() << endl;
		adder++;
	}
	void search(string);
	void display(Product *p, int size){
		for (int i = 0; i < size; i++)
		{
			cout << "Number: " << i;
			cout << " || Name: " + p[i].getName() + "  Price: $" << p[i].getPrice() << endl;
		}
	}
private:
};
enum MenuControls
{
	CHECK, BASKET, CHECKOUT, EXIT
};
bool start();
void MainMenu();
void logIn();
int main(){

	MainMenu();
	system("pause");
	return 0;

}
bool start(){
	bool h = 1;
	while (h)
	{
		string username, password;
		cout << "Welcome to the Online Shopping\n";
		cout << "To exit type 'exit'as your username\nUsername ->";
		cin >> username;
		cout << "Password ->";
		cin >> password;

		if (username == "exit")
			return false;
		if (username == "user" && password == "1234")
		{
			return true;
		}
		else
		{
			system("CLS");
			cout << "Given username or password is invalid\n";
		}
	}
	return true;
}
void logIn(){
	Customer c;
	string name, address;
	cout << "Please, provide your name -> \n";
	cin >> name;
	cout << "Provide your delivery address -> \n";
	cin >> address;
	c.createCustomer(name, address);

}
void MainMenu(){
	Product product[6];
	product[0].createProduct("Car_TOY", 10.5);
	product[1].createProduct("Milk", 5.99);
	product[2].createProduct("Paper", 12.99);
	product[3].createProduct("Hydrolife_Water", 2.99);
	product[4].createProduct("Coca-Cola", 5.22);
	product[5].createProduct("Chocolate_Milka", 7.88);
	Product boughtProducts[6];
	Manage manage;
	if (start()){
		system("CLS");
		int m = 1, chosenElement;
		logIn();
		while (true)
		{
			cout << "[0]. Show Products\n";
			cout << "[1]. Add a new product to basket\n";
			cout << "[2]. Show basket\n";
			cout << "[3]. Exit\n";
			cin >> m;
			switch (m)
			{
			case CHECK:
				manage.display(product, 6);
				break;
			case BASKET:
				cout << "Add a new product to your basket\n";
				manage.display(product, 6);
				cout << "Product number to add to the basket -> ";
				cin >> chosenElement;
				manage.add(product, boughtProducts, chosenElement);
				break;
			case CHECKOUT:
				cout << "CHECK" << endl;
				manage.checkoutOrder(boughtProducts);
				break;
			case EXIT:
				return;
				break;
			}
		}
	}
}
