using System;
using System.Collections.Generic;
using System.Text;

namespace Section2
{
    class Software : Product
    {

        private string version;

        public string Version { get { return version; } set { version = value; } }

        public Software() : base()
        {

        }

        public Software(string code, string description, decimal price, string version) :
            base (code, description, price)
        {
            Version = version;
        }

        public string GetDisplayVersion()
        {
            return "Version is: " + Version;
        }
    }
}
