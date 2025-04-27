using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Project1
{
    internal class Program
    {
        public void Add()
        {
            int a = 120;
            int b = 45;
            int c = a + b;
            Console.WriteLine(c);
        }
        public void Add(int a, int b)
        {
            int c = a + b;
            Console.WriteLine(c);
        }
        public void Add(string a, string b)
        {
            string c = a + " " + b;
            Console.WriteLine(c);
        }
        public void Add(float a, float b)
        {
            float c = a + b;
            Console.WriteLine(c);
        }

        static void Main(string[] args)
        {
            Task1();
            Task2();
            Task3();
            Task4();
            Console.ReadLine();
        }
        public static async void Task1()
        {
            await Task.Run(() =>
            {
                Console.WriteLine("Task 1 Starting.....");
                Thread.Sleep(3000);
                Console.WriteLine("Task 1 Completed.");
            });
        }
        public static async void Task2()
        {
            await Task.Run(() =>
            {
                Console.WriteLine("Task 2 Starting.....");
                Thread.Sleep(1000);
                Console.WriteLine("Task 2 Completed.");
            });
        }
        public static async void Task3()
        {
            await Task.Run(() =>
            {
                Console.WriteLine("Task 3 Starting.....");
                Thread.Sleep(4000);
                Console.WriteLine("Task 3 Completed.");
            });
        }
        public static async void Task4()
        {
            await Task.Run(() =>
            {
                Console.WriteLine("Task 4 Starting.....");
                Thread.Sleep(2000);
                Console.WriteLine("Task 4 Completed.");
            });
        }
    }
}
