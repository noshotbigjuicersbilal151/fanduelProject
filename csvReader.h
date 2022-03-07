#ifndef __CVS_READER_H__
#define __CVS_READER_H__

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<string>> csvReader(){
    string fname = "bestPlayers.csv";

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
