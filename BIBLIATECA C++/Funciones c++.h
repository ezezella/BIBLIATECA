#ifndef FUNCIONES_C++_H_INCLUDED
#define FUNCIONES_C++_H_INCLUDED

///OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
///             EA 2

Prisma(string _color="Incoloro", int _alto=1, int _ancho=1, int _profundidad=1);
Prisma(const Prisma& base);
friend ostream& operator <<(ostream& sal, const Prisma& pri);
friend Prisma operator*(int escalar,const Prisma&obj);
Prisma operator++(int);
Prisma& operator--();

///OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
///             REA 2

friend istream& operator >>(istream& ent, Pers& pers); // ingresa por teclado un objeto
friend ostream& operator <<(ostream& sal, const Pers& pers);  // muestra por pantalla un objeto
~Pers();
Pers(long dni = 0L, string apyn= "NN", char sexo= 'X', int edad = 0);  // parametrizado
Pers operator++(int);                                             // incrementa edad

///OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
///             EA 3

class FiguraInvalidaException
{
	private:
		string mensaje;

	public:
		FiguraInvalidaException(const string mensaje)
		{
		    this->mensaje = mensaje;
		}

		const string what() const
		{
		    return this->mensaje;
		}
};

#endif // FUNCIONES_C++_H_INCLUDED
