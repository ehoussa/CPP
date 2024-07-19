#include "PhoneBook.hpp"
 
void    ft_usage()
{
    std::cout << "--------------------------------------\n";
    std::cout << "|  Welcome to Your Awesome PhoneBook |\n";
    std::cout << "|------------------------------------|\n";
    std::cout << "|               USAGE                |\n";
    std::cout << "|------------------------------------|\n";
    std::cout << "| ADD     | To add a contact         |\n";
    std::cout << "|------------------------------------|\n";
    std::cout << "| SEARCH  | To search for a contact  |\n";
    std::cout << "|------------------------------------|\n";
    std::cout << "| EXIT    | to quite the PhoneBook   |\n";
    std::cout << "--------------------------------------\n" << std::endl;
}

void    ft_display_list(PhoneBook *phonebook, int index)
{
    int i;

    if (index != 0)
        std::cout << "---------------------------------------------" << std::endl;
    i = 0;
    while (i < index)
    {
        std::cout << "|" << std::setw(10) << i;
        if (phonebook->Search(0, i).size() > 10)
            std::cout << "|" << std::setw(9) << phonebook->Search(0, i).substr(0, 9) << ".";
        else
            std::cout << "|" << std::setw(10) << phonebook->Search(0, i).substr(0, 10);
        if (phonebook->Search(1, i).size() > 10)
            std::cout << "|" << std::setw(9) << phonebook->Search(1, i).substr(0, 9) << ".";
        else
            std::cout << "|" << std::setw(10) << phonebook->Search(1, i).substr(0, 10);
        if (phonebook->Search(2, i).size() > 10)
            std::cout << "|" << std::setw(9) << phonebook->Search(2, i).substr(0, 9) << ".";
        else
            std::cout << "|" << std::setw(10) << phonebook->Search(2, i).substr(0, 10) << "|\n";
        std::cout << "---------------------------------------------" << std::endl;
        i++;
    }
}

bool isDigit(std::string str)
{
    const char  *ptr;
    
    ptr = str.c_str();
    while (*ptr != '\0')
    {
        if (!std::isdigit(*ptr))
            return false;
        ptr++;
    }
    return true;
}

void    ft_search(PhoneBook *phonebook, int indx)
{
    int         index;
    std::string str;
    bool        result;

    ft_display_list(phonebook, indx);
    std::cout << "Please enter the contact index: ";
    while (1)
    {
        getline(std::cin, str);
        std::cout << std::endl;
        if (str.compare("Q") == 0)
            break;
        if (str.size() == 0)
        {
            std::cout << "Please enter the contact index: ";
            continue;
        }
        result = isDigit(str);
        if (result == false)
        {
            std::cout << "Please enter just digit: ";
            continue;
        }
        index = std::stoi(str);
        if (index >= indx)
        {
            std::cout << "Out of rang, try again: ";
            continue;
        }
        break;
    }
    if (indx != 0)
    {
        std::cout << "first name: " << phonebook->Search(0, index) << std::endl;
        std::cout << "last name: " << phonebook->Search(1, index) << std::endl;
        std::cout << "nickname: " << phonebook->Search(2, index) << std::endl;
        std::cout << "phone number: " << phonebook->Search(3, index) << std::endl;
        std::cout << "darkest secret: " << phonebook->Search(4, index) << "\n" << std::endl;
    }
}

void    ft_add(PhoneBook *phonebook, int index)
{
    bool        result;
    std::string str;
    int         i;

    i = 0;
    while (1)
    {
        if (i == 0)
            std::cout << "\nPlease enter you first name: ";
        else if (i == 1)
            std::cout << "Please enter you last name: ";
        else if (i == 2)
            std::cout << "Please enter you nickname: ";
        else if (i == 3)
            std::cout << "Please enter you phone number: ";
        else if (i == 4)
            std::cout << "Please enter you darkest secret: ";
        getline(std::cin, str);
        if (std::cin.eof())
            std::exit(1);
        if (str.size() == 0)
            continue;
        result = isDigit(str);  
        if (i == 3 && result == false)
        {
            std::cout << "Please enter just digit: ";
            continue;
        }
        phonebook->Add(str, i, index);
        i++;
        if (i > 4)
            break;
    }
    std::cout << std::endl;
}

int main()
{
    int         index;
    std::string cmd;
    std::string str;
    PhoneBook   phonebook;

    ft_usage();
    index = 0;
    while (1)
    {
        std::cout << "Enter cmd: ";
        getline(std::cin, cmd);
        if (std::cin.eof())
            std::exit(1);
        if (cmd.compare("ADD") == 0)
        {
            ft_add(&phonebook, index);
            index++;
        }
        else if (cmd.compare("SEARCH") == 0)
            ft_search(&phonebook, index);
        else if (cmd.compare("EXIT") == 0)
            exit (0);
        else
            std::cout << "plz enter valide cmd" << std::endl;        
        if (index >= SIZEAR)
            index = 0;
    }
    return (0);
}
