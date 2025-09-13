using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practica_40
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int Opcion, CantidadLados;
            double Lado, Base, Altura, Lado1, Lado2, Lado3, Radio, Perimetro;
            do
            {
                //En esta linea se llama al metodo Menu, como no tiene parámetros
                //solo se ponen parentesis.
                //Como menú es un método tipo void, no devuelve valores, por lo
                //la llamada al método no requiere la operación de asignación.
                Menu();
                Opcion = Int32.Parse(Console.ReadLine());
                switch (Opcion)
                {
                    case 1:
                        Console.Write("Introducir la longitud de uno de los lados: ");
                        Lado = Convert.ToDouble(Console.ReadLine());
                        //En esta línea se llama al método PerimetroCuadrado y se le pasa

                        //como parametro la variable Lado; el paso es por valor.
                        //Como el método devuelve un valor se tiene que asignar a una variable
                        Perimetro = PerimetroCuadrado(Lado); ;
                        Console.Write("El perímetro del cuadrado de {0} x " +
                        " {0} es {1} unidades", Lado, Perimetro);
                        break;
                    case 2:
                        Console.Write("Introducir la longitud de la base: ");
                        Base = Convert.ToDouble(Console.ReadLine());
                        Console.Write("Introducir la longitud de la altura: ");
                        Altura = Convert.ToDouble(Console.ReadLine());
                        //En esta línea se llama al método PerimetroRectangulo y se le pasa
                        //como parametros las variable Base y Altura; el paso es por valor.
                        //Como el método devuelve un valor se tiene que asignar a una variable
                        Perimetro = PerimetroRectangulo(Base, Altura);
                        Console.Write("El perímetro del rectángulo de {0} x " +
                        " {1} es {2} unidades", Base, Altura, Perimetro);
                        break;
                    case 3:
                        Console.Write("Introducir la longitud del lado 1: ");
                        Lado1 = Convert.ToDouble(Console.ReadLine());
                        Console.Write("Introducir la longitud del lado 2: ");
                        Lado2 = Convert.ToDouble(Console.ReadLine());
                        Console.Write("Introducir la longitud del lado 3: ");
                        Lado3 = Convert.ToDouble(Console.ReadLine());
                        //en este if se llama un método que devuelve un valor bool
                        //si el resultado del método es TRUE hara el bloque if
                        //si el resultado es FALSE hara el bloque ELSE
                        if (EsTriangulo(Lado1, Lado2, Lado3))
                        {
                            Perimetro = PerimetroTriangulo(Lado1, Lado2, Lado3);
                            Console.Write("El perímetro del triángulo con lados " +
                            "{0}, {1}, {2} es {3} unidades ", Lado1, Lado2, Lado3,
                            Perimetro);
                        }
                        else
                        {
                            Console.Write("Las longitudes introducidas no forman un triangulo");
                        }
                        break;
                    case 4:
                        Console.WriteLine("Introducir cantidad de lados del polígono");
                        CantidadLados = Int32.Parse(Console.ReadLine());
                        if (CantidadLados >= 5)
                        {
                            Console.Write("Introducir la longitud de uno de los lados:");
                            Lado = Convert.ToDouble(Console.ReadLine());
                            Perimetro = PerimetroPoligono(CantidadLados, Lado);
                            Console.Write("El perímetro del poligono con {0}" +
                            " lados de longitud {1} es {2}" +
                            " unidades ", CantidadLados, Lado, Perimetro);
                        }
                        else
                        {
                            Console.WriteLine("Para esta opción la figura" +
                            " debe tener 5 lados o mas");
                        }
                        break;
                    case 5:
                        Console.Write("Introducir la longitud del radio: ");
                        Radio = Convert.ToDouble(Console.ReadLine());
                        Perimetro = PerimetroCircunferencia(Radio);
                        Console.Write("El perímetro del circulo de" +
                        " radio {0} es {1} unidades ", Radio, Perimetro);
                        break;
                    case 6:
                        Console.Write("Gracias por usar la aplicación");
                        break;
                    default:
                        Console.WriteLine("Opción elegida es invalida");
                        break;
                }
                Console.ReadKey();
            } while (Opcion != 6);
        }

        static void Menu()
        {
            Console.WriteLine("Menú de opciones");
            Console.WriteLine("1.Cuadrado");
            Console.WriteLine("2. Rectángulo");
            Console.WriteLine("3. Triángulo");
            Console.WriteLine("4. Polígono");
            Console.WriteLine("5. Circunferencia");
            Console.WriteLine("6. Salir");
            Console.Write("Introducir opción: ");
        }
        static double PerimetroCuadrado(double Lado)
        {
            double P;
            P = 4 * Lado;
            return P;
        }
        static double PerimetroRectangulo(double Base, double Altura)
        {
            double P;
            P = 2 * Base + 2 * Altura;
            return P;
        }
        static double PerimetroTriangulo(double LadoA, double LadoB, double LadoC)
        {
            double P;
            P = LadoA + LadoB + LadoC;
            return P;
        }
        static double PerimetroPoligono(int N, double Lado)
        {
            double P;
            P = N * Lado;
            return P;
        }
        static double PerimetroCircunferencia(double Radio)
        {
            double P;
            P = Math.PI * Radio;
            return P;
        }
        static bool EsTriangulo(double LadoA, double LadoB, double LadoC)
        {
            bool SiEs;
            if (LadoC < LadoA + LadoB && LadoB < LadoA + LadoC && LadoA < LadoB + LadoC)
            {
                SiEs = true;
            }
            else
            {
                SiEs = false;
            }
            return SiEs;
        }
    }
}
