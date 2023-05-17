using System;
using System.Collections.Generic;
using System.Text;

namespace Section2
{
    class Book : Product
    {

        private string author;

        public string Author { get { return author; }  set { author = value; } }


        public Book() : base()
        {

        }

        public Book(string code, string description, decimal price, string author) :
            base(code, description, price)
        {
            Author = author;
        }

        public string getAuthorText()
        {
            return "The author is: " + Author;
        }

    }
}
