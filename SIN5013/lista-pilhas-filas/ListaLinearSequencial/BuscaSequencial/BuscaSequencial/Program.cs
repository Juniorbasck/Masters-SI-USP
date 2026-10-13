public class ListaSequencial
{
    public int[] A { get; set; } = new int[Max];
    public int NroElem { get; set; }
    private const int Max = 50;
}

public class Program
{
    public static int BuscaSequencial(ListaSequencial l, int ch)
    {
        int i = 0;

        while (i < l.NroElem)
        {
            if (ch == l.A[i])
                return i;
            
            i++;
        }

        return -1;
    }

    public static void Main()
    {
        ListaSequencial minhaLista = new ListaSequencial();

        minhaLista.A[0] = 10;
        minhaLista.A[1] = 25;
        minhaLista.A[2] = 42;
        minhaLista.NroElem = 3;

        int chaveProcurada = 25;
        int posicao = BuscaSequencial(minhaLista, chaveProcurada);

        Console.WriteLine($"Chave {chaveProcurada} {(posicao == -1 ? "não encontrada na lista." : $"encontrada no índice {posicao}.")}");
    }
}