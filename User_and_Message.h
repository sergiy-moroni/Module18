#pragma once
#include <string>

class User {
	std::string _name;
	std::string _login;
	std::string _pass;

public:
	User(std::string name, std::string login, std::string pass) :_name(name), _login(login), _pass(pass) {}

	friend std::fstream& operator >>(std::fstream& is, User& obj);
	friend std::ostream& operator <<(std::ostream& os, const User& obj);
};

class Message {
	std::string _text;
	std::string _sender;
	std::string _receiver;

public:
	Message(std::string text, std::string sender, std::string receiver) : _text(text), _sender(sender), _receiver(receiver){}
	friend std::fstream& operator >>(std::fstream& is, Message& mes);
	friend std::ostream& operator <<(std::ostream& os, const Message& mes);

};

std::fstream& operator >>(std::fstream& is, User& obj)
{
	is >> obj._name;
	is >> obj._login;
	is >> obj._pass;
	return is;
}

std::ostream& operator <<(std::ostream& os, const User& obj)
{
	os << obj._name;
	os << ' ';
	os << obj._login;
	os << ' ';
	os << obj._pass;
	os << std::endl;
	return os;
}

std::fstream& operator >>(std::fstream& is, Message& mes)
{
	is >> mes._text;
	is >> mes._sender;
	is >> mes._receiver;
	return is;
}

std::ostream& operator <<(std::ostream& os, const Message& mes)
{
	os << mes._text;
	os << ' ';
	os << mes._sender;
	os << ' ';
	os << mes._receiver;
	os << std::endl;
	return os;
}
