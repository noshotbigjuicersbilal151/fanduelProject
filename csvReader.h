#ifndef __CVS_READER_H__
#define __CVS_READER_H__

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
/* CSV File Parser taken from: https://java2blog.com/read-csv-file-in-cpp/
 * Author: Aditya Raj, 2020
 * */
vector<vector<string>> csvReader(string csv){
    string fname = csv;

    vector<vector<string>> output;
    vector<string> row;
    string line, word;

    fstream file (fname, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);
            if (!line.empty()){
                while(getline(str, word, ',')) /*separates by using commas as delimiters*/
                    row.push_back(word);
                output.push_back(row);
            }
        }
    }


    return output;

}

#endif //__CVS_READER_H__
