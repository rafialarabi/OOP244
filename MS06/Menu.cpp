


// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Section:        NBB
// Milestone 6
// Date:           10/07/2020


/* I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. */


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Menu.h"
using namespace std;

namespace sdds {

	MenuItem::MenuItem() {

		MenuTitle = nullptr;
	}

	MenuItem::MenuItem(const char* m_items) {

		if (m_items != nullptr) {

			MenuTitle = new char[strlen(m_items) + 1];
			strcpy(MenuTitle, m_items);

		}
		else {

			MenuTitle = nullptr;
		}
	}

	void MenuItem::displayMenuItem() const {

		if (MenuTitle != nullptr) {
			cout << MenuTitle << endl;
		}
	}

	MenuItem::~MenuItem() {
		delete[] MenuTitle;
		MenuTitle = nullptr;
	}

	Menu::Menu() {
		MenuTitle = nullptr;
		*MenuItems = nullptr;
		Menuindentation = 0;
		NOfItems = 0;
	}

	void Menu::Indent(const int ind) {

		Menuindentation = ind;

	}


	Menu::Menu(const char* m_title, int indent) {

		if (m_title != nullptr) {

			MenuTitle = new char[strlen(m_title) + 1];
			strcpy(MenuTitle, m_title);
			*MenuItems = nullptr;
			Menuindentation = indent;
			NOfItems = 0;
		}
		else {

			MenuTitle = nullptr;
			*this = Menu();
		}
	}

	Menu::Menu(const Menu& MI) {

		Menuindentation = MI.Menuindentation;
		NOfItems = MI.NOfItems;

		if (MI.MenuTitle != nullptr) {

			MenuTitle = new char[strlen(MI.MenuTitle) + 1];
			strcpy(MenuTitle, MI.MenuTitle);

			for (int i = 0; i < MI.NOfItems; i++) {

				if (MI.MenuItems[i] != nullptr) {

					MenuItems[i] = new MenuItem(MI.MenuItems[i]->MenuTitle);
				}
				else {

					MenuItems[i] = nullptr;
				}
			}
		}
		else {
			MenuTitle = nullptr;
		}

	}

	Menu& Menu::operator=(const Menu& MI) {

		if (this != &MI) {

			delete[] MenuTitle;
			MenuTitle = nullptr;

			for (int i = 0; i < NOfItems; ++i) {
				delete MenuItems[i];
				MenuItems[i] = nullptr;
			}

			Menuindentation = 0;
			NOfItems = 0;

			Menuindentation = MI.Menuindentation;
			NOfItems = MI.NOfItems;

			if (MI.MenuTitle != nullptr) {

				MenuTitle = new char[strlen(MI.MenuTitle) + 1];
				strcpy(MenuTitle, MI.MenuTitle);
				for (int i = 0; i < MI.NOfItems; i++) {
					MenuItems[i] = new MenuItem(MI.MenuItems[i]->MenuTitle);
				}

			}
			else {

				delete[] MenuTitle;
				MenuTitle = nullptr;

				for (int i = 0; i < NOfItems; ++i) {
					delete MenuItems[i];
					MenuItems[i] = nullptr;
				}

				Menuindentation = 0;
				NOfItems = 0;
			}
		}

		return *this;
	}

	Menu::operator bool() const {

		return MenuTitle != nullptr && NOfItems <= MAX_NO_OF_ITEMS && NOfItems > 0 && Menuindentation >= 0;
	}

	bool Menu::isEmpty() const {

		return *this;
	}

	ostream& Menu::display(ostream& mu) const {

		if (MenuTitle == nullptr) {

			mu << "Invalid Menu!" << endl;
		}
		else if (*MenuItems == nullptr || MenuItems[0]->MenuTitle == nullptr) {

			for (int i = 0; i < Menuindentation; i++) {
				mu << "    ";
			}

			cout << MenuTitle << endl;
			mu << "No Items to display!" << endl;
		}
		else {

			for (int i = 0; i < Menuindentation; i++) {
				mu << "    ";
			}

			mu << MenuTitle << endl;
			for (int i = 0; i < NOfItems && MenuItems[i] != nullptr; i++) {
				if (MenuItems[i]->MenuTitle != nullptr) {

					for (int i = 0; i < Menuindentation; i++) {
						mu << "    ";
					}

					mu << i + 1 << "- " << MenuItems[i]->MenuTitle << endl;
				}
			}
			for (int i = 0; i < Menuindentation; i++) {
				mu << "    ";
			}
			mu << "> ";
		}
		return mu;
	}


	void Menu::add(const char* m_item) {

		if (m_item != nullptr) {

			MenuItems[NOfItems] = new MenuItem(m_item);
			NOfItems++;
		}
		else {

			delete[] MenuTitle;
			MenuTitle = nullptr;

			for (int i = 0; i < NOfItems; ++i) {
				delete MenuItems[i];
				MenuItems[i] = nullptr;
			}

			Menuindentation = 0;
			NOfItems = 0;
		}
	}

	Menu& Menu::operator<<(const char* menuitem) {

		add(menuitem);
		return *this;
	}

	Menu& Menu::operator=(const char* title) {

		if (MenuTitle != nullptr) {

			delete[] MenuTitle;
			MenuTitle = nullptr;

			MenuTitle = new char[strlen(title) + 1];
			strcpy(MenuTitle, title);
		}
		else {

			delete[] MenuTitle;
			MenuTitle = nullptr;

			for (int i = 0; i < NOfItems; ++i) {
				delete MenuItems[i];
				MenuItems[i] = nullptr;
			}

			MenuTitle = nullptr;
			Menuindentation = 0;
			NOfItems = 0;
		}
		return *this;
	}

	int Menu::run() const {

		int choice = 0;

		display();

		if (isEmpty()) {
			while ((choice <= 0 || choice > NOfItems)) {

				cin >> choice;

				if (cin.fail()) {

					cout << "Invalid Integer, try again: ";
					cin.clear();
					cin.ignore(2000, '\n');
				}
				else if (choice <= 0 || choice > NOfItems) {

					cout << "Invalid selection, try again: ";
					cin.clear();
					cin.ignore(2000, '\n');
				}
				else {

					cin.clear();
					cin.ignore(100, '\n');
				}
			}
		}
		return choice;
	}


	Menu::operator int() const {
		return run();
	}


	Menu::~Menu() {

		delete[] MenuTitle;
		MenuTitle = nullptr;

		for (int i = 0; i < NOfItems; ++i) {
			delete MenuItems[i];
			MenuItems[i] = nullptr;
		}
	}
}




