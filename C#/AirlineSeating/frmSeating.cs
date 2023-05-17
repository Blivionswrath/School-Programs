//Programmer: Tanner Gordon
//OCCC C# Online (CS-2563-TW01F)
//Airline seating program

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AirlineSeating
{

    public partial class frmAirlineSeating : Form
    {
        const string DEFAULT_MESSAGE = "Welcome! Would you like to sit in first class or economy?\n" +
        "1 = First Class, 2 = Economy";
        const string FIRST_FULL_MSG = "First Class seating is full, would you like to sit in economy?\n1 = Yes 2 = No";
        const string ECONOMY_FULL_MSG = "Economy seating is full, would you like to sit in First Class?\n1 = Yes 2 = No";
        Random generator = new Random();
        public frmAirlineSeating()
        {
            InitializeComponent();
        }

        bool[] seats;

        private void Form1_Load(object sender, EventArgs e)
        {
            seats = new bool[10];
            lblWelcome.Text = DEFAULT_MESSAGE;
            updateSeating();
        }


        private void updateSeating()
        {


            StringBuilder builder = new StringBuilder();
            string occupied;
            //First class seating update
            for (int i = 0; i < 5; i++)
            {
                //Convert from true/false to Vacant/Occupied
                if (seats[i]) { occupied = "Occupied"; }
                else { occupied = "Vacant"; }

                builder.Append(String.Format("{0,12}", occupied));
                if ((i + 1) % 2 == 0) { builder.Append("\n\n"); }

            }

            lblFirstClassSeating.Text = builder.ToString();
            builder.Clear();


            //Economy seating update
            for (int i = 5; i < 10; i++)
            {

                //Convert from true/false to Vacant/Occupied
                if (seats[i]) { occupied = "Occupied"; }
                else { occupied = "Vacant"; }
                

                builder.Append(String.Format("{0,12}", occupied));
                if ((i + 1)% 2 == 0 ) { builder.Append("\n"); }
            }

            lblEconomySeating.Text = builder.ToString();

        }
        private void updateMessage()
        {
            bool firstClassFull = true;
            bool economyFull = true;
            //A for loop that goes through each value in seats[]
            for (int i = 0; i < seats.Length; i++)
            {
                //If the seat is empty check what section it is
                if (!seats[i] )
                {
                    if (i < 5)
                    {
                        firstClassFull = false;
                    }else
                    {
                        economyFull = false;
                    }
                }
            }

            
            //If we discover there are empty seats in both sections, use the default msg
            if (!firstClassFull && !economyFull)
            {
                lblWelcome.Text = DEFAULT_MESSAGE;
                return;
            }

            if (firstClassFull && !economyFull)
            {
                lblWelcome.Text = FIRST_FULL_MSG;
                return;
            }

            if (economyFull && !firstClassFull)
            {
                lblWelcome.Text = ECONOMY_FULL_MSG;
                return;
            }

            lblWelcome.Text = "Thank you for choosing us, but this flight is fully seated.";
            lblNextFlight.Visible = true;
            btnNext.Visible = true;

            
        }
        //========================
        //Accept Button
        //=======================
        private void btnEnter_Click(object sender, EventArgs e)
        {
            bool validInput = true;
            string response = txtSelection.Text;
            int number;


            //Read the input, if it is not a number it isn't valid...
            if (int.TryParse(response, out number)) { }
            else { validInput = false; }

            //..It also has to be 1 or 2
            if (number != 2)
            {
                if (number != 1)
                {
                    validInput = false;
                }
            }
            //Display message and continue on if it is not valid
            if (!validInput)
            {
                lblInputMsg.Visible = true;
                return;
            }
            //Send to the seat manager method to find a seat
            assignSeat(number);
            //Update the message to the user
            updateMessage();
            //Update the seating chart
            updateSeating();


            lblInputMsg.Visible = false;
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void assignSeat(int input)
        {
            lblYourSeat.Visible = true;
            lblSeatNumber.Visible = true;
            if (String.Equals(lblWelcome.Text, DEFAULT_MESSAGE))
            {
                if (input == 1) {
                    int number = generator.Next(0, 5);
                    //Check to see if the number is taken
                    while (seats[number])
                    {
                        number = generator.Next(0, 5);
                    }

                    seats[number] = true;
                    //Increment the number so my seating starts at 1
                    number++;
                    lblSeatNumber.Text = number.ToString();
                }else {
                    int number = generator.Next(5, 10);
                    while (seats[number])
                    {
                        number = generator.Next(5, 10);
                    }

                    seats[number] = true;
                    //Increment the number so my seating starts at 1
                    number++;
                    lblSeatNumber.Text = number.ToString();

                }
            }
            else if (String.Equals(lblWelcome.Text, FIRST_FULL_MSG))
            {
                if (input == 1)
                {
                    int number = generator.Next(5, 10);
                    while (seats[number])
                    {
                        number = generator.Next(5, 10);
                    }

                    seats[number] = true;
                    //Increment the number so my seating starts at 1
                    number++;
                    lblSeatNumber.Text = number.ToString();
                }
                else
                    lblNextFlight.Visible = true;
                {
                }
            }
            else if (String.Equals(lblWelcome.Text, ECONOMY_FULL_MSG))
            {
                if (input == 1)
                {
                    int number = generator.Next(0, 5);
                    //Check to see if the number is taken
                    while (seats[number])
                    {
                        number = generator.Next(0, 5);
                    }

                    seats[number] = true;
                    //Increment the number so my seating starts at 1
                    number++;
                    lblSeatNumber.Text = number.ToString();
                }
                else
                {
                    lblNextFlight.Visible = true;
                    
                }
            }
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < seats.Length; i++)
            {
                seats[i] = false;
            }
            updateMessage();
            updateSeating();
            lblNextFlight.Visible = false;
            lblSeatNumber.Visible = false;
            lblYourSeat.Visible = false;
            btnNext.Visible = false;
            
        }
    }
}