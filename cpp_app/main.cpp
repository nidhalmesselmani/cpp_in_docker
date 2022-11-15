#include <iostream>
#include <string.h>
#include <sstream>
#include <exception>
#include <typeinfo>


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

class Rectangle {
    int width, height;
  public:
    Rectangle (): width(5), height(5) {};
    Rectangle(int x, int y) : width(x), height(y) {}
    int area() {return width*height;}
};


class Circle {
    double radius;
  public:
    Circle(double r) : radius(r) { }
    double area() {return radius*radius*3.14159265;}
};

class Cylinder {
    Circle base;
    double height;
  public:
    Cylinder(double r, double h) : base (r), height(h) {}
    double volume() {return base.area() * height;}
};
  /* Pointers to classes
  Rectangle obj (3, 4);
  Rectangle * foo, * bar, * baz;
  foo = &obj;
  bar = new Rectangle (5, 6);
  baz = new Rectangle[2] { {2,5}, {3,6} };
  cout << "obj's area: " << obj.area() << '\n';
  cout << "*foo's area: " << foo->area() << '\n';
  cout << "*bar's area: " << bar->area() << '\n';
  cout << "baz[0]'s area:" << baz[0].area() << '\n';
  cout << "baz[1]'s area:" << baz[1].area() << '\n';       
  delete bar;
  delete[] baz;
  */

class CVector {
  public:
    int x,y;
    CVector () {};
    CVector (int a,int b) : x(a), y(b) {}
    CVector operator + (const CVector&);
    bool operator== (const CVector&);
    CVector& operator= (const CVector& param);
};

bool CVector::operator== (const CVector& param) {
  CVector temp;
  if (x == param.x && y == param.y) return true; else return false ;

};

CVector CVector::operator+ (const CVector& param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
};

CVector& CVector::operator= (const CVector& param)
{
  x=param.x;
  y=param.y;
  return *this;
};

class Dummy {
  public:
    static int n;
    Dummy () { n++; };
    bool isitme (Dummy& param);
};

bool Dummy::isitme (Dummy& param)
{
  if (&param == this) return true;
  else return false;
};

class MyClass {
  public:
    int x;
    MyClass(int val) : x(val) {}
    const int& get() const {return x;} 
    int& get() {return x;}
    
};

void print (const MyClass& arg) {
  cout << arg.get() << '\n';
}


int Dummy::n=0;


// class templates
template <class T>
class mypair {
    T a, b;
  public:
    mypair (T first, T second)
      {a=first; b=second;}
    T getmax ();
};

template <class T>
T mypair<T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}

// class template:
template <class T>
class mycontainer {
    T element;
  public:
    mycontainer (T arg) {element=arg;}
    T increase () {return ++element;}
};

// class template specialization:
template <>
class mycontainer <char> {
    char element;
  public:
    mycontainer (char arg) {element=arg;}
    char uppercase ()
    {
      if ((element>='a')&&(element<='z'))
      element+='A'-'a';
      return element;
    }
};

class Example3 {
    string data;
  public:
    Example3 (const string& str) : data(str) {}
    Example3() {}
    const string& content() const {return data;}
};

// Destructor
class Example4 {
    string* ptr;
  public:
    // constructors:
    Example4() : ptr(new string) {}
    Example4 (const string& str) : ptr(new string(str)) {}
    // destructor:
    ~Example4 () {delete ptr;}
    // access content:
    const string& content() const {return *ptr;}
};

class Example5 {
    string* ptr;
  public:
    Example5 (const string& str) : ptr(new string(str)) {}
    ~Example5 () {delete ptr;}
    // copy constructor:
    Example5 (const Example5& x) : ptr(new string(x.content())) {}
    // access content:
    const string& content() const {return *ptr;}
    // Copy assignment
    Example5& operator= (const Example5& x) {
    *ptr = x.content();
    return *this;
}

};

