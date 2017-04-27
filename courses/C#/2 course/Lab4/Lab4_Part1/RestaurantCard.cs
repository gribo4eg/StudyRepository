using System;

namespace Lab4_Part1
{
    public class Card
    {

        public static int FIVE_TENPERCENT = 5000;
        public static int TEN_FIFTEENPERCENT = 10000;

        public Card(IState state)
        {
            Money = 0;
            State = state;
        }

        public int Money { get; private set; }
        public IState State { get; private set; }

        public void SetState(IState newState) => State = newState;

        public void AddMoney(int money)
        {
            Money += money;
            State.Handle(this);
        }

        public void SpendMoney(int money)
        {
            Money -= money;
            State.Handle(this);
        }

    }

    public interface IState
    {
        void Handle(Card card);
    }

    public class FivePercentDiscount : IState
    {
        public void Handle(Card card)
        {
            if (card.Money >= Card.FIVE_TENPERCENT && card.Money < Card.TEN_FIFTEENPERCENT)
            {
                Console.WriteLine("Card switched to TenPercentDiscount");
                card.SetState(new TenPercentDiscount());
            }
            else if (card.Money >= Card.TEN_FIFTEENPERCENT)
            {
                Console.WriteLine("Card switched to FifteenPercentDiscount");
                card.SetState(new FifteenPercentDiscount());
            }
        }
    }

    public class TenPercentDiscount : IState
    {
        public void Handle(Card card)
        {
            if (card.Money >= Card.TEN_FIFTEENPERCENT)
            {
                Console.WriteLine("Card switched to FifteenPercentDiscount");
                card.SetState(new FifteenPercentDiscount());
            }
            else if (card.Money < Card.FIVE_TENPERCENT)
            {
                Console.WriteLine("Card switched to FivePercentDiscount");
                card.SetState(new FivePercentDiscount());
            }
        }
    }

    public class FifteenPercentDiscount : IState
    {
        public void Handle(Card card)
        {
            if (card.Money >= Card.FIVE_TENPERCENT && card.Money < Card.TEN_FIFTEENPERCENT)
            {
                Console.WriteLine("Card switched to TenPercentDiscount");
                card.SetState(new TenPercentDiscount());
            }
            else if (card.Money < Card.FIVE_TENPERCENT)
            {
                Console.WriteLine("Card switched to FivePercentDiscount");
                card.SetState(new FivePercentDiscount());
            }
        }
    }
}