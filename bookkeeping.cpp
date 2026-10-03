/*
	A book shop maintains the inventory of books that are being sold at the shop. 
	The list includes details such as author, title, price, publisher and stock position. 
	Whenever a customer wants a book, the sales person inputs the title and author to the system. 
	If it is not available, “Not found” message is displayed. 
	If it is available, then the system displays the book details and requests for the number of copies required. 
	If the requested copies are available, the total cost of the requested copies is displayed; otherwise “Required copies not in stock” is displayed. 
	Design a system using a class called books with suitable member functions and constructors. 
	Use new operator in constructors to allocate memory space required.
*/

#include<iostream>
#include<fstream>
using namespace std;

struct BookCollection{
		string author;
		string title;
		string publisher;
		int position;
		float price;
}s;

class Book{
	private:
		string author;
		string title;
		int RequestedCopies;
	public:
		Book(string author,string title){	
			this->author=author;
			this->title=title;
		}
		void check_Aviability(){
			ifstream file("bookData.txt");
			if(!file)
			{
				cout<<"Error Opening File"<<endl;
			}
			
			try{
					while(getline(file,s.author,'|')&&getline(file,s.title,'|')&&getline(file,s.publisher,'|')&&file>>s.position&&file.ignore(1)&&file>>s.price&&file.ignore(1))
					{
						if(s.author==author && s.title==title)
						{
							cout<<"Found the Book"<<endl;
							display(s);
							
							cout<<"Enter the Number of copies Required:";
							cin>>RequestedCopies;
							
							if(RequestedCopies<=s.position){
								cout<<"\nThe total price is:"<<(RequestedCopies*s.price)<<endl;	
								break;
							}
							else{
								cout<<"Required copies not in stock"<<endl;
								break;
							}
						}
						else{
							if(file.eof())
							{
								throw("Not Found");	
							}
						}
					}
			}
			catch(const char* msg){
				cout<<msg<<endl;
			}
			file.close();
		}
		
		void display(const BookCollection& p){
				cout<<"The Author is :"<< p.author<<endl;
				cout<<"The Publisher is :"<< p.publisher<<endl;
				cout<<"The Title is :"<< p.title<<endl;
				cout<<"The price is :"<< p.price<<endl;
				cout<<"The copies left is :"<< p.position<<endl;
				
		}
};



int main(){
	string author;
	string title;
	
	cout<<"Enter the author of Book:";
	getline(cin,author);
	cout<<"Enter the title of Book:";
	getline(cin,title);
	
	Book *user = new Book(author,title);
	user->check_Aviability();
	
	
	
	delete user;
	return 0;
}
