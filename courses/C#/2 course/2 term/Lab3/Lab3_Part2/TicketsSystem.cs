using System;

namespace Lab3_Part2
{
    //ABSTRACT FACTORY
    public abstract class CostValue
    {
        public abstract EntranceTicket GetEntranceTicket();
        public abstract SimpleTicket GetSimpleTicket();
        public abstract SpecialTicket GetSpecialTicket();
    }

    //CONCRETE FACTORY 1
    public class ExpensiveTickets : CostValue
    {
        public override EntranceTicket GetEntranceTicket() => new VipEntranceTicket();
        public override SimpleTicket GetSimpleTicket() => new VipSimpleTicket();
        public override SpecialTicket GetSpecialTicket() => new VipSpecialTicket();
    }

    //CONCRETE FACTORY 2
    public class CheapTickets : CostValue
    {
        public override EntranceTicket GetEntranceTicket() => new SimpleEntranceTicket();
        public override SimpleTicket GetSimpleTicket() => new SimpSimpleTicket();
        public override SpecialTicket GetSpecialTicket() => new SimpleSpecialTicket();
    }

    public abstract class EntranceTicket
    {
        public abstract void TicketInfo();
    }

    public abstract class SimpleTicket
    {
        public abstract void TicketInfo();
    }

    public abstract class SpecialTicket
    {
        public abstract void TicketInfo();
    }

    public class VipEntranceTicket : EntranceTicket
    {
        public override void TicketInfo() => Console.WriteLine("Vip Entrance Ticket");
    }

    public class SimpleEntranceTicket : EntranceTicket
    {
        public override void TicketInfo() => Console.WriteLine("Simple Entrance Ticket");
    }

    public class VipSimpleTicket : SimpleTicket
    {
        public override void TicketInfo() => Console.WriteLine("Vip Simple Ticket");
    }

    public class SimpSimpleTicket : SimpleTicket
    {
        public override void TicketInfo() => Console.WriteLine("Just Simple Ticket");
    }

    public class VipSpecialTicket : SpecialTicket
    {
        public override void TicketInfo() => Console.WriteLine("Vip Special Ticket with autograph");
    }

    public class SimpleSpecialTicket : SpecialTicket
    {
        public override void TicketInfo() => Console.WriteLine("Simple Special Ticket");
    }

    public class Shop
    {
        public string Name { get; set; }

        private static Shop _instance;

        private Shop(){}

        public static Shop GetShop() => _instance ?? (_instance = new Shop());

        public void BuyTicket(string type, CostValue fabric)
        {
            switch (type)
            {
                case "Entrance":
                    fabric.GetEntranceTicket().TicketInfo();
                    break;
                case "Simple":
                    fabric.GetSimpleTicket().TicketInfo();
                    break;
                case "Special":
                    fabric.GetSpecialTicket().TicketInfo();
                    break;
            }
        }

    }
}