#include <iostream>
#include <string>
#include <fstream>
#include <ios>


class Lib
{
private:
	int id_reader;
	char name[50];
	char surname[50];
	int id_book;
	std::string book;
	char author[50];
	char ch;
	int journal;
public:
	void getdata_reader();
	void getdata_book();
	void getdata_journal();
	void showdata_reader();
	void showdata_book();
	void showdata_journal();
	int getID_reader()const;
	int getID_book()const;
	int getID_note()const;
	void add_reader();
	void add_book();
	void add_journal();
	void display_all_readers();
	void display_all_books();
	void display_journal();
	void display_reader();
	void display_book();
	void main_menu();
	void delete_reader(int n);
	void delete_book(int n);
	void delete_note(int n);
	
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

//metod vvoda dannih jurnala
void Lib::getdata_journal ()
{
	std::cout<<"Prisvoyte poradkoviy nomer zapisi: ";
	std::cin>>journal;
	std::cout<<"Vvedite ID chitatela: ";
	std::cin.ignore();
	std::cin>>id_reader;
	std::cout<<"Vvedite ID knigi: ";
	std::cin>>id_book;
}

//metod vvoda dannih knigi
void Lib::getdata_book ()
{
	std::cout<<"Prisvoyte ID knige: ";
	std::cin>>id_book;
	std::cout<<"Vvedite nazvanie knigi: ";
	std::cin.ignore();
	std::getline(std::cin,book);
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

//metod vivoda dannih jurnala
void Lib::showdata_journal()
{
	std::cout<<"Poradkoviy nomer zapisi: "<<journal<<std::endl;
	std::cout<<"ID chitatela: "<<id_reader<<std::endl;
	std::cout<<"ID knigi: "<<id_book<<std::endl;
}

//metod vvoda ID chitatela
int Lib::getID_reader() const
{
	return id_reader;
}

//metod vvoda ID knigi
int Lib::getID_book() const
{
	return id_book;
}

//metod vvoda poradkovogo nomera zapiisi v jurnale
int Lib::getID_note() const
{
	return journal;
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
	std::cin.ignore();
	std::cin.get();
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
			std::cout<<"===================================="<<std::endl<<std::endl<<std::endl;
		}
	InBkFile.close();
	std::cin.ignore();
	std::cin.get();
}

//otobrazit vse zapisi jurnala
void display_journal()
{
	Lib note;
	std::ifstream InJFile;
	InJFile.open("Journal.txt",std::ios::binary);
	if(!InJFile)
		{
			std::cout<<"-File ne nayden-";
			return;
		}
	std::cout<<"-Vse zapisi jurnala ucheta-"<<std::endl<<std::endl;
	while(InJFile.read(reinterpret_cast<char *> (&note), sizeof(Lib)))
		{
			note.showdata_journal();
			std::cout<<"===================================="<<std::endl<<std::endl<<std::endl;
		}
	InJFile.close();
	std::cin.ignore();
	std::cin.get();
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
	std::cin.ignore();
	std::cin.get();
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
	std::cin.ignore();
	std::cin.get();
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
	std::cout<<"Zapis udalena ..."; 
	std::cin.ignore();
	std::cin.get();
}

//Udaleniye knigi po ID
void delete_book(int n)
{
	Lib bk;
	std::ifstream inBkFile;
	inBkFile.open("Books.txt",std::ios::binary);
	if(!inBkFile)
	{
		std::cout<<"File ne najden";
		std::cin.ignore();
		std::cin.get();
		return;
	}
	std::ofstream outBkFile;
	outBkFile.open("Temp.txt",std::ios::out);
	inBkFile.seekg(0,std::ios::beg);
	while(inBkFile.read(reinterpret_cast<char *> (&bk), sizeof(Lib)))
	{
		if(bk.getID_book()!=n)
			{
				outBkFile.write(reinterpret_cast<char *> (&bk), sizeof(Lib));
			}
}
	outBkFile.close();
	inBkFile.close();
	remove("Books.txt");
	rename("Temp.txt","Books.txt");
	std::cout<<"Zapis udalena ..."; 
	std::cin.ignore();
	std::cin.get();

}

//Udaleniye zapisi v jurnale ucheta vidachi knig po poradkovomu nomeru
void delete_note(int n)
{
	Lib note;
	std::ifstream inJFile;
	inJFile.open("Journal.txt",std::ios::binary);
	if(!inJFile)
	{
		std::cout<<"File ne najden";
		std::cin.ignore();
		std::cin.get();
		return;
	}
	std::ofstream outJFile;
	outJFile.open("Temp.txt",std::ios::out);
	inJFile.seekg(0,std::ios::beg);
	while(inJFile.read(reinterpret_cast<char *> (&note), sizeof(Lib)))
	{
		if(note.getID_note()!=n)
			{
				outJFile.write(reinterpret_cast<char *> (&note), sizeof(Lib));
			}
}
	outJFile.close();
	inJFile.close();
	remove("Journal.txt");
	rename("Temp.txt","Journal.txt");
	std::cout<<"Zapis udalena ..."; 
	std::cin.ignore();
	std::cin.get();

}

//Dobavit zapis v journal ucheta vidachi knig
void add_journal()
{
	Lib note;
	std::ofstream OutJFile;
	OutJFile.open("Journal.txt",std::ios::binary|std::ios::app);
	note.getdata_journal();
	OutJFile.write(reinterpret_cast<char *> (&note), sizeof(Lib));
	OutJFile.close();
    std::cout<<"File Jurnala sozdan!";
	
}

//Glavnoe menu
void main_menu()
{
	char ch;
	int num;
	system("cls");
	std::cout<<"=====___Menu programmi Biblio___====="<<std::endl;
	std::cout<<' '<<std::endl;
	std::cout<<"1. Dobavit chitatela"<<std::endl;
	std::cout<<' '<<std::endl;
	std::cout<<"2. Dobavit knigu"<<std::endl;
	std::cout<<' '<<std::endl;
	std::cout<<"3. Otobrazit vseh chitatelei"<<std::endl;
	std::cout<<' '<<std::endl;
	std::cout<<"4. Otobrazit vse knigi"<<std::endl;
	std::cout<<' '<<std::endl;
	std::cout<<"5. Otobrazit knigu po ID"<<std::endl;
	std::cout<<' '<<std::endl;
	std::cout<<"6. Udalit chitatela"<<std::endl;
	std::cout<<' '<<std::endl;
	std::cout<<"7. Udalit knigu"<<std::endl;
	std::cout<<' '<<std::endl;
	std::cout<<"8. Vidat knigu"<<std::endl;
	std::cout<<' '<<std::endl;
	std::cout<<"9. Otobrazit vse zapisi v jurnale ucheta vidachi knig"<<std::endl;
	std::cout<<' '<<std::endl;
	std::cout<<"0. Udalit zapis v jurnale ucheta vidachi knig"<<std::endl;
	std::cout<<' '<<std::endl;
	std::cout<<"=====___Sdelayte Vibor___====="<<std::endl;
	std::cout<<' '<<std::endl;
	std::cin>>ch;
	system("cls");

switch(ch)
{
	case '1': add_reader(); break;
	case '2': add_book(); break;
	case '3': display_all_readers(); break;
	case '4': display_all_books(); break;
	case '5': std::cout<<"Vvedite ID knigi: "; std::cin>>num; 
		display_book(num); break;
	case '6': std::cout<<"Vvedite ID chitatela dla udaleniya: "; std::cin>>num;
		delete_reader(num); break;
	case '7': std::cout<<"Vvedite ID knigi dla udaleniya: "; std::cin>>num;
		delete_book(num); break;
	case '8': add_journal(); break;
	case '9': display_journal(); break;
	case '0': std::cout<<"Vvedite nomer zapisi v jurnale dla udaleniya: "; std::cin>>num;
		delete_note(num); break;
}
}