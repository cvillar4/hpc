#include <fstream>
#include <sstream>
#include <stdio.h>
#include "iostream"

using namespace std;

int main()
{
  float data[173][57];
  ifstream file("df_cpp.csv");

  for(int row = 0; row < 173; ++row)
    {
      string line;
      getline(file, line);
      if ( !file.good() )
        break;

      stringstream iss(line);

      for (int col = 0; col < 57; ++col)
        {
          string val;
          getline(iss, val, ',');
          if ( !iss.good() )
            break;

          stringstream convertor(val);
          convertor >> data[row][col];
        }
    }

  for(int i = 0; i < 173; ++i){
    for(int j = 0; j < 57; ++j){
       cout << data[i][j] << ",";
    }
    cout << endl;
  }
  return 0;
}
