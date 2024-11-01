//COMSC 210 | LAB 23 | Abhishek Nanduri

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list<Goat> trip; 

    //int tripSize = 1 + rand() % SZ_COLORS; 

    for(int i = 0; i < 8; i++)
    {
        Goat temp; 
        int randn = rand() % SZ_NAMES;
        int randa = rand() % MAX_AGE; 
        int randc = rand() % SZ_COLORS;
        temp.set_name(names[randn]);
        temp.set_age(randa);
        temp.set_color(colors[randc]);
        trip.push_back(temp); 
    }

    int choice;
       
       do{
        int choice = main_menu();

        switch(choice) 
        {
        case 1:
        
            add_goat(trip, names, colors);
            cout<<endl;
            display_trip(trip);
            break;
        
        case 2:
        
            delete_goat(trip);
            cout<<endl;
            display_trip(trip);
            break;
              
        case 3:
            display_trip(trip);    
            break;
        
        case 4: 
            return 0;
        
        }
       } while(choice != 4);
   
   

    return 0;
}

int main_menu()
{
    int choice; 

  
        cout<<"*** GOAT MANAGER 3001 ***"<<endl; 
        cout<<"[1] Add a goat"<<endl; 
        cout<<"[2] Delete a goat"<<endl;
        cout<<"[3] List goats"<<endl; 
        cout<<"[4] Quit"<<endl; 
        cout<<"Choice --> ";
        cin>>choice; 
        //return choice; 
       cout<<endl;  
       switch(choice) 
            {
                case 1:
                    cout<<"A goat is added"<<endl<<endl; 
                    return choice;
                    
                case 2: 
                    //cout<<"A goat is deleted"<<endl; 
                    return choice;

                case 3: 
                    cout<<"This is the list of goats"<<endl<<endl; 
                    return choice;
                     
                case 4: 
                    cout<<"Exiting..."<<endl; 
                    return choice;
                      
            } 

}

void display_trip(list<Goat> trip)
{   
    int i = 1;
    for(auto it = trip.begin(); it != trip.end(); ++it)
    {
        cout<<"["<<i<<"] "<<it->get_name()<<" "<<"("<<it->get_age()<<", "
        <<it->get_color()<<")"<<endl;
        i++;
    }
    cout<<endl; 
}

void add_goat(list<Goat> &trip, string n[], string c[])
{
    Goat temp; 
    temp.set_name(n[rand() % SZ_NAMES]); 
    temp.set_age(rand() % MAX_AGE); 
    temp.set_color(c[rand() % SZ_COLORS]);
    trip.push_back(temp); 

} 

void delete_goat(list<Goat> &trip)
{
   int del = select_goat(trip); 
   auto it = trip.begin();
   advance(it, del -1);   //looked up the advance function on geeksforgeeks.org on their c++ STL list page
   trip.erase(it); 

    
}

int select_goat(list<Goat> trip) 
{
    int choice; 
    cout<<"Select a goat to delete:"<<endl;
    display_trip(trip);
    cin>>choice; 

    return choice; 

}