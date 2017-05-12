using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace landlord
{
    /// <summary>
    /// Factory Method
    /// </summary>
    public abstract class Developer
    {
        public abstract Building Build();
    }

    public abstract class Building
    {
        public string Name { get; set; }

        public int IncreaseCapacity { get; protected set; }
        public int IncreaseEnergy { get; protected set; }

        protected Building()
        {
            Name = GetType().Name;
        }

    }

    public class Castle : Building
    {
        public Castle()
        {
            IncreaseCapacity = 10;
            IncreaseEnergy = 5;
        }

    }

    public class Pub : Building
    {
        public Pub()
        {
            IncreaseCapacity = 3;
            IncreaseEnergy = 7;
        }

    }

    public class Farm : Building
    {
        public Farm()
        {
            IncreaseCapacity = 5;
            IncreaseEnergy = 4;
        }
    }
}
