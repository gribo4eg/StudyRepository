using System;
using System.Runtime.Serialization;

namespace Lab3
{
    public enum FoodType {Nofood, All=Meat | Grass, Meat=1, Grass=2}

    [DataContract]
    abstract class Animal : IComparable, IDisposable
    {

        protected bool dispose;
        
        protected string sound;
        protected string name;
        protected int age;
        protected FoodType food;

        protected const int START_AGE = 1;

        //Simple constructor
        protected Animal(){}

        //Override constructor
        protected Animal(string name)
        {
            dispose = false;
            this.name = name;
        }

        [DataMember]
        public int Age {
            get { return age; }
            set { age = value; }
        }

        [DataMember]
        public string Name
        {
            get{ return name; }
            set
            {
                if (value.Length > 2 && value.Length < 10)
                    name = value;
            }
        }

        [DataMember]
        public virtual FoodType Food { get; set; }

        public int CompareTo(object a)
        {
            if (!(a is IAnimal))
                throw new ArgumentException();

            IAnimal animal = (IAnimal)a;

            return string.Compare(this.Name, animal.Name, StringComparison.Ordinal);
        }
            
        public virtual void MakeSound()
        {
            Console.WriteLine("Animal make sound!");
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected void Dispose(bool disposing)
        {
            if (!dispose)
            {
                if (disposing)
                {
                    name = null;
                    sound = null;
                    food = FoodType.Nofood;
                    age = 0;

                    //GC.Collect();
                    //GC.WaitForPendingFinalizers();
                }
                dispose = true;
            }
        }


            
    }
}

