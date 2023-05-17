using System;

namespace Gordon_Week4
{
    class CheckingAccount : Account
    {
        private decimal feeRate;

        public decimal FeeRate
        {
            get
            {
                return feeRate;
            }
            set
            {
                feeRate = value;
            }
        }


        public CheckingAccount(decimal amount, decimal feeRate) : base(amount)
        {
            if (feeRate < 0.0m) { throw new ArgumentOutOfRangeException(); }
            this.feeRate = feeRate;
        }

        public override bool creditBalance(decimal amount)
        {
            if (amount < 0.0m) { throw new ArgumentOutOfRangeException(); }

            Balance += amount;
            Balance -= feeRate;

            return true;
        }
        public override bool debitBalance(decimal amount)
        {

            if (amount < 0.0m) { throw new ArgumentOutOfRangeException(); }
            //Check if there is enough money for the fee and charge
            if (amount + feeRate > Balance) { return false; }
            Balance -= amount;
            Balance -= feeRate;
            return true;
        }
    }
}
