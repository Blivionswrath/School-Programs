
namespace AirlineSeating
{
    partial class frmAirlineSeating
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
            this.lblWelcome = new System.Windows.Forms.Label();
            this.txtSelection = new System.Windows.Forms.TextBox();
            this.btnEnter = new System.Windows.Forms.Button();
            this.lblInputMsg = new System.Windows.Forms.Label();
            this.btnExit = new System.Windows.Forms.Button();
            this.imgRedLine = new System.Windows.Forms.PictureBox();
            this.lblEconomy = new System.Windows.Forms.Label();
            this.lblFirstClass = new System.Windows.Forms.Label();
            this.lblFirstClassSeating = new System.Windows.Forms.Label();
            this.lblEconomySeating = new System.Windows.Forms.Label();
            this.lblNextFlight = new System.Windows.Forms.Label();
            this.btnNext = new System.Windows.Forms.Button();
            this.lblYourSeat = new System.Windows.Forms.Label();
            this.lblSeatNumber = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.imgRedLine)).BeginInit();
            this.SuspendLayout();
            // 
            // lblWelcome
            // 
            this.lblWelcome.AutoSize = true;
            this.lblWelcome.Location = new System.Drawing.Point(13, 13);
            this.lblWelcome.Name = "lblWelcome";
            this.lblWelcome.Size = new System.Drawing.Size(363, 34);
            this.lblWelcome.TabIndex = 0;
            this.lblWelcome.Text = "Welcome! Would you like to sit in first class or economy?\r\n1 = First Class, 2 = E" +
    "conomy";
            // 
            // txtSelection
            // 
            this.txtSelection.Location = new System.Drawing.Point(16, 107);
            this.txtSelection.Name = "txtSelection";
            this.txtSelection.ShortcutsEnabled = false;
            this.txtSelection.Size = new System.Drawing.Size(100, 22);
            this.txtSelection.TabIndex = 1;
            // 
            // btnEnter
            // 
            this.btnEnter.Location = new System.Drawing.Point(12, 152);
            this.btnEnter.Name = "btnEnter";
            this.btnEnter.Size = new System.Drawing.Size(140, 57);
            this.btnEnter.TabIndex = 2;
            this.btnEnter.Text = "&Accept";
            this.btnEnter.UseVisualStyleBackColor = true;
            this.btnEnter.Click += new System.EventHandler(this.btnEnter_Click);
            // 
            // lblInputMsg
            // 
            this.lblInputMsg.AutoSize = true;
            this.lblInputMsg.ForeColor = System.Drawing.Color.Red;
            this.lblInputMsg.Location = new System.Drawing.Point(16, 84);
            this.lblInputMsg.Name = "lblInputMsg";
            this.lblInputMsg.Size = new System.Drawing.Size(141, 17);
            this.lblInputMsg.TabIndex = 3;
            this.lblInputMsg.Text = "Please enter a 1 or 2";
            this.lblInputMsg.Visible = false;
            // 
            // btnExit
            // 
            this.btnExit.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnExit.Location = new System.Drawing.Point(12, 235);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(140, 57);
            this.btnExit.TabIndex = 4;
            this.btnExit.Text = "&Exit";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // imgRedLine
            // 
            this.imgRedLine.BackColor = System.Drawing.Color.DarkRed;
            this.imgRedLine.Location = new System.Drawing.Point(312, 157);
            this.imgRedLine.Name = "imgRedLine";
            this.imgRedLine.Size = new System.Drawing.Size(273, 10);
            this.imgRedLine.TabIndex = 15;
            this.imgRedLine.TabStop = false;
            // 
            // lblEconomy
            // 
            this.lblEconomy.AutoSize = true;
            this.lblEconomy.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblEconomy.Location = new System.Drawing.Point(294, 191);
            this.lblEconomy.Name = "lblEconomy";
            this.lblEconomy.Size = new System.Drawing.Size(73, 17);
            this.lblEconomy.TabIndex = 16;
            this.lblEconomy.Text = "Economy";
            // 
            // lblFirstClass
            // 
            this.lblFirstClass.AutoSize = true;
            this.lblFirstClass.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblFirstClass.Location = new System.Drawing.Point(294, 84);
            this.lblFirstClass.Name = "lblFirstClass";
            this.lblFirstClass.Size = new System.Drawing.Size(84, 17);
            this.lblFirstClass.TabIndex = 17;
            this.lblFirstClass.Text = "First Class";
            this.lblFirstClass.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // lblFirstClassSeating
            // 
            this.lblFirstClassSeating.AutoSize = true;
            this.lblFirstClassSeating.Location = new System.Drawing.Point(375, 50);
            this.lblFirstClassSeating.Name = "lblFirstClassSeating";
            this.lblFirstClassSeating.Size = new System.Drawing.Size(83, 17);
            this.lblFirstClassSeating.TabIndex = 18;
            this.lblFirstClassSeating.Text = "Placeholder\r\n";
            // 
            // lblEconomySeating
            // 
            this.lblEconomySeating.AutoSize = true;
            this.lblEconomySeating.Location = new System.Drawing.Point(375, 192);
            this.lblEconomySeating.Name = "lblEconomySeating";
            this.lblEconomySeating.Size = new System.Drawing.Size(83, 17);
            this.lblEconomySeating.TabIndex = 19;
            this.lblEconomySeating.Text = "Placeholder\r\n";
            // 
            // lblNextFlight
            // 
            this.lblNextFlight.AutoSize = true;
            this.lblNextFlight.ForeColor = System.Drawing.Color.Red;
            this.lblNextFlight.Location = new System.Drawing.Point(16, 67);
            this.lblNextFlight.Name = "lblNextFlight";
            this.lblNextFlight.Size = new System.Drawing.Size(209, 17);
            this.lblNextFlight.TabIndex = 20;
            this.lblNextFlight.Text = "The next flight leaves in 3 hours";
            this.lblNextFlight.Visible = false;
            // 
            // btnNext
            // 
            this.btnNext.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnNext.Location = new System.Drawing.Point(158, 235);
            this.btnNext.Name = "btnNext";
            this.btnNext.Size = new System.Drawing.Size(140, 57);
            this.btnNext.TabIndex = 21;
            this.btnNext.Text = "&Next Flight";
            this.btnNext.UseVisualStyleBackColor = true;
            this.btnNext.Visible = false;
            this.btnNext.Click += new System.EventHandler(this.btnNext_Click);
            // 
            // lblYourSeat
            // 
            this.lblYourSeat.AutoSize = true;
            this.lblYourSeat.Location = new System.Drawing.Point(173, 126);
            this.lblYourSeat.Name = "lblYourSeat";
            this.lblYourSeat.Size = new System.Drawing.Size(75, 17);
            this.lblYourSeat.TabIndex = 22;
            this.lblYourSeat.Text = "Your Seat:";
            this.lblYourSeat.Visible = false;
            // 
            // lblSeatNumber
            // 
            this.lblSeatNumber.AutoSize = true;
            this.lblSeatNumber.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSeatNumber.Location = new System.Drawing.Point(193, 159);
            this.lblSeatNumber.Name = "lblSeatNumber";
            this.lblSeatNumber.Size = new System.Drawing.Size(32, 32);
            this.lblSeatNumber.TabIndex = 23;
            this.lblSeatNumber.Text = "1";
            this.lblSeatNumber.Visible = false;
            // 
            // frmAirlineSeating
            // 
            this.AcceptButton = this.btnEnter;
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.btnExit;
            this.ClientSize = new System.Drawing.Size(626, 343);
            this.Controls.Add(this.lblSeatNumber);
            this.Controls.Add(this.lblYourSeat);
            this.Controls.Add(this.btnNext);
            this.Controls.Add(this.lblNextFlight);
            this.Controls.Add(this.lblEconomySeating);
            this.Controls.Add(this.lblFirstClassSeating);
            this.Controls.Add(this.lblFirstClass);
            this.Controls.Add(this.lblEconomy);
            this.Controls.Add(this.imgRedLine);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.lblInputMsg);
            this.Controls.Add(this.btnEnter);
            this.Controls.Add(this.txtSelection);
            this.Controls.Add(this.lblWelcome);
            this.MinimumSize = new System.Drawing.Size(644, 390);
            this.Name = "frmAirlineSeating";
            this.Text = "Airline Seating";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.imgRedLine)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblWelcome;
        private System.Windows.Forms.TextBox txtSelection;
        private System.Windows.Forms.Button btnEnter;
        private System.Windows.Forms.Label lblInputMsg;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.PictureBox imgRedLine;
        private System.Windows.Forms.Label lblEconomy;
        private System.Windows.Forms.Label lblFirstClass;
        private System.Windows.Forms.Label lblFirstClassSeating;
        private System.Windows.Forms.Label lblEconomySeating;
        private System.Windows.Forms.Label lblNextFlight;
        private System.Windows.Forms.Button btnNext;
        private System.Windows.Forms.Label lblYourSeat;
        private System.Windows.Forms.Label lblSeatNumber;
    }
}

