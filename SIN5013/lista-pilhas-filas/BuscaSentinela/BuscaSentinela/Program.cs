public class ListaSequencial
{
    private const int MAX = 50;
    public int[] A { get; set; } = new int[MAX + 1];
    public int NroElem { get; set; } = 0;
}

public class Program
{
    public static int BuscaSentinela(ListaSequencial l, int ch)
    {
        int counter = 0;
        
        l.A[l.NroElem] = ch;

        while (l.A[counter] != ch)
        {
            counter++;
        }

        // 3. Se parou no sentinela, o item não estava na lista original
        if (counter == l.NroElem)
            return -1;
        
        return counter;
    }

    public static void Main()
    {
        ListaSequencial lista = new ListaSequencial();

        lista.A[0] = 15;
        lista.A[1] = 30;
        lista.A[2] = 8;
        lista.NroElem = 3;

        int buscado = 30;
        int resultado = BuscaSentinela(lista, buscado);

        Console.WriteLine(resultado != -1 
            ? $"Chave {buscado} encontrada no índice: {resultado}" 
            : $"Chave {buscado} não encontrada.");
    }
}