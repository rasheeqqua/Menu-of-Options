#include <iostream>
#include<vector>
#include<numeric>
#include<bits/stdc++.h>

void menu(std::vector<int> &list_main);
void selected_option(char option, std::vector<int> &list_menu);
void show_numbers(std::vector<int> &show_list);
void add_numbers(std::vector<int> &add_number);
void average(std::vector<int> &average_list);

void menu(std::vector<int> &list_main){

    char choice{};

    std::cout << "P - Print numbers\n"
    <<"A - Add a number\n"
    <<"M - Display mean of the numbers\n"
    <<"S - Display the smallest number\n"
    <<"L - Display the largest number\n"
    <<"Q - Quit\n\n" 
    <<"Enter your choice: ";
    
    std::cin >> choice;
    std::cout <<"\n" << std::endl;

    selected_option(choice, list_main);
}

void selected_option(char option, std::vector<int> &list_menu){
    switch(option){
        case 'p':
        case 'P':
            show_numbers(list_menu);
            std::cout << "\n" << std::endl;
            menu(list_menu);
            break;
        case 'a':
        case 'A':
            add_numbers(list_menu);
            std::cout << "\n" << std::endl;
            menu(list_menu);
            break;
        case 'q':
        case 'Q':
            std::cout << "Goodbye" << std::endl;
            break;
        case 'm':
        case 'M':
            average(list_menu);
            std::cout << "\n" << std::endl;
            menu(list_menu);
            break;
        case 's':
        case 'S':
            if(list_menu.size()==0){
                std::cout << "Unable to determine the smallest number - list is empty" << std::endl;
            }
            else{
                std::cout << "The smallest number in the list is: " << *min_element(list_menu.begin(), list_menu.end());
            }
            break;
            menu(list_menu);
        case 'l':
        case 'L':
        if(list_menu.size()==0){
                std::cout << "Unable to determine the smallest number - list is empty" << std::endl;
            }
            else{
                std::cout << "The largest number in the list is: " << *max_element(list_menu.begin(), list_menu.end());
            }
            break;
            menu(list_menu);
        default:
            std::cout << "Unknown selection, please try again\n\n" << std::endl;
            menu(list_menu);
    }
}

void show_numbers(std::vector<int> &show_list){
    if(show_list.size() == 0){
        std::cout << "[] - The list is empty";
    }
    else {
        std::cout << "[ ";
        for(int i{0}; i < show_list.size(); i++){
        std::cout << show_list[i] << " ";
    }
        std::cout << "]";
    }
}

void add_numbers(std::vector<int> &add_list){
    int added_number;
    std::cout << "Add number: ";
    std::cin >> added_number;
     std::cout << "\n";
    std::cout << added_number << " added.\n";
    add_list.push_back(added_number);
}

void average(std::vector<int> &average_list){
    if(average_list.size() == 0){
        std::cout << "Unable to calculate the mean - no data" << std::endl;
    }
    else{
        double sum = accumulate(average_list.begin(), average_list.end(), 0);
        double average = sum/average_list.size();
        std::cout << "The average value is : " << average << std::endl;
    }
}

int main(){

    std::vector<int> list{10, 20, 30};

    menu(list);

    return 0;
}