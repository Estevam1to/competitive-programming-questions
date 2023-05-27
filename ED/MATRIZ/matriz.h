#define MATRIZ_GENERICA 1
#define MATRIZ_IDENTIDADE 2
#define MATRIZ_TRIANGULAR_SUPERIOR 3
#define MATRIZ_TRIANGULAR_INFERIOR 4

class MatrizQuadrada{
    private:
        int tipo;
        int n;
        double* vetor;
    public:
        MatrizQuadrada(int ordem);
        MatrizQuadrada(int ordem, int tipo);
        ~MatrizQuadrada();

        int getOrdem();
        int getTipo();
        double get(int i, int j);
        void set(int i, int j, double value);

        MatrizQuadrada soma(MatrizQuadrada& B);
        MatrizQuadrada multiplicacao(MatrizQuadrada& B);
        
        void multiplicacaoPorEscalar(double alpha);
};









