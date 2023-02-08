#include <fstream>
#include <iostream>
#include <filesystem>
#include "User_and_Message.h"

using namespace std;
namespace fs = std::filesystem;
//функция отбирает права доступа у групп и остальных
void setPerms (string filename)
{
	fs::permissions(filename,
		fs::perms::group_all | fs::perms::others_all,
		fs::perm_options::remove);
}

int main() {
	setlocale(LC_ALL, "Rus");
	//Открываем файл пользователя
	fstream user_file = fstream("user.txt", ios::in |  ios::out);
	if (!user_file)
		// Если файла нет, то создаем
		user_file = fstream("user.txt",ios::in | ios::out | ios::trunc);
	//Назначаем права доступа
	setPerms("user.txt");
	if (user_file) {
		//если файл до этого создан а права не назначены, назначаем
		setPerms("user.txt");
		string name;
		string login;
		string pass;
		cout << "Введите имя нового пользователя: ";
		getline(cin, name, '\n');
		cout << "Введите login: ";
		getline(cin, login, '\n');
		cout << "Введите pass: ";
		getline(cin, pass, '\n');
		User obj(name, login, pass);
		// Запишем данные в файл
		user_file << obj;
		// Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
		user_file.seekg(0, ios_base::beg);
		// Считываем данные из файла
		user_file >> obj;
		cout << obj << endl;
	}
	else
	{
		cout << "Could not open file user.txt !" << '\n';
	}
	//Откравыем файл сообщения
	fstream message_file = fstream("message.txt", ios::in | ios::out);
	if (!message_file)
		// Если файла сообщения нет то создаем его
		message_file = fstream("message.txt", ios::in | ios::out | ios::trunc);
	//Назначаем права на файл
	setPerms("message.txt");

	if (message_file)
	{
		//если файл до этого создан а права не назначены, назначаем
		setPerms("message.txt");
		string text;
		cout << "Введите сообщение: ";
		getline(cin, text, '\n');
		Message mes(text, "sender", "receiver");
		// Запишем данные в файл
		message_file << mes;
		// Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
		message_file.seekg(0, ios_base::beg);
		// Считываем данные из файла
		message_file >> mes;
		cout << mes << endl;
	}
	else
	{
		cout << "Could not open file message.txt !" << '\n';
	}
	return 0;
}
