using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Gordon_Week4
{
    public partial class frmAccounts : Form
    {

        Account refObject;
        Account regularAccount;
        SavingsAccount savingsAccount;
        CheckingAccount checkingAccount;

        public frmAccounts()
        {
            InitializeComponent();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void frmAccounts_Load(object sender, EventArgs e)
        {
            regularAccount = new Account(100.0m);
            savingsAccount = new SavingsAccount(200.0m, 3.7m);
            checkingAccount = new CheckingAccount(300.0m, 1.5m);
            cboAccounts.SelectedIndex = 0;
        }

        //Combo box goes:
        //Regular
        //Checkings
        //Savings
        private void updateBalance()
        {
            txtBalance.Text = refObject.Balance.ToString("C");
        }

        private void cboAccounts_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cboAccounts.SelectedIndex == 0)
            {
                refObject = regularAccount;
                lblInfo.Visible = false;
                txtInfo.Visible = false;
                btnAddInterest.Visible = false;
            }
            else if (cboAccounts.SelectedIndex == 1)
            {
                refObject = checkingAccount;
                lblInfo.Text = "Fee:";
                txtInfo.Text = checkingAccount.FeeRate.ToString("C");
                lblInfo.Visible = true;
                txtInfo.Visible = true;
                btnAddInterest.Visible = false;
            }
            else if (cboAccounts.SelectedIndex == 2)
            {
                refObject = savingsAccount;
                lblInfo.Text = "Interest Rate:";
                txtInfo.Text = savingsAccount.InterestRate.ToString() + "%";
                lblInfo.Visible = true;
                txtInfo.Visible = true;
                btnAddInterest.Visible = true;
            }

            updateBalance();
            
        }

        private void btnWithdraw_Click(object sender, EventArgs e)
        {

            decimal amount;

            //Input validation occurs inline, TODO: make this  easier to read
            //===================
            //Input Validation
            //====================

            if (!Decimal.TryParse(txtAmount.Text, out amount))
            {
                lblWarning.Visible = true;
                return;
            }

            if (amount < 0.0m )
            {
                lblWarning.Visible = true;
                return;
            }

            //If we couldn't debit, tell the user to enter a valid amount.
            if (!refObject.debitBalance(amount))
            {
                lblWarning.Visible = true;
                return;
            }

            updateBalance();
            lblWarning.Visible = false;
        }

        private void btnDeposit_Click(object sender, EventArgs e)
        {
            decimal amount;

            //Input validation occurs inline, TODO: make this  easier to read
            //===================
            //Input Validation
            //====================

            if (!Decimal.TryParse(txtAmount.Text, out amount))
            {
                lblWarning.Visible = true;
                return;
            }

            if (amount < 0.0m)
            {
                lblWarning.Visible = true;
                return;
            }

            //If we couldn't credit, tell the user to enter a valid amount.
            if (!refObject.creditBalance(amount))
            {
                lblWarning.Visible = true;
                return;
    
            }

            updateBalance();
            lblWarning.Visible = false;
        }

        private void btnAddInterest_Click(object sender, EventArgs e)
        {
            decimal amount = savingsAccount.calculateInterest();
            savingsAccount.creditBalance(amount);
            updateBalance();
        }
    }
}
