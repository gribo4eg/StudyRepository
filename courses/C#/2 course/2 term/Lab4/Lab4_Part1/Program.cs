namespace Lab4_Part1
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Card card = new Card(new FivePercentDiscount());

            card.AddMoney(7000);

            card.SpendMoney(3000);

            card.AddMoney(7000);
        }
    }
}