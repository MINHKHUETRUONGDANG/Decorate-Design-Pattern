#include <iostream>

using namespace std;

class Component{ public: virtual ~Component(){}; virtual string operate() const = 0; };

class ConcreteComponentA: public Component{ 
    public: virtual ~ConcreteComponentA(){}; virtual string operate() const { return "\nConcreteComponent"; }; };
class ConcreteComponentB: public Component{ 
    public: virtual ~ConcreteComponentB(){}; virtual string operate() const { return "\nConcreteComponent"; }; };

class Decorator: public Component{ 
    protected: Component *component;
    public: Decorator(Component *component): component(component){}; 
            virtual string operate() const{ return this->component->operate() + " + Decorator"; }; };
    
class ConcreteDecoratorA: public Decorator{    
    protected: Component *component;
    public: ConcreteDecoratorA(Component *component): Decorator(component){}; 
            virtual string operate() const{ return Decorator::operate() + " + ConcreteDecoratorA"; }; };
class ConcreteDecoratorB: public Decorator{ 
    protected: Component *component;
    public: ConcreteDecoratorB(Component *component): Decorator(component){}; 
            virtual string operate() const{ return Decorator::operate() + " + ConcreteDecoratorB"; }; };   


void print(Component *c){
   cout << c->operate() << endl; 
}

int main()
{
    Component *simple = new ConcreteComponentA;
    
    Component *d1 = new ConcreteDecoratorA(simple);   
    Component *d2 = new ConcreteDecoratorB(d1);  
    
    print(simple);
    print(d1);
    print(d2);
    
    delete simple;
    delete d2;
    delete d1;
    return 0;
}
