using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Text;

namespace Section2
{
    class Product : IEquatable<Product>
    {
        private string code, description;
        private decimal price;
        public string Code { get { return code; } set { code = value; } }
        public string Description { get { return description; } set { description = value; } }
        public decimal Price { get { return price; } set { price = value; } }

        public Product()
        {

        }

        public Product(string code, string description, decimal price)
        {
            this.Code = code;
            this.Description = description;
            this.Price = price;
        }
        

        public string GetDisplayPrice()
        {
            return "The product number " + Code + " is " + Price.ToString("c");

        }

        public string GetDisplayDescription()
        {
            return "The product number " + Code + " is: " + Description;
        }

        public bool Equals([AllowNull] Product other)
        {
            return Code.Equals(other.Code);
        }
    }
}
