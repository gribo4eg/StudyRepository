using System;
using System.Collections.Generic;

namespace Task2
{
    public abstract class Component
    {
        public string Name { get; set; }
        public abstract int DoctorsCount { get; protected set; }

        protected Component(string name)
        {
            Name = name;
        }

        public abstract void Display();
        public abstract void Add(Component c);
        public abstract void Remove(Component c);

    }
    public class Polyclinic : Component
    {
        private List<Component> children = new List<Component>();

        public Doctor Director { get; set; }

        public int DepartmentsCount { get; protected set; }

        public Polyclinic(string name)
        :base(name){}

        public override void Add(Component c)
        {
            children.Add(c);
            DepartmentsCount++;
        }

        public override void Remove(Component c)
        {
            children.Remove(c);
            DepartmentsCount--;
        }

        public override void Display()
        {
            if(Director!=null)
                Console.WriteLine(" {0}; Director: {1}", Name, Director.Name);
            else
                Console.WriteLine(" {0} :", Name);
            Console.WriteLine("****  ({0}): ", children.Count);
            foreach (Component component in children)
            {
                component.Display();
            }
        }

        public override int DoctorsCount
        {
            get
            {
                int count = 0;

                foreach (var comp in children)
                {
                    count += comp.DoctorsCount;
                }

                return count;
            }
            protected set { }
        }
    }

    public class Doctor : Component
    {
        public Doctor(string name)
            : base(name)
        {
        }

        public override void Display()
        {
            Console.WriteLine("************* Doctor: " + Name);
        }

        public override void Add(Component c)
        {
            throw new NotImplementedException();
        }

        public override void Remove(Component c)
        {
            throw new NotImplementedException();
        }

        public override int DoctorsCount { get{ return 1;}
            protected set { throw new NotImplementedException();}
        }
    }
}