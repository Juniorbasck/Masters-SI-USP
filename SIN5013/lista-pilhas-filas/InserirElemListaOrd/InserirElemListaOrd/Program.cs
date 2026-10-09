public class ListaSequencial
{
    public int[] A { get; set; } = new int[Max];
    public int NroElem { get; set; }
    private const int Max = 50;
}

public class Program
{
    public static bool InserirElemListaOrd(ListaSequencial l, int ch)
    {
        if (l.NroElem >= l.A.Length) 
        {
            return false;
        }

        int pos = l.NroElem;

        while (pos > 0 && l.A[pos - 1] > ch)
        {
            l.A[pos] = l.A[pos - 1];
            pos--;
        }

        l.A[pos] = ch;
    
        l.NroElem++;

        return true;
    }

    public static void Main(string[] args)
    {
        ListaSequencial l = new ListaSequencial();
        
        l.A[0] = 10;
        l.A[1] = 25;
        l.A[2] = 42;
        l.NroElem = 3;
        
        var result =  InserirElemListaOrd(l, 27);
        
        Console.WriteLine("Resultado: " + result);
        
    }
}
