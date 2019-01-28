
/*
sabbir Ahamed 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Customer;
class Person   //create class
{
public:
    string name;
    Person() {}     // create constructor
    Person(string name)
    {
        this->name=name;
    }
};
class Item : public Person
{
private:
    string itemName,made,colour;
    int price;

public:
    Item() {}
    Item(string itemName,string made,int price,string item_colour)
    {
        this-> itemName =itemName;
        this->made = made;
        this->price = price;
        colour=item_colour;


    }
    void showItem();
};
inline void Item :: showItem()   //inline function using scope resulation
{
    cout<<"Item Name     :  "<<itemName<<endl;
    cout<<"Made In :  "<<made<<endl;
    cout<<"Price         :  "<<price<<endl;
    cout<<"Colour of Item : "<<colour<<endl;

}
class Type_of_Item : public Item
{
private:
    string itemCategory;

public:
    Type_of_Item() {}

    Type_of_Item(string itemCategory,string itemName,string made,int price,string item_colour):Item(itemName,made,price,item_colour)
    {
        this->itemCategory =itemCategory ;
    }
    void showDetail();
    friend void buyItems(Type_of_Item, Customer );
};
void Type_of_Item :: showDetail()      // print details
{
    cout<<"Item Description : "<<endl<<endl;
    cout<<"Item Category :  "<<itemCategory<<endl;
    showItem();

    cout<<endl;
}
class Customer:public Person
{
public:
    string customerCategory;
    Customer() {}

    Customer(string customerCategory,string name):Person(name)
    {
        this->customerCategory=customerCategory;
    }
    friend void buyItems(Type_of_Item, Customer );
};
void buyItems(Type_of_Item b, Customer c)
{
    cout<<"Customer Gender  : "<<c.customerCategory<<endl;
    cout<<"Dear customer "<<c.name<<" , you will get discount if you buy 5 Item at a time."<<endl;
}

int main()
{
    Type_of_Item A("Stationary","Khata","Bangladesh",100,"White");  //create object
    Type_of_Item B("Stationary","Pen","Bangladesh",60,"Red");      //create object
    Type_of_Item C("Garment","Hudhi","Bangladesh",700,"Black");    //create object
    Type_of_Item F("Garment","T-shirt","Bangladesh",650,"While");     //create object
    Type_of_Item E("Garment","Panjabi","Bangladesh",1700,"Blue");     //create object
    Type_of_Item G("Garment","Cap","Bangladesh",150,"Black");     //create object

    A.showDetail();
    B.showDetail();
    C.showDetail();
    F.showDetail();
    E.showDetail();
    Customer D("Male","Sabbir");
    buyItems(A,D);

}
