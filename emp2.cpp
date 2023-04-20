//
//  main.cpp
//  Data structures final project
//
//  Created by solo ugbane on 4/30/21

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
struct Employee // Employee class (Node)
{
    long int empid;
    string fname;
    string lname;
    Employee* left; // previous pointer
    Employee* right; // next pointer
    
  //Calculate employee salary?
};


// ----------------------------------- Employee queue class ---------------------------------------------
class Employeequeue
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
        else // if the list has at least one Employee,
          {
            tail->right = e;
            e->left = tail;
            tail = e; // makes the tail points to x
          }
          queue_counter++;
    }
    //quick sort algorithm
    struct Employee *partition(struct Employee *prev, struct Employee *next)
    {
        struct Employee *pivot = next;
        struct Employee *i = prev->left;
        for (struct Employee *ptr = prev; ptr != next; ptr = ptr->right)
        {
            if (ptr->empid <= pivot->empid)
            {
                i = (i == NULL ? prev : i->right);
                long int temp = i->empid;
                i->empid = ptr->empid;
                ptr->empid = temp;
            }
        }
        i = (i == NULL ? prev : i->right);
        long int temp = i->empid;
        i->empid = pivot->empid;
        pivot->empid = temp;
        return i;
    }
    void QuickSort(struct Employee *prev, struct Employee *next)
    {
        if (next != NULL && prev != next && prev != next->right)
        {
            struct Employee *p = partition(prev, next);
            QuickSort(prev, p->left);
            QuickSort(p->right, next);
        }
    }
    
    void printsort(){
        QuickSort(head, tail);
        while (head != NULL) {
            cout<< head -> empid <<" " << head -> fname<< " " << head -> lname << endl;
            head = head -> right;
        }
    }
    
    //delete an employee
    void delemphead(){
        if (head != NULL ) {
            Employee* temp = head;
            head = head -> right;
            temp = NULL;
        }
        queue_counter--;
    }
    void deemployee (long int nempid){
      if( nempid == head ->empid ) //if list is empty
        {
            delemphead();
        }
      else if (nempid == tail ->empid){
          Employee* temp = tail;
          tail = tail -> left;
          temp = NULL;
          
      }
      else {
          Employee* target = head;
          Employee* previous = head;
          
          while (nempid != target -> empid) {
              previous = target;
              target = target -> right;
          }
          previous->right = target->right;
          target->right->left = previous;
          target = NULL;
          
      }
        queue_counter--;

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
    
    void upemployee(long int nempid, string nfname, string nlname){
      //merge sorting will be used here to display the employees, sorted in asceding order by lname
        Employee* d = head;
        while (d -> empid != nempid) {
            d = d -> right;
        }
        if (d == NULL)
            cout<<"Employee not found. Please confirm Employee ID is correct \n";
        d -> fname = nfname;
        d -> lname = nlname;
    }                                // yes sir! since 11:30am 
    //Returns the size of queue
    int getSize()
    {
        return queue_counter;           
    }


};

Employeequeue emp; // object global queue variable

// ---------------------------------------  Binary search tree --------------------------------------
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

    bool updatetree(Employee* root, long int bstid, string nfname, string nlname) {
        if (root == NULL) {
            return false;
        }
        else if (bstid == root ->empid){
            root -> fname = nfname;
            root -> lname = nlname;
            return true;
        }
        else if (bstid < root ->empid){
            return updatetree(root->left, bstid, nfname, nlname);
        }
        else{
            return updatetree(root ->right, bstid, nfname, nlname);
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
 // find min value
Employee* Min(Employee* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

//Delete function
 struct Employee* DelEmployee(struct Employee* root, int empid) {
        if (root == NULL) {
            return root;
        }
        else if (empid < root->empid) {
           root->left = DelEmployee(root->left, empid);
        }
        else if (empid > root-> empid) {
            root->right = DelEmployee(root->right, empid);
        }
        else {
            // No child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                root = NULL;
               
            }
            // one child
            else if (root->left == NULL) {
                struct Employee* temp = root;
                root = root->right;
                delete temp;
                

            }
            else if (root->right == NULL) {
                struct Employee* temp = root;
                root = root->left;
                delete temp;
                

            }
            // 2 child
            else {
                struct Employee* temp = Min(root->right);
                root->empid = temp->empid;
                root->right = DelEmployee(root->right, temp->empid);
            }
           
        }
        return root;
}

//**********************************************************
// This is the Main Function
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
               
                char sort;
                cout<<"Sort by Employee ID? \n Y(Yes) or N(No)";
                cin>>sort;

                if (sort == 'Y'|| sort == 'y'){
                    //Employeequeue quickemp = emp;
                    emp.printsort();
                }
                else 
                    emp.dispemployee();
                
                break;
            }
            case 2:
            {
                char insertcont = 'Y';
                while (insertcont == 'Y'|| insertcont == 'y') {
                    
                    cout << "Enter employee ID" << endl;
                    cin >> temp_empid;
                    cout << "Enter employee first name" << endl;
                    cin >> temp_fname;
                    cout << "Enter employee last name" << endl;
                    cin >> temp_lname;
                    
                    emp.inemployee (temp_empid, temp_fname, temp_lname);
                    //add second object for quicksorting
                    
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
                cout << "Enter target Employee ID to search \n" << endl;
                cin >> target;
                tremp.searchemp(root, target);
                
                break;
            }
            case 4:
            {
                char upcont = 'Y';
                while (upcont == 'Y'|| upcont == 'y') {
                    
                    cout << "Enter employee ID to update" << endl;
                    cin >> temp_empid;
                    if (tremp.searchemp(root, temp_empid)){
                        cout << "Enter updated employee first name" << endl;
                        cin >> temp_fname;
                        cout << "Enter updated employee last name" << endl;
                        cin >> temp_lname;

                        // First function to update linked list
                        emp.upemployee (temp_empid, temp_fname, temp_lname);
                        // Second function to update BST
                        tremp.updatetree(root, temp_empid, temp_fname, temp_lname);

                    }
                    
                    cout<< "Continue updating employees? \n Y(Yes) or N(No) "<< endl;
                    cin >> upcont;
                    
                    
                }                
                break;
            }
            case 5:{
                //Delete employee info
                char delcont = 'Y';
                while (delcont == 'Y'|| delcont == 'y') {
                    
                    cout << "Enter employee ID to delete" << endl;
                    cin >> temp_empid;
                    if (tremp.searchemp(root, temp_empid)){                       
                       
                        emp.deemployee(temp_empid); // function call to delete from queue
                        
                        root = DelEmployee(root, temp_empid);
                        cout<<"Employee deleted \n";
                    }
                    
                    cout<< "Continue deleting employees? \n Y(Yes) or N(No) "<< endl;
                    cin >> delcont;
                    
                    
                }                            
                break;
            }
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
