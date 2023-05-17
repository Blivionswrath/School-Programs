<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmAddForm
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.lblDescription = New System.Windows.Forms.Label()
        Me.lblInvNumber = New System.Windows.Forms.Label()
        Me.lblCost = New System.Windows.Forms.Label()
        Me.lblRetail = New System.Windows.Forms.Label()
        Me.lblOnHand = New System.Windows.Forms.Label()
        Me.txtInvNumber = New System.Windows.Forms.TextBox()
        Me.txtDescription = New System.Windows.Forms.TextBox()
        Me.txtCost = New System.Windows.Forms.TextBox()
        Me.txtRetail = New System.Windows.Forms.TextBox()
        Me.txtOnHand = New System.Windows.Forms.TextBox()
        Me.btnAdd = New System.Windows.Forms.Button()
        Me.btnCancel = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'lblDescription
        '
        Me.lblDescription.Location = New System.Drawing.Point(19, 45)
        Me.lblDescription.Name = "lblDescription"
        Me.lblDescription.Size = New System.Drawing.Size(96, 23)
        Me.lblDescription.TabIndex = 0
        Me.lblDescription.Text = "Description: "
        Me.lblDescription.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblInvNumber
        '
        Me.lblInvNumber.Location = New System.Drawing.Point(19, 20)
        Me.lblInvNumber.Name = "lblInvNumber"
        Me.lblInvNumber.Size = New System.Drawing.Size(96, 23)
        Me.lblInvNumber.TabIndex = 1
        Me.lblInvNumber.Text = "Inventory Number:"
        Me.lblInvNumber.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblCost
        '
        Me.lblCost.Location = New System.Drawing.Point(19, 73)
        Me.lblCost.Name = "lblCost"
        Me.lblCost.Size = New System.Drawing.Size(96, 23)
        Me.lblCost.TabIndex = 2
        Me.lblCost.Text = "Cost: "
        Me.lblCost.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblRetail
        '
        Me.lblRetail.Location = New System.Drawing.Point(19, 98)
        Me.lblRetail.Name = "lblRetail"
        Me.lblRetail.Size = New System.Drawing.Size(96, 23)
        Me.lblRetail.TabIndex = 3
        Me.lblRetail.Text = "Retail Price: "
        Me.lblRetail.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblOnHand
        '
        Me.lblOnHand.Location = New System.Drawing.Point(19, 127)
        Me.lblOnHand.Name = "lblOnHand"
        Me.lblOnHand.Size = New System.Drawing.Size(96, 23)
        Me.lblOnHand.TabIndex = 4
        Me.lblOnHand.Text = "Amount on hand:"
        Me.lblOnHand.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'txtInvNumber
        '
        Me.txtInvNumber.Location = New System.Drawing.Point(139, 23)
        Me.txtInvNumber.Name = "txtInvNumber"
        Me.txtInvNumber.Size = New System.Drawing.Size(100, 20)
        Me.txtInvNumber.TabIndex = 5
        '
        'txtDescription
        '
        Me.txtDescription.Location = New System.Drawing.Point(139, 49)
        Me.txtDescription.Name = "txtDescription"
        Me.txtDescription.Size = New System.Drawing.Size(100, 20)
        Me.txtDescription.TabIndex = 6
        '
        'txtCost
        '
        Me.txtCost.Location = New System.Drawing.Point(139, 75)
        Me.txtCost.Name = "txtCost"
        Me.txtCost.Size = New System.Drawing.Size(100, 20)
        Me.txtCost.TabIndex = 7
        '
        'txtRetail
        '
        Me.txtRetail.Location = New System.Drawing.Point(139, 101)
        Me.txtRetail.Name = "txtRetail"
        Me.txtRetail.Size = New System.Drawing.Size(100, 20)
        Me.txtRetail.TabIndex = 8
        '
        'txtOnHand
        '
        Me.txtOnHand.Location = New System.Drawing.Point(139, 130)
        Me.txtOnHand.Name = "txtOnHand"
        Me.txtOnHand.Size = New System.Drawing.Size(100, 20)
        Me.txtOnHand.TabIndex = 9
        '
        'btnAdd
        '
        Me.btnAdd.Location = New System.Drawing.Point(139, 212)
        Me.btnAdd.Name = "btnAdd"
        Me.btnAdd.Size = New System.Drawing.Size(75, 23)
        Me.btnAdd.TabIndex = 10
        Me.btnAdd.Text = "&Add Item"
        Me.btnAdd.UseVisualStyleBackColor = True
        '
        'btnCancel
        '
        Me.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.btnCancel.Location = New System.Drawing.Point(40, 212)
        Me.btnCancel.Name = "btnCancel"
        Me.btnCancel.Size = New System.Drawing.Size(75, 23)
        Me.btnCancel.TabIndex = 11
        Me.btnCancel.Text = "&Cancel"
        Me.btnCancel.UseVisualStyleBackColor = True
        '
        'frmAddForm
        '
        Me.AcceptButton = Me.btnAdd
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.CancelButton = Me.btnCancel
        Me.ClientSize = New System.Drawing.Size(293, 270)
        Me.Controls.Add(Me.btnCancel)
        Me.Controls.Add(Me.btnAdd)
        Me.Controls.Add(Me.txtOnHand)
        Me.Controls.Add(Me.txtRetail)
        Me.Controls.Add(Me.txtCost)
        Me.Controls.Add(Me.txtDescription)
        Me.Controls.Add(Me.txtInvNumber)
        Me.Controls.Add(Me.lblOnHand)
        Me.Controls.Add(Me.lblRetail)
        Me.Controls.Add(Me.lblCost)
        Me.Controls.Add(Me.lblInvNumber)
        Me.Controls.Add(Me.lblDescription)
        Me.Name = "frmAddForm"
        Me.Text = "Add an item"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents lblDescription As Label
    Private WithEvents lblInvNumber As Label
    Friend WithEvents lblCost As Label
    Friend WithEvents lblRetail As Label
    Friend WithEvents lblOnHand As Label
    Friend WithEvents txtInvNumber As TextBox
    Friend WithEvents txtDescription As TextBox
    Friend WithEvents txtCost As TextBox
    Friend WithEvents txtRetail As TextBox
    Friend WithEvents txtOnHand As TextBox
    Friend WithEvents btnAdd As Button
    Friend WithEvents btnCancel As Button
End Class
