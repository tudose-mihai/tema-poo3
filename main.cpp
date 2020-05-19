#include <iostream>
#include <unordered_map>
#include <cstdio>
#include <string>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl


template<class TipGestiune>
class Gestiune {
    int nr_plati;
    unordered_map<int, TipGestiune> umap;
public:
    Gestiune() {
        nr_plati = 0;
    }
    ~Gestiune() {
        // cum sterg obiectele :(
        umap.erase(umap.begin(),umap.end());
    }

    void addMap(int pos, TipGestiune *G) {
        umap[pos] = *G;
    }

    Gestiune &operator+=(TipGestiune g) {
        umap[nr_plati] = g;
        this->nr_plati++;
        return *this;
    }

    void showPairs() {
        auto it = umap.begin();
        for (auto p : umap)
            cout << p.second << "\n";
        cout << "\n";
    }
    int getNumber(){
        return nr_plati;
    }
    friend ostream &operator<<(ostream &o, Gestiune &lista){
        auto it = lista.umap.begin();
        for (auto p : lista.umap)
            o << p.second << "\n";
        o << "\n";
        return o;
    }
};


class Plata {
protected:
    int data_platii;
    int suma;
public:
    int getDate() const { return data_platii; }

    int getSum() const { return suma; }

    Plata() {
        data_platii = 0;
        suma = 0;
    }

    Plata(int i, int j) {
        data_platii = i;
        suma = j;
    }

    virtual void showTransaction() {
        return;
    }

    bool operator==(const Plata &other) const {
        return this->data_platii == other.data_platii && this->suma == other.suma;
    }

    virtual void print(ostream &o) const {};
};

class MyHashFunction {
public:
    size_t operator()(const Plata &p) const {
        string date, sum;
        date = to_string(p.getDate());
        sum = to_string(p.getSum());
        return (hash<string>()(date)) ^ (hash<string>()(sum));
    }
};

class Credit : public Plata {
    static int nr_plati;
    int id_client;
public:
    Credit() : Plata(0, 0) {
        id_client = -1;
        nr_plati++;
    }

    Credit(int i, int j, int k) : Plata(i, j) {
        id_client = k;
        nr_plati++;
    }

    Credit(const Credit &other) {
        this->data_platii = other.data_platii;
        this->suma = other.suma;
        this->id_client = other.id_client;
        nr_plati++;
    }

    void showTransaction() {
        cout << "Tranzactie Credit\n";
        cout << "Data platii: " << data_platii;
        cout << "\nSuma: " << suma;
        cout << "\nId client: " << id_client << '\n';
    }

    int getNrPlati() const {
        return nr_plati;
    }

    void print(ostream &o) const {
        o << "Tranzactie Credit\n";
        o << "Data platii: " << data_platii;
        o << "\nSuma: " << suma;
        o << "\nId client: " << id_client << '\n';
    }

//    Credit&operator=(const Credit& other) {
//        if (this != &other) {
//            data_platii = other.data_platii;
//            suma = other.suma;
//            id_client= other.id_client;
//        }
//    }
    friend istream &operator>>(istream &i, Credit &plata);
    friend ostream &operator<<(ostream &o, Credit &plata);
};
istream &operator>>(istream &i, Credit &plata){
    cout << "\nData: ";
    i >> plata.data_platii;
    cout << "Suma: ";
    i >> plata.suma;
    cout << "Id_client: ";
    i >> plata.id_client;
    cout << '\n';
    return i;
}
ostream &operator<<(ostream &o, Credit &plata) {
    plata.print(o);
    return o;
}
int Credit::nr_plati = 0;

class Cec : public Plata {
    static int nr_plati;
public:
    Cec() : Plata(0, 0) {
        nr_plati++;
    }

    Cec(int i, int j) : Plata(i, j) {
        nr_plati++;
    }

    Cec(const Cec &other) {
        this->data_platii = other.data_platii;
        this->suma = other.suma;
        nr_plati++;
    }

    void showTransaction() {
        cout << "Tranzactie Cec\n";
        cout << "Data platii: " << data_platii;
        cout << "\nSuma: " << suma << '\n';
        cout << '\n';
    }

    int getNrPlati() const {
        return nr_plati;
    }

