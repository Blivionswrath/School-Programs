Public Class frmAddForm
    Private Sub btnAdd_Click(sender As Object, e As EventArgs) Handles btnAdd.Click
        '===========
        'Validation
        '===========
        Dim failed As Boolean = False
        Dim intInvNumber, intOnHand As UInteger
        Dim sngCost, sngRetail As Single

        Try
            intInvNumber = UInteger.Parse(txtInvNumber.Text)
            Try
                sngCost = Single.Parse(txtCost.Text)
                Try
                    sngRetail = Single.Parse(txtRetail.Text)
                    Try
                        intOnHand = UInteger.Parse(txtOnHand.Text)
                    Catch ex As Exception
                        failed = True
                        MessageBox.Show(ex.Message + " Please enter a valid on hand amount")
                    End Try
                Catch ex As Exception
                    failed = True
                    MessageBox.Show(ex.Message + " Please enter a valid retail price")
                End Try

            Catch ex As Exception
                MessageBox.Show(ex.Message + " Please enter a valid cost.")
                failed = True

            End Try
        Catch ex As Exception
            MessageBox.Show(ex.Message + " Please enter a valid inventory number")
            failed = True
        End Try

        If intOnHand < 0 Then
            failed = True
            MessageBox.Show("Please enter a valid on hand amount")
        End If

        If sngRetail < 0 Then
            failed = True
            MessageBox.Show("Please enter a price greater than 0")
        End If

        If sngCost < 0 Then
            failed = True
            MessageBox.Show("Please enter a cost greater than 0")
        End If

        If failed Then
            Return
        End If

        For Each item In inventoryList
            Dim intID As Integer = Integer.Parse(item.InvNumber)
            If intID = intInvNumber Then
                MessageBox.Show("inventory ID: " + intInvNumber.ToString + ". Is occupied, please choose another")
                Return
            End If

        Next
        '===================
        'Inventory creation
        '===================
        Dim currentItem As New Inventory
        currentItem.InvNumber = intInvNumber.ToString
        currentItem.Description = txtDescription.Text
        currentItem.Cost = sngCost
        currentItem.RetailPrice = sngRetail
        currentItem.OnHand = CInt(intOnHand)



        inventoryList.Add(currentItem)

        Me.Close()

    End Sub
End Class