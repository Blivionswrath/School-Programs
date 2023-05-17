using System;

namespace Gordon_Week4
{
    class Account
    {
        private decimal balance;
        public decimal Balance 
        { 
            get { return balance; }
            set { balance = value; }

        }

        //////////////
        //Constructors
        //////////////
        public Account(decimal balance)
        {
            if (balance < 0.0m) { throw new ArgumentOutOfRangeException(); }
            this.Balance = balance;
        }




        //This is the method responsible for subtracting money
        public virtual bool debitBalance(decimal amount)
        {
            if (amount < 0.0m) { throw new ArgumentOutOfRangeException(); }
            if (Balance - amount < 0.0m) { return false; }
            Balance -= amount;
            return true;
        }

        //This is the method responsible for adding money
        public virtual bool creditBalance(decimal amount)
        {
            //Display invalid input
            if (amount < 0.0m) { throw new ArgumentOutOfRangeException(); }

            Balance += amount;
            return true;
        }


    }
}
