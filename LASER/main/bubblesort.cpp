#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

std::vector<std::vector<float>> ReadData(std::string filename)
{
    std::vector<std::vector<float>> data;
    std::fstream rFile(filename); // read mode
    if (rFile.fail())
    {
        std::cout << "Error: Unable to load data file" << std::endl;
        exit(1);
    }

    std::string line;
    while (getline(rFile, line))
    {
        // loop on file lines
        std::stringstream ss(line); // build object stringstream
        float d;
        std::vector<float> temp;
        while (ss >> d)
        { // parse line words to numbers (empty space separated)
            temp.push_back(d);
        }
        ss.clear(); // erase stringstream contents
        data.push_back(temp);
    }
    rFile.close();

    return data;
};

void BubbleSort(std::string filename)
{

    auto data = ReadData(filename);

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][0] > data[i + 1][0])
        {
            std::vector<float> aux;
            aux.resize(2);
            aux[0] = data[i][0];
            aux[1] = data[i][1];
            data[i][0] = data[i + 1][0];
            data[i][1] = data[i + 1][1];
            data[i + 1][0] = aux[0];
            data[i + 1][1] = aux[1];
        }
        std::cout << "(" << data[i][0] << ", " << data[i][1] << ", " << data[i][2] << ", " << data[i][3] << ")" << std::endl;
    }
}

int main()
{
    BubbleSort("circulo05.txt");
    return 0;
}