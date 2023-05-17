Public Class Inventory
    Private strInvNumber, strDescription As String
    Private sngCost, sngRetailPrice As Single
    Private intOnHand As Integer

    'Constructor
    Public Sub New()
        strInvNumber = String.Empty
        strDescription = String.Empty
        sngCost = 0.0
        sngRetailPrice = 0.0
        intOnHand = 0
    End Sub
    'Inventory number property
    Public Property InvNumber As String
        Get
            Return strInvNumber
        End Get
        Set(value As String)
            strInvNumber = value
        End Set
    End Property

    'Description property

    Public Property Description As String
        Get
            Return strDescription
        End Get
        Set(value As String)
            strDescription = value
        End Set
    End Property
    'Cost property
    Public Property Cost As Single
        Get
            Return sngCost
        End Get
        Set(value As Single)
            sngCost = value
        End Set
    End Property
    'Retail Price property
    Public Property RetailPrice As Single
        Get
            Return sngRetailPrice
        End Get
        Set(value As Single)
            sngRetailPrice = value
        End Set
    End Property
    'On Hand property
    Public Property OnHand As Integer
        Get
            Return intOnHand
        End Get
        Set(value As Integer)
            intOnHand = value
        End Set
    End Property


End Class
