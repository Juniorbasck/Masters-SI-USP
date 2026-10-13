using System;

public class Registro
{
    public int Chave { get; set; }
}

public class Elemento
{
    public Registro Reg { get; set; }
    public Elemento Prox { get; set; } 
    
    public Elemento()
    {
        Reg = new Registro();
    }
}

public class Lista
{
    public Elemento Inicio { get; set; }

    public Lista()
    {
        Inicio = null;
    }

    public int Tamanho()
    {
        Elemento end = Inicio;
        int tam = 0;
        
        while (end != null)
        {
            tam++;
            end = end.Prox;
        }
        
        return tam;
    }
    
    public void ExibirLista()
    {
        Elemento end = Inicio;
        while (end != null)
        {
            Console.Write($"{end.Reg.Chave} ");
            end = end.Prox;
        }
        Console.WriteLine();
    }
}

public class Program
{
    public static void Main()
    {
        Lista l = new Lista();
        
        l.Inicio = new Elemento 
        {
            Reg = new Registro { Chave = 10 },
            Prox = null
        };
        
        l.Inicio.Prox = new Elemento 
        {
            Reg = new Registro { Chave = 20 },
            Prox = null
        };

        l.Inicio.Prox.Prox = new Elemento 
        {
            Reg = new Registro { Chave = 30 },
            Prox = null
        };
          
        l.Inicio.Prox.Prox.Prox = new Elemento 
        {
            Reg = new Registro { Chave = 40 },
            Prox = null
        };
        
        Console.WriteLine($"Tamanho apos insercoes: {l.Tamanho()}");
        
        Console.WriteLine($"Tamanho inicial: {l.Tamanho()}");
        l.ExibirLista(); // Deve imprimir: 10 20 30
    }
}