#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

struct movies_t {
  string title;
  int year;
} mine, yours;

struct movies_t_a {
  string title;
  int year;
} films [3];


struct friends_t {
  string name;
  string email;
  movies_t favorite_movie;
} charlie, maria;

friends_t * pfriends = &charlie;

void printmovie (movies_t movie)
{
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}
void printmovie (movies_t_a movie)
{
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}


int divide (int a, int b=5);

template <class T>
T sum (T a, T b)
{
  T result;
  result = a + b;
  return result;
}

template <class T, class U>
bool are_equal (T a, U b)
{
  return (a==b);
}


void duplicate (int& a, int& b, int& c)
{
  a*=2;
  b*=2;
  c*=2;
}

template <class T, int N>
T fixed_multiply (T val)
{
  return val * N;
}

string concatenate (const string& a, const string& b)
{
  return a+" "+b;
}

int operate (int a, int b)
{
  return (a*b);
}

double operate (double a, double b)
{
  return (a/b);
}

namespace foo
{
  int value() { return 5; }
}

namespace bar
{
  const double pi = 3.1416;
  double value() { return 2*pi; }
}

namespace first
{
  int x = 5;
  int y = 10;
}

namespace second
{
  double x = 3.1416;
  double y = 2.7183;
}

int divide (int a, int b)
{
  int r;
  r=a/b;
  return (r);
}

void printarray (int arg[], int length) {
  for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}

void increment_all (int* start, int* stop)
{
  int * current = start;
  while (current != stop) {
    ++(*current);  // increment value pointed
    ++current;     // increment pointer
  }
}

void print_all (const int* start, const int* stop)
{
  const int * current = start;
  while (current != stop) {
    cout << *current << '\n';
    ++current;     // increment pointer
  }
}
void increase (void* data, int psize)
{
  if ( psize == sizeof(char) )
  { char* pchar; pchar=(char*)data; ++(*pchar); }
  else if (psize == sizeof(int) )
  { int* pint; pint=(int*)data; ++(*pint); }
}

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}

typedef char C;
typedef unsigned int WORD;
typedef char * pChar;
typedef char field [50];

C mychar, anotherchar, *ptc1;
WORD myword;
pChar ptc2;
field name;

using new_type_name = int ;
using C = char;
using WORD = unsigned int;
using pChar = char *;
using field = char [50];

struct book2_t {

  char title[50];

  char author[50];

  union {

    float dollars;

    int yen;

  } price;

} book2;


enum colors_t {black,blue, green, cyan, red, purple, yellow, white};
enum months_t { january=1, february, march, april,
                may, june, july, august,
                september, october, november, december} y2k;

// Enumerated types (enum)
enum class Colors {black, blue, green, cyan, red, purple, yellow, white};
// Enumerated types with enum class
enum class EyeColor : char {blue, green, brown};

int main ()
{  
Colors mycolor;
 EyeColor eye_c;
 eye_c = EyeColor::blue;
mycolor = Colors::blue;
if (mycolor == Colors::green) mycolor = Colors::red;

  return 0;

}