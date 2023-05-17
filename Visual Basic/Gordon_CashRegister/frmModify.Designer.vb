<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmModify
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
        Me.lstInventoryList = New System.Windows.Forms.ListBox()
        Me.lblInventoryId = New System.Windows.Forms.Label()
        Me.lblDescription = New System.Windows.Forms.Label()
        Me.lblCost = New System.Windows.Forms.Label()
        Me.lblRetailPrice = New System.Windows.Forms.Label()
        Me.lblOnHand = New System.Windows.Forms.Label()
        Me.lblCurrentInvId = New System.Windows.Forms.Label()
        Me.lblCurrentDescription = New System.Windows.Forms.Label()
        Me.lblCurrentCost = New System.Windows.Forms.Label()
        Me.lblCurrentRetail = New System.Windows.Forms.Label()
        Me.lblCurrentOnHand = New System.Windows.Forms.Label()
        Me.txtNewInventoryID = New System.Windows.Forms.TextBox()
        Me.txtNewDescription = New System.Windows.Forms.TextBox()
        Me.grpCurrent = New System.Windows.Forms.GroupBox()
        Me.grpNew = New System.Windows.Forms.GroupBox()
        Me.txtNewOnHand = New System.Windows.Forms.TextBox()
        Me.txtNewRetail = New System.Windows.Forms.TextBox()
        Me.txtNewCost = New System.Windows.Forms.TextBox()
        Me.btnApply = New System.Windows.Forms.Button()
        Me.grpCurrent.SuspendLayout()
        Me.grpNew.SuspendLayout()
        Me.SuspendLayout()
        '
        'lstInventoryList
        '
        Me.lstInventoryList.FormattingEnabled = True
        Me.lstInventoryList.ItemHeight = 16
        Me.lstInventoryList.Location = New System.Drawing.Point(12, 12)
        Me.lstInventoryList.Name = "lstInventoryList"
        Me.lstInventoryList.Size = New System.Drawing.Size(254, 308)
        Me.lstInventoryList.TabIndex = 0
        '
        'lblInventoryId
        '
        Me.lblInventoryId.ImageAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.lblInventoryId.Location = New System.Drawing.Point(6, 18)
        Me.lblInventoryId.Name = "lblInventoryId"
        Me.lblInventoryId.Size = New System.Drawing.Size(188, 23)
        Me.lblInventoryId.TabIndex = 1
        Me.lblInventoryId.Text = "Current Inventory Number:"
        Me.lblInventoryId.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblDescription
        '
        Me.lblDescription.ImageAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.lblDescription.Location = New System.Drawing.Point(49, 41)
        Me.lblDescription.Name = "lblDescription"
        Me.lblDescription.Size = New System.Drawing.Size(145, 23)
        Me.lblDescription.TabIndex = 2
        Me.lblDescription.Text = "Current Description:"
        Me.lblDescription.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblCost
        '
        Me.lblCost.ImageAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.lblCost.Location = New System.Drawing.Point(12, 64)
        Me.lblCost.Name = "lblCost"
        Me.lblCost.Size = New System.Drawing.Size(182, 23)
        Me.lblCost.TabIndex = 3
        Me.lblCost.Text = "Current Cost:"
        Me.lblCost.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblRetailPrice
        '
        Me.lblRetailPrice.ImageAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.lblRetailPrice.Location = New System.Drawing.Point(22, 87)
        Me.lblRetailPrice.Name = "lblRetailPrice"
        Me.lblRetailPrice.Size = New System.Drawing.Size(172, 27)
        Me.lblRetailPrice.TabIndex = 4
        Me.lblRetailPrice.Text = "Current Retail Price:"
        Me.lblRetailPrice.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblOnHand
        '
        Me.lblOnHand.Location = New System.Drawing.Point(22, 114)
        Me.lblOnHand.Name = "lblOnHand"
        Me.lblOnHand.Size = New System.Drawing.Size(172, 27)
        Me.lblOnHand.TabIndex = 5
        Me.lblOnHand.Text = "Amount on hand:"
        Me.lblOnHand.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblCurrentInvId
        '
        Me.lblCurrentInvId.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.lblCurrentInvId.Location = New System.Drawing.Point(201, 18)
        Me.lblCurrentInvId.Name = "lblCurrentInvId"
        Me.lblCurrentInvId.Size = New System.Drawing.Size(78, 23)
        Me.lblCurrentInvId.TabIndex = 6
        '
        'lblCurrentDescription
        '
        Me.lblCurrentDescription.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.lblCurrentDescription.Location = New System.Drawing.Point(201, 43)
        Me.lblCurrentDescription.Name = "lblCurrentDescription"
        Me.lblCurrentDescription.Size = New System.Drawing.Size(78, 23)
        Me.lblCurrentDescription.TabIndex = 7
        '
        'lblCurrentCost
        '
        Me.lblCurrentCost.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.lblCurrentCost.Location = New System.Drawing.Point(200, 66)
        Me.lblCurrentCost.Name = "lblCurrentCost"
        Me.lblCurrentCost.Size = New System.Drawing.Size(78, 23)
        Me.lblCurrentCost.TabIndex = 8
        '
        'lblCurrentRetail
        '
        Me.lblCurrentRetail.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.lblCurrentRetail.Location = New System.Drawing.Point(200, 91)
        Me.lblCurrentRetail.Name = "lblCurrentRetail"
        Me.lblCurrentRetail.Size = New System.Drawing.Size(78, 23)
        Me.lblCurrentRetail.TabIndex = 9
        '
        'lblCurrentOnHand
        '
        Me.lblCurrentOnHand.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.lblCurrentOnHand.Location = New System.Drawing.Point(200, 118)
        Me.lblCurrentOnHand.Name = "lblCurrentOnHand"
        Me.lblCurrentOnHand.Size = New System.Drawing.Size(78, 23)
        Me.lblCurrentOnHand.TabIndex = 10
        '
        'txtNewInventoryID
        '
        Me.txtNewInventoryID.Location = New System.Drawing.Point(6, 18)
        Me.txtNewInventoryID.Name = "txtNewInventoryID"
        Me.txtNewInventoryID.Size = New System.Drawing.Size(100, 22)
        Me.txtNewInventoryID.TabIndex = 11
        '
        'txtNewDescription
        '
        Me.txtNewDescription.Location = New System.Drawing.Point(6, 43)
        Me.txtNewDescription.Name = "txtNewDescription"
        Me.txtNewDescription.Size = New System.Drawing.Size(100, 22)
        Me.txtNewDescription.TabIndex = 12
        '
        'grpCurrent
        '
        Me.grpCurrent.Controls.Add(Me.lblInventoryId)
        Me.grpCurrent.Controls.Add(Me.lblDescription)
        Me.grpCurrent.Controls.Add(Me.lblCost)
        Me.grpCurrent.Controls.Add(Me.lblCurrentOnHand)
        Me.grpCurrent.Controls.Add(Me.lblRetailPrice)
        Me.grpCurrent.Controls.Add(Me.lblCurrentRetail)
        Me.grpCurrent.Controls.Add(Me.lblOnHand)
        Me.grpCurrent.Controls.Add(Me.lblCurrentCost)
        Me.grpCurrent.Controls.Add(Me.lblCurrentInvId)
        Me.grpCurrent.Controls.Add(Me.lblCurrentDescription)
        Me.grpCurrent.Location = New System.Drawing.Point(281, 12)
        Me.grpCurrent.Name = "grpCurrent"
        Me.grpCurrent.Size = New System.Drawing.Size(294, 169)
        Me.grpCurrent.TabIndex = 13
        Me.grpCurrent.TabStop = False
        Me.grpCurrent.Text = "Current"
        '
        'grpNew
        '
        Me.grpNew.Controls.Add(Me.txtNewOnHand)
        Me.grpNew.Controls.Add(Me.txtNewRetail)
        Me.grpNew.Controls.Add(Me.txtNewCost)
        Me.grpNew.Controls.Add(Me.txtNewInventoryID)
        Me.grpNew.Controls.Add(Me.txtNewDescription)
        Me.grpNew.Location = New System.Drawing.Point(582, 13)
        Me.grpNew.Name = "grpNew"
        Me.grpNew.Size = New System.Drawing.Size(132, 168)
        Me.grpNew.TabIndex = 14
        Me.grpNew.TabStop = False
        Me.grpNew.Text = "New"
        '
        'txtNewOnHand
        '
        Me.txtNewOnHand.Location = New System.Drawing.Point(6, 117)
        Me.txtNewOnHand.Name = "txtNewOnHand"
        Me.txtNewOnHand.Size = New System.Drawing.Size(100, 22)
        Me.txtNewOnHand.TabIndex = 17
        '
        'txtNewRetail
        '
        Me.txtNewRetail.Location = New System.Drawing.Point(6, 91)
        Me.txtNewRetail.Name = "txtNewRetail"
        Me.txtNewRetail.Size = New System.Drawing.Size(100, 22)
        Me.txtNewRetail.TabIndex = 16
        '
        'txtNewCost
        '
        Me.txtNewCost.Location = New System.Drawing.Point(6, 66)
        Me.txtNewCost.Name = "txtNewCost"
        Me.txtNewCost.Size = New System.Drawing.Size(100, 22)
        Me.txtNewCost.TabIndex = 15
        '
        'btnApply
        '
        Me.btnApply.Location = New System.Drawing.Point(588, 216)
        Me.btnApply.Name = "btnApply"
        Me.btnApply.Size = New System.Drawing.Size(75, 35)
        Me.btnApply.TabIndex = 15
        Me.btnApply.Text = "Apply"
        Me.btnApply.UseVisualStyleBackColor = True
        '
        'frmModify
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.btnApply)
        Me.Controls.Add(Me.grpNew)
        Me.Controls.Add(Me.grpCurrent)
        Me.Controls.Add(Me.lstInventoryList)
        Me.Name = "frmModify"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
        Me.Text = "Modify Inventory"
        Me.grpCurrent.ResumeLayout(False)
        Me.grpNew.ResumeLayout(False)
        Me.grpNew.PerformLayout()
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents lstInventoryList As ListBox
    Friend WithEvents lblInventoryId As Label
    Friend WithEvents lblDescription As Label
    Friend WithEvents lblCost As Label
    Friend WithEvents lblRetailPrice As Label
    Friend WithEvents lblOnHand As Label
    Friend WithEvents lblCurrentInvId As Label
    Friend WithEvents lblCurrentDescription As Label
    Friend WithEvents lblCurrentCost As Label
    Friend WithEvents lblCurrentRetail As Label
    Friend WithEvents lblCurrentOnHand As Label
    Friend WithEvents txtNewInventoryID As TextBox
    Friend WithEvents txtNewDescription As TextBox
    Friend WithEvents grpCurrent As GroupBox
    Friend WithEvents grpNew As GroupBox
    Friend WithEvents txtNewOnHand As TextBox
    Friend WithEvents txtNewRetail As TextBox
    Friend WithEvents txtNewCost As TextBox
    Friend WithEvents btnApply As Button
End Class
