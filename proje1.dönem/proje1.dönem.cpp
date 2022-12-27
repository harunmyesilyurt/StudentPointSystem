#include <iostream>
#include <math.h>
#include <conio.h>
#include <iomanip>
#include <string> 

using namespace std;

// tarih ve ��renci yap�lar�
struct Tarih
{
	unsigned int Gun;
	unsigned int Ay;
	unsigned int Yil;
};

struct Ogrenci
{
	string Adi;
	string Soyadi;
	string No;

	float Vize;
	float Final;
	float Proje;
	float K�saS�nav1;
	float K�saS�nav2;
	float Odev1;
	float Odev2;
	float Ortalama;
	struct Tarih DogumTarihi;
};

float kontrol(string s, float min, float max);

Ogrenci ogrenciler[100];

int RastgeleAtama();

//harf notu atama
string harfNotu(int ogrenciNotu)
{
	if (ogrenciNotu <= 100 && ogrenciNotu > 87)
	{
		return "AA";
	}
	else if (ogrenciNotu <= 87 && ogrenciNotu > 81)
	{
		return "BA";
	}
	else if (ogrenciNotu <= 81 && ogrenciNotu > 74)
	{
		return "BB";
	}
	else if (ogrenciNotu <= 74 && ogrenciNotu > 67)
	{
		return "CB";
	}
	else if (ogrenciNotu <= 67 && ogrenciNotu > 60)
	{
		return "CC";
	}
	else if (ogrenciNotu <= 60 && ogrenciNotu > 53)
	{
		return "DC";
	}
	else if (ogrenciNotu <= 53 && ogrenciNotu > 46)
	{
		return "DD";
	}
	else if (ogrenciNotu <= 46 && ogrenciNotu > 39)
	{
		return "FD";
	}
	else if (ogrenciNotu <= 39 && ogrenciNotu >= 0)
	{
		return "FF";
	}
}
//Her se�enek i�in fonksionlar
float EnYuk()//1. se�ene�in fonksiyonu
{
	float Enbuyuk = ogrenciler[0].Ortalama;

	string Deger;

	for (int i = 0; i < 100; i++)
	{
		if (Enbuyuk < ogrenciler[i].Ortalama)
		{
			Enbuyuk = ogrenciler[i].Ortalama;
		}
	}
	cout << "Highest grade in the class : " << Enbuyuk << endl << endl;

	cout << "Press 0 to return to the previous screen...";

	cin >> Deger;

	if (Deger == "0")
	{
		system("cls");
		return RastgeleAtama();
	}
	else
	{
		system("cls");
		return EnYuk();
	}
}
float EnDus()//2. se�ene�in fonksiyonu
{
	float EnKucuk = ogrenciler[0].Ortalama;

	string Deger;

	for (int i = 0; i < 100; i++)
	{
		if (EnKucuk > ogrenciler[i].Ortalama)
		{
			EnKucuk = ogrenciler[i].Ortalama;
		}
	}
	cout << "Lowest grade in the class :" << EnKucuk << endl << endl;

	cout << "Press 0 to return to the previous screen...";

	cin >> Deger;

	if (Deger == "0")
	{
		system("cls");
		return RastgeleAtama();
	}
	else
	{
		system("cls");
		return EnDus();
	}
}
float NotOrt;
float Ort()//3. se�ene�in fonksiyonu
{
	float Ortalama = 0;

	string Deger;

	for (int i = 0; i < 100; i++)
	{
		Ortalama += ogrenciler[i].Ortalama; //notlar�n ortalamas� al�nd�
	}

	NotOrt = Ortalama / 100;

	cout << "Class average :" << NotOrt << endl << endl;

	cout << "Press 0 to return to the previous screen...";

	cin >> Deger;

	if (Deger == "0")
	{
		system("cls");
		return RastgeleAtama();
	}
	else
	{
		system("cls");
		return Ort();
	}
}

float SapmaHesaplama(float NotOrtalama)//Standart sapma hesaplama fonksiyonu
{
	double Sapma = 0;

	for (int i = 0; i < 100; i++)
	{
		Sapma += pow((ogrenciler[i].Ortalama - NotOrtalama), 2);
	}
	double Sonuc = sqrt((Sapma / 99));
	return Sonuc;
}

float StdSapma()//4. se�ene�in fonksiyonu
{
	string Deger;

	cout << "Standard deviation of the class :" << SapmaHesaplama(NotOrt) << endl << endl;

	cout << "Press 0 to return to the previous screen...";

	cin >> Deger;

	if (Deger == "0")
	{
		system("cls");
		return RastgeleAtama();
	}
	else
	{
		system("cls");
		return StdSapma();
	}
}

void AdSoyad(int min, int max)//Ad ve soyad�n se�enekler i�in birle�ti�i fonksiyon
{
	for (int i = 0; i < 100; i++)
	{
		if (max >= ogrenciler[i].Ortalama && ogrenciler[i].Ortalama > min)
		{
			string AdSoyad = ogrenciler[i].Adi + " " + ogrenciler[i].Soyadi;
			int _Average = ogrenciler[i].Ortalama;
			cout << "Student's name and surname :" << left << setw(20) << AdSoyad << " Student's grade : " << left << setw(7) << _Average << harfNotu(_Average) << endl;
		}
	}

}

