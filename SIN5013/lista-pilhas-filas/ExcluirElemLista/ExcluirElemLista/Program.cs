public class Solution
{
	public class ListaSequencial
	{
		public int[] A { get; set; } = new int[Max];
		public int NroElem { get; set; }
		private const int Max = 50;
	}

	public static bool ExcluirElemLista(ListaSequencial l, int ch)
	{
		int pos = BuscaBinaria(l, ch);

		if (pos == -1)
		{
			return false;
		}
		for (int j = pos; j < l.NroElem - 1; j++)
		{
			l.A[j] = l.A[j + 1];
		}

		l.NroElem--;

		return true;
	}
	
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

		return -1; // Não encontrou
	}
	
	public static void Main(String[] args)
	{	
		
		ListaSequencial l = new ListaSequencial();
		
		l.A[0] = 10;
		l.A[1] = 25;
		l.A[2] = 42;
		l.NroElem = 3;

		var result = ExcluirElemLista(l, 3);
	}
}  