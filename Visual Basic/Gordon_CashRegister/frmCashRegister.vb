Public Class frmCashRegister
    Private Sub mnuFileExit_Click(sender As Object, e As EventArgs) Handles mnuFileExit.Click
        Me.Close()
    End Sub

    Private Sub mnuEditAdd_Click(sender As Object, e As EventArgs) Handles mnuEditAdd.Click
        Dim addForm As New frmAddForm
        addForm.ShowDialog()
        updateList()

    End Sub

    Private Sub mnuEditModify_Click(sender As Object, e As EventArgs) Handles mnuEditModify.Click
        Dim modifyForm As New frmModify
        modifyForm.ShowDialog()

    End Sub


End Class
