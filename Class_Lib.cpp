#include <iostream>
#include <string>
#include <fstream>
#include <ios>

class Lib
{
private:
	int id_reader;
	char name[20];
	char surname[20];
	int id_book;
	char book[20];
	char author[20];
	char ch;
public:
	void getdata_reader();
	void getdata_book();
	void showdata_reader();
	void showdata_book();
	int getID_reader()const;
	int getID_book()const;
	void add_reader();
	void add_book();
	void display_all_readers();
	void display_all_books();
	void display_reader();
	void display_book();
	void main_menu();
};
//metod vvoda dannih chitatela
void Lib::getdata_reader ()
{
	std::cout<<"Prisvoyte ID chitatelu: ";
	std::cin>>id_reader;
	std::cout<<"Vvedite Ima chitatela: ";
	std::cin.ignore();
	std::cin.getline(name,20);
	std::cout<<"Vvedite familiyu chitatela: ";
	std::cin.getline(surname,20);	
}
//metod vvoda dannih knigi
void Lib::getdata_book ()
{
	std::cout<<"Prisvoyte ID knige: ";
	std::cin>>id_book;
	std::cout<<"Vvedite nazvanie knigi: ";
	std::cin.ignore();
	std::cin.getline(book,20);
	std::cout<<"Vvedite avtora knigi: ";
	std::cin.getline(author,20);
}
//metod vivoda dannih chitatela
void Lib::showdata_reader()
{
	std::cout<<"ID chitatela: "<<id_reader<<std::endl;
	std::cout<<"Ima chitatela: "<<name<<std::endl;
	std::cout<<"Familiya chitatela: "<<surname<<std::endl;	
}
//metod vivoda dannih knigi
void Lib::showdata_book()
{
	std::cout<<"ID knigi: "<<id_book<<std::endl;
	std::cout<<"Nazvanie knigi: "<<book<<std::endl;
	std::cout<<"Avtor knigi: "<<author<<std::endl;
}
//metod vvoda ID i sohranaet v id_reader
int Lib::getID_reader() const
{
	return id_reader;
}
//metod vvoda ID i sohranaet v id_book
int Lib::getID_book() const
{
	return id_book;
}
//sohranenie dannih chitatela v file
void add_reader()
{
	Lib rd;
	std::ofstream OutRdFile;
	OutRdFile.open("Readers.txt",std::ios::binary|std::ios::app);
	rd.getdata_reader();
	OutRdFile.write(reinterpret_cast<char *> (&rd), sizeof(Lib));
	OutRdFile.close();
    std::cout<<"File chitateley sozdan!";
}
//sohranenie dannih knigi v file
void add_book()
{
	Lib bk;
	std::ofstream OutBkFile;
	OutBkFile.open("Books.txt",std::ios::binary|std::ios::app);
	bk.getdata_book();
	OutBkFile.write(reinterpret_cast<char *> (&bk), sizeof(Lib));
	OutBkFile.close();
    std::cout<<"File katalog knig sozdan!";
}
//otobrazit vseh chitatelei v file
void display_all_readers()
{
	Lib rd;
	std::ifstream InRdFile;
	InRdFile.open("Readers.txt",std::ios::binary);
	if(!InRdFile)
		{
			std::cout<<"-File ne nayden-";
			return;
		}
	std::cout<<"-Vivesti vseh chitateley-"<<std::endl<<std::endl;
	while(InRdFile.read(reinterpret_cast<char *> (&rd), sizeof(Lib)))
		{
			rd.showdata_reader();
			std::cout<<"===================================="<<std::endl<<std::endl<<std::endl;
		}
	InRdFile.close();
}

//otobrazit vse knigi v file
void display_all_books()
{
	Lib bk;
	std::ifstream InBkFile;
	InBkFile.open("Books.txt",std::ios::binary);
	if(!InBkFile)
		{
			std::cout<<"-File ne nayden-";
			return;
		}
	std::cout<<"-Vivesti vse knigi-"<<std::endl<<std::endl;
	while(InBkFile.read(reinterpret_cast<char *> (&bk), sizeof(Lib)))
		{
			bk.showdata_book();
			std::cout<<"====================================";
		}
	InBkFile.close();
}
//otobrazit chitatela po ID
void display_reader(int n)
{
	Lib rd;
	std::ifstream InRdFile;
	InRdFile.open("Readers.txt",std::ios::binary);
	if(!InRdFile)
		{
			std::cout<<"File ne naiden";
			return;
		}
	while(InRdFile.read(reinterpret_cast<char *> (&rd), sizeof(Lib)))
		{
			if(rd.getID_reader()==n)
			{
				rd.showdata_reader();
			}
		}
InRdFile.close();
}
//otobrazit knigu po ID
void display_book(int n)
{
	Lib bk;
	std::ifstream InBkFile;
	InBkFile.open("Books.txt",std::ios::binary);
	if(!InBkFile)
		{
			std::cout<<"File ne naiden";
			return;
		}
		while(InBkFile.read(reinterpret_cast<char *> (&bk), sizeof(Lib)))
		{
			if(bk.getID_book()==n)
				{
					bk.showdata_book();
				}
		}
	InBkFile.close();
}

//Udaleniye polzovatela po ID

void delete_reader(int n)
{
	Lib rd;
	std::ifstream inRdFile;
	inRdFile.open("Readers.txt",std::ios::binary);
	if(!inRdFile)
	{
		std::cout<<"File ne najden";
		std::cin.ignore();
		std::cin.get();
		return;
	}
	std::ofstream outRdFile;
	outRdFile.open("Temp.txt",std::ios::out);
	inRdFile.seekg(0,std::ios::beg);
	while(inRdFile.read(reinterpret_cast<char *> (&rd), sizeof(Lib)))
	{
		if(rd.getID_reader()!=n)
			{
				outRdFile.write(reinterpret_cast<char *> (&rd), sizeof(Lib));
			}
}
	outRdFile.close();
	inRdFile.close();
	remove("Readers.txt");
	rename("Temp.txt","Readers.txt");
	std::cout<<"\n\n\t Zapis udalena .."; 
}

//Glavnoe menu
void main_menu()
{
	char ch;
	int num;
	system("cls");
	std::cout<<"=====___Menu programmi Biblio___====="<<std::endl;
	std::cout<<"1. Dobavit chitatela"<<std::endl;
	std::cout<<"2. Dobavit knigu"<<std::endl;
	std::cout<<"3. Otobrazit vseh chitatelei"<<std::endl;
	std::cout<<"4. Otobrazit vse knigi"<<std::endl;
	std::cout<<"5. Otobrazit knigu po ID"<<std::endl;
	std::cout<<"6. Udalit chitatela"<<std::endl;
	std::cout<<"=====___Sdelayte Vibor___====="<<std::endl;
	std::cin>>ch;
	system("cls");

switch(ch)
{
	case '1': add_reader(); break;
	case '2': add_book(); break;
	case '3': display_all_readers(); break;
	case '4': display_all_books(); break;
	case '5': std::cout<<"\n\n\tVvedite ID knigi: "; std::cin>>num; 
		display_book(num); break;
	case '6': std::cout<<"\n\n\tVvedite ID chitatela dla udaleniya: "; std::cin>>num;
		delete_reader(num); break;
}
}
int main ()
{
	main_menu();
}






