namespace Lab3_Part2
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Shop shop = Shop.GetShop();

            shop.BuyTicket("Expensive", new CheapTickets());

            shop.BuyTicket("Entrance", new CheapTickets());

            shop.BuyTicket("Special", new ExpensiveTickets());
        }
    }
}