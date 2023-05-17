Public Class frmModify
    Private Sub frmModify_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        For Each item In inventoryList
            lstInventoryList.Items.Add(item.Description.ToString)
        Next
    End Sub

    Private Sub lstInventoryList_SelectedIndexChanged(sender As Object, e As EventArgs) Handles lstInventoryList.SelectedIndexChanged
        Dim selected As Inventory = getItemByDescription(lstInventoryList.SelectedItem.ToString)
        With selected
            lblCurrentCost.Text = .Cost.ToString
            lblCurrentDescription.Text = .Description.ToString
            lblCurrentInvId.Text = .InvNumber.ToString
            lblCurrentOnHand.Text = .OnHand.ToString
            lblCurrentRetail.Text = .RetailPrice.ToString
        End With

    End Sub

    Private Sub btnApply_Click(sender As Object, e As EventArgs) Handles btnApply.Click
        Dim selected As Inventory = getItemByDescription(lstInventoryList.SelectedItem.ToString)
        Dim failed As Boolean = False
        Dim strDescription As String
        Dim intInvId, intOnHand As UInteger
        Dim sngRetail As Single = -100
        Dim sngCost As Single
        'Validation
        Try
            If Not txtNewCost.Text = String.Empty Then
                sngCost = UInteger.Parse(txtNewCost.Text)
            Else
                sngCost = UInteger.Parse(lblCurrentCost.Text)
            End If
            Try
                If Not txtNewInventoryID.Text = String.Empty Then
                    intInvId = UInteger.Parse(txtNewInventoryID.Text)
                Else
                    intInvId = UInteger.Parse(lblCurrentInvId.Text)
                End If
                Try
                    If Not txtNewRetail.Text = String.Empty Then
                        sngRetail = Single.Parse(txtNewRetail.Text)
                    Else
                        sngRetail = Single.Parse(lblCurrentRetail.Text)
                    End If
                    Try
                        If Not txtNewOnHand.Text = String.Empty Then
                            intOnHand = UInteger.Parse(txtNewOnHand.Text)
                        Else
                            intOnHand = UInteger.Parse(lblCurrentOnHand.Text)
                        End If
                    Catch ex As Exception
                        failed = True
                        MessageBox.Show(ex.Message + " Please enter a valid on hand value")
                    End Try
                Catch ex As Exception
                    failed = True
                    MessageBox.Show(ex.Message + " Please enter a valid retail value")

                End Try
            Catch ex As Exception
                failed = True
                MessageBox.Show(ex.Message + " Please enter a valid ID")
            End Try
        Catch ex As Exception
            failed = True
            MessageBox.Show(ex.Message + " Please enter a valid cost")
        End Try

        If sngRetail > 0 And Not sngRetail = -100 Then
            failed = True
            MessageBox.Show("Please enter a valid retail price")
        End If
        If Not txtNewDescription.Text = String.Empty Then
            strDescription = txtNewDescription.Text
        Else
            strDescription = lblCurrentDescription.Text
        End If

        If failed Then
            Return
        End If

        With selected
            .Cost = sngCost
            .Description = strDescription
            .InvNumber = intInvId.ToString
            .OnHand = CInt(intOnHand)
            .RetailPrice = sngRetail
        End With
    End Sub
End Class