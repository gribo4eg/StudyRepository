using System;
using System.Collections.Generic;

namespace Task2
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Component p = new Polyclinic("Policlinic");
            Component d1 = new Polyclinic("First department");
            p.Add(d1);
            Component d2 = new Polyclinic("Second department");
            p.Add(d2);
            Doctor doc1 = new Doctor("Gregor");
            Doctor doc2 = new Doctor("Chill");
            Doctor doc3 = new Doctor("Robin");
            d1.Add(doc1);
            d1.Add(doc3);
            d2.Add(doc2);

            p.Display();

            Console.WriteLine(p.DoctorsCount);
        }
    }

    public class Patient
    {
        public string Name { get; set; }

        public Patient(string name)
        {
            Name = name;
        }

        public void VisitPolyclynic(Component p)
        {
            Console.WriteLine("Patient {0} had visited polyclinic {1}", Name, p.Name);
            p.Display();
        }

        public void VisitSomeDepartment(Component d)
        {
            Console.WriteLine("Patient {0} had visited department {1}", Name, d.Name);
            d.Display();
        }

        public void VisitSomeDoctor(Doctor d)
        {
            Console.WriteLine("Patient {0} had visited doctor ", Name);
            d.Display();
        }
    }
}