class Example6 {
    string* ptr;
  public:
    Example6 (const string& str) : ptr(new string(str)) {}
    ~Example6 () {delete ptr;}
    // move constructor
    Example6 (Example6&& x) : ptr(x.ptr) {x.ptr=nullptr;}
    // move assignment
    Example6& operator= (Example6&& x) {
      delete ptr; 
      ptr = x.ptr;
      x.ptr=nullptr;
      return *this;
    }
    // access content:
    const string& content() const {return *ptr;}
    // addition:
    Example6 operator+(const Example6& rhs) {
      return Example6(content()+rhs.content());
    }
};
// default and delete implicit members
class Rectangle1 {
    int width, height;
  public:
    Rectangle1 (int x, int y) : width(x), height(y) {}
    Rectangle1() = default;
    Rectangle1 (const Rectangle1& other) = delete;
    int area() {return width*height;}
};


// friend functions

class RectangleF {
    int width, height;
  public:
    RectangleF() {}
    RectangleF (int x, int y) : width(x), height(y) {}
    int area() {return width * height;}
    friend RectangleF duplicate (const RectangleF&);
};

RectangleF duplicate (const RectangleF& param)
{
  RectangleF res;
  res.width = param.width*2;
  res.height = param.height*2;
  return res;
}
// friend class
class Square {
  friend class RectangleF1;
  private:
    int side;
  public:
    Square (int a) : side(a) {}
};


class RectangleF1 {
    int width, height;
  public:
    int area ()
      {return (width * height);}
    void convert (Square a);
};


void RectangleF1::convert (Square a) {
  width = a.side;
  height = a.side;
}


// derived classes

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b;}
 };

class RectangleP: public Polygon {
  public:
    int area ()
      { return width * height; }
 };

class Triangle: public Polygon {
  public:
    int area ()
      { return width * height / 2; }
  };

class Mother {
  public:
      int age;
      Mother ()
      { cout << "Mother: no parameters\n"; }
    Mother (int a)
      { cout << "Mother: int parameter\n"; }
};
class Daughter: public Mother{
  public:
     Daughter (int a)
      { cout << "Daughter: int parameter\n\n"; }
    int getAge() { return age;}
    void setAge( const int& age_) {age = age_;}
};
class Son : public Mother {
  public:
    Son (int a) : Mother (a)
      { cout << "Son: int parameter\n\n"; }
};

// multiple inheritance
class Polygon1 {
  protected:
    int width, height;
  public:
    Polygon1 (int a, int b) : width(a), height(b) {}
};

class Output {
  public:
    static void print (int i);
};

void Output::print (int i) {
  cout << i << '\n';
}

class Rectangle2: public Polygon1, public Output {
  public:
    Rectangle2 (int a, int b) : Polygon1(a,b) {}
    int area ()
      { return width*height; }
};

class Triangle2: public Polygon1, public Output {
  public:
    Triangle2 (int a, int b) : Polygon1(a,b) {}
    int area ()
      { return width*height/2; }
};
// pointers to base class
class PolygonP {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
};

class RectanglePo: public PolygonP {
  public:
    int area()
      { return width*height; }
};

class TriangleP: public PolygonP {
  public:
    int area()
      { return width*height/2; }
};
// virtual members
class PolygonV {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area ()
      { return 0; }
};

class RectangleV: public PolygonV {
  public:
    int area ()
      { return width * height; }
};

class TriangleV: public PolygonV {
  public:
    int area ()
      { return (width * height / 2); }
};


// abstract base class
class PolygonA {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area (void) =0;   
};

class RectangleA: public PolygonA {
  public:
    int area (void)
      { return (width * height); }
};

class TriangleA: public PolygonA {
  public:
    int area (void)
      { return (width * height / 2); }
};

// pure virtual members can be called
// from the abstract base class
class PolygonC {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area() =0;
    void printarea()
      { cout << this->area() << '\n'; }
};

