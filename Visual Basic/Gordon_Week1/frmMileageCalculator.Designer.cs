
namespace Mileage_Calculator
{
    partial class frmMileageCalculator
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lblMiles = new System.Windows.Forms.Label();
            this.txtMiles = new System.Windows.Forms.TextBox();
            this.lblCost = new System.Windows.Forms.Label();
            this.txtFuelCost = new System.Windows.Forms.TextBox();
            this.lblFuelEco = new System.Windows.Forms.Label();
            this.txtFuelEco = new System.Windows.Forms.TextBox();
            this.lblParkFees = new System.Windows.Forms.Label();
            this.txtParkingFees = new System.Windows.Forms.TextBox();
            this.lblTolls = new System.Windows.Forms.Label();
            this.txtTolls = new System.Windows.Forms.TextBox();
            this.lblOut = new System.Windows.Forms.Label();
            this.btnCalculate = new System.Windows.Forms.Button();
            this.btnExit = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lblMiles
            // 
            this.lblMiles.AutoSize = true;
            this.lblMiles.Location = new System.Drawing.Point(-2, 53);
            this.lblMiles.Name = "lblMiles";
            this.lblMiles.Size = new System.Drawing.Size(89, 17);
            this.lblMiles.TabIndex = 0;
            this.lblMiles.Text = "&Miles Driven:";
            // 
            // txtMiles
            // 
            this.txtMiles.Location = new System.Drawing.Point(174, 53);
            this.txtMiles.Name = "txtMiles";
            this.txtMiles.Size = new System.Drawing.Size(100, 22);
            this.txtMiles.TabIndex = 1;
            // 
            // lblCost
            // 
            this.lblCost.AutoSize = true;
            this.lblCost.Location = new System.Drawing.Point(-2, 91);
            this.lblCost.Name = "lblCost";
            this.lblCost.Size = new System.Drawing.Size(155, 17);
            this.lblCost.TabIndex = 2;
            this.lblCost.Text = "&Fuel cost (cents/gallon)";
            // 
            // txtFuelCost
            // 
            this.txtFuelCost.Location = new System.Drawing.Point(174, 91);
            this.txtFuelCost.Name = "txtFuelCost";
            this.txtFuelCost.Size = new System.Drawing.Size(100, 22);
            this.txtFuelCost.TabIndex = 3;
            // 
            // lblFuelEco
            // 
            this.lblFuelEco.AutoSize = true;
            this.lblFuelEco.Location = new System.Drawing.Point(-2, 123);
            this.lblFuelEco.Name = "lblFuelEco";
            this.lblFuelEco.Size = new System.Drawing.Size(170, 17);
            this.lblFuelEco.TabIndex = 4;
            this.lblFuelEco.Text = "Avg. Fuel &Economy (mpg)";
            // 
            // txtFuelEco
            // 
            this.txtFuelEco.Location = new System.Drawing.Point(174, 123);
            this.txtFuelEco.Name = "txtFuelEco";
            this.txtFuelEco.Size = new System.Drawing.Size(100, 22);
            this.txtFuelEco.TabIndex = 5;
            // 
            // lblParkFees
            // 
            this.lblParkFees.AutoSize = true;
            this.lblParkFees.Location = new System.Drawing.Point(-2, 157);
            this.lblParkFees.Name = "lblParkFees";
            this.lblParkFees.Size = new System.Drawing.Size(135, 17);
            this.lblParkFees.TabIndex = 6;
            this.lblParkFees.Text = "&Parking fees (cents)";
            // 
            // txtParkingFees
            // 
            this.txtParkingFees.Location = new System.Drawing.Point(174, 157);
            this.txtParkingFees.Name = "txtParkingFees";
            this.txtParkingFees.Size = new System.Drawing.Size(100, 22);
            this.txtParkingFees.TabIndex = 7;
            // 
            // lblTolls
            // 
            this.lblTolls.AutoSize = true;
            this.lblTolls.Location = new System.Drawing.Point(-2, 187);
            this.lblTolls.Name = "lblTolls";
            this.lblTolls.Size = new System.Drawing.Size(118, 17);
            this.lblTolls.TabIndex = 8;
            this.lblTolls.Text = "&Tolls Paid (cents)";
            // 
            // txtTolls
            // 
            this.txtTolls.Location = new System.Drawing.Point(174, 187);
            this.txtTolls.Name = "txtTolls";
            this.txtTolls.Size = new System.Drawing.Size(100, 22);
            this.txtTolls.TabIndex = 9;
            // 
            // lblOut
            // 
            this.lblOut.AutoSize = true;
            this.lblOut.Location = new System.Drawing.Point(12, 266);
            this.lblOut.Name = "lblOut";
            this.lblOut.Size = new System.Drawing.Size(0, 17);
            this.lblOut.TabIndex = 10;
            // 
            // btnCalculate
            // 
            this.btnCalculate.Location = new System.Drawing.Point(175, 412);
            this.btnCalculate.Name = "btnCalculate";
            this.btnCalculate.Size = new System.Drawing.Size(99, 38);
            this.btnCalculate.TabIndex = 11;
            this.btnCalculate.Text = "Calculate";
            this.btnCalculate.UseVisualStyleBackColor = true;
            this.btnCalculate.Click += new System.EventHandler(this.btnCalculate_Click);
            // 
            // btnExit
            // 
            this.btnExit.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnExit.Location = new System.Drawing.Point(69, 412);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(99, 38);
            this.btnExit.TabIndex = 12;
            this.btnExit.Text = "Exit";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // frmMileageCalculator
            // 
            this.AcceptButton = this.btnCalculate;
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.btnExit;
            this.ClientSize = new System.Drawing.Size(318, 473);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.btnCalculate);
            this.Controls.Add(this.lblOut);
            this.Controls.Add(this.txtTolls);
            this.Controls.Add(this.lblTolls);
            this.Controls.Add(this.txtParkingFees);
            this.Controls.Add(this.lblParkFees);
            this.Controls.Add(this.txtFuelEco);
            this.Controls.Add(this.lblFuelEco);
            this.Controls.Add(this.txtFuelCost);
            this.Controls.Add(this.lblCost);
            this.Controls.Add(this.txtMiles);
            this.Controls.Add(this.lblMiles);
            this.Name = "frmMileageCalculator";
            this.Text = "Mileage Calculator";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblMiles;
        private System.Windows.Forms.TextBox txtMiles;
        private System.Windows.Forms.Label lblCost;
        private System.Windows.Forms.TextBox txtFuelCost;
        private System.Windows.Forms.Label lblFuelEco;
        private System.Windows.Forms.TextBox txtFuelEco;
        private System.Windows.Forms.Label lblParkFees;
        private System.Windows.Forms.TextBox txtParkingFees;
        private System.Windows.Forms.Label lblTolls;
        private System.Windows.Forms.TextBox txtTolls;
        private System.Windows.Forms.Label lblOut;
        private System.Windows.Forms.Button btnCalculate;
        private System.Windows.Forms.Button btnExit;
    }
}

