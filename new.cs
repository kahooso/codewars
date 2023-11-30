using System;

namespace clappy;
{
    static void Main(string[] args)
    {
        string employeeName = Console.ReadLine();
        Employee employee = new Employee(employeeName, 15);
        Console.WriteLine ($"Good morning, {employeeName}");
    }
}