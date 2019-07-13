#include<bits/stdc++.h>
using namespace std;

template<class T>
class matrix
{
	private:
		template <typename TE> friend matrix<TE> operator*(int i,const matrix<TE>& rhs);
		template <typename TE> friend matrix<TE> operator*(const matrix<TE>& a, const matrix<TE>& b);
		template <typename TE> friend ostream& operator<<(ostream &os, const matrix<TE>& x);
		vector<vector<T>> mat;
		int N,M;

	public:
		matrix<T>(): N(0), M(0) {}
		matrix<T>(int N,int M,T init=0)
		{
			this->N=N;
			this->M=M;
			mat.resize(N);
			for(int i=0;i<N;i++)
			{
				mat[i].resize(M);
				fill(mat[i].begin(),mat[i].end(),init);
			}
		}
		
		matrix<T>(const std::vector<std::vector<T>> &m)
		{
			int c=0;
			if(m.size()>0)
			{
				c=m[0].size();
				for (int i=1; i<m.size();i++)
					if(m[i].size()!=c)
						cout<<("Not a matrix");
			}
			mat=m;
			N=m.size();
			M=c;
		}
		
		//float det();
		
		matrix<T>& AppendRow(T init=0);
		matrix<T>& AppendCol(T init=0);
		bool operator==(const matrix<T>& rhs);
		matrix<T> operator*(int i);
		matrix<T>& operator=(const matrix<T>& rhs);
		matrix<T> operator+(const matrix<T>& rhs);
		matrix<T> operator-(const matrix<T>& rhs);
		vector<T>& operator[](unsigned i) { return mat[i]; }
		vector<T> operator[](unsigned i) const { return mat[i]; }
		matrix<T> Coff(unsigned i, unsigned j) const;
		static T Det(const matrix<T>& x);
		T Det() const;
		matrix<T> Inv() const;
		unsigned Rows() const;
		unsigned Cols() const;
		matrix<T> LinSolve(const matrix &A, const matrix &b);

};