float BelAral�k()//5. se�ene�in fonksiyonu
{
	string Deger;

	AdSoyad(50, 80);
	cout << "Press 0 to return to the previous screen...";

	cin >> Deger;

	if (Deger == "0")
	{
		system("cls");
		return RastgeleAtama();
	}
	else
	{
		system("cls");
		return BelAral�k();
	}
}

float DegAlt()//6. se�ene�in fonksiyonu
{

	string Deger;

	AdSoyad(0, 50);

	cout << "Press 0 to return to the previous screen...";

	cin >> Deger;

	if (Deger == "0")
	{
		system("cls");
		return RastgeleAtama();
	}
	else
	{
		system("cls");
		return DegAlt();
	}
}

float DegUst()//7. se�ene�in fonksiyonu
{
	string Deger;

	AdSoyad(80, 100);

	cout << "Press 0 to return to the previous screen...";

	cin >> Deger;

	if (Deger == "0")
	{
		system("cls");
		return RastgeleAtama();
	}
	else
	{
		system("cls");
		return DegUst();
	}
}

void ListeYazd�rma(int min, int max)//Liste se�ene�i i�in ad soyad fonksiyonu
{
	for (int i = min; i <= max; i++)
	{
		string AdSoyadL = ogrenciler[i].Adi + " " + ogrenciler[i].Soyadi;
		cout << "Student's name and surname : " << AdSoyadL << endl;
	}
}
float Liste()//8. se�ene�in fonksiyonu
{
	int i = 0, j = 20;
	string Deger;
	do
	{
		int Deger;

		ListeYazd�rma(i, j);

		cout << "Press 0 to exit the list...";

		cin >> Deger;

		if (Deger == 0)
		{
			break;
		}
		system("cls");

		i += 20; j += 20;

		if (j == 100)
		{
			i = 0; j = 20;
		}

	} while (j <= 100);

	cout << "Press 0 to return to the previous screen...";

	cin >> Deger;

	if (Deger == "0")
	{
		system("cls");
		return RastgeleAtama();
	}
	else
	{
		system("cls");
		return Liste();
	}
}

//men� sistemi
int RastgeleAtama()
{
	int Secenekler;

	cout << "1-Calculate the highest grade of the class." << endl;

	cout << "2-Calculate the lowest grade of the class." << endl;

	cout << "3-Calculate the average of the class." << endl;

	cout << "4-Calculate the standard deviation of the class." << endl;

	cout << "5-List those whose grades are within a certain range." << endl;

	cout << "6-A list of students whose grades are below a specified value can be obtained." << endl;

	cout << "7-A list of students with a grade above a specified value can be obtained." << endl;

	cout << "8-Print the class list." << endl;

	cout << "Please select the option you want to do :";

	cin >> Secenekler;

	switch (Secenekler)//Se�eneklerin toplanmas� ve atamas�
	{
	case 1:
		system("cls");
		return EnYuk();
		break;

	case 2:
		system("cls");
		return EnDus();
		break;
	case 3:
		system("cls");
		return Ort();
		break;
	case 4:
		system("cls");
		return StdSapma();
		break;
	case 5:
		system("cls");
		return BelAral�k();
		break;
	case 6:
		system("cls");
		return DegAlt();
		break;
	case 7:
		system("cls");
		return DegUst();
		break;
	case 8:
		system("cls");
		return Liste();
		break;
	default:
		return RastgeleAtama();
		break;
	}
	return 0;
}

float Kontrol(string s, float min, float max)//Say� kontrol fonksiyonu
{
	float Sayi1;
	do
	{
		cout << s;
		cin >> Sayi1;
	} while (!(Sayi1 >= min && Sayi1 <= max));
	return Sayi1;
}

float TarihKontrol(string s, float min, float max)//Tarih kontrol fonksiyonu
{
	float Dogum;
	do
	{
		cout << s;
		cin >> Dogum;
	} while (!(Dogum >= min && Dogum <= max));
	return Dogum;
}

float Ortalama(string s, float Final, float Vize, float Proje, float KisaSinav1, float KisaSinav2, float Odev1, float Odev2)//��rencilerin s�avlara g�re ortalama hesab�
{
	float Ort = 0;

	Ort = (Vize * 50 / 100) + (KisaSinav1 * 7 / 100) + (KisaSinav2 * 7 / 100) + (Odev1 * 10 / 100) + (Odev2 * 10 / 100) + (Proje * 16 / 100);

	return Ort;
}

int RandomNum(int max, int min = 0)//Random say� olu�turma 
{
	int a = rand();
	int Number = a % (max - min + 1) + min;
	return Number;
}

void StudentAddAverage(int _i, int must, int RandMax, int RandMin = 0)//Notlar� random atama fonksionu
{
	for (int i = _i; i < must; i++)
	{
		ogrenciler[i].Ortalama = RandomNum(RandMax, RandMin);
	}
}

