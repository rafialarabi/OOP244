
#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

#include <iostream>
#include <cstring>

namespace sdds {

	const int MAX_NO_OF_ITEMS = 10;

	class Menu;

	class MenuItem {
	
		char* MenuTitle;

	private:
		MenuItem();
		MenuItem(const char* m_items);
		void displayMenuItem() const;
		MenuItem(const MenuItem&) = default;
		MenuItem& operator=(const MenuItem&) = default;
		~MenuItem();
 		friend class Menu;
	};

	class Menu {

		char* MenuTitle;
		MenuItem* MenuItems[MAX_NO_OF_ITEMS];
		int Menuindentation;
		int NOfItems;

	public:
		Menu();
		Menu(const char* m_title, int m_indent = 0);
		Menu(const Menu&);
		Menu& operator=(const Menu&);
		Menu& operator=(const char* title);
		~Menu();
		std::ostream& display(std::ostream& os = std::cout) const;
		void add(const char* m_item);
		Menu& operator<<(const char*);
		int run() const;
		operator int() const;
		operator bool() const;
		bool isEmpty() const;
	};

}


#endif //SDDS_MENU_H