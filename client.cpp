#include"mat.cpp"

//01FB16ECS086 B Shashank
//01FB16ECS105 Debanik Mishra
int main()
{
	cout<<boolalpha;

	matrix<int> a(3,3,1);
	cout<<"Matrix a\n"<<a<<endl;

	vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
	matrix<int>b(v);
	cout<<"Matrix b\n"<<b<<endl;

	matrix<int>sum=a+b;
	cout<<"a+b \n"<<sum<<endl;

	matrix<int>diff=a-b;
	cout<<"a-b \n"<<diff<<endl;

	matrix<int>prod=a*b;
	cout<<"Product of the matrices \n"<<prod<<endl;

	float r=a.Det();
	cout<<"Determinent of matrix : \n"<<r<<"\n";

	matrix<int> m(3,3,1);
	auto i= m==v;
	cout<<"m==v :"<<i<<"\n";
	cout<<m;


	//m*3
	cout<<" m*3 "<<"\n";
	cout<<m*3<<"\n";
	m=m*3;
	cout<<"m=m*3"<<"\n"<<m;

	a=b;
	cout<<a<<"\n";

	vector<vector<int>> k={{1,2,3},{4,5,6},{7,8,9}};
	matrix<int> d(v);

	//3*b
	cout<<" 3*b "<<"\n";
	cout<<3*b<<"\n";
	cout<<b<<"\n";
	m=3*b;
	cout<<m<<"\n";

	m.AppendRow(2);
	cout<<"After appending row\n"<<m;

	m.AppendCol(4);
	cout<<"After appending column\n"<<m;
	cout<<"\nRows :"<<m.Rows()<<" Cols :"<<m.Cols()<<"\n";

	cout<<m[1][1];

	vector<vector<double>>in={
		{ 17.2,    24.4,    1.5  },
		{ 23.8,     5.1,    7.4  },
		{  4.9,     6.4,    13.2 }
	};
	// matrix<double> new_mat(in);
	// cout<<new_mat.Inv();
	auto it=a.begin();
}
