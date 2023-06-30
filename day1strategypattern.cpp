/*
The above code demonstrates the concept of inheritance and composition in object-oriented programming.
 It includes three abstract classes: `Duck`, `FlyingBehavior`, and `QuackBehavior`. 
 The `Duck` class represents common features shared by all duck species,
  while the `FlyingBehavior` and `QuackBehavior` classes define specific behaviors related to flying and quacking.

By utilizing composition, the `Duck` class has member variables of types `FlyingBehavior*` and `QuackBehavior*`, 
allowing for dynamic behavior assignment. 
This means that different duck species can have different flying and quacking behaviors, 
which can be changed at runtime.

For example, if we start with a duck species that initially cannot quack and has no flying ability, 
we can introduce a new class, such as `ProstheticQuack` inheriting from `QuackBehavior`, 
and assign it to the `quackBehavior` member variable of the duck. This will modify the behavior of the duck, enabling it to produce sound.

Similarly, we can introduce a class like `RocketPoweredWings` inheriting from `FlyingBehavior`, 
and assign it to the `flyBehavior` member variable of the duck. This will provide the duck with 
the ability to fly using rocket-powered wings.

In summary, the code showcases how inheritance and composition can be 
used to create flexible and customizable behavior for duck species. 
It demonstrates how different behaviors can be dynamically assigned to objects at runtime,
 allowing for variations in quacking and flying abilities among different types of ducks.
*/
#include<bits/stdc++.h>
using namespace std;

//---------------------- Flying behaviour-------------//
class FlyBehaviour{
public:
    void virtual fly() = 0;
};
//---------------------- Quack behaviour-------------//
class QuackBehaviour{

public:
    void virtual quack() = 0;
};

// Master duck and contain features common to all duck ,,,,,,,
class Duck{
    public:
    FlyBehaviour* flybehave; // 
    QuackBehaviour* quackBehave; // someone has to initialize it
    Duck():flybehave(nullptr),quackBehave(nullptr)
    {}
    void swim()
    {cout << "All duck swimming \n";}
    void performQuack() // no overridding , all duck features
    {

     quackBehave->quack();
    
    }
    void performFly(){  // no overridding , all duck features

     flybehave->fly();

    }
    void setFlyBehaviour(FlyBehaviour* fb)
    {
        flybehave = fb;
    }
    void setQuackbehaviour(QuackBehaviour *qb)
    {
        quackBehave = qb;
    }
    void virtual display()
    {
        cout << "ALl ducks display function to show that all floats" << endl;
    }


};
// Type A flying behaviour
class Flywithwings:public FlyBehaviour{

    public:
    int number_of_wings;
    void fly()
    {
        cout << "I have strong wings to flap \n " ;
    }
    void set_wings_number(int num)
    {
        number_of_wings = num;
    }
};

// Type B flyig behaviour
class NoFlywings:public FlyBehaviour{

    public:
    void fly()
    {
        cout << "I dont  wings to flap and fly \n " ;
    }
};
class ProstheticFly:public FlyBehaviour{

public:
void fly() override
{
    cout << "I am flying driking red bull" << endl;
} 
};

//-------------- different quacking behaviour
//Type A quack
class Quack: public QuackBehaviour
{

public:
    void quack() override
    {
        cout << "I am quacking" << endl;
    }
};
// Type B quack
class MuteQuack: public QuackBehaviour
{

public:
    void quack() override
    {
        cout << "I am deaf and silent" << endl;
    }
};

// lets define some species of Duck -----------

class MallardDuck: public Duck{

    public:
    MallardDuck(){
        quackBehave = new Quack();
        flybehave =  new Flywithwings();
    }
    void display() override
    {
        cout << "I am MALLARD DUck with quack and fly " << endl;

    }

};
class ModelDuck: public Duck{
    public:
    ModelDuck()
    {
        quackBehave =  new Quack();
        flybehave = new NoFlywings();
    }
    void display()
    {
        cout << "I am roboting machine model duck " << endl ;
    }
};

int main()
{



    Duck* mallard = new MallardDuck();
    mallard->display();
    mallard->performFly();
    mallard->performQuack();
cout << "------------------ model Duck ----- " << endl;

    Duck* modelduck = new ModelDuck();
    modelduck->display();
    modelduck->performFly();
    modelduck->performQuack();
    FlyBehaviour* pf =new ProstheticFly();
    modelduck->setFlyBehaviour(pf);

cout << "------------------ new adjustment--- " << endl;

    modelduck->display();
    modelduck->performFly();
    modelduck->performQuack();
    modelduck->swim();

cout << "----------------- normal duck base class--- " << endl;
    Duck* normal = new Duck();
    QuackBehaviour* qb = new MuteQuack();
    FlyBehaviour* fb = new ProstheticFly();
    normal->setFlyBehaviour(fb); // flexibility to add any flying behaviou
    normal->setQuackbehaviour(qb);
    normal->performFly();
    normal->performQuack();
cout << "----------------- normal duck base class--- " << endl;

    return 0;
}


