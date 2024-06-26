#include <iostream>
#include <string>
#include <vector>
class Om{
    protected:
        std::string nume;
        std::string prenume;
    public:
        Om();
        Om(std::string nume, std::string prenume){
            this->nume = nume;
            this->prenume = prenume;
        }
        std::string getNume(){
            return nume+" "+prenume;
        }
        // std::string getPrenume(){
        //     return prenume;
        //}
        void setNume(std::string nume){
            this->nume = nume;
        }
        void setPrenume(std::string prenume){
            this->prenume = prenume;
        }
};

class Angajat : public Om{
    protected:
        double salariu;
    public:
        Angajat(std::string nume, std::string prenume, double salariu) : Om(nume, prenume){
            this->salariu = salariu;
        }
        double getSalariu(){
            return salariu;
        }
        void setSalariu(double salariu){
            this->salariu = salariu;
        }
};
class Produs{
    private:
        std::string nume;
        double pret;
    public:
        Produs(std::string nume, double pret){
            this->nume = nume;
            this->pret = pret;
        }
        std::string getNume(){
            return nume;
        }
        double getPret(){
            return pret;
        }
        void setNume(std::string nume){
            this->nume = nume;
        }
        void setPret(double pret){
            this->pret = pret;
        }
};

class Cos{
    private:
        double pret;
        std::vector <Produs> produse;
    public:
        void adaugaProdus(Produs _produs){
            produse.push_back(_produs);
        }
        void stergeProdus(int index){
            produse.erase(produse.begin()+index-1);
        }
        void afiseazaProduse(){
            for(int i = 0; i < produse.size(); i++){
                std::cout <<i+1<<".    "<< produse[i].getNume() << " " << produse[i].getPret() << std::endl;
            }
        }
        void resetCos(){
            produse.clear();
            pret=0;
        }
        std::vector<Produs> getProduse(){
            return produse;
        }
        double getPretTotal(std::vector<Produs> _produse){
            pret=0;
            for(auto it : _produse){
                pret+=it.getPret();
            }
            return pret;
        }
        ~Cos(){
            produse.clear();
            std::cout << "Cosul a fost golit" << std::endl;
        }

};

class Comanda{
    private:
        std::string nume;
        double pret;
        std::vector <Produs> produse;
    public:
        Comanda(std::string nume, double pret){
            this->nume = nume;
            this->pret = pret;
        }
        std::string getNume(){
            return nume;
        }
        double getPret(){
            return pret;
        }
        void setNume(std::string nume){
            this->nume = nume;
        }
        void setProduse(std::vector<Produs> _produse){
            produse=_produse;
        }
        void setPret(std::vector<Produs> _produse){
            pret=0;
            for(auto it : _produse){
                pret+=it.getPret();
        }
    }
};

class Bar{
    private:
        std::string nume;
        std::string adresa;
        Om proprietar= Om("Ionescu", "Alexandru");
        std::vector<Angajat> angajati;
        std::vector<Produs> produse;
        std::vector<Comanda> comenzi;
    public:
        Bar(std::string nume, std::string adresa){
            this->nume = nume;
            this->adresa = adresa;
        }
        void adaugaAngajat(Angajat angajat){
            angajati.push_back(angajat);
        }
        void adaugaProdus(Produs produs){
            produse.push_back(produs);
        }
        void PLaseazaComanda(Comanda comanda){
            comenzi.push_back(comanda);
        }
        void stergeAngajat(int index){
            angajati.erase(angajati.begin()+index-1);
        }
        void stergeProdus(int index){
            produse.erase(produse.begin()+index-1);
        }
        void stergeComanda(int index){
            comenzi.erase(comenzi.begin()+index-1);
        }
        void afiseazaAngajati(){
            for(int i = 0; i < angajati.size(); i++){
                std::cout <<i+1<<".    "<< angajati[i].getNume()  << " " << angajati[i].getSalariu() << std::endl;
            }
        }
        void afiseazaProduse(){
            for(int i = 0; i < produse.size(); i++){
                std::cout <<i+1<<".    "<< produse[i].getNume() << " " << produse[i].getPret() << std::endl;
            }
        }
        void afiseazaComenzi(){
            for(int i = 0; i < comenzi.size(); i++){
                std::cout <<i+1<<".    "<< comenzi[i].getNume() << " " << comenzi[i].getPret() << std::endl;
            }
        }
        std::string getNume(){
            return nume;
        }
        std::string getAdresa(){
            return adresa;
        }
        Produs getProdus(int index){
            return produse[index-1];
        }
        std::vector<Produs> getProduse(){
            return produse;
        }
        std::vector<Comanda> getComenzi(){
            return comenzi;
        }
        std::vector<Angajat> getAngajati(){
            return angajati;
        }
        void setNume(std::string nume){
            this->nume = nume;
        }
        void setAdresa(std::string adresa){
            this->adresa = adresa;
        }
        ~Bar(){
            angajati.clear();
            produse.clear();
            comenzi.clear();
            std::cout << "Barul a fost inchis" << std::endl;
        }
};

