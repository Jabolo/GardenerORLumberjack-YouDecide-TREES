//Michał J

//Programs allows to create an BST/AVL tree and move through
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>

using namespace std;

typedef struct node
{
    node *left;
    node *right;
    node *father;
    char data;
}root;

//definitions
void theEnd();

void addNodeToBST(node &*root);
void addNodeToAVL(node &*root);
void downloadDataFromFile(bool isAVL);
int main()
{

    int optionMainMenu=0, optionSomewhereInside=0, optionAnother=0;
    bool isAVL=false;

    //************interface*************

    cout<<"Hello!\n";
    Sleep(1000);
    do
    {
        do{
            system("cls");
            cout<<"Choose wisely ^^ :\n";
            cout<<"**********************************************************\n";
            cout<<"1. Work with new BST tree\n";
            cout<<"2. Work with new AVL tree\n";
            cout<<"666. Exit\n";
            cout<<"**********************************************************\n";

            cin>>optionMainMenu;
        }
        while(optionMainMenu != 1 && optionMainMenu != 2 && optionMainMenu !=666);
        switch(optionMainMenu)
        {
        case 1:
            isAVL=false; //BSTtree
            break;
        case 2:
            isAVL=true;  //AVLtree
            break;
        case 666:
            theEnd();
            return 0;
        }
here:
        system("cls");
        cout<<"**********************************************************\n";
        cout<<"1.\tDownload data from .txt file and create a Tree.\n";
        cout<<"2.\tAdd node by hand\n";
        cout<<"3.\tDelete node\n";
        cout<<"4.\tDisplay the Tree\n";
        cout<<"55.\tDelete ALL tree\n";
        cout<<"66.\tBo back to main menu\n";
        cout<<"**********************************************************\n";
        do
        {
            cin>>optionSomewhereInside;
            switch(optionSomewhereInside)
            {
            case 1:  //download from file
                downloadDataFromFile(isAVL);
                break;
            case 2:  //add node
                break;
            case 3:  //delete node
                break;
            case 4:  //display
                do
                {
                    cout<<"**********************************************************\n";
                    cout<<"1.\tShow pre-order\n";
                    cout<<"2.\tShow in-order\n";
                    cout<<"3.\tShow post-order\n";
                    cout<<"6.\tGo back\n";
                    cout<<"**********************************************************\n";
                    cin>>optionAnother;
                    switch(optionAnother)
                    {
                    case 1:  //pre
                        break ;
                    case 2:  //in
                        break;
                    case 3:  //post
                        break;
                    }
                }
                while(optionAnother != 6);
                goto here;
                break;
            case 55:  //delete ALL
                break;
            case 66:  //go to main menu
                break;
            }
        }
        while(optionSomewhereInside!=66);
    }
    while(optionMainMenu != 666);
    return 0;
}


//declarations

void addNodeToBST()
{

}

void addNodeToAVL()
{

}

void downloadDataFromFile(bool isAVL)
{
    ifstream fileToRead;
    do
    {
        string fileName;
        cout<<"Type in the file name:\t";
        cin>>fileName;
        cin.get(); //helpful when we want to read later
        fileToRead.open(fileName.c_str()); //open file to read
        if(!fileToRead.is_open())  //if there is no such a file
        {
            fileToRead.close();
            fileToRead.clear();
        }
    }while(!fileToRead.is_open()); //till opening the file
    do{
        if(isAVL == 1) addNodeToAVL();
        else addNodeToBST();
    }while(! fileToRead.eof());
}


void theEnd(){
    cout<<"Shut down in:\t";
    Sleep(1000);
    cout<<"3 -->\t";
    Sleep(1000);
    cout<<"2 -->\t";
    Sleep(1000);
    cout<<"1 -->\t";
    Sleep(1000);
    for(int i=0; i<100; i++)
        cout<<"!@#$%^&*()$&!_+##_)%@@!3(*&^%$#@!";
}


