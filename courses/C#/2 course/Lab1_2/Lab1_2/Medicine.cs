using System;

namespace Lab1_2
{
    public enum MedicineType
    {
        NoType, Antibiotic, Vitamin
    }

    public enum License
    {
        NoCountry, China, Canada
    }

    public abstract class Medicine
    {
        public string Name { get; set; }
        protected MedicineType Type;
        public License CountryLicense { get; protected set; }
        protected internal double Price { get; set; }

        public virtual void ShowInfo()
        {
            Console.WriteLine("Name: {0}; Type: {1}; Price: {2}", Name, Type, GetPrice());
        }

        public virtual double GetPrice()
        {
            return Price;
        }

        public virtual MedicineType MedType()
        {
            return Type;
        }
    }

    public abstract class ForeignMedicine : Medicine
    {
        protected Medicine Medicine;

        public void SetMedicine(Medicine medicine)
        {
            if (Medicine != null)
            {
                Medicine.Price += (int) CountryLicense;
            }
            Medicine = medicine;
        }

        public Medicine GetMedicine()
        {
            if (Medicine != null)
            {
                Medicine.Price -= (int) CountryLicense;
            }
            Medicine tmp = Medicine;
            Medicine = null;
            return tmp;
        }

        public override void ShowInfo()
        {
            Medicine?.ShowInfo();
        }

        public override double GetPrice()
        {
            return Medicine.Price;
        }

        public override MedicineType MedType()
        {
            return Medicine.MedType();
        }
    }

    public class Antibiotic : Medicine
    {

        private Antibiotic()
        {
            Type = MedicineType.Antibiotic;
            CountryLicense = License.NoCountry;
        }

        public Antibiotic(string name)
        :this()
        {
            Name = name;
        }

        public Antibiotic(string name, double price)
            : this(name)
        {
            Price = price;
        }
    }

    public class Vitamin : Medicine
    {
        private Vitamin()
        {
            Type = MedicineType.Vitamin;
            CountryLicense = License.NoCountry;
        }

        public Vitamin(string name)
            :this()
        {
            Name = name;
        }

        public Vitamin(string name, double price)
            : this(name)
        {
            Price = price;
        }
    }

    public class ChinaMedicine : ForeignMedicine
    {

        public ChinaMedicine(Medicine medicine)
        {
            Medicine = medicine;
            CountryLicense = License.China;
            Medicine.Price += (int)CountryLicense;
        }

        public override void ShowInfo()
        {
            base.ShowInfo();
            Console.WriteLine("License: Medicine from " + CountryLicense);
        }
    }

    public class CanadaMedicine : ForeignMedicine
    {
        public CanadaMedicine(Medicine medicine)
        {
            Medicine = medicine;
            CountryLicense = License.Canada;
            Medicine.Price += (int) CountryLicense;
        }

        public override void ShowInfo()
        {
            base.ShowInfo();
            Console.WriteLine("License: Medicine from " + CountryLicense);

        }
    }
}