#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct USER
{
    int id;
    string firstName;
    string lastName;
    string username;
    string password;
    string address;
    string childName;
    int childAge;


};

/*=========CRUD=========*/
int getUserIndex(USER* users, int& userCount, int id) //Gets user's index by using the id of the user
{
    for (int i = 0; i < userCount; i++)
    {
        if (users[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void createUser(USER* users, int& userCount, int& maxId, USER newUsers) // adds new user to the main list (the array)
{
    newUsers.id = maxId++;
    users[userCount] = newUsers;
    userCount++;
}

void updateUser(USER* users, int userCount, int id, USER newUsers) //edits the data of the user
{
    int index = getUserIndex(users, userCount, id);
    users[index] = newUsers;
}

void deleteUser(USER* users, int& usersCount, int id) // "deletes" user
{
    int index = getUserIndex(users, usersCount, id);

    for (int i = index; i < usersCount - 1; i++)
    {
        users[i] = users[i + 1];
    }
    usersCount--;
}

USER getUser(USER* users, int& userCount, int id) // finds product by its index
{
    int index = getUserIndex(users, userCount, id);
    return users[index];
}
/*======================*/


/*=====PRESENTATION LAYER=====*/

void menu() // diplsays main menu of the program
{
    cout << "   MENU:" << endl;
    cout << "1.Enter user" << endl;
    cout << "2.View all users" << endl;
    cout << "3.Edit user" << endl;
    cout << "4.Delete user" << endl;
    cout << "6.Exit" << endl;
    cout << endl << "Your choice: ";
}

void enterUserMenu(USER* users, int& userCount, int& maxId) //dislays the menu that help the admin to enter user's data
{
    USER user;
    cout << "Enter the id of the parent: "; cin >> user.id; cout << endl;
    cout << "Enter the first name of the parent: "; cin >> user.firstName; cout << endl;
    cout << "Enter the last name of the parent: "; cin >> user.lastName; cout << endl;
    cout << "Enter the username of the parent: "; cin >> user.username; cout << endl;
    cout << "Enter the password of the parent: "; cin >> user.password; cout << endl;
    cout << "Enter the address of the parent"; cin >> user.address; cout << endl;
    cout << "Enter the first name of the child: "; cin >> user.childName; cout << endl;
    cout << "Enter the age of the child: "; cin >> user.childAge; cout << endl;

    createUser(users, userCount, maxId, user);
    cout << "You are ready! The user has been added to your list!" << endl;
}

void showUserMenu(USER* users, int& userCount, int& maxId) // shows all current saved users' data to the admin
{
    cout << "List of the entered products:" << endl;
    for (int i = 0; i < userCount; i++)
    {
        cout << "Id: " << users[i].id << endl;
        cout << "First name: " << users[i].firstName << endl;
        cout << "Last name: " << users[i].lastName << endl;
        cout << "Username: " << users[i].username << endl;
        cout << "Password: " << users[i].password << endl;
        cout << "Address:" << users[i].address << endl;
        cout << "Child name:" << users[i].childName << endl;
        cout << "Child age:" << users[i].childAge << endl;
    }
}

void editEditMenu(USER* users, int& userCount) //displays the menu that help the admin to edit data of a user
{
    int userId;

    cout << "please enter the id of the user that you want to edit: ";
    cin >> userId;

    USER user = getUser(users, userCount, userId);

    cout << "1.Id" << endl;
    cout << "2.First name" << endl;
    cout << "3.Last name" << endl;
    cout << "4.Username" << endl;
    cout << "5.Password" << endl;
    cout << "6.Address" << endl;
    cout << "7.Child name" << endl;
    cout << "8.Child age" << endl;
    cout << "What do you want to edit: " << endl;

    int choose;
    cin >> choose;

    switch (choose)
    {
    case 1:
        cout << "Enter new ID: ";
        cin >> user.id;
        updateUser(users, userCount, userId, user);
        break;
    case 2:
        cout << "Enter new first name: ";
        cin >> user.firstName;
        updateUser(users, userCount, userId, user);
        break;
    case 3:
        cout << "Enter new last name: ";
        cin >> user.lastName;
        updateUser(users, userCount, userId, user);
        break;
    case 4:
        cout << "Enter new username: ";
        cin >> user.username;
        updateUser(users, userCount, userId, user);
        break;
    case 5:
        cout << "Enter new pasword: ";
        cin >> user.password;
        updateUser(users, userCount, userId, user);
        break;
    case 6:
        cout << "Enter new address: ";
        cin >> user.address;
        updateUser(users, userCount, userId, user);
        break;
    case 7:
        cout << "Enter new child name: ";
        cin >> user.childName;
        updateUser(users, userCount, userId, user);
        break;
    case 8:
        cout << "Enter new child age: ";
        cin >> user.childAge;
        updateUser(users, userCount, userId, user);
        break;

    default:
        cout << "Invalid input!" << endl;
    }
    cout << "You are ready! The user has been added to your list!" << endl;
}

void deleteUserMenu(USER* users, int& userCount, int& maxId) //displays a menu that help the admin to delete a whole user
{
    int userId;

    cout << "please enter the id of the user that you want to delete: ";
    cin >> userId;

    deleteUser(users, userCount, userId);

    cout << "You are ready!The user has been removed from the list!" << endl;
}




/*===================================================*/
int main() // the main function of the project
{


}