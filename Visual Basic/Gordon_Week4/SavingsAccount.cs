using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gordon_Week4
{
    class SavingsAccount : Account
    {
        private decimal interestRate;
        public decimal InterestRate
        {
            get
            {
                return interestRate;
            }
            set
            {
                interestRate = value;
            }
        }

        public SavingsAccount(decimal amount, decimal interestRate) : base(amount)
        {
            if (interestRate < 0.0m)  { throw new ArgumentOutOfRangeException(); }
            this.interestRate = interestRate;
        }

        
        public decimal calculateInterest()
        {
            decimal result = (decimal)Balance * (interestRate/100);
            return result;
        }
    }
}
