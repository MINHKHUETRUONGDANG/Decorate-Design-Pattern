#include <iostream>

using namespace std;

class Beverage{ public: virtual ~Beverage(){}; 
    virtual string getDescription() const = 0; virtual double cost() const = 0; };
class DarkRoast : public Beverage{ public: virtual ~DarkRoast(){}; 
    virtual string getDescription() const { return "\nDarkRoast"; }; 
    virtual double cost() const { return 1.0; };
};
class Decaf : public Beverage{ public: virtual ~Decaf(){}; 
    virtual string getDescription() const { return "\nDecaf"; }; 
    virtual double cost() const { return 1.2; };    
};
class Espresso : public Beverage{ public: virtual ~Espresso(){}; 
    virtual string getDescription() const { return "\nEspresso"; }; 
    virtual double cost() const { return 2.3; };
};


class Condiment : public Beverage{ protected: Beverage *beverage;
    public: Condiment(Beverage *beverage): beverage(beverage){}; virtual ~Condiment(){}; 
    virtual string getDescription() const { return this->beverage->getDescription() + " + "; }; 
    virtual double cost() const { return this->beverage->cost(); };    
};

class Milk : public Condiment{ protected: Beverage *beverage;
    public: Milk(Beverage *beverage): Condiment(beverage){}; virtual ~Milk(){}; 
    virtual string getDescription() const { return Condiment::getDescription() + "Milk"; }; 
    virtual double cost() const { return Condiment::cost() + 0.1; };    
};
class Mocha : public Condiment{ protected: Beverage *beverage;
    public: Mocha(Beverage *beverage): Condiment(beverage){}; virtual ~Mocha(){}; 
    virtual string getDescription() const { return Condiment::getDescription() + "Mocha"; }; 
    virtual double cost() const  { return Condiment::cost() + 0.5; };    
};
class Whip : public Condiment{ protected: Beverage *beverage;
    public: Whip(Beverage *beverage): Condiment(beverage){}; virtual ~Whip(){}; 
    virtual string getDescription() const { return Condiment::getDescription() + "Whip"; }; 
    virtual double cost() const  { return Condiment::cost() + 0.01; };    
};


void printBill(Beverage *b){
    cout << b->getDescription() << endl;
    cout << b->cost() << endl;
}

int main()
{
    Beverage *espresso = new Espresso;
    
    Beverage *beverage = new Mocha(espresso);
    Beverage *beverage1 = new Mocha(beverage);
    Beverage *beverage2 = new Whip(beverage1);
    
    printBill(beverage2);
    
    delete espresso; delete beverage; 
    delete beverage1; delete beverage2;

    return 0;
}
