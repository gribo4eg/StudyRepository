using System;
using System.Collections.Generic;

namespace Lab1_2
{
    class Program
    {
        public static void Main(string[] args)
        {
            Antibiotic antibiotic = new Antibiotic("Antibiotic", 32.99);
            antibiotic.ShowInfo();
            Vitamin vitamin = new Vitamin("Vitamin", 30.35);
            vitamin.ShowInfo();
            ChinaMedicine chinaMedicine = new ChinaMedicine(antibiotic);
            chinaMedicine.ShowInfo();
            CanadaMedicine canadaMedicine = new CanadaMedicine(vitamin);
            canadaMedicine.ShowInfo();

            Console.WriteLine("**************************");
            Pharmacy pharmacy = new Pharmacy("MyPharmacy");

            pharmacy.AddDrug(chinaMedicine);
            pharmacy.AddDrug(canadaMedicine);
            pharmacy.AddDrug(new Vitamin("VITAAAMIN", 30.00));
            pharmacy.ShowDrugs();
            Console.WriteLine("********");
            pharmacy.FindByType(MedicineType.Antibiotic);
            Console.WriteLine("********");
            pharmacy.FindByType(MedicineType.Vitamin);
        }
    }

    public class Pharmacy
    {
        private List<Medicine> _drugs;
        public string Name { get; set; }

        public Pharmacy(string name)
        {
            Name = name;
            _drugs = new List<Medicine>();
        }

        public void AddDrug(Medicine med)
        {
            _drugs.Add(med);
        }

        public void RemoveDrug(Medicine med)
        {
            _drugs.Remove(med);
        }

        public void ShowDrugs()
        {
            foreach (var drug in _drugs)
            {
                drug.ShowInfo();
            }
        }

        public void FindByType(MedicineType type)
        {
            foreach (var drug in _drugs)
            {
                if (drug.MedType().Equals(type))
                {
                    drug.ShowInfo();
                }
            }
        }
    }
}