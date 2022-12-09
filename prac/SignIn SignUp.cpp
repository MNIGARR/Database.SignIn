#include <iostream>
using namespace std;

//class User :
//	string username;
//string password;
//
//class Database :
//	User * users;
//
//bool SignIn(User& user)
//bool SignUp(User& user)

class DataBase;

class User {
public:
	friend class DataBase;
	string username;
	string password;
	User() {}
	User(string username, string password) {
		this->username = username;
		this->password = password;
	}
	bool operator>(const User& obj) {
		return username > obj.username && password > obj.password;
	}
	friend istream& operator>>(istream& in, User& obj) {
		cout << "Enter username: " << "\n";
		in >> obj.username;
		cout << "Enter your password: " << "\n";
		in >> obj.password;
		return in;
	}
};

class DataBase {
	
	User* users = nullptr;
	int size = 0;
public:
	
	bool SignIn(User& user) {
		for (int i = 0; i < size; i++)
		{
			if (user.username == users->username) {
				if (user.password == users->password) {
					cout << "~~~You logged in successfully~~~" << "\n";
					return true;
				}
				else {
					cout << "You couldn't log in successfully!!!" << "\n";
					return false;
				}
			}
			else {
				cout << "Your username is incorrect!!!" << "\n";
				return false;
			}
		}
	}
	bool SignUp(User& user) {
		if (size != 0) {
			for (int i = 0; i < size; i++) {
				if (user.username == users->username) {
					cout << "~~~This username is taken~~~" << "\n";
					return false;
				}
				else {
					User* newArr = new User[size + 1];
					for (int i = 0; i < size; i++) {
						newArr[i] = users[i];
					}
					newArr[size] = user;
					delete[] users;
					users = newArr;
					newArr = nullptr;
					size++;
				}
			}
		}
		else {
			User* newArr = new User[size + 1];
			for (int i = 0; i < size; i++) {
				newArr[i] = users[i];
			}
			newArr[size] = user;
			delete[] users;
			users = newArr;
			newArr = nullptr;
			size++;
		}
	}
};

void main() {
	DataBase log;
	User Nigar("Nigar", "Ragin1812");
	User Khayyam;
	cin >> Khayyam;
	cout << "\n";
	log.SignUp(Nigar);
	log.SignIn(Khayyam);
}