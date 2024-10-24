#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Human
{
protected:

   char* name;
   int age;

public:
   
   Human(const char* name_, const int age_)
   {

      name = new char[strlen(name_) + 1];
      strcpy(name, name_);

      age = age_;
   }

   virtual ~Human() 
   {
      delete[] name;
   }

   virtual void Print()
   {
      cout << age << ' ' << name;
   }

   virtual int income()
   {
      return 0;
   }
};


class Student : virtual public Human
{
protected:

   int grants;

public:

   Student(const char* name_,const int age_,const int grants_) : Human(name_, age_)
   {
      grants = grants_;
   }

   void Print() override
   {
      cout << age << ' ' << name << ' ' << grants;
   }

   int income() override
   {
      return grants;
   }
};

class Worker : virtual public Human
{
protected:

   char* name_factory;
   int salary;

public:

   Worker(const char* name_, const int age_, const int salary_, const char* name_factory_) : Human(name_, age_)
   {
      salary = salary_;
      name_factory = new char[strlen(name_factory_)];
      sprintf(name_factory, "%s", name_factory_);
   }

   ~Worker() override
   {
      delete[] name_factory;
      //Деструктор Human вызывается автоматически
   }

   void Print() override
   {
      cout << age << ' ' << name << ' ' << salary;
   }

   int income() override
   {
      return salary;
   }
};


class Working_Student: public Student, public Worker
{
public:

   Working_Student(const char* name_, const int age_, const int grants_, const int salary_, const char* name_factory_): Student(name_, age_, grants_), Worker(name_, age_, salary_, name_factory_), Human(name_, age_){}


   void Print() override
   {
      cout << age << ' ' << name << ' ' << grants << ' ' << salary << ' ' << name_factory;
   }

   int income() override
   {
      return salary + grants;
   }
};

int main()
{
   Human* human1 = new Human("Max", 85);

   Human* human2 = new Student("Nik", 19, 2700);

   Human* human3 = new Worker("Dan", 48, 48000, "Tvgu");

   Human* human4 = new Working_Student("Kii", 22, 2700, 25000, "Mak");

   cout << human1->income() << endl;
   cout << human2->income() << endl;
   cout << human3->income() << endl;
   cout << human4->income() << endl;
   return 0;
}