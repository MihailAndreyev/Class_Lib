#include <iostream>
#include <string>

class Lib
{
private:
	int id_reader;
	char name[20];
	char surname[20];
	int id_book;
	char book[20];
	char author[20];
public:
	void getdata();
	void showdata()const;
	int getID()const;
};

void Lib::getdata()
{
	std::cout<<"Prisvoyte ID chitatelu: ";
	std::cin>>id_reader;
	
}
