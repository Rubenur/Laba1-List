#include <iostream>
#include <string>
#include <sstream>
#include "List.h"

void menu() // menu
{
    std::cout << std::endl;
    std::cout << "Function menu:" << std::endl;
    std::cout << "1) add to the end of the list" << std::endl;
    std::cout << "2) add to the beginning of the list" << std::endl;
    std::cout << "3) remove the last element" << std::endl;
    std::cout << "4) remove the first element" << std::endl;
    std::cout << "5) adding an element by index (insert before an element that was previously available at this index)" << std::endl;
    std::cout << "6) get the element by index." << std::endl;
    std::cout << "7) remove element by index" << std::endl;
    std::cout << "8) get the size of the list" << std::endl;
    std::cout << "9) output list items to the console through a separator" << std::endl;
    std::cout << "10) remove all list element" << std::endl;
    std::cout << "11) replace the element by index with the passed element" << std::endl;
    std::cout << "12) check if the list is empty" << std::endl;
    std::cout << "13) changes the order of the items in the list" << std::endl;
    std::cout << "14) end the program" << std::endl;
}

int input() // input function
{
    int output_value;
    bool nonDig = true;

    do
    {
        std::string str;
        std::cin >> str;
        if (str.find_first_not_of("-0123456789", 0) != std::string::npos)
        {
            nonDig = false;
            std::cout << std::endl;
            std::cout << "Input error!" << std::endl;
            std::cout << "Repeat the input:";
        }
        else
        { 
            std::istringstream sstream(str);
            sstream >> output_value;
            nonDig = true;
        }
    }
    while (nonDig == false);

    return output_value;
}

int main()
{
    Singly_Linked_List List;
    int data, pos, temp;
    bool end_indicator = false;

    do
    {
        int numChoice = 0;
        menu();
        std::cout << std::endl;
        std::cout << "Enter the element number:";

        numChoice = input();

        switch (numChoice)
        {
        case 1:
            std::cout << std::endl;
            std::cout << "Enter the data you want to write to the new element:";
            data = input();
            List.push_back(data);
            break;
        case 2:
            std::cout << std::endl;
            std::cout << "Enter the data you want to write to the new element:";
            data = input();
            List.push_front(data);
            break;
        case 3:
            std::cout << std::endl;
            List.pop_back();                
            break;
        case 4:
            std::cout << std::endl;
            List.pop_front();                
            break;
        case 5:
            std::cout << std::endl;
            std::cout << "Enter the data you want to write to the new element:";
            data = input();
            std::cout << "Enter the index of the place in the list where you want to insert the new item:";
            pos = input();
            List.insert(data, pos);
            break;
        case 6:
            std::cout << std::endl;
            std::cout << "Enter the index of the element you want to get:";
            pos = input();
            temp = List.at(pos);
            std::cout << "Element by index:" << pos << " -> " << temp << std::endl;
            break;
        case 7:
            std::cout << std::endl;
            std::cout << "Enter the index of the item you want to delete:";
            pos = input();
            List.remove(pos);
            break;
        case 8:
            std::cout << std::endl;
            temp = List.get_size();
            std::cout << "Total number of elements:" << temp << std::endl;
            break;
        case 9:
            std::cout << std::endl;
            List.print_to_console();
            break;
        case 10:
            std::cout << std::endl;
            List.clear();
            break;
        case 11:
            std::cout << std::endl;
            std::cout << "Enter the index of the element you want to replace:";
            pos = input();
            std::cout << "Enter the data of the item you want to replace it with:";
            data = input();
            List.set(pos, data);
            break;
        case 12:
            std::cout << std::endl;
            if (List.isEmpty() == true)
            {
                std::cout << "The list is empty" << std::endl;
            }
            else
            {
                std::cout << "The list is complete" << std::endl;
                int temp = List.get_size();
                std::cout << "Total number of elements:" << temp << std::endl;
            }
            break;
        case 13:
            std::cout << std::endl;
            List.reverse();
            break;
        case 14:
            end_indicator = true;
            break;
        default:
            std::cout << std::endl;
            std::cout << "Input error!" << std::endl;
            std::cout << std::endl;
            break;
        }
    } while (end_indicator != true);
 
    return 0;
}