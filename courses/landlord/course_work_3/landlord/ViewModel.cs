using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using GalaSoft.MvvmLight;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;

namespace landlord
{
    public class ViewModel
    {

        public List<Peasant> Peasants { get; private set; }

        public ViewModel()
        {
            Peasants = new List<Peasant>();

            using (Stream stream = new FileStream("peasants.json", FileMode.Open))
            {
                DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(List<Peasant>));

                Peasants = (List<Peasant>)ser.ReadObject(stream);
            }
        }
    }
}

/*  
 *  using (Stream stream = new FileStream("peasants.json", FileMode.Create))
            {
                DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(List<Peasant>));

                List<Peasant> peasants = new List<Peasant> {
                    new Peasant("PeasantOne", 10),
                    new Peasant("PeasantTwo", 20)
                };

                ser.WriteObject(stream, peasants);
            }
*/