using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace structure
{
    struct Person
    {
        public string name;
        public int age;
    }

    enum Gender
    {
        Male,
        Female,
        Others
    }

    enum Profession
    {
        Actor,
        Doctor,
        DataAnalyst,
        Business
    }
    class Program
    {
        static void Main(string[] args)
        {
            Person person1;
            person1.name = "Aayush";
            person1.age = 20;
            Profession person1job = Profession.DataAnalyst;

            Console.WriteLine("\nPerson1: ");
            Console.WriteLine("Name: "+ person1.name);
            Console.WriteLine("Age: " +person1.age);
            Console.WriteLine("Profession: " + person1job);


            Person person2 = new Person();
            person2.name = "Ram";
            person2.age = 34;
            Gender person2gender = Gender.Male;
            Profession person2job = Profession.Business;

            Console.WriteLine("\nPerson2");
            Console.WriteLine("Name: " + person2.name);
            Console.WriteLine("Age: " + person2.age);
            Console.WriteLine("Gender: " + person2gender);
            Console.WriteLine("Profession: " + person2job);



            // Enum
            String person3name = "Hari";
            int person3age = 29;
            Gender person3gender = Gender.Male;

            Console.WriteLine("\n Person3");
            Console.WriteLine("Name: " + person3name);
            Console.WriteLine("Age: " + person3age);
            Console.WriteLine("Gender: " + person3gender);


            Person person4 = new Person();
            person4.name = "Asika";
            person4.age = 19;
            Gender person4gender = Gender.Female;

            Console.WriteLine("\nPerson4");
            Console.WriteLine("Name: " +person4.name);
            Console.WriteLine("Age: " +person4.age);
            Console.WriteLine("Gender: " + person4gender);


            Console.ReadLine();
        }
    }
}