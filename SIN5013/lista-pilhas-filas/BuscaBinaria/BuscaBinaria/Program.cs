public class ListaSequencial
{
    public int[] A { get; set; } = new int[Max];
    public int NroElem { get; set; }
    private const int Max = 50;
}

class Solution
{
    public static int BuscaBinaria(ListaSequencial l, int ch)
    {
        int esq = 0;
        int dir = l.NroElem - 1;
        int meio;

        while (esq <= dir)
        {
            meio = (esq + dir) / 2;

            if (l.A[meio] == ch)
            {
                return meio; 
            }
            else
            {
                if (l.A[meio] < ch)
                {
                    esq = meio + 1;
                }
                else
                {
                    dir = meio - 1;
                }
            }
        }

        return -1;
    }

    public static void Main(string[] args)
    {
        ListaSequencial l = new ListaSequencial();
        
        l.A[0] = 10;
        l.A[1] = 25;
        l.A[2] = 42;
        l.A[3] = 45;
        l.NroElem = 4;
        
        var result =  BuscaBinaria(l, 45);
        
        Console.WriteLine("Resultado: " + result);
        
    }
}