using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mileage_Calculator
{
    public partial class frmMileageCalculator : Form
    {
        public frmMileageCalculator()
        {
            InitializeComponent();
        }

        
        //================
        //Exit Button
        //================
        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        //================
        //Calculate Button
        //================
        private void btnCalculate_Click(object sender, EventArgs e)
        {
            lblOut.Visible = false;

            double averageCost = 0;
            double miles, fuelCost, fuelEconomy, tollsPaid, parkingFees;

            //If the there is not a mileage, fuel cost, and economy entered, indicate there has been an error 
            //and skip the calculation
            bool error = false;
            if (Double.TryParse(txtMiles.Text, out miles)) { }
            else { error = true; }

            if (Double.TryParse(txtFuelCost.Text, out fuelCost)) { }
            else { error = true; }


            if (Double.TryParse(txtFuelEco.Text, out fuelEconomy)) { }
            else { error = true; }
                

            Double.TryParse(txtTolls.Text, out tollsPaid);
            Double.TryParse(txtParkingFees.Text, out parkingFees);


            //As long as the error flag isn't set, do the calculation.
            if (!error)
            {
                
                averageCost = (((miles / fuelEconomy) * fuelCost) + tollsPaid + parkingFees)/100;

                //There is an issue with casting large numbers here.
                decimal output = Decimal.Round((decimal)averageCost, 2);
                lblOut.Text = "Your average cost per day to drive is:\n$" + (output);

            }else
            {
            lblOut.Text = "Please enter a valid mileage, fuel cost, and\nfuel economy to continue.";

            }
            //Set the output label to visible
            lblOut.Visible = true;
        }
    }
}