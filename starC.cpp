#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starC(int width, int height);
void runTests(void);

string starC(int width, int height)
{
  if (width < 2 || height < 3) 
    return "";

  string result = "";

  for (int row = 0; row < height; row++)
  {
    if (row == 0 || row == height - 1)
    {
      result += string(width, '*') + "\n";
    }
    else
    {
      result += "*"; 
      result += string(width - 1, ' ');
      result += "\n";
    }
  }

  return result;
}

void runTests(void)
{
  string starC34Expected =
      "***\n"
      "*  \n"
      "*  \n"
      "***\n";
  assertEquals(starC34Expected, starC(3, 4), "starC(3,4)");

  string starC53Expected =
      "*****\n"
      "*    \n"
      "*****\n";
  assertEquals(starC53Expected, starC(5, 3), "starC(5,3)");

  assertEquals("", starC(2, 1), "starC(2,1)");
  assertEquals("", starC(2, 2), "starC(2,2)");

  string starC23Expected =
      "**\n"
      "* \n"
      "**\n";
  assertEquals(starC23Expected, starC(2, 3), "starC(2,3)");
}

void assertEquals(string expected, string actual, string message = "")
{
  if (expected == actual)
  {
    cout << "PASSED: " << message << endl;
  }
  else
  {
    cout << "   FAILED: " << message << endl
         << "   Expected:[\n"
         << expected << "] actual = [\n"
         << actual << "]\n"
         << endl;
  }
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Usage: " << argv[0] << " width height" << endl;
    return 1;
  }

  int width = atoi(argv[1]);
  int height = atoi(argv[2]);

  if (width == -1 && height == -1)
  {
    runTests();
    return 0;
  }
  cout << starC(width, height);
  return 0;
}
