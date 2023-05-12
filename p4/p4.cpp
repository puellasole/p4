#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>


bool CheckWord(std::string path, std::string word)
{
    std::ifstream myfile(path);
    std::string line;
    std::string search = word;
    bool found = false;
    while (std::getline(myfile, line) && !found)
    {
        if (line.find(search) != std::string::npos)
        {
            std::cout << word << std::endl;
            found = true;
            break;
        }
    }
    //if (!found)
        //std::cout << "NOT FOUND\n";
    return 0;
}


void poll(std::vector<std::string> Electricity, std::vector<std::string> DiscreteSignals, std::vector<std::string> Heating, std::string filename) {

    for (int i = 0; i < Electricity.size(); i++) {
        if (CheckWord(filename, Electricity[i]) != 0) {
            std::cout << Electricity[i] << std::endl;
        }
    }
    for (int i = 0; i < DiscreteSignals.size(); i++) {
        if (CheckWord(filename, DiscreteSignals[i]) != 0) {
            std::cout << DiscreteSignals[i] << std::endl;
        }
    }
    for (int i = 0; i < Heating.size(); i++) {
        if (CheckWord(filename, Heating[i]) != 0) {
            std::cout << Heating[i] << std::endl;
        }
    }
    //не реализуем считывание данных со счетчиков
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    std::vector<std::string> Electricity = { "Меркурий 230", "Нева МТ314", "Энергомера CE308" };
    std::vector<std::string> DiscreteSignals = { "Reallab NL-16HV", "Приборэлектро PRE-16", "Энергосервис ЭНМВ-1-24" };
    std::vector<std::string> Heating = { "Ouman S203", "Овен ТРМ232" };
    poll(Electricity, DiscreteSignals, Heating, "NewFile.txt");
    return 0;
}