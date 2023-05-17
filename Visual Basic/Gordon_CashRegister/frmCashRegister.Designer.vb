<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class frmCashRegister
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
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
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.mnuMain = New System.Windows.Forms.MenuStrip()
        Me.mnuFile = New System.Windows.Forms.ToolStripMenuItem()
        Me.mnuFileExit = New System.Windows.Forms.ToolStripMenuItem()
        Me.mnuEdit = New System.Windows.Forms.ToolStripMenuItem()
        Me.mnuEditAdd = New System.Windows.Forms.ToolStripMenuItem()
        Me.mnuEditModify = New System.Windows.Forms.ToolStripMenuItem()
        Me.lstInventoryList = New System.Windows.Forms.ListBox()
        Me.mnuMain.SuspendLayout()
        Me.SuspendLayout()
        '
        'mnuMain
        '
        Me.mnuMain.ImageScalingSize = New System.Drawing.Size(20, 20)
        Me.mnuMain.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.mnuFile, Me.mnuEdit})
        Me.mnuMain.Location = New System.Drawing.Point(0, 0)
        Me.mnuMain.Name = "mnuMain"
        Me.mnuMain.Size = New System.Drawing.Size(607, 28)
        Me.mnuMain.TabIndex = 0
        Me.mnuMain.Text = "MenuStrip1"
        '
        'mnuFile
        '
        Me.mnuFile.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.mnuFileExit})
        Me.mnuFile.Name = "mnuFile"
        Me.mnuFile.Size = New System.Drawing.Size(46, 24)
        Me.mnuFile.Text = "&File"
        '
        'mnuFileExit
        '
        Me.mnuFileExit.Name = "mnuFileExit"
        Me.mnuFileExit.Size = New System.Drawing.Size(116, 26)
        Me.mnuFileExit.Text = "&Exit"
        '
        'mnuEdit
        '
        Me.mnuEdit.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.mnuEditAdd, Me.mnuEditModify})
        Me.mnuEdit.Name = "mnuEdit"
        Me.mnuEdit.Size = New System.Drawing.Size(49, 24)
        Me.mnuEdit.Text = "&Edit"
        '
        'mnuEditAdd
        '
        Me.mnuEditAdd.Name = "mnuEditAdd"
        Me.mnuEditAdd.Size = New System.Drawing.Size(139, 26)
        Me.mnuEditAdd.Text = "&Add"
        '
        'mnuEditModify
        '
        Me.mnuEditModify.Name = "mnuEditModify"
        Me.mnuEditModify.Size = New System.Drawing.Size(139, 26)
        Me.mnuEditModify.Text = "&Modify"
        '
        'lstInventoryList
        '
        Me.lstInventoryList.FormattingEnabled = True
        Me.lstInventoryList.ItemHeight = 16
        Me.lstInventoryList.Location = New System.Drawing.Point(16, 33)
        Me.lstInventoryList.Margin = New System.Windows.Forms.Padding(4)
        Me.lstInventoryList.Name = "lstInventoryList"
        Me.lstInventoryList.Size = New System.Drawing.Size(488, 420)
        Me.lstInventoryList.TabIndex = 1
        '
        'frmCashRegister
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(607, 524)
        Me.Controls.Add(Me.lstInventoryList)
        Me.Controls.Add(Me.mnuMain)
        Me.MainMenuStrip = Me.mnuMain
        Me.Margin = New System.Windows.Forms.Padding(4)
        Me.Name = "frmCashRegister"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "Cash Register by Tanner Gordon"
        Me.mnuMain.ResumeLayout(False)
        Me.mnuMain.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents mnuMain As MenuStrip
    Friend WithEvents mnuFile As ToolStripMenuItem
    Friend WithEvents mnuFileExit As ToolStripMenuItem
    Friend WithEvents mnuEdit As ToolStripMenuItem
    Friend WithEvents mnuEditAdd As ToolStripMenuItem
    Friend WithEvents mnuEditModify As ToolStripMenuItem
    Friend WithEvents lstInventoryList As ListBox
End Class
