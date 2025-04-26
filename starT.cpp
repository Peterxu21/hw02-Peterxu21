// starT.cpp   A demonstration of ASCII Art printing T characters

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starT(int width, int height);
void runTests(void);

// Write starT per specifications in the lab writeup
string starT(int width, int height)
{
  if (width < 3 || height < 2 || width % 2 == 0)
  {
    return "";
  }

  string result = "";

  // Top row
  for (int i = 0; i < width; i++)
  {
    result += "*";
  }
  result += "\n";

  // Vertical column
  int middle = width / 2;
  for (int i = 1; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (j == middle)
        result += "*";
      else
        result += " ";
    }
    result += "\n";
  }

  return result;
}

// Test-Driven Development; check expected results against actual
void runTests(void)
{
  string starT34Expected =
      "***\n"
      " * \n"
      " * \n"
      " * \n";

  assertEquals(starT34Expected, starT(3, 4), "starT(3,4)");

  string starT53Expected =
      "*****\n"
      "  *  \n"
      "  *  \n";

  assertEquals(starT53Expected, starT(5, 3), "starT(5,3)");

  string starT72Expected =
      "*******\n"
      "   *   \n";

  assertEquals(starT72Expected, starT(7, 2), "starT(7,2)");

  assertEquals("", starT(1, 2), "starT(1,2)");
  assertEquals("", starT(5, 1), "starT(5,1)");
  assertEquals("", starT(4, 2), "starT(4,2)");
  assertEquals("", starT(6, 2), "starT(6,2)");
}

// Test harness
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

// Main function
int main(int argc, char *argv[])
{
  // Check for correct number of arguments
  if (argc != 3)
  {
    cout << "Usage: " << argv[0] << " width height" << endl;
    cout << "Enter -1 -1 to run test suite." << endl;
    return 1;
  }

  // Convert arguments to integers
  int width = atoi(argv[1]);
  int height = atoi(argv[2]);

  // Run tests if requested
  if (width == -1 && height == -1)
  {
    runTests();
    return 0;
  }

  // Generate and print the T
  string result = starT(width, height);
  cout << result; // no extra newline

  return 0;
}