    void print(ostream &o) const {
        o << "Tranzactie Cec\n";
        o << "Data platii: " << data_platii;
        o << "\nSuma: " << suma;
    }
//    Cec&operator=(const Cec& other){
//        if(this!= &other){
//            data_platii=other.data_platii;
//            suma=other.suma;
//        }
//    }
    friend istream &operator>>(istream &i, Cec &plata);
    friend ostream &operator<<(ostream &o, Cec &plata);
};
istream &operator>>(istream &i, Cec &plata){
    cout << "\nData: ";
    i >> plata.data_platii;
    cout << "Suma: ";
    i >> plata.suma;
    cout << '\n';
    return i;
}
ostream &operator<<(ostream &o, Cec &plata) {
    plata.print(o);
    return o;
}
int Cec::nr_plati = 0;

class Cash : public Plata {
    static int nr_plati;
public:
    Cash() : Plata(0, 0) {
        nr_plati++;
    }

    Cash(int i, int j) : Plata(i, j) {
        nr_plati++;
    }

    Cash(const Cash &other) {
        this->data_platii = other.data_platii;
        this->suma = other.suma;
        nr_plati++;
    }

    void showTransaction() {
        cout << "Tranzactie Cash\n";
        cout << "Data platii: " << data_platii;
        cout << "\nSuma: " << suma << '\n';
        cout << '\n';
    }

    int getNrPlati() const {
        return nr_plati;
    }

    void print(ostream &o) const {
        o << "Tranzactie Cash\n";
        o << "Data platii: " << data_platii;
        o << "\nSuma: " << suma;
    }
//    Cash&operator=(const Cash& other){
//        if(this != &other){
//            data_platii=other.data_platii;
//            suma=other.suma;
//        }
//    }
    friend istream &operator>>(istream &i, Cash &plata);
    friend ostream &operator<<(ostream &o, Cash &plata);
};
istream &operator>>(istream &i, Cash &plata){
    cout << "\nData: ";
    i >> plata.data_platii;
    cout << "Suma: ";
    i >> plata.suma;
    cout << '\n';
    return i;
}
ostream &operator<<(ostream &o, Cash &plata) {
    plata.print(o);
    return o;
}
int Cash::nr_plati = 0;

Plata *factory(int x) {
    switch (x) {
        case 1: {
            int data, suma, id_client;
            cout << "\ndata:";
            cin >> data;
            cout << "\nsuma:";
            cin >> suma;
            cout << "\nid_client:";
            cin >> id_client;
            cout << '\n';
            return new Credit(data, suma, id_client);
        }
        case 2: {
            int data, suma;
            cout << "\ndata:";
            cin >> data;
            cout << "\nsuma:";
            cin >> suma;
            cout << '\n';
            return new Cec(data, suma);
        }
        case 3: {
            int data, suma;
            cout << "\ndata:";
            cin >> data;
            cout << "\nsuma:";
            cin >> suma;
            cout << '\n';
            return new Cash(data, suma);
        }
    }
    return 0;
}

int main() {
    Cash x(2020, 200);
    Credit y(2020, 304000, 123123);
    Cec z(2019, 8762), z1, z2, z3(12, 30);

    Plata *p;

    //cash
    p = &x;
    cout << typeid(*p).name() << '\n';
    cout << x.getNrPlati() << '\n' << '\n';

    //credit
    p = &y;
    cout << typeid(*p).name() << '\n';
    cout << y.getNrPlati() << '\n' << '\n';

    //cec
    p = &z;
    cout << typeid(*p).name() << '\n';
    cout << z.getNrPlati() << '\n' << '\n';
    cout << '\n' << '\n' << '\n' ;
    Gestiune<Credit> lista_credit;
    Gestiune<Cec> lista_cec;
    Gestiune<Cash> lista_cash;


    int b = 1;
    Plata *ptr;
    int i = 0;
    while (b) {
        cout << "Credit (1), Cec (2), Cash (3), Exit (0)\n";
        cin >> b;
        cout << b;
        if(b != 1 && b!=2 && b!=3)
            break;
        ptr = factory(b);
        if (typeid(*ptr) == typeid(Credit)) {
            Credit *temp;
            temp = dynamic_cast<Credit *>(ptr);
            lista_credit += *temp;
            cout << "Nr. chitante: "<<lista_credit.getNumber()<< '\n' << lista_credit;
        } else if (typeid(*ptr) == typeid(Cec)) {
            Cec *temp;
            temp = dynamic_cast<Cec *>(ptr);
            lista_cec += *temp;
            cout << "Nr. chitante: "<<lista_cec.getNumber()<< '\n' << lista_cec;

        } else if (typeid(*ptr) == typeid(Cash)) {
            Cash *temp;
            temp = dynamic_cast<Cash *>(ptr);
            lista_cash += *temp;
            cout << "Nr. chitante: "<<lista_cash.getNumber()<< '\n' << lista_cash;
        }

    }


    return 0;

}
