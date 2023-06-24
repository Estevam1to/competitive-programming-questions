#define MATRIZ_GENERICA 1
#define MATRIZ_IDENTIDADE 2
#define MATRIZ_TRIANGULAR_SUPERIOR 3
#define MATRIZ_TRIANGULAR_INFERIOR 4

template <typename T> 
class MatrizQuadrada {
    private:
        int tipo;
        int n;
        T *vetor;

    public:
        MatrizQuadrada(int ordem);
        MatrizQuadrada(int ordem, int tipo);
        ~MatrizQuadrada();

        int getOrdem();
        int getTipo();
        T get(int i, int j) const;
        void set(int i, int j, T value);

        MatrizQuadrada<T> soma(const MatrizQuadrada<T> &B);
        MatrizQuadrada<T> multiplicacao(const MatrizQuadrada<T> &B);

        void multiplicacaoPorEscalar(T alpha);
};
