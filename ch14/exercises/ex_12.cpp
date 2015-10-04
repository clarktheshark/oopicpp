// ex_12.cpp
// modified rewerr.cpp with exceptions to handle errors
#include <fstream> // for file stream
#include <iostream>
#include <stdlib.h> // for exit()
using namespace std;
/////////////////////////////////////////////////////////////
// File for writing integers
class dofile
{
private:
  fstream file;
public:
  class DofileEx
  {
  public:
    char* explanation;
    DofileEx(char* e)
    { explanation = e; }
  };
  dofile(char*);
  void open(char*);
  void read(int[], int);
  void write(int[], int);
  void close();
  void find_head();
  void find_end();
};
//-----------------------------------------------------------
dofile::dofile(char* s)
{
  open(s);
}
//-----------------------------------------------------------
void dofile::open(char* s)
{
  file.open(s, ios::trunc | ios::in | ios::out | ios::binary);
  if (!file)
    throw DofileEx("Could not open file");
}
//-----------------------------------------------------------
void dofile::find_head()
{
  file.seekg(0);
}
//-----------------------------------------------------------
void dofile::find_end()
{
  file.seekg(0, ios::end);
}
//-----------------------------------------------------------
void dofile::write(int buff[], int size)
{
  find_end();
  file.write( (char*)buff, size * sizeof(int) );
  if (!file)
    throw DofileEx("Could not write to file");
}
//-----------------------------------------------------------
void dofile::read(int buff[], int size)
{
  find_head();
  file.read( (char*)buff, size * sizeof(int) );
  if (!file)
    throw DofileEx("Could not read from file");
}
//-----------------------------------------------------------
void dofile::close()
{
  file.close();
  if( !file)
    throw DofileEx("Could not close file");
}
/////////////////////////////////////////////////////////////
void print_array(int a[], int size)
{
  for(int i = 0; i < size; i++)
    cout << a[i] << " ";
}
/////////////////////////////////////////////////////////////
int main()
{
  // set filename
  char* filename = "a:edata.dat";
  // set up buffer
  const int BUFF_SIZE = 5;
  int buffer[BUFF_SIZE];

  try
    {
      // give buffer data
      cout << "\nSetting buffer data";
      for (int i = 0; i < BUFF_SIZE; i++)
	buffer[i] = 10 * i;
      cout << "\nBuffer: ";
      print_array(buffer, BUFF_SIZE);

      // open file
      cout << "\nOpening file: " << filename;
      dofile f(filename);

      // write buffer data to file
      cout << "\nWriting buffer to file";
      f.write(buffer, BUFF_SIZE);
  
      // clear buffer
      cout << "\nClearing buffer";
      for (int i = 0; i < BUFF_SIZE; i++)
	buffer[i] = 0;
      cout << "\nCleaned buffer: ";
      print_array(buffer, BUFF_SIZE);

      // read file to buffer
      cout << "\nReading file to buffer";
      f.read(buffer, BUFF_SIZE);

      // print buffer
      cout << "\nBuffer from read: ";
      print_array(buffer, BUFF_SIZE);
      cout << endl;

      // close the sucker
      cout << "\nClosing file";
      f.close();
    }
  catch(dofile::DofileEx e)
    {
      cout << "\nProblem Handling File: " << e.explanation;
    }
  cout << endl;
  return 0;
}
