#!/usr/bin/env python
# coding: utf-8

# In[1]:


import os
from os import system
import time
import pandas as pd
import getpass

# In[2]:


# Global Variable for directories
# For Current Working User
User_Name = "admin"
Record_Dir = User_Name +"/records/student_record.csv"


# # Regestration

# In[3]:


def Regestration():
    """ This Function is to make an account for to manage Student Record
    """
    # ask user name
    # ask Password
    # ask confirm password
    
    Heading()
    username = input("\nPlease Enter the User Name to regester:- ")
    password = getpass.getpass(prompt='Enter Password : ')
    repassword = getpass.getpass(prompt='Re-enter Password : ')
    
    #print(username)
    #print(password)
    #print(repassword)
    
    #confirm regestration
    if password == repassword:
        #create the New account
        os.mkdir(f"{username}")
        filepath =username+"/Config"  
        
        file = open(filepath,'w')
        
        file.write("UserName: "+ username+"\n")
        file.write("password: "+ password+ "\n")
        file.close()
        print("Regestration completed. ")
        time.sleep(2)
        return Login()
    


# # Read Config File

# In[4]:


def Readconfig(username):

    # retrive the data from the config file
    filepath = username+"/Config"
    
    try:
        file =open(filepath,'r')

        line = file.readline()
        username = line.split(":")[1].strip()
        #print (line.split(":")[1].strip())

        line = file.readline()
        password = line.split(":")[1].strip() 
        #print(password)

        file.close()
        
        return username , password
        
    except:
        return False

    
    


# # Login Screen

# In[5]:


def Login():
    
    # ask for the userName and password
    
    Heading()
    UserName = input("Please Enter the user Name:- ")
    Password = getpass.getpass(prompt='Enter Password : ')
    
    Data = Readconfig(UserName)
    
    if Data != False:
        
        # Compare the Password
        if Password == Data[1]:
            
            global User_Name 
            User_Name = UserName
            print("\nAccess Granted")
            return True
        else:
            print("User Name or Password is incorrect.  Please Try again.\n")
            time.sleep(3)
            system("cls")
            print("Login...\n")
            return Login()
            
        
    else:
        print("User Name is not found")
        return False
    


# # Student Entry
# 
# Student Name, class, Section, Stream, Roll no., Sports, Hobbies, Grade

# In[6]:


#from os import system
#import time

def Student_new_entry(User_Name):
    time.sleep(1)
    Heading()
    # Enter the Details of Student
    # create or check the directory for the record.
    DirName = User_Name + "/records"
    
    if os.path.isdir(DirName):
    
        print("\nEnter the Details of the Students as asked.\n\n")

        Student_Name = input("Student Name:- ")
        Class = input("Class:- ")
        Section = input("Section:- ")
        Stream = input("Stream:- ")
        Roll_no = input("Roll no.:- ")
        Sports = input("Sports:- ")
        Hobbies = input("Hobbies:- ")
        Grade = input("Grade:- ")
        
        file = open(DirName+"/student_records.csv",'a')
        file.write(f"{Student_Name},{Class},{Section},{Stream},{Roll_no},{Sports},{Hobbies},{Grade}\n")
        file.close()
        
    else :
        
        os.mkdir(User_Name +"/records")
        file = open(DirName+"/student_records.csv",'w')
        file.write("Name,Class,Section,Stream,Roll No.,Sports,Hobbies,Grade\n")
        file.close()
        
        return Student_new_entry(User_Name) 
          


# # Return to Main Menu

# In[16]:


def return_menu():
    global User_Name
    cmd = input("\n\n Press 0 to return main menu: ")
    if cmd =='0':
        return Show_options(User_Name)
    else:
        return return_menu()


# # Show Details

# In[7]:


def Show_Student_details(User_Name):
    Heading()
    print("Student Details:>\n\n")
    # This will show the all student Details
    DIR = User_Name+"/records/student_records.csv"
    file = pd.read_csv(DIR)
    file.set_index("Name",inplace=True)
    print(file)
    
    return_menu()


# # Update the Student Data Entry

# In[8]:


def Update(User_Name):
    Heading()
    # This Function is used to update the inforamtion of a student in a column
    DIR = User_Name+"/records/student_records.csv"
    
    file = pd.read_csv(DIR)
    file.set_index("Name",inplace=True)
    
    time.sleep(1)
    Heading()
    Student_Name = input("\nPlease Enter the Student Name:- ")
    #print(file.loc[Student_Name])
    try:
        while(1):
            Heading()
            print("\nType 'exit' to come back from Update Student Entry.\n\n")
            print(file.loc[Student_Name])
            cat = input("\nSelect the catageory to Update:- ")
            CatValue =False
            
            if cat != "exit":
                
                for icat in file.columns.to_list():
                    
                    if icat == cat:
                        CatValue = True
                        break
                    else:
                        CatValue = False
                    
                if CatValue==True:
                    
                    Input_data = input("\nEnter New Value:- ")
                    file.loc[Student_Name,cat] = Input_data
                    print("\n\nUpdating the Entry in 2 sec...")
                    time.sleep(2)
                    system ("cls")
                else:
                    print("\nInvalid Catagery Please try Again.")
            
            else: break
    except:
        system("cls")
        print(F"\n{Student_Name}'s Entry Not Found \n")
        print("Please try Again.")
        time.sleep(3)
        return Update(User_Name)
    
    # Now after updating the data we need to save the file
    
    file.to_csv(User_Name+"/records/student_records.csv")
    


