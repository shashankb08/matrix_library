#include"mat.h"
template <typename T>
matrix<T>& matrix<T>::AppendCol(T init)
{
	for (unsigned i=0;i<N;i++)
		mat[i].push_back(init);
	++M;
	return *this;
}


// Returns the number of rows
template <typename T>
unsigned matrix<T>::Rows()const
{ 
	return N; 
}

// Returns the number of cols
template <typename T>
unsigned matrix<T>::Cols()const 
{ 
	return M; 
}


// Appends the row of the matrix with given value
template <typename T>
matrix<T>& matrix<T>::AppendRow(T init)
{
	vector<T> r(M,init);
	mat.push_back(r);
	++N;
	return *this;
}

//Sclar multiplication
template <typename TE>
matrix<TE> operator*(int k,const matrix<TE>& rhs)
{
	matrix<TE> temp(rhs.N,rhs.M,0);
	for(int i=0; i<rhs.N; i++)
		{
			for( int j=0; j<rhs.M; j++)
			{
				temp.mat[i][j]=rhs.mat[i][j]*k;
			}
		}
	return temp;
}


// Copy assignment operator
template <typename T>
matrix<T>& matrix<T>::operator=(const matrix<T>& rhs)
{ 
	if(N==rhs.N && M==rhs.M )
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				mat[i][j]=rhs.mat[i][j];
			}
		}
	}
	else
	{
		cout<<"Not equal\n";
		exit(0);
	}	
	return *this;
}


// For printing the matrix
template <typename TE> 
ostream& operator<<(ostream &os, const matrix<TE>& d)
{
	//cout<<d.N<<d.M;
	for(int i=0;i<d.N;i++)
	{
		os<<"[";
		for(int j=0;j<d.M;j++)
			os<<d.mat[i][j]<<" ";
		os<<"]\n";
	}
	return os;
}

// Addition of matrix
template <typename T>
matrix<T> matrix<T>::operator+(const matrix<T>& rhs)
{
	matrix<T> temp(N,M,0);
	if(N!=rhs.N||M!=rhs.M){
		cout<<"Cannot add the Matrices...they should be of same order\n";
		exit(0);
	}
	else{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				temp.mat[i][j]= mat[i][j]+ rhs.mat[i][j];
			}
		}
		return temp;
	}
}

// Subtraction of matrix
template <typename T>
matrix<T> matrix<T>::operator-(const matrix<T>& rhs)
{
	matrix<T> temp(N,M,0);	
	if(N!=rhs.N||M!=rhs.M){
		cout<<"Cannot find diff the Matrices...they should be of same order\n";
		exit(0);
	}
	else{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				temp.mat[i][j]= mat[i][j]- rhs.mat[i][j];
			}
		}
		return temp;
	}
}


// Multiplication of matrix
template <typename TE>
matrix<TE> operator*(const matrix<TE>& a, const matrix<TE>& b)
{
	if(a.M!=b.N){
		cout<<"Multiplication of these Matrices not allowed \n";
		exit(0);
	}
	else{
		matrix<TE>res(a.N,b.M,0);
		int i, j, k; 
    	for (i = 0; i < a.N; i++) 
    	{	 
        	for (j = 0; j < b.M; j++) 
        	{ 
            	res.mat[i][j] = 0; 
            	for (k = 0; k < a.M; k++) 
                	res.mat[i][j] += a.mat[i][k] * b.mat[k][j]; 
        	} 
    	}	 
		return res;
	}
}

// template <typename T>
// float matrix<T>::det()
// {	
// 	float det;
// 	matrix<T>res(N,N,0);
// 	if (N == 2)
//       return ((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
// 	else
// 	  det = mat[0][0]*((mat[1][1]*mat[2][2]) - (mat[2][1]*mat[1][2])) 
// 	  -mat[0][1]*(mat[1][0]*mat[2][2] - mat[2][0]*mat[1][2]) + mat[0][2]*(mat[1][0]*mat[2][1] 
// 	  - mat[2][0]*mat[1][1]);
//    return det;

// }

// Equality of the matrices
template <typename T> 
bool matrix<T>::operator==(const matrix<T>& rhs)
{
	int cnt=0;
	if( N==rhs.N && M==rhs.M )
	{
		for(int i=0; i<N; i++)
		{
		for( int j=0; j<M; j++)
		{
			if( mat[i][j]!=rhs.mat[i][j] )
				return 0;
			else
				++cnt;
		}
		}
	}
	return cnt==N*M;
}


//m*3
template<typename T>
matrix<T> matrix<T>::operator*(int k)
{
	matrix<T> temp(N,M,0);
	for(int i=0; i<N; i++)
		{
			for( int j=0; j<M; j++)
			{
				temp.mat[i][j]=k*mat[i][j];
			}
		}	
	return temp;
}

template <class T>
matrix<T> matrix<T>::Coff(unsigned i, unsigned j) const
{
	if (N==0)
		cout<<"Coff: the matrix is empty \n";

	matrix<T> y(N-1,M-1);
	
	unsigned k_c=0;
	for (unsigned k_x=0; k_x<N;k_x++)
	{
		if (k_x==i)
			continue;
		
		unsigned j_c=0;
		for (unsigned j_x=0 ; j_x<N; j_x++)
		{
			if (j_x==j)
				continue;
				
			y.mat[k_c][j_c]=mat[k_x][j_x];
			j_c++;
		}

		k_c++;
	}
	
	return y;	
}


template <class T>
T matrix<T>::Det(const matrix<T>& x)
{
	if(x.N != x.M)
		cout<<"Can't compute the determinant of a non square matrix";
	
	if (x.N == 0)
		cout<<"Empty matrix";
	
	if (x.N==1)
		return x.mat[0][0];
	
	T y=0;
	signed char d=1;
	
	for (unsigned i=0; i<x.N; i++)
	{
		y+=d*x.mat[i][0]*Det(x.Coff(i,0));
		d=-d;
	}

	return y;
}

template <class T>
T matrix<T>::Det() const
{
	return Det(*this);
}

template <class T>
matrix<T> matrix<T>::Inv() const
{
	double det_x=Det();
if(det_x==0)
	cout<<"inverse not possible\n";
	
	matrix<T> y(N,M);
	
	signed int d=1;

	for (unsigned i=0; i<N; i++)
		for (unsigned j=0; j<N; j++)
		{
			y.mat[j][i]=d*Det(Coff(i,j))/det_x;
			d=-d;
		}

	return y;
	
}
template <class T>
matrix<T> LinSolve(const matrix<T> &A, const matrix<T> &b)
{ 
	return A.Inv()*b; 
}