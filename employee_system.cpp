//
//  main.cpp
//  Data structures final project
//
//  Created by solo ugbane on 4/30/21.

//**********************************************************
//      PROJECT EMPLOYEE MANAGEMENT
//**********************************************************

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


using namespace std;


//**********************************************************
// This Struct defines the Employee data using a linked list
//**********************************************************
struct Employee // Employee class
{
    long int empid;
    string fname;
    string lname;
    Employee* left; // previous pointer
    Employee* right; // next pointer
    
  //Calculate employee salary?
};

/*struct BTemploynode
{
  long int BTempid;
  string BTfname;
  string BTtitle;
  employnode* BTleft;
  employnode* BTright;
}; */



class Employeequeue //(Employee queue class)
{
  private : //Defining the linked list for the class employee
    Employee* head;
    Employee* tail;
    int queue_counter;

  public : //Defining the functions
    Employeequeue()
    {
      queue_counter = 0;
      head = NULL;
      tail = NULL;
    }
    //Insert an employee
     void inemployee (long int nempid, string nfname, string nlname){

         Employee* e = new Employee();
          e->empid = nempid;
          e->fname = nfname;
          e->lname = nlname;
          e->right = NULL;
          e->left = NULL;
         
        if (head == NULL && tail == NULL) //if the list is empty
          {
              head = tail = e;
          }
        else // if the list has at least one node,
          {
            tail->right = e;
            e->left = tail;
            tail = e; // makes the tail points to x
          }
          queue_counter++;
    }
    
    //delete an employee
    void deemployee (long int nempid){
      if( head == NULL ) //if list is empty
        {
          cout<<"Queue is empty \n";
        }
        else
        {
            Employee* temp = head;
            head = head->right;
            if (head == NULL)
              tail = NULL;
            else
              head->left = NULL;
            temp = NULL;
            queue_counter--;
        }

    }

    //checks if queue is empty
    bool isEmpty()
    {
      if(queue_counter==0){
          return true;
        }
        else{
          return false;
        }
    }

    //display employees   Case 1
    void dispemployee(){

      //merge sorting will be used here to display the employees, sorted in asceding order by lname
        Employee* d = head;
        while (d != NULL) {
            cout << d -> empid << " " << d -> fname << " " << d -> lname << endl;
            d = d -> right;
            cout << "\n";
        }
            
    }
    
    void upemployee(){
      //merge sorting will be used here to display the employees, sorted in asceding order by lname
        Employee* d = head;
        while (d != NULL) {
            cout << d -> empid << " " << d -> fname << " " << d -> lname << endl;
            d = d -> right;
            cout << "\n";
        }
    }
    //Returns the size of queue
    int getSize()
    {
        return queue_counter;
    }


};

Employeequeue emp; // object global queue variable

class Employeetree
{
private:
    Employee* root;
    
public:
    Employeetree(){
        root = NULL;
    }
    
    void insertree(Employee* &root, long int bstid, string bstfname, string bstlname)
    {
        if (root == NULL) {
            root = new Employee();
            root -> empid = bstid;
            root -> fname = bstfname;
            root -> lname = bstlname;
            root ->left = NULL;
            root ->right = NULL;
        }
        else if (bstid < root ->empid ){
            insertree(root -> left, bstid,bstfname,bstlname);
        }
        else
            insertree (root -> right,bstid,bstfname,bstlname);
        
    }
    
    bool searchemp(Employee* root, long int bstid){
        if (root == NULL) {
            cout << "Employee Not Found" << endl;
            return false;
        }
        else if (bstid == root ->empid){
            cout<< "Employee found" <<endl;
            cout << "Name: " << root -> fname <<" " << root -> lname << endl;
            return true;
        }
        else if (bstid < root ->empid){
            return searchemp(root->left,bstid);
        }
        else{
            return searchemp(root ->right, bstid);
        }
 
    }
    
};

Employeetree tremp; //Tree object global variable

// login function
int login (string& username, string& password) {
    const int attempts = 3;
    int count = 0;
    
    while (count < attempts)
    {
        cout << "Enter Username: ";
        cin >> username;
        cout << "\nEnter Password: ";
        cin >> password;
        
        if (username == "Admin" && password == "emp2020"){
            cout << "\nSuccess\n" << endl;
            return 0;
        }
        else if (count < attempts-1) {
            cout << "Wrong login details \n\nPlease re-enter login details \n";

        }
        count++;
           
    }
    cout<<"\nToo many invalid attempts. Program exiting.";

    exit(-1);
    
}
//Main Menu function


//**********************************************************
// This defines the functions called in the main function
//**********************************************************


int main(){
    
    string username,password;
    int temp_empid;
    string temp_fname;
    string temp_lname;
    
    long int target;
    Employee *root;
    root = NULL;

    cout << " **************************************** \n";
    cout << " Welcome to the Employee Managment System" << endl;
    cout << " **************************************** \n";
    cout << " \nPlease login with your details \n" << endl;

    // call to login function
    login(username, password);  //(commented out for testing purposes)
    
    
        
    int option = 0;// option initialized to zero
    while (option != 6) {
        cout << " **************************************** \n";
        cout << " MAIN MENU " << endl;
        cout << " **************************************** \n";
        cout << " Employee Managment System" << endl;
        cout << " Enter 1 to Display Employee information " << endl;
        cout << " Enter 2 to Insert Employee information " << endl;
        cout << " Enter 3 to Search Employee information " << endl;
        cout << " Enter 4 to Update Employee information " << endl;
        cout << " Enter 5 to Delete Employee information " << endl;
        cout << " Enter 6 to Exit Application \n" << endl;
        cin >> option;

        switch (option)
        {
            case 1:
            {
                emp.dispemployee();
                break;
            }
            case 2:
            {
                char insertcont = 'Y';
                while (insertcont == 'Y'|| insertcont == 'y') {
                    
                    cout << "Enter employee ID" << endl;
                    cin >> temp_empid;
                    cout << "Enter employee firstname" << endl;
                    cin >> temp_fname;
                    cout << "Enter employee title" << endl;
                    cin >> temp_lname;
                    
                    emp.inemployee (temp_empid, temp_fname, temp_lname);
                    //second function to to insert into tree
                    tremp.insertree(root, temp_empid, temp_fname, temp_lname);
                    
                    cout<< "continue inserting employees? \n Y(Yes) or N(No) "<< endl;
                    cin >> insertcont;
                    
                    
                }
                break;
                //insert function
                
            }
            case 3:
            {
                cout << "Enter target Employee ID to search" << endl;
                cin >> target;
                tremp.searchemp(root, target);
                
                break;
            }
            case 4:
            {
                //Update employee info
                break;
            }
            case 5:
                //Delete employee info
            case 6:
                cout << "Goodbye!" << endl;
                exit(0);
            
            default:
                cout<<"\nPlease select a valid option\n"<<endl;
                option = 0;
                break;
        }
    }


 
    return 0;
}