# # Delete Entry

# In[9]:


def Delete_Entry(User_Name):
    Heading()
    DIR = User_Name+"/records/student_records.csv"
    
    file = pd.read_csv(DIR)
    file.set_index("Name",inplace=True)
    
    # Select the Student Name to Delete
    
    
    
    # delete entries if it is not exit 
    while(1):
        time.sleep(2)
        Heading()
        print("Type 'exit' to come back from Delete Function.")
        Student_Name = input("Please select the student to delete:- ")
        if Student_Name !="exit":
            # confirmation before deletion   Y/y or N/n
            try:
                print(f"\n\n{file.loc[Student_Name]}")
                confirm = input(f"Are you sure to delete {Student_Name}'s entry (Y/N):> ")
                confirm  = confirm.lower()
            
                if confirm != "n":
                    
                    file.drop(Student_Name,inplace=True)
                    file.to_csv(User_Name+"/records/student_records.csv")
                    
                else:
                    return Delete_Entry(User_Name)
                
            except:
                print("\nRecord Not Found..\nPlease try again. \n")   
                
                
           
            
        else : break


# # Login or Regestration

# In[10]:


def Account_entry():

    system("cls")
    Heading()
    print("1. Login \n2. Regestration \n ")
    selection = input("Select the option in number:-  ")
    
    if selection=='1':
        return Login()
    elif selection == '2':
        return Regestration()
    else:
        print("\nInvalid Selection Please Select the option from above... ")
        time.sleep(2)
        system("cls")
        print("Please Try Again\n")
        
        return Account_entry()


# # Option Menu for Student Data

# In[11]:


def Show_options(User_Name):
    user = User_Name
    system("cls")
    
    Heading()
    print("1. New Student Entry")
    print("2. Update Student Entry")
    print("3. Delete Student Entry")
    print("4. Show Students Record")
    print("5. Close the program\n\n")
    
    selection = input("Please Select the option in Number:- ")
    
    if selection == '1' or selection == '2' or selection == '3' or selection == '4': 
        return selection
    
    elif selection == '5' :
        cmd = input("\nDo you realy want to close the program (Y/N): ")
        cmd = cmd.lower()
        
        if cmd == 'y':
            exit()
        else:
            print(f"User Name: {user}")
            return Show_options(user)
    else:
        print("\nSelection is not Valid. Please try Again")
        time.sleep(3)
        system("cls")
        print(f"User Name: {user}")
        return Show_options(user)
        
        
def welcome_screen():
    system("cls")
    print("{}".format("\n"*10))
    print("{}Welcome".format(" "*55))
    print("{}To".format(" "*57))
    print("{}Student Management System".format(" "*45))
    time.sleep(5)
    system("cls")
    

def Heading():
    system("cls")
    print("{}Student Management System".format(" "*50))
    print("{}".format("_"*120))
    
# # Main Scereen Function

# In[12]:


def main():
    global User_Name
    
    welcome_screen()
    # first Ask for Login or Regestrarion   
    
    # capture login result Acc
    Access_result = Account_entry()
    
    if Access_result ==True:
        selection = Show_options(User_Name)
        
        while(selection !='5'): 
            
            
            if selection == '1':
                # This selectio if for to make a new student entry
                Student_new_entry(User_Name)
                system("cls")
                # return to the main menu Functionality
                #return Show_options(User_Name)
                selection = Show_options(User_Name) 
                
            elif selection == '2':
                  # This selectio if for to Update the Entry
                Update(User_Name)
                system("cls")
                #return Show_options(User_Name)
                selection = Show_options(User_Name) 
                
            elif selection == '3':
                  # This selectio if for to Delete The Entry
                Delete_Entry(User_Name)
                system("cls")
                #return Show_options(User_Name)
                selection = Show_options(User_Name) 
                
            elif selection == '4':
                  # This selectio if for showing the Students records
                Show_Student_details(User_Name)
                selection = Show_options(User_Name) 
                
            elif selection == '5':
                exit()
                 
                
            else:
                print("Invalid Selection..")
                
               
        
    else:
        print("||Access Denied||\n\nPlease try Again..\n")
        time.sleep(3)
        system("cls")
        return main()
        


# In[13]:


if __name__ == "__main__":
    main()