void STudentManuelRecord(int i)
{
	cout << "Enter student's name : " << endl;
	cin >> ogrenciler[i].Adi;

	cout << "Enter student's surname : " << endl;
	cin >> ogrenciler[i].Soyadi;

	cout << "Enter student's id : " << endl;
	cin >> ogrenciler[i].No;

	//De�erlerin do�ru aral�kta yaz�ld��� kontrol 
	ogrenciler[i].DogumTarihi.Gun = TarihKontrol("Enter the day the student was born (1,31) : ", 1, 31);

	ogrenciler[i].DogumTarihi.Ay = TarihKontrol("Enter the month the student was born (1,12) : ", 1, 12);

	ogrenciler[i].DogumTarihi.Yil = TarihKontrol("Enter the year the student was born (1990,2022) : ", 1990, 2022);

	ogrenciler[i].Final = Kontrol("Enter the student's final grade :", 0, 100);

	ogrenciler[i].K�saS�nav1 = Kontrol("Enter the student's 1st quiz grade : ", 0, 100);

	ogrenciler[i].K�saS�nav2 = Kontrol("Enter the student's 2nd quiz grade : ", 0, 100);

	ogrenciler[i].Odev1 = Kontrol("Enter the student's 1st homework grade: ", 0, 100);

	ogrenciler[i].Odev2 = Kontrol("Enter the student's 2nd homework grade : ", 0, 100);

	ogrenciler[i].Vize = Kontrol("Enter the student's midterm grade : ", 0, 100);

	ogrenciler[i].Proje = Kontrol("Enter the student's project grade : ", 0, 100);

	ogrenciler[i].Ortalama = Kontrol("Enter the student's average grade: ", 0, 100);

}
int main()
{
	setlocale(LC_ALL, "Turkish");//T�rk�e dilini kullanmak i�in atama
	//Haz�rlanan isim ve soyisimler
	string Isimler[30] = { "Harun","Batuhan","Emir","G�kberk","Mahmut","Adem","Kaan","Cemil","H�seyin","Osman","Ali","Mehmet","Mustafa","Celal","Ertu�rul","Ay�e","Esma","Fatmanur","Ela","S�la","Sude","Beyzanur","Ceren","Buse","Eda","�rem","Melisa","Nurdan","Dilek","Hatice" };
	string Soyadlar[30] = { "Y�lmaz","Ye�ilyurt","Bahayetmez","�zbay","�zbey","Eski","�z","Kaplan","Y�rt�c�","Man�o","Akarsu","Koray","Meri�","Biler","Armut�u","Demirkan","Utanga�","�lkan","Cepkin","�epni","Tekin","Sanl�soy","�nn�","T�rkcan","Cansu","��nar","�al","Vardar","G�bekli","G�n�lc�" };

	string Sayfalar;//�lk se�enekler

	cout << "Please choose one of the options : " << endl;

	cout << "Please press 1 to assign a Random value. " << endl;

	cout << "Please press 2 to manually assign value. " << endl;

	cin >> Sayfalar;

	if (Sayfalar == "1")//�Lk men� 1. se�ene�in fonksiyonu
	{
		cout << "1" << endl;


		// �s�mler ve soyadlar� 1. se�enek i�in random atar
		for (int i = 0; i < 100; i++)
		{
			ogrenciler[i].Adi = Isimler[RandomNum(29)];

			ogrenciler[i].Soyadi = Soyadlar[RandomNum(29)];
		}

		// notlar� random ve bir orana g�re atama 
		StudentAddAverage(0, 10, 40);
		StudentAddAverage(10, 60, 70, 40);
		StudentAddAverage(60, 75, 80, 70);
		StudentAddAverage(75, 100, 100, 80);

		//tarihi random atama
		for (int i = 0; i < 100; i++)
		{
			int gun = rand() % (30 - 1 + 1) + 1;
			int ay = rand() % (12 - 1 + 1) + 1;
			int yil = rand() % (2010 - 1988 + 1) + 1988;

			ogrenciler[i].DogumTarihi.Gun = gun;
			ogrenciler[i].DogumTarihi.Ay = ay;
			ogrenciler[i].DogumTarihi.Yil = yil;
		}

		return RastgeleAtama();
	}

	else if (Sayfalar == "2")//�Lk men� 2. se�ene�in fonksiyonu
	{
		cout << "2" << endl;

		for (int i = 0; i < 100; i++)//2. se�enek i�in istenen veriler 
		{ 
			string Control;
			cout << "Do you want to continue ? (Y,N) : " << endl;
			cin >> Control ;
			Control[0] = toupper(Control[0]);

			if(Control == "Y")
			{
				cout << i + 1 << " Enter the student's information , " << endl;
				STudentManuelRecord(i);
			}
			else
			{
				system("cls");
				return main() ;
			}
		}
	}
	else
	{
		cout << "Please enter an available option..." << endl;

		return main();
	}

}



