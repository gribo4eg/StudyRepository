using System;
using System.IO;
using System.Runtime.Serialization;
using System.Xml.Serialization;

namespace Lab3
{
    public delegate void Feeding(Watchman w);

    [Serializable]
    [DataContract]
    public class Watchman:IHuman, IDisposable
    {
        private bool _dispose;

        public event Feeding WatchmanFeedingEvent;
        private FoodType _food;


        public Watchman(){}

        public Watchman(string name, int age)
        {
            Name = name;
            Age = age;
            Iq = 100.0;
            Weight = 73.4;
            _food = FoodType.All;
            _dispose = false;
        }

        [DataMember]
        public string Name {get;set;}
        [DataMember]
        public int Age {get;set;}
        [DataMember]
        public double Iq { get; set; }
        [DataMember]
        public FoodType Food { get{return _food;} set { _food = value; } }
        [DataMember]
        public double Weight { get; set; }

        //BrainStorm Training

        public void FeedAnimalsInZoo()
        {
            Console.WriteLine("Watchman "+ this.Name + " is going to " +
                "feed animals!");
            WatchmanFeedingEvent?.Invoke(this);
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected void Dispose(bool disposing)
        {
            if (!_dispose)
            {
                if (disposing)
                {
                    Name = null;
                    Age = 0;
                    _food = FoodType.Nofood;
                    WatchmanFeedingEvent = null;

                    //GC.Collect();
                    //GC.WaitForPendingFinalizers();
                }

                _dispose = true;
            }
        }

        ~Watchman()
        {
            Console.WriteLine("~Watchman()");
            Dispose();
        }
    }
        
}

