
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#define KISI 10;
using namespace std;
class personel_bilgileri{
  public:
  void ortalama_maas();
  void yas_ortalama();
  void personelBilgisi();//sicil numarası doğruysa göster
  private:
  string sicil_no;
  string sicil_sorgu;
  string isim;
  string soyad;
  string yil;
  string zaman;
  string ucret;
  string satir;
  double maas=0;
  double yas=0;
};
void personel_bilgileri::yas_ortalama(){
ifstream bilgi("personelBilgileri.txt",ios::in);
while (!bilgi.eof())
			{
				bilgi >> sicil_no >> isim >> soyad >> yil >> zaman >> ucret;
      yas+=(2020-stoi(yil));
      }
      cout<<"Yas Ortalama"<<yas/KISI;
      cout<<endl;
}

  void personel_bilgileri::ortalama_maas(){
   ifstream bilgi("personelBilgileri.txt",ios::in);
while (!bilgi.eof())
			{
				bilgi >> sicil_no >> isim >> soyad >> yil >> zaman >> ucret;
      maas+=(stoi(zaman)*stoi(ucret));
      }
      cout<<"Ortalama Maas"<<maas/KISI;
}
  





  void personel_bilgileri::personelBilgisi(){
ifstream bilgi("personelBilgileri.txt",ios::in);
cout<<"Sicil No Giriniz:";
cin>>sicil_sorgu;
while (!bilgi.eof())
			{
				bilgi >> sicil_no >> isim >> soyad >> yil >> zaman >> ucret;
        if (sicil_no == sicil_sorgu){
          cout << "\n---Personelin Mevcut Bilgileri--- \n" << endl;
					cout << "Personel Adi	:" << isim << endl;
					cout << "Personel  Soyadi	:" << soyad << endl;
					cout << "Personel  Dogum Yılı	:" << yil << endl;
          cout<<"Yasi:"<<(2020-stoi(yil))<<endl;
					cout << "Aylik Calısma Zamani	:" << zaman<< endl;
					cout << "Saat ucret	:" << ucret << endl;
          cout<<"Maası:"<<(stoi(zaman)*stoi(ucret));
         

        }
      
      }

}
int main() {
cout<<"---------ISLEM YAPMAK ICIN MENUDEN BIR SECENEK SECIN---------"<<endl;
cout<<"\t\t------MENU-------\t\t"<<endl;
cout<<"\t\t1.Personel bilgisi göster\t\t"<<endl;
cout<<"\t\t2.Personellerin ortalama maasini\t\t"<<endl;
cout<<"\t\t3.Personellerin ortalama yasini göster\t\t"<<endl;
int secenek;
cin>>secenek;
personel_bilgileri a;

switch (secenek) 
    {
        case 1: a.personelBilgisi(); break;
        case 2: a.ortalama_maas();   break;
        case 3:a.yas_ortalama();     break;
        default: cout<<"ARADIGINIZ SECENEK BULUNMAMAKTADIR"; break;
}
}