class RectangleC: public PolygonC {
  public:
    int area (void)
      { return (width * height); }
};

class TriangleC: public PolygonC {
  public:
    int area (void)
      { return (width * height / 2); }
};

// dynamic allocation and polymorphism
class PolygonD {
  protected:
    int width, height;
  public:
    PolygonD (int a, int b) : width(a), height(b) {}
    virtual int area (void) =0;
    void printarea()
      { cout << this->area() << '\n'; }
};

class RectangleD: public PolygonD {
  public:
    RectangleD(int a,int b) : PolygonD(a,b) {}
    int area()
      { return width*height; }
};

class TriangleD: public PolygonD {
  public:
    TriangleD(int a,int b) : PolygonD(a,b) {}
    int area()
      { return width*height/2; }
};

class A {};

class B {
public:
  // conversion from A (constructor):
  explicit B (const A& x) {}
  // conversion from A (assignment):
  B& operator= (const A& x) {return *this;}
  // conversion to A (type-cast operator)
  operator A() {return A();}
};

class Dummy1 {
    double i,j;
};

class Addition {
    int x,y;
  public:
    Addition (int a, int b) { x=a; y=b; }
    int result() { return x+y;}
};

// dynamic_cast
class Base { virtual void dummy() {} };
class Derived: public Base { int a; };

// const_cast
void print (char * str)
{
  cout << str << '\n';
}
// typeid
 /* int * a,b;
  a=0; b=0;
  if (typeid(a) != typeid(b))
  {
    cout << "a and b are of different types:\n";
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
    
  }
  */
// typeid, polymorphic class
class Base1 { virtual void f(){} };
class Derived1 : public Base1 {};
/*
try {
    Base* a = new Base;
    Base* b = new Derived;
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
    cout << "*a is: " << typeid(*a).name() << '\n';
    cout << "*b is: " << typeid(*b).name() << '\n';
  } catch (exception& e) { cout << "Exception: " << e.what() << '\n'; }
*/
// exceptions
/*
  try
  {
   
     try {
      // code here
      throw 4;
  }
  catch (int n) {
      cout << " internal int exception " << n << "\n";
      throw;
  }
   
  }
catch (int param) { cout << "external int exception " << param; }
catch (char param) { cout << "char exception"; }
catch (...) { cout << "default exception"; }
*/

// using standard exceptions
/*
class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;
in main
  try
  {
    throw myex;
  }
  catch (exception& e)
  {
    cout << e.what() << '\n';
  }*/

// bad_alloc standard exception
/*
  try
  {

  int* myarray= new int[1000];
  }
  catch (exception& e)
  {
    cout << "Standard exception: " << e.what() << endl;
}*/

// function macro
#define getmax(a,b) ((a)>(b)?(a):(b)) 
/* 
  int x=5, y;
  y= getmax(x,2);
  cout << y << endl;
  cout << getmax(7,x) << endl;
*/
#define glue(a,b) a ## b 
#define str(x) #x
/*cout << str(test);

  glue(c,out) << "test";
*/
// Conditional inclusions (#ifdef, #ifndef, #if, #endif, #else and #elif)
#ifdef TABLE_SIZE
int table[TABLE_SIZE];
#endif

#ifndef TABLE_SIZE
#define TABLE_SIZE 100
#endif
int table[TABLE_SIZE];

#if TABLE_SIZE>200
#undef TABLE_SIZE
#define TABLE_SIZE 200
 
#elif TABLE_SIZE<50
#undef TABLE_SIZE
#define TABLE_SIZE 50
 
#else
#undef TABLE_SIZE
#define TABLE_SIZE 100
#endif
 
int table[TABLE_SIZE];



#if defined ARRAY_SIZE
#define TABLE_SIZE ARRAY_SIZE
#elif !defined BUFFER_SIZE
#define TABLE_SIZE 128
#else
#define TABLE_SIZE BUFFER_SIZE
#endif 


int main ()
{
  

  return 0;

}