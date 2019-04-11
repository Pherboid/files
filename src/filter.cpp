#include <iostream> //For keyboard/console I/O
#include <fstream>// For file I/O

using namespace std;

int main(){
  int x = 0, sum = 0, count = 0, avg = 0, writeVal = 0;
  ifstream file1{"data/file1", ios::binary}; //input file stream to read from file1
  ofstream file3{"data/file3_binary",ios::binary}; //output file stream to write to file3
  ofstream file3_2{"data/file3_text"}; //output file stream to write to file3


  //If the file has been successfully opened
  if (file1 && file3 && file3_2){

    //While not end of file
    while (!file1.eof()) {

      //Reading the binary file for integers
      file1.read(reinterpret_cast<char*>(&x), sizeof(x));

      /*Because this function has a pointer to var x
        whatever int found in the file will be stored in var x
      */

      sum += x; //Sum is added to x
      ++count; //incrementing the value of count

      //If three integers have been read
      if (count == 3){
        count = 0;
        avg = sum / 3;
        if (avg < 75){
            writeVal = 0;
        }
        else if (avg > 150) {
          writeVal = 255;
        }

        else{
          writeVal = 100;
        }
        for (int i = 0; i < 3; i++) {
          file3.write(reinterpret_cast<char*>(&writeVal), sizeof(int));
          file3_2 << writeVal << endl;
        }
        sum = 0;
      }
    }

  }

  else{
    cout << "Error opening file";
  }

  file1.close();
  file3.close();
  file3_2.close();
  return 0;
}
