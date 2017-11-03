

namespace Lab3
{
    public interface IAnimal
    {
        int Age { get; set; }
        string Name { get; set; }
        FoodType Food { get; set; }
        void Dispose();
        void Feed(Watchman w);
    }
}

