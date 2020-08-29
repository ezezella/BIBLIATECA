///OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
///             EA 2

Prisma::Prisma(const Prisma& base)
{
    this->alto=base.alto;
    this->ancho=base.ancho;
    this->color=base.color;
    this->profundidad=base.profundidad;
}

Prisma::Prisma(string _color, int _alto, int _ancho, int _profundidad)
{
    if(_alto<=0)///Valido de esta forma ya que al no haber un try/catch en el main, en caso de hacer una validacion mediante exception
                ///no se atraparia la excepcion y por ende no se mostraria el mensaje, solo mostrando que termino la ejecucion a causa
                ///de dicha excepcion.
    {
        cout<<"El valor alto es menor o igual a cero, poniendo valor por defecto (1)"<<endl;
        alto=1;
    }
    else
        alto=_alto;

    if(_ancho<=0)
    {
        cout<<"El valor ancho es menor o igual a cero, poniendo valor por defecto (1)"<<endl;
        ancho=1;
    }
    else
        ancho=_ancho;

    if(_profundidad<=0)
    {
        cout<<"El valor profundidad es menor o igual a cero, poniendo valor por defecto (1)"<<endl;
        profundidad=1;
    }
    else
        profundidad=_profundidad;
    color=_color;
}

ostream& operator <<(ostream& sal, const Prisma& pri)
{
    sal<<pri.alto<<"x"<<pri.ancho<<"x"<<pri.profundidad<<"-"<<pri.color;
    return sal;
}

Prisma operator*(const int escalar,const Prisma&obj)
{
    Prisma aux(obj.color,escalar*obj.alto, escalar*obj.ancho, escalar*obj.profundidad);
    return aux;
}

Prisma Prisma::operator++(int)
{
    Prisma aux(*this);
    this->alto++;
    this->ancho++;
    this->profundidad++;
    return aux;
}

Prisma& Prisma::operator--()
{
    this->alto--;
    this->ancho--;
    this->profundidad--;
    return *this;
}


///OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
///             REA 2


Pers::Pers(long dni, string apyn, char sexo, int edad)  // parametrizado
{
    this->dni=dni;
    this->apyn=apyn;
    this->sexo=sexo;
    this->edad=edad;
}

Pers::~Pers()
{

}

ostream& operator <<(ostream& sal, const Pers& pers)
{
    sal<<pers.dni<<"-"<<pers.sexo<<"-"<<pers.edad<<"-"<<pers.apyn;
    return sal;
}

istream& operator >>(istream& ent, Pers& pers)
{
    ent>>pers.dni;
    ent.ignore();
    ent>>pers.sexo;
    ent.ignore();
    ent>>pers.edad;
    ent.ignore();
    getline(ent,pers.apyn);
    return ent;
}

Pers Pers::operator++(int)
{
    Pers aux(*this);
    this->edad++;
    return aux;
}


///OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
///             EA 3


Figura::~Figura()
{

}

Triangulo::Triangulo(double _base,double _altura)
{
    if(_altura<=0||_base<=0)
        throw  FiguraInvalidaException("Figura invalida");
    this->base=_base;
    this->altura=_altura;
}
