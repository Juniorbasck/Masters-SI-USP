using System;

public class Registro
{
    public int Chave { get; set; }
}

public class ListaSequencial
{
    public Registro[] A { get; set; }
    public int NroElem { get; set; }
    private const int Max = 50;

    public ListaSequencial()
    {
        A = new Registro[Max];
        NroElem = 0;

        for (int i = 0; i < Max; i++)
        {
            A[i] = new Registro();
        }
    }
}

public class Program
{
    public static int BuscaSequencial(ListaSequencial l, int ch)
    {
        int i = 0;

        while (i < l.NroElem)
        {
            if (ch == l.A[i].Chave)
            {
                return i;
            }
            else
            {
                i++;
            }
        }

        return -1;
    }

    public static void Main()
    {
        ListaSequencial minhaLista = new ListaSequencial();

        minhaLista.A[0].Chave = 10;
        minhaLista.A[1].Chave = 25;
        minhaLista.A[2].Chave = 42;
        minhaLista.NroElem = 3;

        int chaveProcurada = 25;
        int posicao = BuscaSequencial(minhaLista, chaveProcurada);

        Console.WriteLine($"Chave {chaveProcurada} {(posicao == -1 ? "não encontrada na lista." : $"encontrada no índice {posicao}.")}");
    }
}