using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Runtime.Serialization;
using System.ComponentModel;

namespace Lab5
{
    [Serializable]
    public class Watchman: IDisposable
    {
        private bool _dispose;
        private string _name;

        public Watchman(string name, string surname, int age, int weight)
        {
            _name = name;
            Surname = surname;
            Age = age;
            Weight = weight;
            _dispose = false;
        }

        [XmlAttribute]
        public string Name 
        {
            get { return _name; }
            set 
            { 
                _name = value;
            }
        }

        [XmlAttribute]
        public string Surname { get; set; }
        [XmlAttribute]
        public int Age {get;set;}
        [XmlAttribute]
        public int Weight { get; set; }

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
                    Weight = 0;
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