int main()
{
    Bar bar = Bar("Barul lui Alex", "Strada Hololulu");
    Cos cos;
    while (true)
    {
        system("cls");
        std::cout<<"1. Admin\n";
        std::cout<<"2. Client\n";
        std::cout<<"3. Iesire\n";
        std::string opt;bool admin;
        std::cin>>opt;
        if(opt=="1")
            admin=true;
        else if(opt=="2")
            admin=false;
        else if(opt=="3")
            break;
        else
            continue;
        system("cls");
        if (admin==true){
            while (true){
                std::cout << "1. Afiseaza angajati" << std::endl;
                std::cout << "2. Adauga angajat" << std::endl;
                std::cout << "3. Sterge angajat" << std::endl;

                std::cout << "4. Afiseaza produse" << std::endl;
                std::cout << "5. Adauga produs" << std::endl;
                std::cout << "6. Sterge produs" << std::endl;

                std::cout << "7. Afiseaza comenzi" << std::endl;
                std::cout << "8. Sterge comanda" << std::endl;

                std::cout << "9. Iesire" << std::endl;
                std::string optiune;
                std::cin >> optiune;
                if(optiune == "9"){
                    break;
                }
                if(optiune == "2"){
                    std::string nume, prenume,salarius,copsalarius;
                    double salariu;
                    std::cout << "Nume: ";
                    std::cin >> nume;
                    std::cout << "Prenume: ";
                    std::cin >> prenume;
                    std::cout << "Salariu: ";
                    std::cin >> salarius;
                    for(int c=0;c<salarius.length();c++){
                        if(salarius[c]!=' '){
                            if(salarius[c]==','){
                                copsalarius.push_back('.');
                            }
                            else{copsalarius.push_back(salarius[c]);}
                        }
                    }
                    bool flag=true;
                    for (int c=0;c<copsalarius.length();c++){
                        if (isdigit(copsalarius[c])==false && copsalarius[c]!='.'){
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        salariu= stod(copsalarius);
                    }
                    else{
                        system("cls");
                        std::cout<<"inputul trebuie sa fie format doar din cifre\n";
                        continue;
                    }
                    Angajat angajat = Angajat(nume, prenume, salariu);
                    bar.adaugaAngajat(angajat);
                    system("cls");
                }
                if(optiune == "5"){
                    std::string nume,salarius,copsalarius;
                    double pret;
                    std::cout << "Nume: ";
                    std::cin >> nume;
                    std::cout << "Pret: ";
                    std::cin >> salarius;

                    for(int c=0;c<salarius.length();c++){
                        if(salarius[c]!=' '){
                            if(salarius[c]==','){
                                copsalarius.push_back('.');
                            }
                            else{copsalarius.push_back(salarius[c]);}
                        }
                    }
                    bool flag=true;
                    for (int c=0;c<copsalarius.length();c++){
                        if (isdigit(copsalarius[c])==false && copsalarius[c]!='.'){
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        pret= stod(copsalarius);
                    }
                    else{
                        system("cls");
                        std::cout<<"inputul trebuie sa fie format doar din cifre\n";
                        continue;
                    }

                    Produs produs = Produs(nume, pret);
                    bar.adaugaProdus(produs);
                    system("cls");
                }
                if(optiune == "3"){
                    int index;std::string indexs;
                    std::cout << "Index: ";
                    std::cin >> indexs;
                    bool flag=true;
                    for (int c=0;c<indexs.length();c++){
                        if (isdigit(indexs[c])==false){
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        index= stoi(indexs);
                    }
                    else{
                        system("cls");
                        std::cout<<"inputul trebuie sa fie format doar din cifre\n";
                        continue;
                    }
                    system("cls");
                    if (index>0 && index<=bar.getAngajati().size()){
                        bar.stergeAngajat(index);}
                    else {std::cout<<"Index gresit\n";}
                }
                if(optiune == "6"){
                    int index;std::string indexs;
                    std::cout << "Index: ";
                    std::cin >> indexs;
                    bool flag=true;
                    for (int c=0;c<indexs.length();c++){
                        if (isdigit(indexs[c])==false){
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        index= stoi(indexs);
                    }
                    else{
                        system("cls");
                        std::cout<<"inputul trebuie sa fie format doar din cifre\n";
                        continue;
                    }
                    system("cls");
                    if(index>0 && index<=bar.getProduse().size()){
                        bar.stergeProdus(index);}
                    else {std::cout<<"Index gresit\n";}
            }
                if(optiune == "8"){
                    int index;std::string indexs;
                    std::cout << "Index: ";
                    std::cin >> indexs;
                    bool flag=true;
                    for (int c=0;c<indexs.length();c++){
                        if (isdigit(indexs[c])==false){
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        index= stoi(indexs);
                    }
                    else{
                        system("cls");
                        std::cout<<"inputul trebuie sa fie format doar din cifre\n";
                        continue;
                    }
                    system("cls");
                    if (index>0 && index<=bar.getComenzi().size()){
                        bar.stergeComanda(index);}
                    else {std::cout<<"Index gresit\n";}
                }
                if(optiune == "1"){
                    system("cls");
                    bar.afiseazaAngajati();
                    std::cout<<"\n\n";
                }
                if(optiune == "4"){
                    system("cls");
                    bar.afiseazaProduse();
                    std::cout<<"\n\n";
                }
                if(optiune == "7"){
                    system("cls");
                    bar.afiseazaComenzi();
                    std::cout<<"\n\n";
                }
                if(optiune!="1" && optiune!="2" && optiune!="3" && optiune!="4" && optiune!="5" && optiune!="6" && optiune!="7" && optiune!="8" && optiune!="9"){
                    system("cls");
                }
            }
        }
        else{
            while (true){

                std::cout << "1. Afiseaza produse" << std::endl;
                std::cout << "2. Adauga produs in cos" << std::endl;
                std::cout << "3. Afiseaza produsele din cos" << std::endl;
                std::cout << "4. Sterge produs din cos" << std::endl;
                std::cout << "5. Plaseaza comanda" << std::endl;
                std::cout << "6. Iesire" << std::endl;

                std::string optiune;
                std::cin >> optiune;
                if(optiune == "6"){
                    break;
                }
                if(optiune == "2"){
                    int index;std::string indexs;
                    std::cout << "Index: ";
                    std::cin >> indexs;
                    bool flag=true;
                    for (int c=0;c<indexs.length();c++){
                        if (isdigit(indexs[c])==false){
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        index= stoi(indexs);
                    }
                    else{
                        system("cls");
                        std::cout<<"inputul trebuie sa fie format doar din cifre\n";
                        continue;
                    }
                    system("cls");
                    if (index>0 && index<bar.getProduse().size()+1){
                        cos.adaugaProdus(bar.getProdus(index));}
                    else{std::cout<<"Index gresit\n";}
                }
                if(optiune == "5"){
                    std::string nume;
                    std::cout << "Nume: ";
                    std::cin >> nume;
                    if (cos.getProduse().size()>0){
                        Comanda comanda = Comanda(nume, cos.getPretTotal(cos.getProduse()));
                        comanda.setProduse(cos.getProduse());
                        bar.PLaseazaComanda(comanda);
                        system("cls");
                        std::cout << "Comanda "<<comanda.getNume()<<" a fost plasata cu succes!    Pret total: " << comanda.getPret() << std::endl;
                        cos.resetCos();
                    }
                    else{
                            system("cls");
                            std::cout<<"Cosul este gol\n\n";}

                }
                if(optiune == "4"){
                    int index;std::string indexs;
                    std::cout << "Index: ";
                    std::cin >> indexs;
                    bool flag=true;
                    for (int c=0;c<indexs.length();c++){
                        if (isdigit(indexs[c])==false){
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        index= stoi(indexs);
                    }
                    else{
                        system("cls");
                        std::cout<<"inputul trebuie sa fie format doar din cifre\n";
                        continue;
                    }
                    system("cls");
                    if (index>0 && index<cos.getProduse().size()+1){
                        cos.stergeProdus(index);}
                    else {std::cout<<"Index gresit\n";}
                }
                if(optiune == "1"){
                    system("cls");
                    bar.afiseazaProduse();
                    std::cout<<"\n\n";
                }
                if(optiune == "3"){
                    system("cls");
                    cos.afiseazaProduse();
                    std::cout<<"\n\n";
                }
                if(optiune!="1" && optiune!="2" && optiune!="3" && optiune!="4" && optiune!="5" && optiune!="6"){
                    system("cls");
                }
            }
        }
    }
    return 0;
}
