using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using GalaSoft.MvvmLight;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.Windows.Input;
using GalaSoft.MvvmLight.Command;
using System.Windows;
using GalaSoft.MvvmLight.Messaging;
using System.ComponentModel;
using System.Windows.Controls;

/// <summary>
/// WRAPPER
/// PROXY
/// STATE
/// BRIDGE
/// CHAIN OF RESPONSIBILITY
/// ABSTRACT FACTORY 
/// FABRIC METHOD
/// </summary>

namespace landlord
{
    public class ViewModel : ViewModelBase
    {
        private const int MaxStartedCapacity = 10;

        public static int Capacity { get; set; }
        public static int MaxCapacity { get; set; }

        public static int GoldCount
        {
            get => Gold.Count;
            set
            {
                CheckPeopleEnergy(); SetAllCapacities(); Gold.Count = value;
            }
        }

        public static int FoodCount
        {
            get => Food.Count;
            set
            {
                CheckPeopleEnergy(); SetAllCapacities(); Food.Count = value;
            }
        }
        public static int WoodCount
        {
            get => Wood.Count; set
            {
                CheckPeopleEnergy(); SetAllCapacities(); Wood.Count = value;
            }
        }

        private static Wood Wood { get; set; }
        private static Gold Gold { get; set; }
        private static Food Food { get; set; }

        public static ObservableCollection<Settler>  Settlers  { get; set; }
        public static ObservableCollection<Peasant>  Peasants  { get; set; }
        public static ObservableCollection<Warrior>  Warriors  { get; set; }
        public static ObservableCollection<Builder>  Builders  { get; set; }
        public static ObservableCollection<Work>     Jobs      { get; set; }
        public static ObservableCollection<Building> Buildings { get; set; }

        public ViewModel()
        {
            Wood = new Wood();
            Gold = new Gold();
            Food = new Food();

            Settlers = new ObservableCollection<Settler>() {
                new Settler(),
                new Settler(),
                new Settler()
            };
            
            Peasants = new ObservableCollection<Peasant>();
            Warriors = new ObservableCollection<Warrior>();
            Builders = new ObservableCollection<Builder>();
            Buildings = new ObservableCollection<Building>();
            Jobs = new ObservableCollection<Work>()
            {
                new ProxyPeasantSickleWork("Harvest", 7, 5),
                new ProxyPeasantAxeWork("Collect timber", 10, 8),
                new ProxyWarriorSwordWork("Kill the Spy", 25, 7),
                new ProxyPeasantAxeWork("Cut some Trees", 6, 3),
                new ProxyWarriorBowWork("Protect Castle", 10, 9),
                new ProxyBuilderPickaxeWork("Build Castle", 0, 13),
                new ProxyBuilderHammerWork("Build Pub", 0, 10),
                new ProxyBuilderSawWork("Build Farm", 0, 7)
            };
            MaxCapacity = MaxStartedCapacity;
            SetCapacity();
        }

        public static void SetCapacity() => Capacity = Settlers.Count + Peasants.Count +
                   Warriors.Count + Builders.Count;

        public static void SetMaxCapacity() => MaxCapacity = MaxStartedCapacity + Buildings.Sum(building => building.IncreaseCapacity);

        public static void SetAllCapacities() { SetCapacity(); SetMaxCapacity(); }

        public static void IncreaseEnergyForAll(int energy)
        {
            foreach (var settler in Settlers)
            {
                settler.Energy += energy;
            }

            foreach (var peasant in Peasants)
            {
                peasant.Energy += energy;
            }

            foreach (var warrior in Warriors)
            {
                warrior.Energy += energy;
            }

            foreach (var builder in Builders)
            {
                builder.Energy += energy;
            }
        }

        public static void SetSuccessors()
        {
            SetPeasantsSuccessors();
            SetWarriorsSuccessors();
            SetBuildersSuccessors();
        }

        private static void SetPeasantsSuccessors()
        {
            var list = Peasants;
            if (list.Count < 2) return;
            for (int i = 0; i+1 < list.Count; i++)
            {
                list[i].Successor = list[i + 1];
            }
        }

        private static void SetWarriorsSuccessors()
        {
            var list = Warriors;
            if (list.Count < 2) return;
            for (int i = 0; i + 1 < list.Count; i++)
            {
                list[i].Successor = list[i + 1];
            }
        }

        private static void SetBuildersSuccessors()
        {
            var list = Builders;
            if (list.Count < 2) return;
            for (int i = 0; i + 1 < list.Count; i++)
            {
                list[i].Successor = list[i + 1];
            }
        }

        private static void CheckPeopleEnergy()
        {
            bool killed = false;
            foreach (var peasant in Peasants)
            {
                if (peasant.Energy != 0) continue;
                Peasants.Remove(peasant);
                killed = true;
                break;
            }

            foreach (var warrior in Warriors)
            {
                if (warrior.Energy != 0) continue;
                Warriors.Remove(warrior);
                killed = true;
                break;
            }

            foreach (var builder in Builders)
            {
                if (builder.Energy != 0) continue;
                Builders.Remove(builder);
                killed = true;
                break;
            }

            if (killed)
                MessageBox.Show("Worker lost his energy and die :`(", "Bad news", MessageBoxButton.OK, MessageBoxImage.Information);

            SetSuccessors();
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
            
            using (Stream stream = new FileStream("settlers.json", FileMode.Create))
            {
                DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(ObservableCollection<Settler>));

                ser.WriteObject(stream, Settlers);
            }

            using (Stream stream = new FileStream("settlers.json", FileMode.Open))
            {
                DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(ObservableCollection<Settler>));

                Settlers = (ObservableCollection<Settler>)ser.ReadObject(stream);
            }
            
*/