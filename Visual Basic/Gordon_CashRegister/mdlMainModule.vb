Imports System.IO
Module mdlMainModule
    Public inventoryList As New List(Of Inventory)
    Dim cashRegisterForm As frmCashRegister

    Sub Main()
        Dim stringList As New List(Of String)
        Using srReader As StreamReader = New StreamReader("Data.txt")
            Dim strLine As String = srReader.ReadLine()

            While Not strLine = String.Empty
                stringList.Add(strLine)
                strLine = srReader.ReadLine()
            End While



        End Using

        cashRegisterForm = New frmCashRegister
        cashRegisterForm.ShowDialog()

    End Sub

    Public Function getItemByDescription(ByVal descripton As String) As Inventory



        For Each item In inventoryList
            If item.Description.Equals(descripton) Then
                Return item
            End If
        Next
    End Function

    Public Sub updateList()
        cashRegisterForm.lstInventoryList.Items.Clear()



        For Each item In inventoryList
            Dim itemDescription As String = item.Description
            cashRegisterForm.lstInventoryList.Items.Add("Item: " + itemDescription)
        Next
    End Sub



End Module
